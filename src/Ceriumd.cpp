//Copyright (c) 2021 Heewon Cho 

#include <iostream>
#include "crypto/Crypto.hpp"

int main(int argc, char* argv[]) {
    std::cout << "   ___          _                 \n  / __\\___ _ __(_)_   _ _ __ ___  \n / /  / _ \\ '__| | | | | '_ ` _ \\\n/ /__|  __/ |  | | |_| | | | | | |\n\\____/\\___|_|  |_|\\__,_|_| |_| |_|" << std::endl;
    std::cout << Crypto::SHA256("hello") << std::endl;
    std::cout << Crypto::SHA256("Hello") << std::endl;
    return 0;
}
