#include "VertexArray.h"

MCLAPI Mycle::VertexArray::VertexArray() : m_RendererID(0)
{
	/*
	GLCall(glGenVertexArrays(1, &m_RendererID));
	*/
}

MCLAPI Mycle::VertexArray::~VertexArray()
{
	ContextManager::deleteVertexArrays(1, &m_RendererID);
	/*
	GLCall(glDeleteVertexArrays(1, &m_RendererID));
	*/
}

MCLAPI void Mycle::VertexArray::Init()
{
	ContextManager::genVertexArrays(1, &m_RendererID);
}

MCLAPI void Mycle::VertexArray::AddBuffer(const VertexBuffer& vb, const VBLayout& layout) const {
	this->Bind();
	vb.Bind();
	const auto& elements = layout.GetElements();
	uint32_t offset = 0;
	for (size_t i = 0; i < elements.size(); ++i) {
		
		const auto& element = elements[i];
		ContextManager::enableVertexAttribArray(i);
		ContextManager::vertexAttribPointer(i, element.count, element.type, (int)element.normalized, layout.GetStride(), (const void*)offset);
		/*
		GLCall(glEnableVertexAttribArray(i));
		GLCall(glVertexAttribPointer(i, element.count, element.type, (int)element.normalized, layout.GetStride(), (const void*)offset));
		*/
		offset += element.count * VBElement::getSizeOfType(element.type);
	}
}

MCLAPI void Mycle::VertexArray::Bind() const {
	ContextManager::bindVertexArray(m_RendererID);
	/*
	GLCall(glBindVertexArray(m_RendererID));
	*/
}

MCLAPI void Mycle::VertexArray::Unbind() const {
	ContextManager::bindVertexArray(0);
	/*
	GLCall(glBindVertexArray(0));
	*/
}
