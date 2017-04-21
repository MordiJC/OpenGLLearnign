#include "OpenGL/GLShader.hpp"

#include <OpenGL/impl/GLShader_Impl.hpp>

GLShader::GLShader(GLShader::ShaderType type) throw(GLException)
	: impl_(spimpl::make_impl<GLShader::Impl>(type))
{}

GLShader::~GLShader()
{}

auto GLShader::getSource() const throw(GLException) -> std::string
{
	return impl_->getSource();
}

auto GLShader::compileShader(const std::string & source) throw(GLException) -> void
{
	return impl_->compileShader(source);
}

auto GLShader::compileShader(const char * source) throw(GLException) -> void
{
	return impl_->compileShader(source);
}

auto GLShader::log() const -> std::string
{
	return impl_->log();
}

auto GLShader::shaderId() const -> GLuint
{
	return impl_->shaderId();
}

auto GLShader::shaderType() const -> GLShader::ShaderType
{
	return impl_->shaderType();
}
