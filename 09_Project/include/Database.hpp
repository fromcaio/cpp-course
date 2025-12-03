#pragma once

#include <sqlite3.h>

// used for exception handling
#include <stdexcept>
#include <string>

class Statement {
private:
    sqlite3_stmt* stmt_{nullptr};
    bool done_{false};
public:
// we recieve a pointer to the database and the sql string
// we prepare the sql statement using sqlite3_prepare_v2
// the prepared statement is stored in stmt_ attribute
    Statement(sqlite3* db, const std::string& sql);
// we finalize the prepared statement to release resources
    ~Statement();
// prevent copy
    Statement(const Statement&) = delete;
// prevent copy assignment
    Statement& operator=(const Statement&) = delete;
// prevent move
    Statement(Statement&&) = delete;
// prevent move assignment
    Statement& operator=(Statement&&) = delete;

// 
    void bindText(int index, const std::string& value);
    void bindDouble(int index, double value);
    void bindInt(int index, int value);

    bool step();          // returns true if a row is available
    bool done() const;    // true if SQLITE_DONE reached

    std::string columnText(int index) const;
    int columnInt(int index) const;
    double columnDouble(int index) const;
};

class Database {
private:
    sqlite3* db_{nullptr};

public:
    // Explicit prevent implicit conversions, e.g.
    // Database db("gym.db"); is valid
    // Database db2 = "gym.db"; is blocked
    // To avoid accidental copies
    explicit Database(const std::string& path);
    ~Database();

    // delete tells the compiler that these functions exists
    // but we don't want to allow their usage
    // if we recieve a Database object as parameter
    Database(const Database&) = delete;
    // if we try to assign a Database object to another
    Database& operator=(const Database&) = delete;
    // if we try to move a Database object to another
    Database(Database&&) = delete;
    // if we try to move assign a Database object to another
    Database& operator=(Database&&) = delete;

    // This is a getter that returns the pointer to sqlite3 database
    sqlite3* handle() const noexcept { return db_; }

    void exec(const std::string& sql);
    void initializeSchema();
};
