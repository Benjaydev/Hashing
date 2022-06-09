#pragma once
#include <functional>

namespace HashFunction {
    unsigned int DJBHash(const char* str, unsigned int length);

    // Helper
    static std::function<unsigned int(const char*, unsigned int)> hash = DJBHash;
}