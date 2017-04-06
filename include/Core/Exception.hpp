#ifndef EXCEPTION_HPP
#define EXCEPTION_HPP

#include <stdexcept>
#include <string>

class Exception : std::runtime_error
{
private:
	std::string message;

public:
	explicit Exception(const std::string&);

	explicit Exception(const char *);

	virtual ~Exception();

	const char *what() const noexcept;
};

#endif // EXCEPTION_HPP
