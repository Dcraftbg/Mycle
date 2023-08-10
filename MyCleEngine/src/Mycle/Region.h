#pragma once
#include <cstdint>
#include <string.h>
#include <stdlib.h>
#include "Utils.h"
namespace Mycle {
    class MCLAPI Region {
    public:
        size_t size;
        size_t capacity;
        uintptr_t* sector;
    private:
        Region* allocator;
    public:
        Region(Region* r, size_t size);
        Region() : capacity(0), size(0), sector(nullptr), allocator(nullptr) {}
        ~Region();
        //void Destruct();
        void Reinit(Region* r, size_t size);
        void* alloc(size_t size);
        void* realloc(void* data, size_t s_old, size_t size);
        void free(void* data, size_t size);
        void reset();

        inline size_t available_space() const {
            return (capacity - size) * sizeof(uintptr_t);
        }
        inline size_t memusage() const {
            return size * sizeof(uintptr_t);
        }
    };
    MCLAPI void* RegionAlloc(Region* reg, size_t size);
    MCLAPI void* RegionRealloc(Region* reg, void* data, size_t s_old, size_t size);
    MCLAPI void  RegionFree(Region* reg, void* data, size_t size);
}
