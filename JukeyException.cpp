#include "JukeyException.h"
#include <iostream>

char const* JukeyException::what() const
{
	std::cout << "This is a custom exception message from JukeyException: error: ";
	return std::exception::what();
}
