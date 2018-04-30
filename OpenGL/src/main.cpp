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

	Sprites* playerObjs = new Player[1];
	playerObjs[0].setPos(0.0f, 0.0f);

	vector<Sprites*> testSprite;
	for (int index = 0; index < 5; index++) {
		testSprite.push_back(getSprite());
	}

	for (int index = 0; index < 5; index++) {
		testSprite[index]->InitializeSprite();
	}
	
	//Sprites* testSprite = new Sprites[1];
	testSprite[0]->setPos(-1.0f, 1.0f);
	testSprite[1]->setPos(-1.0f, .8f);
	testSprite[2]->setPos(-1.0f, .6f);
	testSprite[3]->setPos(-1.0f, .4f);
	testSprite[4]->setPos(-1.0f, .2f);

	while (true) {
		engine.Update();
		playerObjs[0].Update();

		engine.BeginRender();
		playerObjs[0].Render();

		for (int index = 0; index < 5; index++) {
			testSprite[index]->Render();
		}

		//testSprite[0].Render();

		engine.EndRender();
	}

	delete[] playerObjs;
	//delete[] testSprite;
}