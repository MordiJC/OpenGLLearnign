#ifndef VIDEOMODE_HPP
#define VIDEOMODE_HPP

#include <vector>

#include <Window/WindowException.hpp>
#include <spimpl.h>

class VideoMode
{
private:
	class Impl;
	spimpl::unique_impl_ptr<VideoMode::Impl> impl_;
public:
	VideoMode(unsigned int width, unsigned int height, unsigned int bitsPerPixel = 32) throw(WindowException);

	VideoMode(unsigned int width, unsigned int height,
			  unsigned int red, unsigned int green, unsigned int blue, unsigned int alpha) throw(WindowException);

	VideoMode(const VideoMode &) noexcept = default;

	VideoMode(VideoMode &&) noexcept = default;

	auto operator=(const VideoMode &) noexcept -> VideoMode & = default;

	auto operator=(VideoMode &&) noexcept -> VideoMode & = default;

	virtual ~VideoMode();

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

#endif // VIDEOMODE_HPP
