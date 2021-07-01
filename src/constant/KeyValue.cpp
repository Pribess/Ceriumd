//Copyright (c) 2021 Heewon Cho

#include "KeyValue.hpp"

std::unordered_map<std::string, std::string> KeyValue::KeyDatabase;

void KeyValue::SetKeyValue(std::string key, std::string value) {
    try {
        KeyValue::KeyDatabase[key] = value;
    } catch (std::runtime_error e) {
        throw e;
    }
}

std::string KeyValue::GetKeyValue(std::string key) {
    try {
        return KeyValue::KeyDatabase[key];
    } catch (std::runtime_error e) {
        throw e;
    }
}