#pragma once
#include "Application.h"
#include "Window.h"
#include "ExceptionManager.h"

// Temporary I hope
#include <stdio.h>
#include <stdlib.h>
#include <chrono>

#ifdef MCL_PLATFORM_WINDOWS
extern Mycle::Application* Mycle::CreateApplication();

int main() {
	
	auto app = Mycle::CreateApplication();
	auto memconfig = app->getMemconfig();
	Mycle::Memory::Init(memconfig);
	/*
	auto exceptionManager = Mycle::getGlobalExceptionManager();
	exceptionManager->Init(app->getExceptionHandler());
	*/

	Mycle::Window window;

	MCL_MASSERT(Mycle::ContextManager::Init(), stderr, "ERROR: Could not init glfw!");
	//if (!Mycle::ContextManager::Init()) {
	//	Mycle::throwException(Mycle::Exception(Mycle::ExceptionType::CONTEXT_MANAGER_EXCEPTION,0,"Could not initalize ContextManager context", EXCEP_STATE(FATAL)));
	//}
	auto props = app->getProps();
	MCL_MASSERT(!window.Init(*props), stderr, "ERROR: Could not init window!");
	window.Bind();
	{
		int i = Mycle::ContextManager::InitGL();
		MCL_MASSERT(i == 0, stderr, "ERROR: Could not init opengl! %s",Mycle::ContextManager::__glewGetErrorString(i));
	}
	Mycle::Shape::Init();
	app->onInit();
	app->onWindowInit(&window);
	std::chrono::steady_clock::time_point currentTime = std::chrono::steady_clock::now();
	std::chrono::steady_clock::time_point previousTime = currentTime;
	float deltaTime = 0;
	
	while(!window.shouldClose()) {
		currentTime = std::chrono::steady_clock::now();
		deltaTime = std::chrono::duration_cast<std::chrono::duration<float>>(currentTime-previousTime).count();
		previousTime = currentTime;
		app->onUpdate(deltaTime);
		window.swapBuffers();
		Mycle::ContextManager::pollEvents();
		Mycle::Memory::Temporary()->reset();
	//	exceptionManager->Handle();
	}
	Mycle::Shape::Destroy();
	app->onAppDestroy();
	delete app;
	delete props;
//	Mycle::Memory::Destruct();
	
	Mycle::ContextManager::Terminate();
	return 0;
}
#endif