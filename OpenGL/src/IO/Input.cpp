#include <GLFW/glfw3.h>
#include "Input.h"
#include <iostream>

int Input::keyState = 0;
int Input::keyAction = 0;

void Input::KeyCallBack(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_ESCAPE) {
		glfwTerminate();
		exit(1);
	}
	else if (key == GLFW_KEY_E && action == GLFW_PRESS) {
		std::cout << "Pressed" << std::endl;
	}

	keyState = key;
	keyAction = action;
}

bool Input::keyPressed(int key) {
	if (key == keyState && (keyAction == GLFW_PRESS || keyAction == GLFW_REPEAT)) {
		return true;
	}

	return false;
}
