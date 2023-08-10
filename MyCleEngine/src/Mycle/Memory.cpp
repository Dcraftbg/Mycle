#include "Memory.h"

Mycle::Region GlobalMemory;
Mycle::Region TemporaryMemory;
MCLAPI void Mycle::Memory::InitGlobal(size_t size)
{
    GlobalMemory.Reinit(nullptr, size);
}

MCLAPI void Mycle::Memory::InitTemporary(size_t size)
{
    TemporaryMemory.Reinit(&GlobalMemory, size);
}

MCLAPI Mycle::Region* Mycle::Memory::Global()
{
    return &GlobalMemory;
}

MCLAPI Mycle::Region* Mycle::Memory::Temporary()
{
    return &TemporaryMemory;
}

//MCLAPI void Mycle::Memory::Destruct()
//{
//    TemporaryMemory.Destruct();
//    GlobalMemory.Destruct();
//}

MCLAPI void Mycle::Memory::Init(Mycle::Memory::Config& config)
{
    Mycle::Memory::InitGlobal(config.global_size);
    Mycle::Memory::InitTemporary(config.temporary_size);
}