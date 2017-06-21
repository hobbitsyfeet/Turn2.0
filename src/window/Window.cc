#include "Window.h"
/****************************************************/
//** Window Construtor to initialize size and title
/****************************************************/

Window::Window(int width, int height, const char* title){
	//disable resize manually
	//glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
  running = true;
	window_Width = width;
	window_Height = height;
	this->title = title;
	createWindow();
}

/****************************************************/
//**            Window destructor
/****************************************************/
//Window::~Window(){};

/****************************************************/
//**              createWindow
/****************************************************/
void Window::createWindow(){
	glfwInit();
	this->window = glfwCreateWindow(window_Width, window_Height, "Turn", NULL, NULL);
}

void Window::renderScene(){
	/* Swap front and back buffers */
	glfwSwapBuffers(window);

	/* Poll for and process events */
	glfwPollEvents();
}

/****************************************************/
//**               resizeWindow
//** resize given an int value (Ex. menu select)
/****************************************************/
void Window::resizeWindow(int size){
	//resize window
	switch(size){
		case 0:  glfwMaximizeWindow(window); break;
		//Bad Practice...
		//4:3 aspect ratio resolutions: 640×480, 800×600, 960×720, 1024×768,
		//1280×960, 1400×1050, 1440×1080 , 1600×1200, 1856×1392, 1920×1440,
		// and 2048×1536.
		case 1: setWidth(640); setHeight(480); break;
		case 2: setWidth(800); setHeight(600); break;
		case 3: setWidth(960); setHeight(720); break;
		case 4: setWidth(1024); setHeight(768); break;
		case 5: setWidth(1280); setHeight(960); break;
		case 6: setWidth(1400); setHeight(1050); break;
		case 7: setWidth(1440); setHeight(1080); break;
		case 8: setWidth(1600); setHeight(1200); break;
		case 9: setWidth(1856); setHeight(1392); break;
		case 10: setWidth(1920); setHeight(1440); break;
		case 11: setWidth(2048); setHeight(1546); break;

		//16:10 aspect ratio resolutions: - 1280×800, 1440×900, 1680×1050, 1920×1200
		// and 2560×1600
		case 12: setWidth(1280); setHeight(800); break;
		case 13: setWidth(1440); setHeight(900);  break;
		case 14: setWidth(1680); setHeight(1050); break;
		case 15: setWidth(1920); setHeight(1200); break;
		case 16: setWidth(2560); setHeight(1600); break;

		//16:9 aspect ratio resolutions: 1024×576, 1152×648, 1280×720, 1366×768,
		// 1600×900, 1920×1080, 2560×1440 and 3840×2160.
		case 17: setWidth(1024); setHeight(576); break;
		case 18: setWidth(1152); setHeight(648); break;
		case 19: setWidth(1280); setHeight(720); break;
		case 20: setWidth(1366); setHeight(768); break;
		case 21: setWidth(1600); setHeight(900); break;
		case 22: setWidth(1920); setHeight(1080); break;
		case 23: setWidth(2560); setHeight(1440); break;
		case 24: setWidth(3840); setHeight(2160); break;
	};
	//set resolution will resize and then position into the center of the screen
	glfwSetWindowSize(window, window_Width, window_Height);
	centerWindow();
}

/****************************************************/
//                centerWindow
/****************************************************/
void Window::centerWindow(){
	GLFWmonitor* monitor = glfwGetPrimaryMonitor();
	const GLFWvidmode* mode = glfwGetVideoMode(monitor);
	glfwSetWindowPos(window, (mode->width - window_Width) / 2, (mode->height - window_Height) / 2);
}

/****************************************************/
//          Setter/Getter functions
/****************************************************/
bool Window::setRunning(bool running)
	{return this->running = running;}

void Window::setWidth(int width)
	{window_Width = width;}

void Window::setHeight(int height)
	{window_Height = height;}

bool Window::getRunning()
	{return running;}

int Window::getHeight()
	{return window_Height;}

int Window::getWidth()
	{return window_Width;}

GLFWwindow* Window::getWindow()
	{return window;}
