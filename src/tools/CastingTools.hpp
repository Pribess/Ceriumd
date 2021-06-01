//Copyright (c) 2021 Heewon Cho

#ifndef _CERIUM_TOOLS_CASTINGTOOLS
#define _CERIUM_TOOLS_CASTINGTOOLS

#include <iostream>
#include <cstring>
#include <string>
#include <sstream>

class CastingTools {
    public:
        static const char *itoa(int Buff);
        static const char *ctoh(const char *Buff, size_t size);
        static const char *ctod(const char *Buff, size_t size);
};

#endif