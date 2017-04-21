#ifndef EXCEPTION_HPP
#define EXCEPTION_HPP

#include <stdexcept>
#include <string>

class Exception : public virtual std::runtime_error
{
private:
	std::string message;

public:
	explicit Exception(const std::string&);

	explicit Exception(const char *);

	virtual ~Exception();

	auto what() const noexcept -> const char *;
};

#endif // EXCEPTION_HPP
