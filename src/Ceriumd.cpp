//Copyright (c) 2021 Heewon Cho 

#include "crypto/Crypto.hpp"
#include "Block.hpp"
#include "tools/CastingTools.hpp"

#include <iostream>

int main(int argc, char* argv[]) {
    std::cout << "   ___          _                 \n  / __\\___ _ __(_)_   _ _ __ ___  \n / /  / _ \\ '__| | | | | '_ ` _ \\\n/ /__|  __/ |  | | |_| | | | | | |\n\\____/\\___|_|  |_|\\__,_|_| |_| |_|" << std::endl;
    Block *b1 = new Block(1, (char *)"1", (char *)"1", 1, 1, 1);
    std::cout << b1->CalculateBlockHash() << std::endl;
    free(b1);
    return 0;
}
