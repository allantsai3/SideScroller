#ifndef ENGINE_H
#define ENGINE_H

#include<GLFW/glfw3.h>

class Engine {
public:
	static int SCREEN_WIDTH;
	static int SCREEN_HEIGHT;

	Engine();
	Engine(int width, int height);
	~Engine();

	bool Initialize(char* windowTitle);

	void Update();
	void BeginRender();
	void EndRender();

private:
	GLFWwindow * window;
};



#endif //ENGINE_H