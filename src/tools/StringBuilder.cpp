//Copyright (c) 2021 Heewon Cho

#include "StringBuilder.hpp"

#include "CastingTools.hpp"

StringBuilder::StringBuilder(int Buff) {
    String.append(CastingTools::itoa(Buff));
}

StringBuilder::StringBuilder(const char *Buff) {
    String.append(Buff);
}

void StringBuilder::AppendInt(int Buff) {
    String.append(CastingTools::itoa(Buff));
}

void StringBuilder::AppendChar(const char *Buff) {
    String.append(Buff);
}

const char *StringBuilder::RetString() {
    return String.c_str();
}