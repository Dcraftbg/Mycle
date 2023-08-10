#pragma once
#include "Utils.h"
#include "Region.h"
namespace Mycle {
	namespace Memory {
		struct Config {
			size_t global_size;
			size_t temporary_size;
		};
		MCLAPI void InitGlobal(size_t size);
		MCLAPI void InitTemporary(size_t size);
		MCLAPI Region* Global();
		MCLAPI Region* Temporary();
		//MCLAPI void Destruct();
		MCLAPI void Init(Mycle::Memory::Config& config);
	}
}