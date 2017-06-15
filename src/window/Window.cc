#include "Window.h"

Window::Window(int width, int height, std::string title){
	//disable resize manually
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
  running = true;
	Window_Width = width;
	Window_Height = height;
	this->Title = title;
	createWindow();
}


bool Window::setRunning(bool running){
  return this->running = running;
}
void Window::setWidth(int width){
	Window_Width = width;
}
void Window::setHeight(int height){
	Window_Height = height;
}

bool Window::getRunning(){
  return running;
}
int Window::getHeight(){
	return Window_Height;
}
int Window::getWidth(){
	return Window_Width;
}

GLFWwindow* Window::getWindow(){
	return window;
}

void Window::createWindow(){
	glfwInit();
	this->window = glfwCreateWindow(Window_Width, Window_Height, "Turn", NULL, NULL);
	WindowInit();
}

void Window::draw(){}

void Window::RenderScene(){


		/* Render here */
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		draw();

		/* Swap front and back buffers */
		glfwSwapBuffers(window);

		/* Poll for and process events */
		glfwPollEvents();


	// Clear the color and depth buffers.

}



void Window::ResizeScene(){}

void Window::resize(int size){

	switch(size){
		case 0: break;
		//4:3 aspect ratio resolutions: 640×480, 800×600, 960×720, 1024×768,
		//1280×960, 1400×1050, 1440×1080 , 1600×1200, 1856×1392, 1920×1440, and 2048×1536.
		case 1: Window_Width = 640; Window_Height = 480; break;
		case 2: Window_Width = 800; Window_Height = 600; break;
		case 3: Window_Width = 960; Window_Height = 720; break;
		case 4: Window_Width = 1024; Window_Height = 768; break;
		case 5: Window_Width = 1280; Window_Height = 960; break;
		case 6: Window_Width = 1400; Window_Height = 1050; break;
		case 7: Window_Width = 1440; Window_Height = 1080; break;
		case 8: Window_Width = 1600; Window_Height = 1200; break;
		case 9: Window_Width = 1856; Window_Height = 1392; break;
		case 10: Window_Width = 1920; Window_Height = 1440; break;
		case 11: Window_Width = 2048; Window_Height = 1546; break;
		case 12: Window_Width = 640; Window_Height = 480; break;
		case 13: Window_Width = 640; Window_Height = 480; break;
		case 14: Window_Width = 640; Window_Height = 480; break;
		case 15: Window_Width = 640; Window_Height = 480; break;

		//16:10 aspect ratio resolutions: - 1280×800, 1440×900, 1680×1050, 1920×1200 and 2560×1600
		case 16: Window_Width = 1280; Window_Height = 800; break;
		case 17: Window_Width = 1440; Window_Height = 900; printf("%s\n","Display Changed" ); break;
		case 18: Window_Width = 1680; Window_Height = 1050; break;
		case 19: Window_Width = 1920; Window_Height = 1200; break;
		case 20: Window_Width = 2560; Window_Height = 1600; break;

		//16:9 aspect ratio resolutions: 1024×576, 1152×648, 1280×720, 1366×768, 1600×900, 1920×1080, 2560×1440 and 3840×2160.
		case 21: Window_Width = 1024; Window_Height = 576; break;
		case 22: Window_Width = 1152; Window_Height = 648; break;
		case 23: Window_Width = 1280; Window_Height = 720; break;
		case 24: Window_Width = 1366; Window_Height = 768; break;
		case 25: Window_Width = 1600; Window_Height = 900; break;
		case 26: Window_Width = 1920; Window_Height = 1080; break;
		case 27: Window_Width = 2560; Window_Height = 1440; break;
		case 28: Window_Width = 3840; Window_Height = 2160; break;
	};
	glfwSetWindowSize(window, Window_Width, Window_Height);
	CenterWindow();
}

void Window::WindowInit()
{
	// Color to clear color buffer to.
	glClearColor(0.1f, 0.1f, 0.1f, 0.0f);

	// Depth to clear depth buffer to; type of test.
	glClearDepth(1.0);
	glDepthFunc(GL_LESS);

	// Enables Smooth Color Shading; try GL_FLAT for (lack of) fun.
	glShadeModel(GL_SMOOTH);

	// Load up the correct perspective matrix; using a callback directly.
}

void Window::CenterWindow(){
	GLFWmonitor* monitor = glfwGetPrimaryMonitor();
	const GLFWvidmode* mode = glfwGetVideoMode(monitor);
	glfwSetWindowPos(window, (mode->width - Window_Width) / 2, (mode->height - Window_Height) / 2);
}
