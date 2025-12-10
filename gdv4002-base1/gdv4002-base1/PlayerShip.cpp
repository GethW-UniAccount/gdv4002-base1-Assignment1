#include "PlayerShip.h"

PlayerShip::PlayerShip()
{
	GameObject2D::position = glm::vec2(0,0);
	GameObject2D::orientation = 0.0f;
	GameObject2D::size = glm::vec2(0,0);
	GameObject2D::textureID = 0;
}

PlayerShip::PlayerShip(glm::vec2 initPos, float initRot, glm::vec2 initSize, GLuint initTextureID) {
	GameObject2D::position = initPos;
	GameObject2D::orientation = initRot;
	GameObject2D::size = initSize;
	GameObject2D::textureID = initTextureID;
	
}
void PlayerShip::update(double tDelta) {
	//input check - W
	if (InForward)
	{
		if (linearVelocity < speedCap)
		{
			linearVelocity += acceleration*tDelta;
		}
	}
	//input check - A
	if (InLeft)
	{
		if (rotationVelocity < turnSpeedCap)
		{
			rotationVelocity -= turnSpeed * tDelta;
		}
	}
	//input check - D
	if (InRight)
	{
		if (rotationVelocity < turnSpeedCap)
		{
			rotationVelocity += turnSpeed * tDelta;
		}
	}
	//input check - SPACE
	if (InFire)
	{
		if (firecooldown )
		{
			rotationVelocity += turnSpeed * tDelta;
		}
	}
}

