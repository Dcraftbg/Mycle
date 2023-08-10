#include "Random.h"
uint32_t MCLAPI Mycle::Random::wang_hash(uint32_t seed) {
	 seed = (seed ^ 61) ^ (seed >> 16);
	 seed *= 9;
	 seed = seed ^ (seed >> 4);
	 seed *= 0x27d4eb2d;
	 seed = seed ^ (seed >> 15);
	 return seed;
}
uint32_t MCLAPI Mycle::Random::pcg_hash(uint32_t seed) {
	uint32_t state = seed * 747796405u + 2891336453u;
	uint32_t word = ((state >> ((state >> 28u) + 4u)) ^ state) * 277803737u;
	return (word >> 22u) ^ word;
}

float MCLAPI Mycle::Random::fwang_hash(uint32_t seed)
{
	return (float)wang_hash(seed) / (float)UINT32_MAX;
}

float MCLAPI Mycle::Random::fpcg_hash(uint32_t seed)
{
	return (float)fpcg_hash(seed) / (float)UINT32_MAX;
}
