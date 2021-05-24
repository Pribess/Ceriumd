//Copyright (c) 2021 Heewon Cho

#include "CastingTools.hpp"

#include <iostream>
#include <cstring>
#include <string>
#include <sstream>

const char *CastingTools::itoa(int Buff) {
    static char Buff_RET[64];
    std::sprintf(Buff_RET, "%d", Buff);
    return Buff_RET;
}

const char *CastingTools::ctoh(const char *Buff) {
    static char Buff_RET[256];
    std::stringstream ss;
    for (int cnt = 0; cnt < std::strlen(Buff); cnt++) {
        ss << std::hex << (int)Buff[cnt];
        ss << " ";
    }
    std::strcpy(Buff_RET, ss.str().c_str());
    return Buff_RET;
}

const char *CastingTools::ctod(const char *Buff) {
    static char Buff_RET[256];
    std::stringstream ss;
    for (int cnt = 0; cnt < std::strlen(Buff); cnt++) {
        ss << std::dec << (int)Buff[cnt];
        ss << " ";
    }
    std::strcpy(Buff_RET, ss.str().c_str());
    return Buff_RET;
}