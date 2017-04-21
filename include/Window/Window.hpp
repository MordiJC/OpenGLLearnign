#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <string>

#include <GLFW/glfw3.h>

#include <Window/WindowException.hpp>
#include <spimpl.h>

#include <SFML/Window.hpp>

/**
 * \class Window
 *
 * \brief Basic class used to manage window.
 */
class Window
{
private:
	class Impl;
	spimpl::impl_ptr<Window::Impl> impl_;
public:
	enum Style {
		None = 0u,

		Windowed = 1u << 0,
		Resizable = 1u << 1,
		Maximized = 1u << 2,

		Fullscreen = 1u << 3,

		Default = Windowed | Resizable,
	};

	/**
	 * \brief Construct window object.
	 */
	Window() throw(WindowException);

	//explicit Window() throw(WindowException);

	Window(const Window &) noexcept = default;

	Window(Window &&) noexcept = default;

	auto operator=(const Window &) noexcept -> Window & = default;

	auto operator=(Window &&) noexcept -> Window & = default;

	virtual ~Window();
};

#endif // WINDOW_HPP
