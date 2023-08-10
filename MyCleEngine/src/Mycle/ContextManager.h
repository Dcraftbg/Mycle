#pragma once
#include "Utils.h"
#include <inttypes.h>
#include "Vector.h"
namespace Mycle {
	namespace ContextManager
	{
		struct MCLAPI WindowContextProp {
			int width;
			int height;
			const char* title;
			void* monitor;
			void* share;
			WindowContextProp(int width, int height, const char* title, void* monitor=nullptr, void* share=nullptr);
		};
		MCLAPI void* CreateWindow(WindowContextProp& props);
		MCLAPI void Terminate();
		MCLAPI void makeContextCurrent(void* window);
		MCLAPI void swapInterval(int i);
		MCLAPI int Init();
		MCLAPI int InitGL();
		MCLAPI bool windowShouldClose(void* window);
		MCLAPI void windowSwapBuffers(void* window);
		MCLAPI void pollEvents();
		MCLAPI void windowSetWindowTitle(void* window, const char* title);
		MCLAPI Vector2i GetDesktopSize(void* window);


		MCLAPI void drawArrays(int mode, int first, size_t count);
		MCLAPI void genBuffers(int count, uint32_t* rendererId);
		MCLAPI void bindBuffers(int type, uint32_t rendererId);
		MCLAPI void bufferData(int type, uint32_t size, const void* data, int drawType);
		MCLAPI void deleteBuffers(int count, uint32_t* rendererId);
		MCLAPI void bindBuffer(int type, uint32_t rendererId);
		MCLAPI void genVertexArrays(size_t n, uint32_t* rendererId);
		MCLAPI void deleteVertexArrays(size_t n, uint32_t* rendererId);
		MCLAPI void enableVertexAttribArray(size_t i);
		MCLAPI void vertexAttribPointer(int index, int size, int type, uint8_t normalized, size_t stride, const void* pointer);
		MCLAPI void bindVertexArray(uint32_t rendererId);
		MCLAPI void drawElements(int mode, size_t count, int type, const void* indices);
		MCLAPI void clearColor(const Vector4f& color);
		MCLAPI void updateViewPort(int x, int y, int width, int height);
		MCLAPI const unsigned char* __glewGetErrorString(int res);

	};
}

