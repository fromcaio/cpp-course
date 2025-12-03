#include <iostream>
#include <sqlite3.h>
#include <string>
#include <stdexcept>
#include <vector>
#include <utility>

class Database {
    private:
        sqlite3* db_{nullptr};
    public:
        // Explicit prevent implicit conversions, e.g.
        // Database db("gym.db"); is valid
        // Database db = "gym.db"; is invalid
        explicit Database(const std::string& path) {
            if (sqlite3_open(path.c_str(), &db_) != SQLITE_OK) {
                throw std::runtime_error(std::string("Cannot open database: ") +
                                         sqlite3_errmsg(db_));
            }
        }
        ~Database() {
            if (db_) {
                sqlite3_close(db_);
            }
        }

        // execute a sql statement that does not return results
        void exec(const std::string& sql) {
            char * errMsg = nullptr;
            if (sqlite3_exec(db_, sql.c_str(), nullptr, nullptr, &errMsg) != SQLITE_OK) {
                std::string error = errMsg ? errMsg : "Unknown error";
                sqlite3_free(errMsg);
                throw std::runtime_error("SQL error: " + error);
            }
        }
        void initializeSchema(){
            exec(R"sql(
                CREATE TABLE IF NOT EXISTS examples(
                    id INTEGER PRIMARY KEY AUTOINCREMENT,
                    name TEXT NOT NULL
                );
            )sql");
        }
        sqlite3* handle() const noexcept { return db_; }
};

class Statement {
    private: 
        sqlite3_stmt* stmt_{nullptr};
        bool done_{false};
    public:
        // we recieve a pointer to the database and the sql string with placeholders
        // we prepare the sql statement using sqlite3_prepare_v2
        Statement(sqlite3* db, const std::string& sql) {
            if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt_, nullptr) != SQLITE_OK) {
                throw std::runtime_error(std::string("Failed to prepare statement: ") +
                                         sqlite3_errmsg(db));
            }
        }
        ~Statement() {
            if (stmt_) {
                sqlite3_finalize(stmt_);
            }
        }

        void bindText(int index, const std::string& value){
            if (sqlite3_bind_text(stmt_, index, value.c_str(), -1, SQLITE_TRANSIENT) != SQLITE_OK) {
                throw std::runtime_error("Failed to bind text at index " + std::to_string(index));
            }
        };
        void bindDouble(int index, double value){
            if (sqlite3_bind_double(stmt_, index, value) != SQLITE_OK) {
                throw std::runtime_error("Failed to bind double at index " + std::to_string(index));
            }
        };
        void bindInt(int index, int value){
            if (sqlite3_bind_int(stmt_, index, value) != SQLITE_OK) {
                throw std::runtime_error("Failed to bind int at index " + std::to_string(index));
            }
        };
        bool step(){
            int rc = sqlite3_step(stmt_);
            // our sql statement could return either SQLITE_ROW (a row is available)
            // or SQLITE_DONE (no more rows)
            if (rc == SQLITE_ROW) {
                return true; // Row is available
            } else if (rc == SQLITE_DONE) {
                done_ = true;
                return false; // No more rows
            } else {
                throw std::runtime_error("Failed to execute statement");
            }
        }
        // we can use this method to check if we are done iterating over the results
        bool done() const {
            return done_;
        }
        std::string columnText(int index) const {
            const unsigned char* text = sqlite3_column_text(stmt_, index);
            return text ? reinterpret_cast<const char*>(text) : "";
        }
        int columnInt(int index) const { return sqlite3_column_int(stmt_, index); }
        double columnDouble(int index) const { return sqlite3_column_double(stmt_, index); }
};

// Controller focused on the `examples` table
class ExampleController {
private:
    Database& db_;
public:
    explicit ExampleController(Database& db) : db_(db) {}

    int addExample(const std::string& name) {
        Statement stmt(db_.handle(), "INSERT INTO examples(name) VALUES (?);");
        stmt.bindText(1, name);
        stmt.step();
        return static_cast<int>(sqlite3_last_insert_rowid(db_.handle()));
    }

    std::vector<std::pair<int, std::string>> fetchAll() {
        Statement stmt(db_.handle(), "SELECT id, name FROM examples ORDER BY id;");
        std::vector<std::pair<int, std::string>> rows;
        while (stmt.step()) {
            rows.emplace_back(stmt.columnInt(0), stmt.columnText(1));
        }
        return rows;
    }

    int count() {
        Statement stmt(db_.handle(), "SELECT COUNT(*) FROM examples;");
        stmt.step();
        return stmt.columnInt(0);
    }

    void remove(int id) {
        Statement stmt(db_.handle(), "DELETE FROM examples WHERE id = ?;");
        stmt.bindInt(1, id);
        stmt.step();
    }
};

int main() {

    Database db("gym.db");
    db.initializeSchema();

    ExampleController controller(db);

    controller.addExample("Alice");
    controller.addExample("Bob");

    std::cout << "Examples count: " << controller.count() << "\n";

    for (auto& [id, name] : controller.fetchAll()) {
        std::cout << id << ": " << name << "\n";
    }

    return 0;
}
