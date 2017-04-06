#include "Core/Exception.hpp"

Exception::Exception(const std::string & arg)
	: std::runtime_error(arg), message(arg)
{}

Exception::Exception(const char * arg)
	: std::runtime_error(arg), message(arg)
{}

Exception::~Exception()
{}

const char *Exception::what() const noexcept
{
	return this->message.c_str();
}
