#include "Application.h"
MCLAPI Mycle::Application::Application() {}
MCLAPI Mycle::Application::~Application() {}
MCLAPI void Mycle::Application::onUpdate(float deltaTime){}
MCLAPI void Mycle::Application::onInit(){}
MCLAPI void Mycle::Application::onWindowInit(Window* window) {}
MCLAPI void Mycle::Application::onAppDestroy() {}

Mycle::Memory::Config Mycle::Application::getMemconfig()
{
	return { 640000, 640000 / 2 };;
}
