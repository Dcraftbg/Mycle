#pragma once
#include "Utils.h"
#include "ContextManager.h"
#include <inttypes.h>

#define GL_STATIC_DRAW 0x88E4

namespace Mycle {
	class MCLAPI VertexBuffer
	{
	public:
		VertexBuffer();
		~VertexBuffer();
		void Init();
		void SendData(const void* data, uint32_t size, int usage=GL_STATIC_DRAW) const;
		void Bind() const;
		void Unbind() const;
	private:
		uint32_t m_RendererID;
	};
}

#undef GL_STATIC_DRAW