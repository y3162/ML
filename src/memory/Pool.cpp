#include "memory.hpp"

using namespace Memory;

void* Pool::malloc(size_t size)
{
    return ::malloc(size);
}

void* Pool::calloc(size_t count, size_t size)
{
    return ::calloc(count, size);
}

void* Pool::realloc(void *ptr, size_t size)
{
    return ::realloc(ptr, size);
}

void Pool::free(void *ptr)
{
    ::free(ptr);
}
