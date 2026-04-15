#pragma once
#include <exception>
#include <string>

class JukeyException : public std::exception
{
public:
	explicit JukeyException(const char* message) : std::exception(message) {}
	char const* what() const override;
};

