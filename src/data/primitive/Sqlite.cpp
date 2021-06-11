//Copyright (c) 2021 Heewon Cho

#include "Sqlite.hpp"
#include "tools/CastingTools.hpp"

std::vector<std::vector<std::string>> Sqlite::buff;

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

int Sqlite::HandleResult(void *ArgThrough, int argc, char **argv, char **azColName) {
    std::vector<std::string> row;

    for (int cnt = 0 ; cnt < argc ; cnt++) {
        std::cout << "row.at(" << cnt << ") == " << CastingTools::ctoh(argv[cnt], 8) << std::endl;
        row.push_back(std::string(argv[cnt]));
        // printf("%s\n", CastingTools::ctoh(argv[cnt], 4));    uint32_t ui32;
        uint32_t as;
        std::string asd;
        asd.append(argv[cnt]);
        std::memcpy(&as, asd.c_str(), sizeof(uint32_t));
        std::cout << std::hex << as << std::endl;
        uint32_t ui32;
        std::memcpy(&ui32, argv[cnt], sizeof(uint32_t));
        std::cout << std::hex << ui32 << std::endl;
        uint32_t ui321;
        std::memcpy(&ui321, row.at(cnt).c_str(), 4);
        std::cout << std::hex << ui321 << std::endl; 
    }

    Sqlite::buff.push_back(row);

    return 0;
}

std::vector<std::vector<std::string>> Sqlite::ExecuteQuery(std::string sql) {
    char *errmsg;

    Sqlite::buff.clear();
    
    if (sqlite3_exec(this->db, sql.c_str(), Sqlite::HandleResult, this, &errmsg)) {
        throw std::ios_base::failure(std::strcat((char *)"Get Execute Query Failed : ", errmsg));
    }

    sqlite3_free(errmsg);

    return Sqlite::buff;
}