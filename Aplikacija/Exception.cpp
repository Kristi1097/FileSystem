#include "Exception.h"
#include <string>
#include <iostream>
Exception::Exception(const char* message)
{
	strcpy_s(this->msg, message);
}
Exception::~Exception() {}
void Exception::printMsg()
{
	std::cout << msg;
}
