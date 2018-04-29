#ifndef SPRITES_H
#define SPRITES_H

#include <string.h>
#include <iostream>

class Sprites {
public:
	Sprites();

	void setPos(float x, float y);

	float getxPos();
	float getyPos();

	virtual void Update();
	virtual void Render();
	//Sprites(std::string imgPath);
	//Sprites(std::string imgPath, float xPos, float yPos);
private:
	float xPos;
	float yPos;
};

#endif //SPRITES_H