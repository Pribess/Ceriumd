//Copyright (c) 2021 Heewon Cho

#ifndef CERIUM_TOOLS_CASTINGTOOLS
#define CERIUM_TOOLS_CASTINGTOOLS

#include <iostream>
#include <cstring>
#include <string>
#include <sstream>

class CastingTools {
private:
public:
    static const char *itoa(int Buff);
    static const char *ctoh(const char *Buff);
    static const char *ctod(const char *Buff);
};

#endif