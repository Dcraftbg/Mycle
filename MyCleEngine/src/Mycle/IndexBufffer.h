#pragma once
#include "Utils.h"
#include "ContextManager.h"
#include <inttypes.h>
#define GL_STATIC_DRAW 0x88E4
namespace Mycle {
	class MCLAPI IndexBuffer
	{
	private:
		uint32_t m_RendererID;
		size_t m_Count;
	public:
		IndexBuffer();
		~IndexBuffer();
		
		void Init(size_t count);
		void Bind() const;
		void Unbind() const;
		void SendData(const uint32_t* data, int usage = GL_STATIC_DRAW);
		inline size_t GetCount() const {
			return m_Count;
		}
	};


}
#undef GL_STATIC_DRAW