//Copyright (c) 2021 Heewon Cho

#include "CastingTools.hpp"

#include <iostream>

char *CastingTools::itoa(int Buff) {
    static char Buff_RET[64];
    std::sprintf(Buff_RET, "%d", Buff);
    return Buff_RET;
}
