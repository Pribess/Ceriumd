//Copyright (c) 2021 Heewon Cho

#include "Sqlite.hpp"

Sqlite::Sqlite(std::string dbname) {
    this->OpenDatabase(dbname);
}

Sqlite::~Sqlite() {
    this->CloseDatabase();
}

void Sqlite::OpenDatabase(std::string dbname) {
    if (sqlite3_open(dbname.c_str(), &this->db)) {
        throw std::ios_base::failure("Opening Database Failed!");
    }
}

void Sqlite::CloseDatabase() {
    if (sqlite3_close(this->db)) {
        throw std::ios_base::failure("Closing Database Failed!");
    }
}

std::vector<std::vector<std::pair<std::string, size_t>>> Sqlite::ExecuteQuery(std::string sql) {
    std::vector<std::vector<std::pair<std::string, size_t>>> rs;
    sqlite3_stmt *stmt;

    if (sqlite3_prepare(this->db, sql.c_str(), sql.length(), &stmt, nullptr)) {
        throw std::ios_base::failure("Prepare Statement Failed!");
    }
    
    while (SQLITE_ROW == sqlite3_step(stmt)) {
        std::vector<std::pair<std::string, size_t>> row;
        // row.push_back(std::pair<std::string, size_t>());
        printf("%d\n", sqlite3_column_bytes(stmt, 0));
        printf("%d\n", sqlite3_column_bytes(stmt, 1));
        uint32_t as;
        memcpy(&as, sqlite3_column_blob(stmt, 0), sqlite3_column_bytes(stmt, 0));
        printf("%x\n", as);
        printf("%x\n", sqlite3_column_blob(stmt, 0));
        printf("%x\n", sqlite3_column_blob(stmt, 1));
        rs.push_back(row);
    }

    if (sqlite3_finalize(stmt)) {
        throw std::ios_base::failure("Finalize Statement Failed!");
    }

    return rs;
}