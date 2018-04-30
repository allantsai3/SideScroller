#ifndef SPRITES_H
#define SPRITES_H

#include <string.h>
#include <iostream>

class Sprites {
public:
	Sprites();

	void setPos(float x, float y);

	void InitializeSprite();

	virtual void Update();
	virtual void Render();
	//Sprites(std::string imgPath);
	//Sprites(std::string imgPath, float xPos, float yPos);
protected:
	unsigned int VAO;
	unsigned int VBO;
	unsigned int EBO;
	unsigned int shader;

	float xPos;
	float yPos;

	const unsigned int squareIndices[6] = {
		0, 1, 3, //first triangle
		1, 2, 3 // second triangle
	};
};

static Sprites* getSprite() {
	Sprites* sprite = new Sprites;
	return sprite;
}

#endif //SPRITES_H