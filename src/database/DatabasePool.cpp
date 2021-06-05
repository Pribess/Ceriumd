//Copyright (c) 2021 Heewon Cho

#include "DatabasePool.hpp"

void DatabasePool::SetUpDatabase() {
    if (sqlite3_open("", &DatabasePool::db)) {
        throw std::ios_base::failure("Database Opening Failed!");
    }
}