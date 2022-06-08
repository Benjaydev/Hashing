#include "HashFunction.h"

namespace HashFunction {

    // implementation of a basic addition hash
    unsigned int badHash(const char* data, unsigned int length) {
        unsigned int hash = 0;

        for (unsigned int i = 0; i < length; ++i)
            hash += data[i];

        return hash;
    }

    unsigned int DJBHash(const char* str, unsigned int length)
    {
        unsigned int hash = 5381;
        unsigned int i = 0;

        for (i = 0; i < length; ++str, ++i)
        {
            hash = ((hash << 5) + hash) + (*str);
        }

        return hash;
    }




}