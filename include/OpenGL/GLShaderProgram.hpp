#ifndef GLSHADERPROGRAM_HPP
#define GLSHADERPROGRAM_HPP

#include <OpenGL/GLException.hpp>
#include <OpenGL/GLShader.hpp>
#include <spimpl.h>

class GLShaderProgram
{
private:
	class Impl;
	spimpl::impl_ptr<GLShaderProgram::Impl> impl_;
public:
	GLShaderProgram();

	void addShader(GLShader & shader) throw(GLException);


};

#endif // GLSHADERPROGRAM_HPP
