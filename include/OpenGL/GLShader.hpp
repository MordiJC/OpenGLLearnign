#ifndef GLSHADER_HPP
#define GLSHADER_HPP

#include <string>

#include <memory>

#include <GL/glew.h>

#include <Core/Exception.hpp>

/**
 * Class for OpenGL shaders.
 */
class GLShader
{
public:
	enum ShaderType {
		None,
		Fragment,
		Vertex,
		Geometry,
		Compute,
		TessellationEvaluation,
		TessellationControl,

		ShadersNumber
	};

	/**
	 * Constructs a new \class GLShader object ofthe specified type.
	 *
	 * \param type Type of shader.
	 */
	explicit GLShader(GLShader::ShaderType type);


	// All five special member functions [Rule of Zer0]

	GLShader(const GLShader &) noexcept = default;

	GLShader(GLShader &&) noexcept = default;

	GLShader & operator=(const GLShader &) noexcept = default;

	GLShader & operator=(GLShader &&) noexcept = default;

	virtual ~GLShader() = default;

	/**
	 * Get the source code of shader
	 *
	 * \return Shader source code
	 */
	std::string getSource() const throw(Exception);

	/**
	 * Compile given shader source code
	 *
	 *	\param source String containing source code of shader
	 *
	 *	\throws Exception
	 */
	void compileShader(const std::string & source) throw(Exception);

	/**
	 * Compile given shader source code
	 *
	 *	\param source String containing source code of shader
	 *
	 *	\throws Exception
	 */
	void compileShader(const char * source) throw(Exception);

	/**
	 * Get shader log.
	 *
	 * \return String with shader log
	 */
	std::string log() const;

	/**
	 * Get OpenGL-Environment shader id
	 *
	 * \return Shader id
	 */
	GLuint shaderId() const;

	/**
	 * Get shader type.
	 *
	 * \return Shader type
	 */
	GLShader::ShaderType shaderType() const;

private:
	class Impl;
	std::unique_ptr<GLShader::Impl, void (*)(GLShader::Impl *)> pImpl;
};

#endif // GLSHADER_HPP
