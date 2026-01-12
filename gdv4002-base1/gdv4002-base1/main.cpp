#include "Engine.h"
#include "PlayerShip.h"
#include "ReferencePoint.h"
//#include <filesystem> NO LONGER NEEDED


// Function prototypes
void myUpdate(GLFWwindow* window, double tDelta);
void myKeyboardHandler(GLFWwindow* window, int key, int scancode, int action, int mods);

PlayerShip* Player;

int main(void) {

	// Initialise the engine (create window, setup OpenGL backend)
	int initResult = engineInit("GDV4002 - Applied Maths for Games", 1024, 1024);

	// If the engine initialisation failed report error and exit
	if (initResult != 0) {

		printf("Cannot setup game window!!!\n");
		return initResult; // exit if setup failed
	}
	
	//thanks, https://stackoverflow.com/questions/5206373/opengl-texture-transparency-doesnt-work
	//Also thanks, 
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	
	//Use the default update function, use a callback to call after.
	setUpdateFunction(myUpdate, false);
	setKeyboardHandler(myKeyboardHandler);
	std::srand(time(0));

	//preload textures so we can refer to them by their GL Unisigned Int identifiers
		//1: Ship
	loadTexture("Resources\\Textures\\Ship.png");
		//2: Reference Point marker / Background
	loadTexture("Resources\\Textures\\Background.png");
		//3: Asteroid1
	loadTexture("Resources\\Textures\\Asteroid1.png");
		//4: LaserProjectile
	loadTexture("Resources\\Textures\\LaserProjectile.png");
	

	//spawn objects
	Player = new PlayerShip();
	addObject("player", Player);
	ReferencePoint* Ref = new ReferencePoint();
	addObject("ref", Ref);
	
	
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
	//Using key L to List game object keys, C to list counts
	if (action == GLFW_PRESS) {
		switch (key)
		{
			
			case GLFW_KEY_ESCAPE:
				glfwSetWindowShouldClose(window, true);
				break;
			case GLFW_KEY_W:
				Player->InForward = true;
				break;
			case GLFW_KEY_A:
				Player->InLeft = true;
				break;
			case GLFW_KEY_S:
				Player->InDown = true;
				break;
			case GLFW_KEY_D:
				Player->InRight = true;
				break;
			case GLFW_KEY_SPACE:
				Player->InFire = true;
				break;
			case GLFW_KEY_L:
				listGameObjectKeys();
				break;
			case GLFW_KEY_C:
				listObjectCounts();
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
			Player->InForward = false;
			break;
		case GLFW_KEY_A:
			Player->InLeft = false;
			break;
		case GLFW_KEY_S:
			Player->InDown = false;
			break;
		case GLFW_KEY_D:
			Player->InRight = false;
			break;
		case GLFW_KEY_SPACE:
			Player->InFire = false;
			break;
		}
	}

}

void myUpdate(GLFWwindow* window, double tDelta) 
{
	//projectile deletion function, iterate through projectiles and delete ones marked for deletion
	GameObjectCollection Projectiles = getObjectCollection("Projectile");
	for (int i = 0; i < Projectiles.objectCount; i++) {
		if (Projectiles.objectArray[i]->DeleteThis = true) {
			deleteObject(Projectiles.objectArray[i]);
		}
	}
}
