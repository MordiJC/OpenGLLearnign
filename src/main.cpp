#include <cstdio>
#include <cstdlib>

#include <fstream>
#include <vector>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>

using namespace glm;

#include <OpenGL/GLShader.hpp>

GLuint LoadShaders(const char * vertex_shader_path, const char * fragment_shader_path)
{
	std::string vertexShaderBuffer, fragmentShaderBuffer;
	std::ifstream inputStream;

	inputStream.open(vertex_shader_path, std::ios::in);

	if(inputStream.is_open())
	{
		vertexShaderBuffer = std::string(std::istreambuf_iterator<std::string::value_type>(inputStream),
										 std::istreambuf_iterator<std::string::value_type>());
		inputStream.close();
	}
	else
	{
		fprintf(stderr, "Unable to open Vertex shader file at '%s'\n", vertex_shader_path);
		return 0;
	}

	inputStream.open(fragment_shader_path, std::ios::in);

	if(inputStream.is_open())
	{
		fragmentShaderBuffer = std::string(std::istreambuf_iterator<std::string::value_type>(inputStream),
										   std::istreambuf_iterator<std::string::value_type>());
		inputStream.close();
	}
	else
	{
		printf("Unable to open Fragment shader file at '%s'\n", fragment_shader_path);
		return 0;
	}

	GLint result, infoLogLength;
	GLShader vertexShader(GLShader::Vertex),
			 fragmentShader(GLShader::Fragment);

	try {

		vertexShader.compileShader(vertexShaderBuffer);
		fragmentShader.compileShader(fragmentShaderBuffer);
	}
	catch(GLException & e)
	{
		printf("Error while compiling shader\n%s\n", e.what());
	}

	printf("Linking shaders\n");
	GLuint ProgramID = glCreateProgram();
	glAttachShader(ProgramID, vertexShader.shaderId());
	glAttachShader(ProgramID, fragmentShader.shaderId());
	glLinkProgram(ProgramID);

	glGetProgramiv(ProgramID, GL_LINK_STATUS, &result);
	glGetProgramiv(ProgramID, GL_INFO_LOG_LENGTH, &infoLogLength);
	if(result == GL_FALSE)
	{
		printf("Linking error!\n");
		if ( infoLogLength > 0 ){
			std::vector<char> ShaderProgramErrorMessage(infoLogLength+1);
			glGetShaderInfoLog(ProgramID, infoLogLength, NULL, &ShaderProgramErrorMessage[0]);
			printf("%s\n", &ShaderProgramErrorMessage[0]);
		}
	}

	glDetachShader(ProgramID, vertexShader.shaderId());
	glDetachShader(ProgramID, fragmentShader.shaderId());

	return ProgramID;
}


int main(/*int argc, char *argv[]*/)
{
	if(!glfwInit())
	{
		printf("Failed to initialize GLFW.");
		return -1;
	}

	glfwWindowHint(GLFW_SAMPLES, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_COMPAT_PROFILE, GL_TRUE);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow * window;
	window = glfwCreateWindow(1024, 768, "GLearning", NULL, NULL);

	if(window == NULL)
	{
		printf("Failed to create window. Your graphics card may be incampatible.");
		return -1;
	}

	glfwMakeContextCurrent(window); // Initialize GLEW
	glewExperimental=true; // Needed in core profile
	if (glewInit() != GLEW_OK) {
		printf("Failed to initialize GLEW\n");
		return -1;
	}

	glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

	const GLubyte * ver = glGetString(GL_VERSION);
	glfwSetWindowTitle(window, (char*)ver);

	GLuint VertexArrayID;
	glGenVertexArrays(1, &VertexArrayID);
	glBindVertexArray(VertexArrayID);

	static const GLfloat g_vertex_buffer_data[] = {
		-1.0f, -1.0f, 0.0f,
		1.0f, -1.0f, 0.0f,
		0.0f,  1.0f, 0.0f,
	};

	GLuint vertexbuffer;
	// Generate 1 buffer, put the resulting identifier in vertexbuffer
	glGenBuffers(1, &vertexbuffer);
	// The following commands will talk about our 'vertexbuffer' buffer
	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
	// Give our vertices to OpenGL.
	glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);

	GLuint programID = LoadShaders( "shaders/vertex.vsh", "shaders/fragment.fsh" );

	do{
		glClear(GL_COLOR_BUFFER_BIT);
		glClearColor(0.f,.8f, 0.f, 1.0f);
		glUseProgram(programID);

		glEnableVertexAttribArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
		glVertexAttribPointer(
					0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
					3,                  // size
					GL_FLOAT,           // type
					GL_FALSE,           // normalized?
					0,                  // stride
					(void*)0            // array buffer offset
					);
		// Draw the triangle !
		glDrawArrays(GL_TRIANGLES, 0, 3); // Starting from vertex 0; 3 vertices total -> 1 triangle
		glDisableVertexAttribArray(0);



		// Swap buffers
		glfwSwapBuffers(window);
		glfwPollEvents();

	} // Check if the ESC key was pressed or the window was closed
	while( glfwGetKey(window, GLFW_KEY_ESCAPE ) != GLFW_PRESS &&
		   glfwWindowShouldClose(window) == 0 );

	return 0;
}
