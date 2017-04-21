#ifndef GLSHADER_HPP
#define GLSHADER_HPP

#include <string>

#include <GL/glew.h>

#include <OpenGL/GLException.hpp>
#include <spimpl.h>

/**
 * \class GLShader
 *
 * \brief Class for OpenGL shaders.
 */
class GLShader
{
private:
	class Impl;
	spimpl::impl_ptr<GLShader::Impl> impl_;

public:
	/**
	 * \brief Shader types
	 */
	enum ShaderType {
		Fragment,               ///< OpenGL fragment shader (GL_FRAGMENT_SHADER)
		Vertex,                 ///< OpenGL vertex shader (GL_VERTEX_SHADER)
		Geometry,               ///< OpenGL geometry shader (GL_GEOMETRY_SHADER)
		Compute,                ///< OpenGL compute shader (GL_COMPUTE_SHADER)
		TessellationEvaluation, ///< OpenGL tessellation evaluation shader (GL_TESS_EVALUATION_SHADER)
		TessellationControl,    ///< OpenGL tessellation control shader (GL_TESS_CONTROL_SHADER)

		ShadersNumber
	};

	/**
	 * \brief Constructs a new \link GLShader object of the specified type.
	 *
	 * \param type Type of shader.
	 */
	explicit GLShader(GLShader::ShaderType type) throw(GLException);


	// All five special member functions [Rule of Zer0]

	GLShader(const GLShader &) noexcept = default;

	GLShader(GLShader &&) noexcept = default;

	auto operator=(const GLShader &) noexcept -> GLShader & = default;

	auto operator=(GLShader &&) noexcept -> GLShader & = default;

	virtual ~GLShader();

	/**
	 * \brief Get the source code of shader
	 *
	 * \return Shader source code
	 */
	auto getSource() const throw(GLException) -> std::string;

	/**
	 * \brief Compile given shader source code
	 *
	 * \param source String containing source code of shader
	 *
	 * \throws Exception
	 */
	auto compileShader(const std::string & source) throw(GLException) -> void;

	/**
	 * \brief Compile given shader source code
	 *
	 * \param source String containing source code of shader
	 *
	 * \throws Exception
	 */
	auto compileShader(const char * source) throw(GLException) -> void;

	/**
	 * \brief Get shader log.
	 *
	 * \return String with shader log
	 */
	auto log() const -> std::string;

	/**
	 * \brief Get OpenGL-Environment shader id
	 *
	 * \return Shader id
	 */
	auto shaderId() const -> GLuint;

	/**
	 * \brief Get shader type.
	 *
	 * \return Shader type
	 */
	auto shaderType() const -> GLShader::ShaderType;
};

#endif // GLSHADER_HPP
