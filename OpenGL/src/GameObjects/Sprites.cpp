#include "GL/glew.h"
#include "Sprites.h"
#include <iostream>
#include "GLFW/glfw3.h"
#include "../Engine/Graphics/Graphics.h"

Sprites::Sprites() {
	std::cout << "default position set" << std::endl;
	xPos = 0.0f;
	yPos = 0.0f;
}

void Sprites::setPos(float x, float y) {
	xPos = x;
	yPos = y;
}

float Sprites::getxPos() {
	return xPos;
}
float Sprites::getyPos() {
	return yPos;
}

void Sprites::Update() {

}

void Sprites::Render() {
	float posit[] = {
		-1.0f, 0.0f, 1.0f,
		0.0f, 0.0f, 1.0f,
		-1.0f, -1.0f, 1.0f
	};

	unsigned int VBO;
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(posit), posit, GL_DYNAMIC_DRAW);
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

	unsigned int shader = Graphics::CreateShader(vertexShader, fragmentShader);
	glUseProgram(shader);  //binding shader

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), NULL);
	glEnableVertexAttribArray(0);

	glDrawArrays(GL_TRIANGLES, 0, 3);
}