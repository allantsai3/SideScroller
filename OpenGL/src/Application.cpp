#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include "Input.h"
#include "Player.h"

void keyCallback(GLFWwindow *window, int key, int scancode, int action, int mods);

static unsigned int CompileShader(unsigned int type, const std::string& source)
{
	unsigned int id = glCreateShader(type);
	const char* src = source.c_str();
	glShaderSource(id, 1, &src, NULL);
	glCompileShader(id);

	//Error handling
	int result;
	glGetShaderiv(id, GL_COMPILE_STATUS, &result);
	if (result == GL_FALSE) {
		int length;
		glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
		char message = (char)alloca(length * sizeof(char)); //keep message on stack
		glGetShaderInfoLog(id, length, &length, &message);
		std::cout << "Failed to compile shader!" << 
			(type == GL_VERTEX_SHADER ? "vertex" : "fragment") << std::endl;
		std::cout << message << std::endl;
		return 0;
	}

	return id;
}

//Provide OpenGL with shader source code
static unsigned int CreateShader(const std::string& vertexShader, const std::string& fragmentShader)
{
	unsigned int program = glCreateProgram();
	unsigned int vs = CompileShader(GL_VERTEX_SHADER, vertexShader);
	unsigned int fs = CompileShader(GL_FRAGMENT_SHADER, fragmentShader);

	glAttachShader(program, vs);
	glAttachShader(program, fs);
	glLinkProgram(program);
	glValidateProgram(program);

	glDeleteShader(vs);
	glDeleteShader(fs);

	return program;
}

int main(void)
{
	GLFWwindow* window;

	/* Initialize the library */
	if (!glfwInit())
		return -1;

	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(640, 480, "SideScroller", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	/* Make the window's context current */
	glfwMakeContextCurrent(window);

	if (glewInit() != GLEW_OK) {
		std::cout << "Error!" << std::endl;
	}

	std::cout << glGetString(GL_VERSION) << std::endl;
	
	float positions[6] = {
		-0.5f, -0.5f,
		0.0f, 0.5f,
		0.5f, -0.5f
	};

	//Creating buffer
	unsigned int buffer;
	glGenBuffers(1, &buffer);
	glBindBuffer(GL_ARRAY_BUFFER, buffer);
	glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(float), positions, GL_STATIC_DRAW);
	
	// Tells OpenGl the layout of the buffer
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2*sizeof(float), 0);

	//Shader
	std::string vertexShader = "#version 330 core\n"
		"\n"
		"layout(location = 0) in vec4 position;\n"  //location = index of attribute
		"\n"
		"void main()\n"
		"{\n"
		"   gl_Position = position;\n"
		"}\n";

	std::string fragmentShader = "#version 330 core\n"
		"\n"
		"layout(location = 0) out vec4 color;"  //location = index of attribute
		"\n"
		"void main()\n"
		"{\n"
		"   color = vec4(1.0, 0.0, 0.0, 1.0);\n"
		"}\n";

	unsigned int shader = CreateShader(vertexShader, fragmentShader);
	glUseProgram(shader);  //binding shader

	//key presses
	glfwSetKeyCallback(window, keyCallback);



	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window))
	{
		

		/* Render here */
		glClear(GL_COLOR_BUFFER_BIT);

		glDrawArrays(GL_TRIANGLES, 0, 3);

		/* Swap front and back buffers */
		glfwSwapBuffers(window);

		/* Poll for and process events */
		glfwPollEvents();
	}

	glDeleteProgram(shader);

	glfwTerminate();
	return 0;
}

void keyCallback(GLFWwindow *window, int key, int scancode, int action, int mods) 
{
	std::cout << key << std::endl;

	if (key == GLFW_KEY_SPACE && action == GLFW_PRESS) {
		std::cout << "Space key pressed" << std::endl;
	}
}