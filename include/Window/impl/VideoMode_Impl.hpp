#ifndef VIDEOMODE_IMPL_HPP
#define VIDEOMODE_IMPL_HPP

#include <vector>

#include <Window/WindowException.hpp>
#include <Window/VideoMode.hpp>

class VideoMode::Impl
{
public:
	unsigned int width_;
	unsigned int height_;
	unsigned int redBits_;
	unsigned int greenBits_;
	unsigned int blueBits_;
	unsigned int alphaBits_;

	Impl(unsigned int width, unsigned int height, unsigned int bitsPerPixel) throw(WindowException);

	Impl(unsigned int width, unsigned int height,
		 unsigned int redBits, unsigned int greenBits, unsigned int blueBits, unsigned int alphaBits) throw(WindowException);

	~Impl();

	auto width() -> unsigned int;

	auto height() -> unsigned int;

	auto bitsPerPixel() -> unsigned int;

	auto redBits() -> unsigned int;

	auto greenBits() -> unsigned int;

	auto blueBits() -> unsigned int;

	auto alphaBits() -> unsigned int;

	static auto getDesktopMode() -> VideoMode;

	static auto getFullscreenModes() -> std::vector<VideoMode> &;
};

#endif // VIDEOMODE_IMPL_HPP
