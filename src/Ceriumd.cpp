//Copyright (c) 2021 Heewon Cho 

#include "crypto/Crypto.hpp"
#include "Block.hpp"
#include "tools/CastingTools.hpp"
#include "net/primitive/Socket.hpp"

#include <iostream>
#include <arpa/inet.h>

int main(int argc, char* argv[]) {
    std::cout << "   ___          _                 \n  / __\\___ _ __(_)_   _ _ __ ___  \n / /  / _ \\ '__| | | | | '_ ` _ \\\n/ /__|  __/ |  | | |_| | | | | | |\n\\____/\\___|_|  |_|\\__,_|_| |_| |_|" << std::endl;
    Block *b1 = new Block(1, (char *)"1", (char *)"1", 1, 1, 1);
    std::cout << b1->CalculateBlockHash() << std::endl;
    delete b1;
    Socket *s1 = new Socket(6752, (char *)"127.0.0.1");
    s1->CreateSocket(SOCK_STREAM, IPPROTO_TCP);
    std::cout << s1->Connect() << std::endl;
    s1->SendData(78);
    s1->SendData(10);
    std::cout << CastingTools::ctoh(s1->RecvData()) << std::endl;
    s1->CloseSocket();
    delete s1;
    return 0;
}
