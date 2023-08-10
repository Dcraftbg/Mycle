#include "VertexBuffer.h"
#define GL_ARRAY_BUFFER 0x8892
MCLAPI Mycle::VertexBuffer::VertexBuffer() : m_RendererID(0)
{
	/*
	* glGenBuffers(1, &m_RendererID)
	* glBindBuffer(GL_ARRAY_BUFFER, m_RendererID)
	* glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW)
	*/
}
MCLAPI void Mycle::VertexBuffer::Init() {
	Mycle::ContextManager::genBuffers(1, &m_RendererID);
	Mycle::ContextManager::bindBuffer(GL_ARRAY_BUFFER, m_RendererID);
}
MCLAPI void Mycle::VertexBuffer::SendData(const void* data, uint32_t size, int usage) const {
	Mycle::ContextManager::bufferData(GL_ARRAY_BUFFER, size, data, usage);

}
MCLAPI Mycle::VertexBuffer::~VertexBuffer()
{
	/*
	* glDeleteBuffers(1, &m_RendererID)
	*/
	Mycle::ContextManager::deleteBuffers(1, &m_RendererID);
}


MCLAPI void Mycle::VertexBuffer::Bind() const
{
	/*
	* glBindBuffer(GL_ARRAY_BUFFER, m_RendererID)
	*/
	Mycle::ContextManager::bindBuffer(GL_ARRAY_BUFFER, m_RendererID);
}

MCLAPI void Mycle::VertexBuffer::Unbind() const
{
	/*
	* glBindBuffer(GL_ARRAY_BUFFER, 0)
	*/
	Mycle::ContextManager::bindBuffer(GL_ARRAY_BUFFER, 0);
}
