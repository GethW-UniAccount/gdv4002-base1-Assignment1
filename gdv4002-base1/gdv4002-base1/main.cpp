#include "Engine.h"
#include "PlayerShip.h"
// Function prototypes

void myKeyboardHandler(GLFWwindow* window, int key, int scancode, int action, int mods);

void myUpdate(GLFWwindow* window, double tDelta);

int main(void) {

	// Initialise the engine (create window, setup OpenGL backend)
	int initResult = engineInit("GDV4002 - Applied Maths for Games", 1024, 1024);

	// If the engine initialisation failed report error and exit
	if (initResult != 0) {

		printf("Cannot setup game window!!!\n");
		return initResult; // exit if setup failed
	}
	//
	//Create Variables to be used later:
	// 

	// 
	// Setup game scene objects here
	//
	//Use the default update function, no need to set a callback here.
	setKeyboardHandler(myKeyboardHandler);

	PlayerShip* Player = new PlayerShip();
	addObject("player", Player);


	// Enter main loop - this handles update and render calls
	engineMainLoop();
	// When we quit (close window for example), clean up engine resources
	engineShutdown();

	// return success :)
	return 0;
}



void myKeyboardHandler(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	//bitwise operations learned  from https://www.geeksforgeeks.org/cpp/cpp-bitwise-operators/
	if (action == GLFW_PRESS) {
		switch (key)
		{
			
			case GLFW_KEY_ESCAPE:
				glfwSetWindowShouldClose(window, true);
				break;
			case GLFW_KEY_W:
				PlayerShip::Inputs::InForward | 1;
				break;
			case GLFW_KEY_A:
				PlayerShip::Inputs::InLeft | 1;
				break;
			case GLFW_KEY_S:
				PlayerShip::Inputs::InDown | 1;
				break;
			case GLFW_KEY_D:
				PlayerShip::Inputs::InRight | 1;
				break;
			case GLFW_KEY_SPACE:
				PlayerShip::Inputs::InFire | 1;
				break;
		}
	}
	if (action == GLFW_RELEASE) {
		switch (key)
		{

		case GLFW_KEY_ESCAPE:
			glfwSetWindowShouldClose(window, true);
			break;
		case GLFW_KEY_W:
			PlayerShip::Inputs::InForward | 1;
			break;
		case GLFW_KEY_A:
			PlayerShip::Inputs::InLeft | 1;
			break;
		case GLFW_KEY_S:
			PlayerShip::Inputs::InDown | 1;
			break;
		case GLFW_KEY_D:
			PlayerShip::Inputs::InRight | 1;
			break;
		case GLFW_KEY_SPACE:
			PlayerShip::Inputs::InFire | 1;
			break;
		}
	}

}
