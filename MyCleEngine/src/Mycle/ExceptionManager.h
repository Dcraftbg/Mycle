#pragma once
// TODO: Add Array into the action!


#include <inttypes.h>
#include "Utils.h"
// Should we, or should we not have this system in place.
// Its fun and all, its really quite enjoyable, but it is going to take some CPU time - for now not that much, but if we have a lot of exceptions being triggered or anything like that
// Stuff could get messy, and could take some time tor process everything. Which is sad :(
/*
#define EXCEPTION_STACK_CAPACITY 20
#define EXCEP_STATE(x) ((int)(Mycle::ExceptionState::##x))
namespace Mycle {
	enum class ExceptionType {
		NONE,
		GL_EXCEPTION,
		CONTEXT_MANAGER_EXCEPTION,
		OVERFLOW_EXCEPTION,

	};
	enum class ExceptionState {
		HANDLED = BIT(0),
		FATAL = BIT(1),
	};
	class Exception {
	public:
		ExceptionType exceptionType;
		int32_t operand;
		const char* description;
		int state;
		
		Exception(ExceptionType exceptionType = ExceptionType::NONE , int32_t operand = 0, const char* description = nullptr, int state = (int)ExceptionState::HANDLED) : exceptionType(exceptionType), operand(operand), description(description), state(state) {}
	};
	class MCLAPI ExceptionManager
	{
	public:
		typedef void (*ExceptionHandler)(Exception& exception);
	private:
		Exception* m_ExceptionStack;
		size_t m_ExceptionStackCapacity;
		size_t m_ExceptionStackCount;
		ExceptionHandler m_Handler;

	public:
		void Init(ExceptionHandler handler) {m_Handler = handler;}
		ExceptionManager() : m_ExceptionStackCapacity(EXCEPTION_STACK_CAPACITY), m_ExceptionStackCount(0), m_Handler(nullptr) { m_ExceptionStack = new Mycle::Exception[EXCEPTION_STACK_CAPACITY]; }
		ExceptionManager(ExceptionManager& other) = delete;
		ExceptionManager(const ExceptionManager& other) = delete;
		// Call to the ExceptionHandler with the exception
		void Handle(int count=-1);
		// Add exception
		Exception Exception(Exception exception);
		~ExceptionManager() { delete[] m_ExceptionStack; }
	};

	MCLAPI Mycle::Exception throwException(Mycle::Exception exception);
	MCLAPI Mycle::ExceptionManager* getGlobalExceptionManager();
}
*/