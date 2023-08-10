#pragma once
#include "Utils.h"
#include "VertexBuffer.h"
#include "VBLayout.h"
#include "ContextManager.h"
#include <inttypes.h>
namespace Mycle {
	class MCLAPI VertexArray
	{
	public:
		VertexArray();
		~VertexArray();
		void Init();
		void AddBuffer(const VertexBuffer& vb, const VBLayout& layout) const;
		void Bind() const;
		void Unbind() const;
	private:
		uint32_t m_RendererID;
	};
}
