#ifndef PLAYER_H
#define PLAYER_H

#include "Sprites.h"

class Player : public Sprites{
public:
	Player();
	//Player(float xPos, float yPos);
	void InitializePlayer();
	void Update();
	void Render();
private:
	unsigned int VAO;
	unsigned int VBO;
	unsigned int EBO;
	unsigned int shader;

	float xVel = 0.0f;
	const float yVel = 0.0000f;

	const unsigned int indices[6] = {
		0, 1, 3, //first triangle
		1, 2, 3 // second triangle
	};
};

#endif //PLAYER_H