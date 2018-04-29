#include <GL/glew.h>
#include "Engine.h"
#include "GLFW/glfw3.h"
#include "../IO/Input.h"
#include <iostream>

int Engine::SCREEN_WIDTH = 1024;
int Engine::SCREEN_HEIGHT = 768;

void framebuffer_size_callback(GLFWwindow* window, int width, int height);

Engine::Engine() {

}

Engine::Engine(int inputWidth, int inputHeight)
{
	SCREEN_HEIGHT = inputHeight;
	SCREEN_WIDTH = inputWidth;
}

Engine::~Engine() {

}

bool Engine::Initialize(char* windowTitle) {


	/* Initialize the library */
	if (!glfwInit())
	{
		std::cout << "Error initializing GLFW" << std::endl;
		return false;
	}

	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, windowTitle, NULL, NULL);
	if (window == NULL)
	{
		glfwTerminate();
		return false;
	}

	/* Make the window's context current */
	glfwMakeContextCurrent(window);

	if (glewInit() != GLEW_OK) {
		std::cout << "Error!" << std::endl;
	}

	int width, height;
	glfwGetFramebufferSize(window, &width, &height);
	glfwSwapInterval(1);

	//Input
	glfwSetKeyCallback(window, Input::KeyCallBack);


	const GLFWvidmode* mode = glfwGetVideoMode(glfwGetPrimaryMonitor());
	int xPos = (mode->width - SCREEN_WIDTH) / 2;
	int yPos = (mode->height - SCREEN_HEIGHT) / 2;
	glfwSetWindowPos(window, xPos, yPos);

	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
	glViewport(0, 0, width, height);

	//glMatrixMode(GL_PROJECTION);
	//glLoadIdentity();
	//glOrtho(0, width, 0, height, -10, 10);
	//glDepthRange(-10, 10);
	//glMatrixMode(GL_MODELVIEW);

	//glEnable(GL_ALPHA_TEST);
	//glEnable(GL_BLEND);
	//glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);


	return true;
}

void Engine::Update() {
	glfwPollEvents();
}


void Engine::BeginRender() {
	//Clearing the buffer
	glClearColor(255, 255, 255, 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Engine::EndRender(){

	/* Swap front and back buffers */
	glfwSwapBuffers(window);

}

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
	glViewport(0, 0, width, height);
	std::cout << "resized to W:" << width << " H:" << height << std::endl;
}
