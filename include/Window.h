#ifndef WINDOW_H
#define WINDOW_H




#include <GLFW/glfw3.h>


#include <string>
class Window {
public:
	Window(int width, int height, const char* title);

	//** methods
	void createWindow();				//** Creates a window, initializes and assigns it **//
	void renderScene();					//** GLFW swapbuffer and pollevents **//
	void resizeWindow(int size);//** int value will select a resolution **//
																	//(useful for menu selection)

	//** setters and getters
		void setWidth(int width);
		void setHeight(int height);
		bool setRunning(bool running);

	//** getVariables
		bool getRunning();
		int getWidth();
		int getHeight();

	//** get GLFW window properties
		const char* getTitle();
		GLFWwindow* getWindow();

private:
	void centerWindow();

	bool running;
	int position_x;
	int position_y;
	int window_Width;
	int window_Height;
	const char* title;
	GLFWwindow* window;
	float ratio;
};



#endif //WINDOW_H
