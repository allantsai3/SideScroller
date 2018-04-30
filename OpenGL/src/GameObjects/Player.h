#ifndef PLAYER_H
#define PLAYER_H

#include "Sprites.h"

class Player : public Sprites{
public:
	Player();
	//Player(float xPos, float yPos);

	void Update();
	void Render();
private:

	int xVel = 5;
	const int yVel = 0;
};

#endif //PLAYER_H