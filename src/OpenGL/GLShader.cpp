#include "OpenGL/GLShader.hpp"

#include "OpenGL/impl/GLShader_Impl.hpp"

GLShader::GLShader(GLShader::ShaderType type)
	: impl_(spimpl::make_impl<GLShader::Impl>(type))
{}

GLShader::~GLShader()
{}

std::string GLShader::getSource() const throw(GLException)
{
	return impl_->getSource();
}

void GLShader::compileShader(const std::string & source) throw(GLException)
{
	return impl_->compileShader(source);
}

void GLShader::compileShader(const char * source) throw(GLException)
{
	return impl_->compileShader(source);
}

std::string GLShader::log() const
{
	return impl_->log();
}

GLuint GLShader::shaderId() const
{
	return impl_->shaderId();
}

GLShader::ShaderType GLShader::shaderType() const
{
	return impl_->shaderType();
}
