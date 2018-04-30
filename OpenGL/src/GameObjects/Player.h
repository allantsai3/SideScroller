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

	float xVel = 0.0f;
	const float yVel = 0.0000f;
};

#endif //PLAYER_H