#include <GLFW/glfw3.h>
#include"Window.h"

int main(int argc, char **argv) {


	/* Initialize the library */
	if (!glfwInit())
	return -1;

	//Create window class
	//Takes care of initialization and also creates a glfwWindow
	Window window(480,640,"Turn");

	/* Make the window's context current */
	glfwMakeContextCurrent(window.getWindow());
	window.resize(15);
	while (!glfwWindowShouldClose(window.getWindow()))
	{
	window.RenderScene();
	}
	/* Loop until the user closes the window */
	glfwTerminate();
	return 0;

}
