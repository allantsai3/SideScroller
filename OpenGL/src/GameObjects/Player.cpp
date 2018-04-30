#include "GL/glew.h"
#include "Player.h"
#include <iostream>
#include "../Engine/Graphics/Graphics.h"
#include "GLFW/glfw3.h"
#include "../IO/Input.h"

Player::Player() {
	InitializePlayer();
	std::cout << "Player initialized" << std::endl;
}

void Player::InitializePlayer() {
	//https://www.khronos.org/opengl/wiki/Tutorial2:_VAOs,_VBOs,_Vertex_and_Fragment_Shaders_(C_/_SDL)

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
		"   color = vec4(0.0, 0.0, 0.0, 1.0);\n"
		"}\n";

	shader = Graphics::CreateShader(vertexShader, fragmentShader);
}

void Player::Update() {

	if (Input::keyPressed(GLFW_KEY_A)) {
		xVel =- 0.01f;
	}
	else if(Input::keyPressed(GLFW_KEY_D)) {
		xVel = 0.01f;
	}
	else {
		xVel = 0.0f;
	}

	setPos(xPos + xVel, yPos - yVel);


}
void Player::Render() {
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