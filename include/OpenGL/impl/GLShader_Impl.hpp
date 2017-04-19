#ifndef GLSHADER_IMPL_HPP
#define GLSHADER_IMPL_HPP

#include <GL/glew.h>

#include <OpenGL/GLException.hpp>
#include <OpenGL/GLShader.hpp>

class GLShader::Impl {
public:
	GLShader::ShaderType shaderType_;
	GLuint shaderId_;

	explicit Impl(GLShader::ShaderType type);

	~Impl();

	std::string getSource() const throw(GLException);

	void compileShader(const std::string & source) throw(GLException);

	void compileShader(const char * source) throw(GLException);

	std::string log() const;

	GLuint shaderId() const;

	GLShader::ShaderType shaderType() const;

};

#endif // GLSHADER_IMPL_HPP
