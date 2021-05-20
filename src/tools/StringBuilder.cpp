//Copyright (c) 2021 Heewon Cho

#include "StringBuilder.hpp"

#include "CastingTools.hpp"

#include <iostream>

StringBuilder::StringBuilder(int Buff) {
    this->String.append(CastingTools::itoa(Buff));
}

StringBuilder::StringBuilder(const char *Buff) {
    this->String.append(Buff);
}

void StringBuilder::AppendInt(int Buff) {
    this->String.append(CastingTools::itoa(Buff));
}

void StringBuilder::AppendChar(const char *Buff) {
    this->String.append(Buff);
}

const char *StringBuilder::RetString() {
    return this->String.c_str();
}