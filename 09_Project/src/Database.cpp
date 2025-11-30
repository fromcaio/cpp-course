#include "Database.hpp"

#include <utility>

Statement::Statement(sqlite3* db, const std::string& sql) {
    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt_, nullptr) != SQLITE_OK) {
        throw std::runtime_error(std::string("Failed to prepare statement: ") +
                                 sqlite3_errmsg(db));
    }
}

Statement::~Statement() {
    if (stmt_) {
        sqlite3_finalize(stmt_);
    }
}

void Statement::bindText(int index, const std::string& value) {
    if (sqlite3_bind_text(stmt_, index, value.c_str(), -1, SQLITE_TRANSIENT) !=
        SQLITE_OK) {
        throw std::runtime_error("Failed to bind text parameter");
    }
}

void Statement::bindDouble(int index, double value) {
    if (sqlite3_bind_double(stmt_, index, value) != SQLITE_OK) {
        throw std::runtime_error("Failed to bind double parameter");
    }
}

void Statement::bindInt(int index, int value) {
    if (sqlite3_bind_int(stmt_, index, value) != SQLITE_OK) {
        throw std::runtime_error("Failed to bind int parameter");
    }
}

bool Statement::step() {
    int rc = sqlite3_step(stmt_);
    if (rc == SQLITE_ROW) {
        return true;
    }
    if (rc == SQLITE_DONE) {
        done_ = true;
        return false;
    }
    throw std::runtime_error("Failed to step statement");
}

bool Statement::done() const { return done_; }

std::string Statement::columnText(int index) const {
    const unsigned char* text = sqlite3_column_text(stmt_, index);
    return text ? reinterpret_cast<const char*>(text) : "";
}

int Statement::columnInt(int index) const { return sqlite3_column_int(stmt_, index); }

double Statement::columnDouble(int index) const { return sqlite3_column_double(stmt_, index); }

// we recieve a string then we call sqlite3_open from sqlite3 library
// we send to it the path where the db is stored
// the adress of atribute db_ that is a pointer to sqlite3 type
// if it returns something different from SQLITE_OK we throw an exception
Database::Database(const std::string& path) {
    if (sqlite3_open(path.c_str(), &db_) != SQLITE_OK) {
        throw std::runtime_error(std::string("Cannot open database: ") +
                                 sqlite3_errmsg(db_));
    }
}

// we close the bd connection if db_ is not a nullptr
Database::~Database() {
    if (db_) {
        sqlite3_close(db_);
    }
}

void Database::exec(const std::string& sql) {
    char* errMsg = nullptr;
// int sqlite3_exec(
//   sqlite3*,                                  /* An open database */
//   const char *sql,                           /* SQL to be evaluated */
//   int (*callback)(void*,int,char**,char**),  /* Callback function */
//   void *,                                    /* 1st argument to callback */
//   char **errmsg                              /* Error msg written here */
// );
    if (sqlite3_exec(db_, sql.c_str(), nullptr, nullptr, &errMsg) != SQLITE_OK) {
        std::string error = errMsg ? errMsg : "Unknown SQLite error";
        // Free the error message allocated by SQLite
        sqlite3_free(errMsg);
        throw std::runtime_error("SQLite exec failed: " + error);
    }
}

void Database::initializeSchema() {
    exec("PRAGMA foreign_keys = ON;");

    // R means \n and \t are treated literally
    // sql is a chosen delimiter
    exec(R"sql(
        CREATE TABLE IF NOT EXISTS members(
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            name TEXT NOT NULL,
            cpf TEXT,
            phone TEXT,
            pix TEXT
        );
    )sql");

    //  FOREIGN KEY enforces the need to link member_id to members table
    //  REFERENCES enforces the need to have a valid member_id in members table
    exec(R"sql(
        CREATE TABLE IF NOT EXISTS payments(
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            member_id INTEGER NOT NULL,
            amount REAL NOT NULL,
            date TEXT NOT NULL,
            duration TEXT NOT NULL,
            FOREIGN KEY(member_id) REFERENCES members(id) ON DELETE CASCADE
        );
    )sql");

    exec(R"sql(
        CREATE TABLE IF NOT EXISTS checkins(
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            member_id INTEGER NOT NULL,
            date TEXT NOT NULL,
            time TEXT,
            FOREIGN KEY(member_id) REFERENCES members(id) ON DELETE CASCADE
        );
    )sql");

    exec(R"sql(
        CREATE TABLE IF NOT EXISTS workout_plans(
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            member_id INTEGER NOT NULL,
            FOREIGN KEY(member_id) REFERENCES members(id) ON DELETE CASCADE
        );
    )sql");

    exec(R"sql(
        CREATE TABLE IF NOT EXISTS workout_plan_days(
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            plan_id INTEGER NOT NULL,
            day_index INTEGER NOT NULL,
            FOREIGN KEY(plan_id) REFERENCES workout_plans(id) ON DELETE CASCADE
        );
    )sql");

    exec(R"sql(
        CREATE TABLE IF NOT EXISTS exercises(
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            day_id INTEGER NOT NULL,
            name TEXT NOT NULL,
            sets INTEGER NOT NULL DEFAULT 0,
            reps INTEGER NOT NULL DEFAULT 0,
            weight REAL NOT NULL DEFAULT 0,
            FOREIGN KEY(day_id) REFERENCES workout_plan_days(id) ON DELETE CASCADE
        );
    )sql");
}
