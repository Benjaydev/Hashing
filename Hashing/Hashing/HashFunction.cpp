#include "HashFunction.h"

namespace HashFunction {
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