#include "IndexBufffer.h"
#define GL_ELEMENT_ARRAY_BUFFER 0x8893
MCLAPI Mycle::IndexBuffer::IndexBuffer()
{
	m_Count = 0;
	m_RendererID = 0;
}

MCLAPI Mycle::IndexBuffer::~IndexBuffer()
{

	if(m_RendererID) ContextManager::deleteBuffers(1, &m_RendererID);
	m_RendererID = 0;
	m_Count = 0;
}

MCLAPI void Mycle::IndexBuffer::Init(size_t count)
{
	m_Count = count;
	Mycle::ContextManager::genBuffers(1, &m_RendererID);
	Mycle::ContextManager::bindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_RendererID);
}

MCLAPI void Mycle::IndexBuffer::Bind() const
{
	Mycle::ContextManager::bindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_RendererID);
}

MCLAPI void Mycle::IndexBuffer::Unbind() const
{
	Mycle::ContextManager::bindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

MCLAPI void Mycle::IndexBuffer::SendData(const uint32_t* data, int usage)
{
	Mycle::ContextManager::bufferData(GL_ELEMENT_ARRAY_BUFFER, m_Count * sizeof(uint32_t), data, usage);
}
