#include <GLFW/glfw3.h>
#include"Window.h"

int main(int argc, char **argv) {


	/* Initialize the library */
	if (!glfwInit())
	return -1;

	//Create window class
	//Takes care of initialization and also creates a glfwWindow
	Window window(480,640,"Turn");
window.resize(16);
	/* Make the window's context current */
	glfwMakeContextCurrent(window.getWindow());
	//window.resize(17);
	window.RenderScene();

	/* Loop until the user closes the window */

	glfwTerminate();
	return 0;

}
