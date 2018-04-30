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

void Sprites::InitializeSprite() {

	glGenVertexArrays(1, &VAO);

	glGenBuffers(1, &VBO);

	glGenBuffers(1, &EBO);


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

	shader = Graphics::CreateShader(vertexShader, fragmentShader);
}


void Sprites::Update() {

}

void Sprites::Render() {
	const float square[4][3] = {
		{ xPos, yPos, 0.0f }, /* Top Left */
	{ xPos + 0.2f, yPos, 0.0f }, /* Top Right */
	{ xPos + 0.2f, yPos - 0.2f, 0.0f }, /* Bottom Right */
	{ xPos, yPos - 0.2f, 0.0f } /* Bottom Left */
	};


	////Vertex Array Object
	//glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	////Vertex Buffer Object
	//glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(square), square, GL_DYNAMIC_DRAW);

	//Element buffer Object
	//glGenBuffers(1, &EBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(squareIndices), squareIndices, GL_DYNAMIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);
	glEnableVertexAttribArray(0);



	glUseProgram(shader);  //binding shader

	glBindVertexArray(VAO);

	//glDrawArrays(GL_TRIANGLES, 0, 6);

	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);
}