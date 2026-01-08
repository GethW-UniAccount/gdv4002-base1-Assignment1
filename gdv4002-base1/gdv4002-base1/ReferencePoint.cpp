#include "ReferencePoint.h"
#include "Engine.h"
#include "Asteroid.h"
#include "time.h"
#include <iostream>

ReferencePoint::ReferencePoint()
{
	GameObject2D::position = glm::vec2(0, 0);
	GameObject2D::orientation = 0.0f;
	GameObject2D::size = glm::vec2(1, 1);
	GameObject2D::textureID = loadTexture("Resources\Textures\ReferencePointMarker.png");
	//Thanks to https://www.geeksforgeeks.org/cpp/rand-and-srand-in-ccpp/
	
}

ReferencePoint::ReferencePoint(glm::vec2 initPos, float initRot, glm::vec2 initSize, GLuint initTextureID) {
	GameObject2D::position = initPos;
	GameObject2D::orientation = initRot;
	GameObject2D::size = initSize;
	GameObject2D::textureID = initTextureID;

}



void ReferencePoint::update(double tDelta) {
	TimeToAsteroid += tDelta;
	if (TimeToAsteroid > AsteroidThreshold)
	{
		
		//used these https://www.geeksforgeeks.org/cpp/rand-and-srand-in-ccpp/
		//https://www.w3schools.com/cpp/cpp_howto_random_number.asp
		//https://www.w3schools.com/cpp/cpp_operators_logical.asp
		float InitY = 0;
		float InitX = 0;
		InitX = (std::rand() % 1152) - 576;
		if (InitX < 512 || InitX > -512)
		{
			InitY = (std::rand() % 1153) - 576;
			if (InitX < 0)
{
				InitY = (std::rand() % 129) - 512;
			}
			else
			{
				InitY = (std::rand() % 129) + 512;
			}
		}
		else
		{
			float InitY = (std::rand() % 1152) - 576;
		}
		glm::vec2 initPos = glm::vec2(InitX, InitY);
		//https://en.cppreference.com/w/cpp/language/static_cast.html
		float initRot = glm::radians(static_cast<float>(std::rand() % 360));
		float initSize;
		//GLuint initTextureID;
		//size 1 or 0.5 asteroid (size 0.25 is only from asteroids being broken)
		if ((std::rand() % 3) > 1)
		{
			initSize = 1;
		}
		else
		{
			initSize = 0.5f;
		}
		//pick one of 3 textures

		/*switch (std::rand() % 4)
		{
		case 1:
			initTextureID = loadTexture("Resources\Textures\Asteroid1.png");
				break;
		case 2:
			initTextureID = loadTexture("Resources\Textures\Asteroid1.png");
			break;
		case 3:
			initTextureID = loadTexture("Resources\Textures\Asteroid1.png");
			break;
		default:
			initTextureID = loadTexture("Resources\Textures\Asteroid1.png");
			break;
		}
		*/
		Asteroid (initPos, initRot, glm::vec2(initSize, initSize), loadTexture("Resources\Textures\Asteroid1.png"), glm::vec2(10, 10));
		
		std::cout << "\nX:";
		std::cout << initPos.x;
		std::cout << "\nY:";
		std::cout << initPos.y;
		std::cout << "\nRotation:";
		std::cout << initRot;
		std::cout << "\nSize:";
		std::cout << initSize;
		TimeToAsteroid = 0;
	}
	
	render();
}

