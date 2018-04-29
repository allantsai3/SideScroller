#ifndef INPUT_H
#define INPUT_H

#include "GLFW/glfw3.h"

class Input {
public:
	static void KeyCallBack(GLFWwindow* window, int key, int scancode, int action, int mods);
	static bool keyPressed(int key);
	//static bool keyReleased(int key);
	
private:
	static int keyState;
	static int keyAction;
};

#endif //INPUT_H
