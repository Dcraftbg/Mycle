#pragma once
#include "Utils.h"
#include "ContextManager.h"
namespace Mycle {
	typedef Mycle::ContextManager::WindowContextProp WindowProps;
	class MCLAPI Window
	{
	public:
		Window();
		bool Init(WindowProps& props);
		void Bind();
		void SetTitle(const char* title);
		bool shouldClose();
		void swapBuffers();
		void clear(const Vector4f& color);
		void clear(const Vector3f& color);
		Vector2i WindowSize();
	private:
		void* m_Window;
	};
}
