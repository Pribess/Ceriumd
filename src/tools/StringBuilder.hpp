//Copyright (c) 2021 Heewon Cho

#include <string>

class StringBuilder {
private:
    std::string String;
public:
    StringBuilder();
    StringBuilder(int Buff);
    StringBuilder(const char *Buff);
    void AppendInt(int Buff);
    void AppendChar(const char *Buff);
    const char *RetString();
};