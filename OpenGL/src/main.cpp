#include "Engine/Engine.h"
#include <iostream>
#include "GameObjects/Player.h"
#include <vector>
#include "GameObjects/Sprites.h"
#include <map>

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

	//Static obj
	Sprites sprite;
	sprite.createBoundary();


	while (true) {
		engine.Update();
		playerObjs[0].Update();

		engine.BeginRender();

		playerObjs[0].Render();
		sprite.Render();

		engine.EndRender();

	}

	delete[] playerObjs;

}