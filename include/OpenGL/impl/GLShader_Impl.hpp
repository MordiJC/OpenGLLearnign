#ifndef GLSHADER_IMPL_HPP
#define GLSHADER_IMPL_HPP

#include <GL/glew.h>

#include <OpenGL/GLException.hpp>
#include <OpenGL/GLShader.hpp>

class GLShader::Impl {
public:
	GLShader::ShaderType shaderType_;
	GLuint shaderId_;

	explicit Impl(GLShader::ShaderType type) throw(GLException);

	~Impl();

	auto getSource() const throw(GLException) -> std::string;

	auto compileShader(const std::string & source) throw(GLException) -> void;

	auto compileShader(const char * source) throw(GLException) -> void;

	auto log() const -> std::string;

	auto shaderId() const -> GLuint;

	auto shaderType() const -> GLShader::ShaderType;

};

#endif // GLSHADER_IMPL_HPP
