#include "GL/glew.h"
#include "Player.h"
#include <iostream>
#include "../Engine/Graphics/Graphics.h"
#include "GLFW/glfw3.h"
#include "../IO/Input.h"
#include "../Engine/Engine.h"

Player::Player() {
	InitializeSprite();
	std::cout << "Player initialized" << std::endl;
}


void Player::Update() {

	float curX = (xPos + 1) * ((float)Engine::SCREEN_WIDTH / 2);
	float curY = (yPos + 1) * ((float)Engine::SCREEN_HEIGHT / 2);

	if (Input::keyPressed(GLFW_KEY_A)) {
		xVel = -5;
	}
	else if(Input::keyPressed(GLFW_KEY_D)) {
		xVel = 5;
	}
	else {
		xVel = 0;
	}


	setPos(curX + xVel, curY + yVel);


}
void Player::Render() {
	const float square[4][3] = {
		{ xPos, yPos, 0.0f }, /* Top Left */
	{ xPos + width, yPos, 0.0f }, /* Top Right */
	{ xPos + width, yPos - height, 0.0f }, /* Bottom Right */
	{ xPos, yPos - height, 0.0f } /* Bottom Left */
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