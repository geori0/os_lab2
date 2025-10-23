#pragma once

#include <string>

typedef struct {
    size_t start_seek;
    size_t end_seek;
    size_t id;
    const std::string* str; 
    const std::string* sub_str;
} ThreadData;