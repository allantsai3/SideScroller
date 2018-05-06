#include "GL/glew.h"
#include "Sprites.h"
#include <iostream>
#include "GLFW/glfw3.h"
#include "../Engine/Graphics/Graphics.h"
#include "../Engine/Engine.h"

static std::vector<Sprites*> envSprites;

Sprites::Sprites() {
	std::cout << "default position set" << std::endl;
	xPos = 0.0f;
	yPos = 0.0f;
}

void Sprites::setPos(int x, int y) {
	xPos = ((2 / (float)Engine::SCREEN_WIDTH) * x) - 1;
	yPos = ((2 / (float)Engine::SCREEN_HEIGHT) * y) - 1;

}

void Sprites::InitializeSprite(int initialHeight, int initialWidth, std::string color) {
	height = (initialHeight / (float)Engine::SCREEN_HEIGHT) * 2;
	width = (initialWidth / (float)Engine::SCREEN_WIDTH) * 2;

	glGenVertexArrays(1, &VAO);

	glGenBuffers(1, &VBO);

	glGenBuffers(1, &EBO);

	std::cout << color << std::endl;
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
		"   color = vec4" + color + ";\n"
		"}\n";

	shader = Graphics::CreateShader(vertexShader, fragmentShader);
}

void Sprites::createBoundary()
{
	for (int index = 0; index < 4; index++) {
		envSprites.push_back(new Sprites);
	}

	//TODO: Spatial partitioning using quad tree?


	envSprites[0]->InitializeSprite(768, wallThickness, "(1.0, 0.0, 0.0, 1.0)"); //left
	envSprites[0]->setPos(0, 768);
	envSprites[1]->InitializeSprite(wallThickness, 1024 - 2 * wallThickness, "(1.0, 0.0, 0.0, 1.0)"); //top
	envSprites[1]->setPos(wallThickness, 768);
	envSprites[2]->InitializeSprite(768, wallThickness, "(1.0, 0.0, 0.0, 1.0)"); //right
	envSprites[2]->setPos(1024 - wallThickness, 768);
	envSprites[3]->InitializeSprite(wallThickness, 1024 - 2 * wallThickness, "(1.0, 0.0, 0.0, 1.0)"); //bottom
	envSprites[3]->setPos(wallThickness, wallThickness);

}


void Sprites::Update() {

}

void Sprites::Render() {
	for (auto index = 0; index < envSprites.size();index++) {
		const float square[4][3] = {
			{ envSprites[index]->xPos, envSprites[index]->yPos, 0.0f }, /* Top Left */
		{ envSprites[index]->xPos + envSprites[index]->width, envSprites[index]->yPos, 0.0f }, /* Top Right */
		{ envSprites[index]->xPos + envSprites[index]->width, envSprites[index]->yPos - envSprites[index]->height, 0.0f }, /* Bottom Right */
		{ envSprites[index]->xPos, envSprites[index]->yPos - envSprites[index]->height, 0.0f } /* Bottom Left */
		};

		////Vertex Array Object
		//glGenVertexArrays(1, &VAO);
		glBindVertexArray(envSprites[index]->VAO);

		////Vertex Buffer Object
		//glGenBuffers(1, &VBO);
		glBindBuffer(GL_ARRAY_BUFFER, envSprites[index]->VBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(square), square, GL_DYNAMIC_DRAW);

		//Element buffer Object
		//glGenBuffers(1, &EBO);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, envSprites[index]->EBO);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(squareIndices), squareIndices, GL_DYNAMIC_DRAW);

		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);
		glEnableVertexAttribArray(0);



		glUseProgram(envSprites[index]->shader);  //binding shader

		glBindVertexArray(envSprites[index]->VAO);

		//glDrawArrays(GL_TRIANGLES, 0, 6);

		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
		glBindVertexArray(0);
	}
}