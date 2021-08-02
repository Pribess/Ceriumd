// Copyright (c) 2021 Heewon Cho

#ifndef _CERIUM_CONSTANT_KEYVALUE
#define _CERIUM_CONSTANT_KEYVALUE

#include <unordered_map>
#include <string>
#include <iostream>

class KeyValue {
    private:
        static std::unordered_map<std::string, std::string> KeyDatabase;
    public:
        static void SetKeyValue(std::string key, std::string value);
        static std::string GetKeyValue(std::string key); 
};

#endif