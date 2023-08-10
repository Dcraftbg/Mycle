#pragma once
#include "Utils.h"
#include "ContextManager.h"
#include "ExceptionManager.h"
#include "Window.h"
#include "Memory.h"
namespace Mycle{
	class MCLAPI Application
	{
	public:
		Application();
		~Application();
		// Called after (the context) rendering library and window library are initialized! But BEFORE onWindowInit is called!
		virtual void onInit();
		// Called once the window is initialized!
		virtual void onWindowInit(Window* window);
		// Required to get the properties of the window. I.e. Window width, height, etc.
		virtual ContextManager::WindowContextProp* getProps() = 0;
		// Called once per frame!
		virtual void onUpdate(float deltaTime);
		virtual void onAppDestroy();
		virtual Mycle::Memory::Config getMemconfig();
		//virtual Mycle::ExceptionManager::ExceptionHandler getExceptionHandler() = 0;
	};
	Application* CreateApplication();
}
