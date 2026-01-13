#include "Asteroid.h"
#include "Engine.h"
Asteroid::Asteroid()
{
	GameObject2D::position = glm::vec2(0, 0);
	GameObject2D::orientation = 0.0f;
	GameObject2D::size = glm::vec2(0.25f, 0.25f);
	GameObject2D::textureID = 3;
}

Asteroid::Asteroid(glm::vec2 initPos, float initRot, glm::vec2 initSize, GLuint initTextureID) {
	GameObject2D::position = initPos;
	GameObject2D::orientation = initRot;
	GameObject2D::size = initSize;
	GameObject2D::textureID = initTextureID;

}
Asteroid::Asteroid(glm::vec2 initPos, float initRot, glm::vec2 initSize, GLuint initTextureID, glm::vec2 initVelocity, float initRotVel) {
	GameObject2D::position = initPos;
	GameObject2D::orientation = initRot;
	GameObject2D::size = initSize;
	GameObject2D::textureID = initTextureID;
	velocity = initVelocity;
	rotationVelocity = initRotVel;
}
Asteroid::Asteroid(glm::vec2 initPos, float initRot, glm::vec2 initSize, glm::vec2 initVelocity) {
	GameObject2D::position = initPos;
	GameObject2D::orientation = initRot;
	GameObject2D::size = initSize;
	GameObject2D::textureID = 3;
	velocity = initVelocity;
}

void Asteroid::update(double tDelta) {

	//position update
	
	//update it FPS-independently via TDelta, casted to float
	//Thank you, https://www.geeksforgeeks.org/cpp/casting-operators-in-cpp/


	position += glm::vec2(velocity.x * static_cast<float>(tDelta), velocity.y * static_cast<float>(tDelta));
	orientation += rotationVelocity * tDelta;
	//wrap-around
	if (position.x > 3) //576px
	{
		position.x = -2.75; //544px
	}
	else if (position.x < -3) //576px
	{
		position.x = 2.75; //544px
	}
	if (position.y > 3) //576px
	{
		position.y = -2.75; //544px
	}
	else if (position.y < -3) //576px
	{
		position.y = 2.75; //544px
	}
	render();
}


/*void Asteroid::Break() {
	//glm::vec2 Pos = GameObject2D::position;
	//glm::vec2 Size = GameObject2D::size;
	float VelX;
	float VelY;
	VelX = static_cast<float>((std::rand() % 4) - 2);
	VelY = static_cast<float>((std::rand() % 4) - 2);
	Asteroid* AsteroidObj = new Asteroid(glm::vec2(0,0), glm::radians(static_cast<float>(std::rand() % 360)), glm::vec2(size.x/2, size.y/2), 3, glm::vec2(VelX, VelY), static_cast<float>((std::rand() % 4) - 2));
	addObject("AsteroidInstance", AsteroidObj);
}*/



