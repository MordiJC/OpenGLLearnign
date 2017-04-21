#include "include/Window/VideoMode.hpp"

#include <Window/impl/VideoMode_Impl.hpp>

VideoMode::VideoMode(unsigned int width, unsigned int height, unsigned int bitsPerPixel) throw(WindowException)
	: impl_(spimpl::make_unique_impl<VideoMode::Impl>(width, height, bitsPerPixel))
{}

VideoMode::VideoMode(unsigned int width, unsigned int height,
					 unsigned int red, unsigned int green, unsigned int blue, unsigned int alpha) throw(WindowException)
	: impl_(spimpl::make_unique_impl<VideoMode::Impl>(width, height, red, green, blue, alpha))
{}

VideoMode::~VideoMode()
{}

auto VideoMode::width() -> unsigned int
{
	return impl_->width();
}

auto VideoMode::height() -> unsigned int
{
	return impl_->height();
}

auto VideoMode::bitsPerPixel() -> unsigned int
{
	return impl_->bitsPerPixel();
}

auto VideoMode::redBits() -> unsigned int
{
	return impl_->redBits();
}

auto VideoMode::greenBits() -> unsigned int
{
	return impl_->greenBits();
}

auto VideoMode::blueBits() -> unsigned int
{
	return impl_->blueBits();
}

auto VideoMode::alphaBits() -> unsigned int
{
	return impl_->alphaBits();
}

auto VideoMode::getDesktopMode() -> VideoMode
{
	return Impl::getDesktopMode();
}

auto VideoMode::getFullscreenModes() -> std::vector<VideoMode> &
{
	return Impl::getFullscreenModes();
}
