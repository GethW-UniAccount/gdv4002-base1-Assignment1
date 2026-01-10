#include "ReferencePoint.h"
#include "Engine.h"
#include "Asteroid.h"
#include "time.h"
#include <iostream>

ReferencePoint::ReferencePoint()
{
	GameObject2D::position = glm::vec2(0, 0);
	GameObject2D::orientation = 0.0f;
	GameObject2D::size = glm::vec2(5, 5);
	GameObject2D::textureID = 2;
	
}

ReferencePoint::ReferencePoint(glm::vec2 initPos, float initRot, glm::vec2 initSize, GLuint initTextureID) {
	GameObject2D::position = initPos;
	GameObject2D::orientation = initRot;
	GameObject2D::size = initSize;
	GameObject2D::textureID = initTextureID;
}



void ReferencePoint::update(double tDelta) {
	GameObjectCollection Asteroids = getObjectCollection("AsteroidInstance");
	int AsteroidCount = Asteroids.objectCount;
	TimeToAsteroid += tDelta;
	if (AsteroidCount < 10) {
		if (TimeToAsteroid > AsteroidThreshold)
		{
			
			//used these https://www.geeksforgeeks.org/cpp/rand-and-srand-in-ccpp/
			//https://www.w3schools.com/cpp/cpp_howto_random_number.asp
			//https://www.w3schools.com/cpp/cpp_operators_logical.asp
			float InitY = 0;
			float InitX = 0;

			//pick from 1 of 8 spots outside the screen boundary

			switch (std::rand() % 9) {
			case 1:
				//Top Left
				InitX = -2.5;
				InitY = 2.5;
				break;
			case 2:
				//Top Middle
				InitX = 0;
				InitY = 2.5;
				break;
			case 3:
				//Top Right
				InitX = 2.5;
				InitY = 2.5;
				break;
			case 4:
				//Middle Left
				InitX = -2.5;
				InitY = 0;
				break;
			case 5:
				//Middle Right
				InitX = 2.5;
				InitY = 0;
				break;
			case 6:
				//Bottom Left
				InitX = -2.5;
				InitY = -2.5;
				break;
			case 7:
				//Bottom Middle
				InitX = 0;
				InitY = -2.5;
				break;
			case 8:
				//Bottom Right
				InitX = 2.5;
				InitY = -2.5;
				break;
			}

			/*
			Would've worked if it were the scale I initially thought.
			 
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
			}*/


			glm::vec2 initPos = glm::vec2(InitX, InitY);
			//https://en.cppreference.com/w/cpp/language/static_cast.html
			float initRot = glm::radians(static_cast<float>(std::rand() % 360));
			float initSize;
			//size 0.5 or 0.25 asteroid (size 0.125 is only from asteroids being broken)
			if ((std::rand() % 3) > 1)
			{
				initSize = 0.5f;
			}
			else
			{
				initSize = 0.25f;
			}
			float VelX;
			float VelY;
			VelX = static_cast<float>((std::rand() % 4) - 2);
			VelY = static_cast<float>((std::rand() % 4) - 2);
			Asteroid* AsteroidObj = new Asteroid(initPos, initRot, glm::vec2(initSize, initSize), 3, glm::vec2(VelX, VelY), static_cast<float>((std::rand() % 4) - 2));
			addObject("AsteroidInstance", AsteroidObj);
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
	}





	render();
}

