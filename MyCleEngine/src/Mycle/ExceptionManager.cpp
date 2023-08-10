#include "ExceptionManager.h"
/*
void Mycle::ExceptionManager::Handle(int count) {
	if (count == -1) {
		count = m_ExceptionStackCount;
	}
	size_t handled = 0;
	for (size_t i = 0; i < count; i++) {
		m_Handler(m_ExceptionStack[i]);
		if (m_ExceptionStack[i].state & (int)ExceptionState::HANDLED) {
			handled++;
			continue;
		}
		else {
			break;
		}
		
	}
	m_ExceptionStackCount = count - handled;
}

Mycle::Exception Mycle::ExceptionManager::Exception(Mycle::Exception exception) {
	if (m_ExceptionStackCount >= m_ExceptionStackCapacity)
		return Mycle::Exception(ExceptionType::OVERFLOW_EXCEPTION, 0, "Exception stack overflow", EXCEP_STATE(FATAL));
	m_ExceptionStack[m_ExceptionStackCount] = exception;
	m_ExceptionStackCount++;
	return Mycle::Exception();
}


Mycle::ExceptionManager GlobalExceptionManager;

MCLAPI Mycle::Exception Mycle::throwException(Mycle::Exception exception) {
	return GlobalExceptionManager.Exception(exception);
}
MCLAPI Mycle::ExceptionManager* Mycle::getGlobalExceptionManager() {
	return &GlobalExceptionManager;
}
*/