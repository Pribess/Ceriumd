//Copyright (c) 2021 Heewon Cho

#include "Sqlite.hpp"
#include "tools/CastingTools.hpp"

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

std::vector<std::vector<std::vector<unsigned char>>> Sqlite::ExecuteQuery(std::string sql) {
    std::vector<std::vector<std::vector<unsigned char>>> rs;
    sqlite3_stmt *stmt;

    if (sqlite3_prepare(this->db, sql.c_str(), sql.length(), &stmt, nullptr)) {
        throw std::ios_base::failure("Prepareing Statement Failed!");
    }

    while (SQLITE_ROW == sqlite3_step(stmt)) {
        std::vector<std::vector<unsigned char>> row;

        for (int cntcol = 0 ; cntcol < sqlite3_column_count(stmt) ; cntcol++) {
            std::vector<unsigned char> col;
            
            const char *rsbyte = (const char *)sqlite3_column_blob(stmt, cntcol);

            for (int cntbyte = 0 ; cntbyte < sqlite3_column_bytes(stmt, cntcol) ; cntbyte++) {
                col.push_back((unsigned char)rsbyte[cntbyte]);
            }
            
            row.push_back(col);
        }

        rs.push_back(row);
    }

    if (sqlite3_finalize(stmt)) {
        throw std::ios_base::failure("Finalize Statement Failed!");
    }

    return rs;
}