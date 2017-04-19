#ifndef URL_HPP
#define URL_HPP

#include <string>

#include <Core/Exception.hpp>
#include <spimpl.h>

/**
 * \class Url
 *
 * \brief Url class used for accessing data using e.g. HTTP, local files and virtual file systems
 */
class Url
{
private:
	class Impl;
	spimpl::impl_ptr<Url::Impl> impl_;
public:
	/**
	 * \brief Constructs a new \link Url object from given url string.
	 *
	 * \param url Url string.
	 *
	 * Examples:
	 *  file://data/users.db - access local file (relative path)
	 *  log/console.log - relative path to current working directory
	 *  ../images/icon.png - relative path to current working directory
	 *  http://example.com:8080/files/img.png - access file on http server using 8080 port
	 *  vfs://textures/terrain/grass.tex - access file from Virtual File System names "textures".
	 *										VFS should be registered earlier using @link Url::registerFilesystem(vfs)
	 */
	explicit Url(std::string & url) noexcept;

	Url(const Url &) noexcept = default;

	Url(Url &&) noexcept = default;

	Url & operator=(const Url &) noexcept = default;

	Url & operator=(Url &&) noexcept = default;

	virtual ~Url();

	bool isValid() noexcept;

	int port() const throw(Exception);

	std::string host() const throw(Exception);

	std::string user() const throw(Exception);

	std::string password() const throw(Exception);

	std::string userInfo() const throw(Exception);

	std::string scheme() const throw(Exception);
};

#endif // URL_HPP
