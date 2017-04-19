#ifndef URL_IMPL_HPP
#define URL_IMPL_HPP

#include <string>

#include <network/uri.hpp>
#include <Core/Exception.hpp>

class Url::Impl
{
public:
	network::uri url_;


	template<typename Source>
	explicit Impl(Source & source) throw(Exception);

	bool hasScheme() const;
};

#endif // URL_IMPL_HPP
