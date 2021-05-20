//Copyright (c) 2021 Heewon Cho 

#include "crypto/Crypto.hpp"
#include "Block.hpp"
#include "tools/CastingTools.hpp"
#include "net/Socket.hpp"

#include <iostream>
#include <arpa/inet.h>

int main(int argc, char* argv[]) {
    char dt[] = "HELLOW";
    std::cout << "   ___          _                 \n  / __\\___ _ __(_)_   _ _ __ ___  \n / /  / _ \\ '__| | | | | '_ ` _ \\\n/ /__|  __/ |  | | |_| | | | | | |\n\\____/\\___|_|  |_|\\__,_|_| |_| |_|" << std::endl;
    Block *b1 = new Block(1, (char *)"1", (char *)"1", 1, 1, 1);
    std::cout << b1->CalculateBlockHash() << std::endl;
    delete b1;
    Socket *s1 = new Socket(AF_INET, 6752);
    s1->CreateSocket(SOCK_STREAM, IPPROTO_TCP);
    s1->BindSocket();
    s1->Listen();
    s1->CloseSocket();
    delete s1;
    return 0;
}
