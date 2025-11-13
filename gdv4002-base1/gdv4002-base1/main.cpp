#include "Engine.h"

// Function prototypes

void myUpdate(GLFWwindow* window, double tDelta) {
	//
	//Update function, do not forget delta timing
	//
	float player1RotationSpeed = glm::radians(90.0f);
	GameObject2D* player1 = getObject("Player1");
	if (player1 != nullptr) {
		player1->orientation += player1RotationSpeed * tDelta;
	}
}

int main(void) {

	// Initialise the engine (create window, setup OpenGL backend)
	int initResult = engineInit("GDV4002 - Applied Maths for Games", 1024, 1024);

	// If the engine initialisation failed report error and exit
	if (initResult != 0) {

		printf("Cannot setup game window!!!\n");
		return initResult; // exit if setup failed
	}

	//
	// Setup game scene objects here
	//
	setUpdateFunction(myUpdate);
	addObject("Player1",glm::vec2(1.0f,1.0f),glm::radians(45.0f),glm::vec2(1.0f,1.0f),"Resources\\Textures\\SpaceShip.png",TextureProperties::NearestFilterTexture());
	GameObject2D* player1Object = getObject("Player1");
	if (player1Object != nullptr) {
		player1Object->position = player1Object->position + glm::vec2(-2.0f, -1.0f);
		player1Object->orientation = glm::radians(10.0f);
		player1Object->textureID = loadTexture("Resources\\Textures\\SpaceShip.png");
	}
	// Enter main loop - this handles update and render calls
	engineMainLoop();
	// When we quit (close window for example), clean up engine resources
	engineShutdown();

	// return success :)
	return 0;
}


