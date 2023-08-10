#pragma once
#include <inttypes.h>
#include "Utils.h"
#include <limits.h>
namespace Mycle {
namespace Random {
	// Generates a random uint32_t from 0 to UINT32_MAX
	uint32_t MCLAPI wang_hash(uint32_t seed);
	// Generates a random uint32_t from 0 to UINT32_MAX
	uint32_t MCLAPI pcg_hash(uint32_t seed);


	// Generates a random float from 0 to 1.0f
	float    MCLAPI fwang_hash(uint32_t seed);
	// Generates a random float from 0 to 1.0f
	float    MCLAPI fpcg_hash(uint32_t seed);
}
}