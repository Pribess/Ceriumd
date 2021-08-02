// Copyright (c) 2021 Heewon Cho

#include "TimeStamp.hpp"

long int TimeStamp::GetUtcTimeStamp() {
    return std::chrono::duration_cast<std::chrono::seconds>(std::chrono::system_clock::now().time_since_epoch()).count();
}