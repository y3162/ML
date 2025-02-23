#pragma once

#include <cstdlib> 

namespace Memory
{
    class Pool
    {
    public:
        static void* malloc(size_t);
        static void* calloc(size_t, size_t);
        static void* realloc(void*, size_t);
        static void  free(void*);
    };
}