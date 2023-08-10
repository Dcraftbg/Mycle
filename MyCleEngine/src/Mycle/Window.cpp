#include "Window.h"
MCLAPI Mycle::Window::Window() : m_Window(nullptr) {}
bool MCLAPI Mycle::Window::Init(ContextManager::WindowContextProp& props) {
	m_Window = ContextManager::CreateWindow(props);
	return !m_Window;
}
bool MCLAPI Mycle::Window::shouldClose() {
	return ContextManager::windowShouldClose(m_Window);
}

void Mycle::Window::swapBuffers()
{
	ContextManager::windowSwapBuffers(m_Window);
}
void Mycle::Window::Bind()
{
	ContextManager::makeContextCurrent(m_Window);
}

MCLAPI void Mycle::Window::SetTitle(const char* title)
{
	Mycle::ContextManager::windowSetWindowTitle(m_Window, title);
}
MCLAPI void Mycle::Window::clear(const Vector4f& color) {
	Mycle::ContextManager::clearColor(color);
}
MCLAPI void Mycle::Window::clear(const Vector3f& color) {
	Mycle::ContextManager::clearColor(Vector4f(color,1.0f));
}
MCLAPI Mycle::Vector2i Mycle::Window::WindowSize() {
	return Mycle::ContextManager::GetDesktopSize(m_Window);
}