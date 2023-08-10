#include "Renderer.h"
#define GL_FLOAT 0x1406
#define GL_TRIANGLES 0x0004
#define GL_UNSIGNED_INT 0x1405
#define GL_ARRAY_BUFFER 0x8892
#define GL_STATIC_DRAW 0x88E4
#define GL_DYNAMIC_DRAW 0x88E8
MCLAPI void Mycle::Renderer::DrawTriangle(const Vector2f& p1, const Vector2f& p2, const Vector2f& p3) const {
	//Mycle::VertexBuffer vb;
	//vb.Init();
	//vb.Bind();
	Vector2f buf[3] = { 0 };
	buf[0] = p1;
	buf[1] = p2;
	buf[2] = p3;
	//vb.SendData(&buf, sizeof(buf));
	uint32_t VertexBufferId;
	Mycle::ContextManager::genBuffers(1, &VertexBufferId);
	Mycle::ContextManager::bindBuffer(GL_ARRAY_BUFFER, VertexBufferId);
	Mycle::ContextManager::bufferData(GL_ARRAY_BUFFER, sizeof(buf), buf, GL_STATIC_DRAW);
	Mycle::ContextManager::bindBuffer(GL_ARRAY_BUFFER, VertexBufferId);
	Mycle::ContextManager::enableVertexAttribArray(0);
	Mycle::ContextManager::vertexAttribPointer(0, 2, GL_FLOAT, false, 0, (void*)0);
	Mycle::ContextManager::drawArrays(GL_TRIANGLES, 0, 3);
	Mycle::ContextManager::deleteBuffers(1, &VertexBufferId);
	
}

MCLAPI void Mycle::Renderer::DrawRect(const Vector2f& p1, const Vector2f& p2, const Vector2f& p3, const Vector2f& p4, Mycle::Region* Allocator /*=nullptr*/) const
{
	Mycle::IndexBuffer ib;
	Mycle::VertexArray va;
	Mycle::VertexBuffer vb;
	Mycle::VBLayout layout(Allocator);
	vb.Init();
	va.Init();
	ib.Init(6);
	uint32_t indices[] = {
		0, 1, 2,
		2, 3, 0
	};
	Vector2f buf[] = {
		p1,
		p2,
		p3,
		p4
	};
	ib.SendData(indices);
	layout.Push<float>(2, false);
	vb.SendData(buf, sizeof(buf));
	va.AddBuffer(vb, layout);

	va.Bind();
	ib.Bind();
	Mycle::ContextManager::drawElements(GL_TRIANGLES, ib.GetCount(), GL_UNSIGNED_INT, nullptr);
}

static uint32_t RectangleIndecies[] = {0,1,2,2,3,0};
static Mycle::IndexBuffer Ib;
MCLAPI void Mycle::Rectangle::__DestroyShape() {
	Ib.~IndexBuffer();
}
MCLAPI void Mycle::Rectangle::__InitShape() {
	Ib.Init(6);
	Ib.SendData(RectangleIndecies);
}
MCLAPI void Mycle::Rectangle::Init(bool is_static) {
	m_Va.Init();
	//m_Vb.Init(is_static ? GL_STATIC_DRAW : GL_DYNAMIC_DRAW); // TODO: Add GL_DYNAMIC_DRAW
	m_Vb.Init();
	// Maybe prep the data if provided?
}

MCLAPI void Mycle::Rectangle::Draw(const VBLayout& layout, const void* data,size_t size) const
{
	m_Va.Bind();
	m_Vb.Bind();
	Ib.Bind();
	m_Vb.SendData(data, size);
	m_Va.AddBuffer(m_Vb, layout);
	Mycle::ContextManager::drawElements(GL_TRIANGLES, Ib.GetCount(), GL_UNSIGNED_INT, nullptr);
}

MCLAPI void Mycle::Shape::Destroy()
{
	Mycle::Rectangle::__DestroyShape();
}

MCLAPI void Mycle::Shape::Init()
{
	Mycle::Rectangle::__InitShape();
}
