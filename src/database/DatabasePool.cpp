//Copyright (c) 2021 Heewon Cho

#include "DatabasePool.hpp"

void DatabasePool::SetUpDatabase(std::string dirname) {
    dirname.append("net.db");
    if (access(dirname.c_str(), F_OK)) {
        std::ofstream out(dirname);
        out.close();
    }
}