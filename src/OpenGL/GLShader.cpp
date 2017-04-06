#include "OpenGL/GLShader.hpp"

#include "OpenGL/GLShader_Impl.hpp"

GLShader::GLShader(GLShader::ShaderType type)
	: pImpl(new GLShader::Impl(type), [](GLShader::Impl *impl) { delete impl; })
{}

std::string GLShader::getSource() const throw(Exception)
{
	return pImpl->getSource();
}

void GLShader::compileShader(const std::string & source) throw(Exception)
{
	return pImpl->compileShader(source);
}

void GLShader::compileShader(const char * source) throw(Exception)
{
	return pImpl->compileShader(source);
}

std::string GLShader::log() const
{
	return pImpl->log();
}

GLuint GLShader::shaderId() const
{
	return pImpl->shaderId();
}

GLShader::ShaderType GLShader::shaderType() const
{
	return pImpl->shaderType();
}
