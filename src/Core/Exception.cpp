#include "Core/Exception.hpp"

Exception::Exception(const std::string & arg)
	: std::runtime_error(arg), message(arg)
{}

Exception::Exception(const char * arg)
	: std::runtime_error(arg), message(arg)
{}

Exception::~Exception()
{}

auto Exception::what() const noexcept -> const char *
{
	return this->message.c_str();
}
