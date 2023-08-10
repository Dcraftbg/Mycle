#include "ContextManager.h"
#include "ExceptionManager.h"
#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <stdio.h>


#define SAFE_CALL(x) \
	GLClearError(); \
	x; \
	while (uint32_t error = glGetError()) { \
		printf("Error: %u",error);\
		/*Mycle::throwException(Mycle::Exception(Mycle::ExceptionType::GL_EXCEPTION,error,nullptr));*/ \
		\
	} 
	

inline void GLClearError() { while (glGetError() != GL_NO_ERROR); }
inline void GLHandleError() {

}
void __GLFW_ERROR_CALLBACK(int op, const char* msg) {
	//Mycle::throwException(Mycle::Exception(Mycle::ExceptionType::CONTEXT_MANAGER_EXCEPTION, op, msg, EXCEP_STATE(FATAL)));
}
MCLAPI Mycle::ContextManager::WindowContextProp::WindowContextProp(int width, int height, const char* title, void* monitor, void* share) : width(width), height(height), title(title), monitor(monitor), share(share) {}
MCLAPI void* Mycle::ContextManager::CreateWindow(WindowContextProp& props)
{
	//printf("Window.width: %d, Window.height: %d, Window.title: %s, Window.monitor: %lld, Window.share: %lld", props.width, props.height, props.title, props.monitor, props.share);
	
	auto result = glfwCreateWindow(props.width, props.height, props.title, (GLFWmonitor*)props.monitor, (GLFWwindow*)props.share);
	return result;
}

MCLAPI void Mycle::ContextManager::Terminate()
{
	glfwTerminate();
}

MCLAPI void Mycle::ContextManager::makeContextCurrent(void* window)
{
	//printf("Called makeContextCurrent %lld!\n",window);
	glfwMakeContextCurrent((GLFWwindow*)window);
}

MCLAPI void Mycle::ContextManager::swapInterval(int i)
{
	glfwSwapInterval(i);
}

MCLAPI int Mycle::ContextManager::Init()
{
	glfwSetErrorCallback(__GLFW_ERROR_CALLBACK);
	return glfwInit();
}

MCLAPI int Mycle::ContextManager::InitGL()
{
	return glewInit();
}

MCLAPI bool Mycle::ContextManager::windowShouldClose(void* window)
{
	return glfwWindowShouldClose((GLFWwindow*)window);
}

MCLAPI void Mycle::ContextManager::windowSwapBuffers(void* window)
{
	glfwSwapBuffers((GLFWwindow*)window);
}

MCLAPI void Mycle::ContextManager::pollEvents()
{
	glfwPollEvents();
}

MCLAPI void Mycle::ContextManager::windowSetWindowTitle(void* window, const char* title)
{
	glfwSetWindowTitle((GLFWwindow*)window, title);
}
MCLAPI Mycle::Vector2i Mycle::ContextManager::GetDesktopSize(void* window) {
	Mycle::Vector2i res = { 0 };
	glfwGetWindowSize((GLFWwindow*)window,&res.width,&res.height);
	return res;
}
MCLAPI const unsigned char* Mycle::ContextManager::__glewGetErrorString(int res)
{
	return glewGetErrorString(res);
}

MCLAPI void Mycle::ContextManager::drawArrays(int mode, int first, size_t count)
{
	SAFE_CALL(glDrawArrays(mode, first, count));
}

MCLAPI void Mycle::ContextManager::genBuffers(int count, uint32_t* rendererId)
{
	SAFE_CALL(glGenBuffers(count, rendererId));
}

MCLAPI void Mycle::ContextManager::bindBuffers(int type, uint32_t rendererId)
{
	SAFE_CALL(glBindBuffer(type, rendererId));
}

MCLAPI void Mycle::ContextManager::bufferData(int type, uint32_t size, const void* data, int drawType)
{
	SAFE_CALL(glBufferData(type, size, data, drawType));
}

MCLAPI void Mycle::ContextManager::deleteBuffers(int count, uint32_t* rendererId)
{
	SAFE_CALL(glDeleteBuffers(count, rendererId));
}

MCLAPI void Mycle::ContextManager::bindBuffer(int type, uint32_t rendererId)
{
	SAFE_CALL(glBindBuffer(type, rendererId));
}

MCLAPI void Mycle::ContextManager::genVertexArrays(size_t n, uint32_t* rendererId)
{
	SAFE_CALL(glGenVertexArrays(n, rendererId));
}

MCLAPI void Mycle::ContextManager::deleteVertexArrays(size_t n, uint32_t* rendererId)
{
	SAFE_CALL(glDeleteVertexArrays(n, rendererId));
}

MCLAPI void Mycle::ContextManager::enableVertexAttribArray(size_t i)
{
	SAFE_CALL(glEnableVertexAttribArray(i));
}

MCLAPI void Mycle::ContextManager::vertexAttribPointer(int index, int size, int type, uint8_t normalized, size_t stride, const void* pointer)
{
	SAFE_CALL(glVertexAttribPointer(index, size, type, normalized, stride, pointer));
}

MCLAPI void Mycle::ContextManager::bindVertexArray(uint32_t rendererId)
{
	SAFE_CALL(glBindVertexArray(rendererId));
}

MCLAPI void Mycle::ContextManager::clearColor(const Vector4f& color)
{
	//printf("clearing with color: r: %f, g: %f, b: %f, a: %f\n", r, g, b, a);

	SAFE_CALL(glClearColor(color.r,color.g,color.b,color.a));
	SAFE_CALL(glClear(GL_COLOR_BUFFER_BIT));
}
MCLAPI void Mycle::ContextManager::drawElements(int mode, size_t count, int type, const void* indices) {
	SAFE_CALL(glDrawElements(mode, count, type, indices));
}
