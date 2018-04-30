#include "Engine/Engine.h"
#include <iostream>
#include "GameObjects/Player.h"
#include <vector>
#include <memory>
#include "GameObjects/Sprites.h"

using namespace std;

//https://www.lonesock.net/soil.html
//https://www.youtube.com/watch?v=4R5vSIZxr0M
//https://learnopengl.com/Getting-started/Review



int main() {
	Engine engine(1024, 768);
	char GameTitle[] = "SideScroller";
	char * titleptr = GameTitle;
	engine.Initialize(titleptr);

	//Player
	Sprites* playerObjs = new Player[1];
	playerObjs[0].setPos(200, 200);


	// Wall
	vector<Sprites*> boundary;
	for (int index = 0; index < 4; index++) {
		boundary.push_back(getSprite());
	}

	const int thickness = 50;
	boundary[0]->InitializeSprite(768, thickness, "(1.0, 0.0, 0.0, 1.0)"); //left
	boundary[0]->setPos(0, 768);
	boundary[1]->InitializeSprite(thickness, 1024 - 2 * thickness, "(1.0, 0.0, 0.0, 1.0)"); //top
	boundary[1]->setPos(thickness, 768);
	boundary[2]->InitializeSprite(768, thickness, "(1.0, 0.0, 0.0, 1.0)"); //right
	boundary[2]->setPos(1024 - thickness, 768);
	boundary[3]->InitializeSprite(thickness, 1024 - 2 * thickness, "(1.0, 0.0, 0.0, 1.0)"); //bottom
	boundary[3]->setPos(thickness, thickness);

	//TODO : clean up the rendering process

	while (true) {
		engine.Update();
		playerObjs[0].Update();

		engine.BeginRender();
		playerObjs[0].Render();

		for (int index = 0; index < 4; index++) {
			boundary[index]->Render();
		}

		//testSprite[0].Render();

		engine.EndRender();
	}

	delete[] playerObjs;

}