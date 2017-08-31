#include <GLFW/glfw3.h>
#include "GLModel.h"
#include "GLView.h"
#include"Window.h"
#include <iostream>


int main(int argc, char **argv) {
	GLModel model;

	rectangle rect(1,1);
	/* Initialize the library */
	if (!glfwInit())
	return -1;

	//Create window class
	//Takes care of initialization and also creates a glfwWindow
	Window window(480,640,"Turn");
	if (!window.getWindow())
	{
		glfwTerminate();
		//exit(EXIT_FAILURE);
	}
	/* Make the window's context current */
	glfwMakeContextCurrent(window.getWindow());
	model.init();
	model.setViewport(window.getWidth()*2,window.getHeight());
			window.resizeWindow(5);

	while (!glfwWindowShouldClose(window.getWindow()))
	{
		//double last = glfwGetTime();
		window.renderScene();

		model.display();
		generateShapes();

	}
	/* Loop until the user closes the window */
	glfwTerminate();
	return 0;

}
