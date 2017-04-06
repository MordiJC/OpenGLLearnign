#include "OpenGL/GLShader_Impl.hpp"

#include <vector>

GLenum shaderTypeToGLenum(GLShader::ShaderType type)
{
	switch(type)
	{
	case GLShader::Fragment:               return GL_FRAGMENT_SHADER;
	case GLShader::Vertex:                 return GL_VERTEX_SHADER;
	case GLShader::Geometry:               return GL_GEOMETRY_SHADER;
	case GLShader::Compute:                return GL_COMPUTE_SHADER;
	case GLShader::TessellationEvaluation: return GL_TESS_EVALUATION_SHADER;
	case GLShader::TessellationControl:    return GL_TESS_CONTROL_SHADER;
	default:                               return 0;
	}
}

GLShader::Impl::Impl(GLShader::ShaderType type)
	: shaderType_(type), shaderId_(0)
{
	// Sheck if shader type is valid
	if(shaderTypeToGLenum(shaderType()) == 0)
	{
		throw Exception("Invalid shader type");
	}
}

GLShader::Impl::~Impl()
{
	GLuint sid = shaderId();
	if(glIsShader(sid))
	{
		glDeleteShader(sid);
	}
}

std::string GLShader::Impl::getSource() const  throw(Exception)
{
	if(glIsShader(shaderId()))
	{
		GLint shaderSourceLength;

		glGetShaderiv(shaderId(), GL_SHADER_SOURCE_LENGTH, &shaderSourceLength);

		if(shaderSourceLength == 0)
		{
			throw Exception("Shader has no source");
		}

		std::vector<GLchar> shaderSource(shaderSourceLength+1);

		glGetShaderSource(shaderId(), shaderSourceLength+1, &shaderSourceLength, &shaderSource[0]);

		return std::string(shaderSource.begin(), shaderSource.end());
	}
	else
	{
		throw Exception("Shader has no source");
	}
}

void GLShader::Impl::compileShader(const std::string & source)  throw(Exception)
{
	compileShader(source.c_str());
}

void GLShader::Impl::compileShader(const char * source)  throw(Exception)
{
	// Create shader program if does not exists.
	if(!glIsShader(shaderId()))
	{
		shaderId_ = glCreateShader(shaderTypeToGLenum(shaderType()));
	}

	GLint result;
	const char * sourcePtr = source;

	// Set shader source
	glShaderSource(shaderId(), 1, &sourcePtr, NULL);

	// Compile shader from source
	glCompileShader(shaderId());

	// Get compilation status
	glGetShaderiv(shaderId(), GL_COMPILE_STATUS, &result);

	if(result == GL_FALSE)
	{
		throw Exception("Shader comopilation error");
	}
}

std::string GLShader::Impl::log() const
{
	std::string logContent;
	if(glIsShader(shaderId()))
	{
		GLint logLength;

		glGetShaderiv(shaderId(), GL_INFO_LOG_LENGTH, &logLength);

		std::vector<GLchar> shaderLog(logLength+1);

		glGetShaderInfoLog(shaderId(), logLength, &logLength, &logContent[0]);

		logContent.assign(shaderLog.begin(), shaderLog.end());
	}

	return logContent;
}

GLuint GLShader::Impl::shaderId() const
{
	return shaderId_;
}

GLShader::ShaderType GLShader::Impl::shaderType() const
{
	return shaderType_;
}
