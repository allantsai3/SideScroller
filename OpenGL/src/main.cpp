#include "Engine/Engine.h"
#include <iostream>
#include "GameObjects/Player.h"

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
	
	Sprites* testSprite = new Sprites[1];

	while (true) {
		engine.Update();
		playerObjs[0].Update();

		engine.BeginRender();
		playerObjs[0].Render();
		testSprite[0].Render();

		engine.EndRender();
	}

	delete[] playerObjs;
	delete[] testSprite;
}