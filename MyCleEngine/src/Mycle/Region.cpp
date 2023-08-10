#include "Region.h"

MCLAPI Mycle::Region::Region(Region* r, size_t size) : allocator(r) {
    this->capacity = ((size + sizeof(uintptr_t) - 1) / sizeof(uintptr_t));
    size_t s_bytes = capacity * sizeof(uintptr_t);
    this->sector = (uintptr_t*)RegionAlloc(r, s_bytes);
    this->size = 0;
    if (this->sector == nullptr) {
        fprintf(stderr, "ERROR: Could not allocate region!");
        exit(1);
    }
}
MCLAPI Mycle::Region::~Region() {
    Mycle::RegionFree(allocator, this->sector, this->capacity * sizeof(uintptr_t));
    this->capacity = 0;
    this->size = 0;
}
//MCLAPI void Mycle::Region::Destruct() {
//    Mycle::RegionFree(allocator, this->sector, this->capacity * sizeof(uintptr_t));
//    this->capacity = 0;
//    this->size = 0;
//}
MCLAPI void Mycle::Region::reset()
{
    this->size = 0;
}

MCLAPI void Mycle::Region::Reinit(Region* r, size_t size) {
    this->capacity = ((size + sizeof(uintptr_t) - 1) / sizeof(uintptr_t));
    size_t s_bytes = capacity * sizeof(uintptr_t);
    this->sector = (uintptr_t*)RegionAlloc(r, s_bytes);
    this->size = 0;
    this->allocator = r;
    if (this->sector == nullptr) {
        fprintf(stderr, "ERROR: Could not allocate region!");
        exit(1);
    }
}

MCLAPI void* Mycle::Region::alloc(size_t size)
{
    if (sector == nullptr) {
        fprintf(stderr, "ERROR: Could not allocate within null region!");
        exit(1);
    }
    void* result = (void*)((uintptr_t)sector + (this->size * sizeof(uintptr_t)));
    this->size += (size + sizeof(uintptr_t) - 1) / sizeof(uintptr_t);
    if (this->size >= capacity) {
        fprintf(stderr, "Error: RAN OUT OF MEMORY TO ALLOCATE WITHIN!");
        exit(1);
    }
    return result;
}

MCLAPI void* Mycle::Region::realloc(void* data, size_t o_size, size_t n_size)
{
    if (n_size < o_size) {
        fprintf(stderr, "Error: REALLOCATION ERROR. Cannot realloc with size less than the pevious size!\n");
        fprintf(stderr, "New size: %zu\nOld size: %zu\n", n_size, o_size);
        exit(1);
    }
    if (((intptr_t)data - (intptr_t)sector + (o_size + sizeof(uintptr_t) - 1)) / sizeof(uintptr_t) == size) { //((((intptr_t)data+o_size - (intptr_t)sector + o_size) + sizeof(uintptr_t) - 1) / sizeof(uintptr_t) == size)
        size += (n_size - o_size + sizeof(uintptr_t) - 1) / sizeof(uintptr_t);
        if (this->size >= capacity) {
            fprintf(stderr, "Error: RAN OUT OF MEMORY TO REALLOCATE WITHIN!");
            exit(1);
        }
        return data;
    }
    else {
        void* res = this->alloc(n_size);

        if (res == nullptr) {
            fprintf(stderr, "ERROR: Could not reallocate region!");
            exit(1);
        }
        memcpy_s(res, n_size, data, o_size);
        return res;
    }
}

MCLAPI void Mycle::Region::free(void* data, size_t d_size)
{
    if (((intptr_t)data - (intptr_t)sector + (d_size + sizeof(uintptr_t) - 1)) / sizeof(uintptr_t) == size) { size -= d_size; }
}


MCLAPI void* Mycle::RegionAlloc(Region* reg, size_t size)
{
    if (reg == nullptr) {
        return malloc(size);
    }
    else {
        return reg->alloc(size);
    }
}

MCLAPI void* Mycle::RegionRealloc(Region* reg, void* data, size_t s_old, size_t size)
{
    if (reg == nullptr) {
        return realloc(data, size);
    }
    else {
        return reg->realloc(data, s_old, size);
    }
}

MCLAPI void Mycle::RegionFree(Region* reg, void* data, size_t size)
{
    if (reg == nullptr) {
        free(data);
    }
    else {
        reg->free(data, size);
    }
}
