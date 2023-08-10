#pragma once
#include "Utils.h"
#include "Vector.h"
#include "Region.h"
#include "Memory.h"
#include "VertexBuffer.h"
#include "IndexBufffer.h"
#include "VertexArray.h"
namespace Mycle {
	class MCLAPI Rectangle {
	private:
		VertexBuffer m_Vb;
		VertexArray  m_Va;
	public:
		static void __InitShape();
		static void __DestroyShape();
		void Init(bool is_static=false);
		Rectangle() {};
		inline const VertexBuffer& getVertexBuffer() const { return m_Vb; }
		inline const VertexArray& getVertexArray()   const { return m_Va; }
		void Draw(const VBLayout& layout, const void* data, size_t size) const;
		
	};
	namespace Shape {
		MCLAPI void Destroy();
		MCLAPI void Init();
	}
	class MCLAPI Renderer {
	public:
		// TODO: Add Debug prefix
		void DrawTriangle(const Vector2f& p1, const Vector2f& p2, const Vector2f& p3) const;
		void DrawRect(const Vector2f& p1, const Vector2f& p2, const Vector2f& p3, const Vector2f& p4, Mycle::Region* Allocator=Mycle::Memory::Temporary()) const;
		inline void DrawRect(const Rectangle& rect, const VBLayout& layout, void* data, size_t size) const {rect.Draw(layout, data,size);}
	};



}