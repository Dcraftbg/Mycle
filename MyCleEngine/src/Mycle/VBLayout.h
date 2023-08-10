#pragma once
#include "Utils.h"
#include "Array.h"
#include "Memory.h"
#define GL_FLOAT 0x1406
#define GL_UNSIGNED_INT 0x1405
namespace Mycle {
	struct VBElement {
		uint32_t type;
		uint32_t count;
		bool     normalized;
		static uint32_t getSizeOfType(uint32_t type) {
			switch (type) {
			case GL_FLOAT: return 4;
			case GL_UNSIGNED_INT: return 4;
			default:
				fprintf(stderr, "ERROR: Unhandled case!\n");
				exit(1);
			}
		}
	};
	class VBLayout
	{
	private:
		Mycle::Array<VBElement> m_Elements;
		uint32_t m_Stride;
	public:
		VBLayout(Mycle::Region* Allocator=Mycle::Memory::Global()) : m_Stride(0), m_Elements(Allocator) {}
		template<typename T>
		void Push(uint32_t count, bool normalized) {
			//static_assert(false);
			fprintf(stderr, "to be done");
			exit(1);
		};
		template<>
		void Push<float>(uint32_t count, bool normalized) {
			m_Elements.push({ GL_FLOAT,count,normalized });
			m_Stride += 4 * count;
		}
		template<>
		void Push<uint32_t>(uint32_t count, bool normalized) {
			m_Elements.push({ GL_UNSIGNED_INT,count,normalized });
			m_Stride += 4 * count;
		}
		inline const Mycle::Array<VBElement>& GetElements() const {
			return m_Elements;
		}
		inline uint32_t GetStride() const {
			return m_Stride;
		}
	};
}

