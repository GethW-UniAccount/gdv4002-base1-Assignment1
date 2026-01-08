#include "Asteroid.h"
#include "Engine.h"
Asteroid::Asteroid()
{
	GameObject2D::position = glm::vec2(0, 0);
	GameObject2D::orientation = 0.0f;
	GameObject2D::size = glm::vec2(0.25f, 0.25f);
	GameObject2D::textureID = loadTexture("Resources\\Textures\\Asteroid1.png");
}

Asteroid::Asteroid(glm::vec2 initPos, float initRot, glm::vec2 initSize, GLuint initTextureID) {
	GameObject2D::position = initPos;
	GameObject2D::orientation = initRot;
	GameObject2D::size = initSize;
	GameObject2D::textureID = initTextureID;

}
Asteroid::Asteroid(glm::vec2 initPos, float initRot, glm::vec2 initSize, GLuint initTextureID, glm::vec2 initVelocity) {
	GameObject2D::position = initPos;
	GameObject2D::orientation = initRot;
	GameObject2D::size = initSize;
	GameObject2D::textureID = initTextureID;
	velocity = initVelocity;
}


void Asteroid::update(double tDelta) {

	//position update
	
	//update it FPS-independently via TDelta, casted to float
	//Thank you, https://www.geeksforgeeks.org/cpp/casting-operators-in-cpp/


	position += (velocity * static_cast<float>(tDelta));
	//wrap-around
	if (position.x > 512) //576
	{
		position.x = -256; //544
	}
	else if (position.x < -512) //576
	{
		position.x = 256; //544
	}
	if (position.y > 512) //576
	{
		position.y = -256; //544
	}
	else if (position.y < -512) //576
	{
		position.y = 256; //544
	}
	render();
}


