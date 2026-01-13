#include "PlayerShip.h"
#include "Engine.h"
#include "Projectile.h"
#include <string>
PlayerShip::PlayerShip()
{
	GameObject2D::position = glm::vec2(0,0);
	GameObject2D::orientation = 0.0f;
	GameObject2D::size = glm::vec2(0.25f,0.25f);
	GameObject2D::textureID = 1;
	InForward = false;
	InLeft = false;
	InDown = false;
	InRight = false;
	InFire = false;
}

PlayerShip::PlayerShip(glm::vec2 initPos, float initRot, glm::vec2 initSize, GLuint initTextureID) {
	GameObject2D::position = initPos;
	GameObject2D::orientation = initRot;
	GameObject2D::size = initSize;
	GameObject2D::textureID = initTextureID;
	InForward = false;
	InLeft = false;
	InDown = false;
	InRight = false;
	InFire = false;
}
void PlayerShip::Fire() {
	Projectile* Laser = new Projectile(position, orientation);
	addObject("LaserProjectile", Laser);
}



void PlayerShip::update(double tDelta)
{
	glm::vec2 velocityToAdd;

	velocityToAdd = glm::vec2(linearVelocity * cos(orientation), linearVelocity * sin(orientation));
	
	velocity += velocityToAdd;
	glm::vec2 VelocityTDelta = glm::vec2(velocity.x * tDelta, velocity.y * tDelta);
	


	if (velocity.x > speedCap)
	{
		velocity.x = speedCap;
	}
	else if (velocity.x < (speedCap * -1))
	{
		velocity.x = (speedCap * -1);
	}
	if (velocity.y > speedCap)
	{
		velocity.y = speedCap;
	}
	else if (velocity.y < (speedCap * -1))
	{
		velocity.y = (speedCap * -1);
	}

	//Decay velocity based on TDelta
	float velocityDecayX = (velocity.x * -5.0f) * static_cast<float>(tDelta);
	float velocityDecayY = (velocity.y * -5.0f) * static_cast<float>(tDelta);
	float velocityDecayR = (rotationVelocity * -1.0f) * static_cast<float>(tDelta);

		if (velocity.x > 0.0f || velocity.x < 0.0f)
		{
			velocity.x += velocityDecayX;
		}
		if (velocity.y > 0.0f || velocity.y < 0.0f)
		{
			velocity.y += velocityDecayY;
		}
		if (rotationVelocity > 0.0f || rotationVelocity < 0.0f)
		{
			rotationVelocity += velocityDecayR;
		}
		
	

	

	//apply velocity
	position += VelocityTDelta;
	orientation += rotationVelocity;

	//Cooldown for firing
	if (firecooldown > 0.1f)
	{
		firecooldown -= static_cast<float>(tDelta);
	}

	//input check - W
	if (InForward)
	{
		if (linearVelocity < speedCap)
		{
			linearVelocity += (0.25f * tDelta);
		}
		
	}
	
	//input check - A
	if (InLeft)
	{
		if (rotationVelocity < turnSpeedCap)
		{
			rotationVelocity += (0.25f * tDelta);
			
		}
		
	}
	
	//input check - D
	if (InRight)
	{
		if (rotationVelocity > (-turnSpeedCap))
		{
			rotationVelocity -= (0.25f * tDelta);
			
		}
		
	}
	//input check - S
	if (InDown)
	{
		if (linearVelocity < turnSpeedCap)
		{
			linearVelocity -= (0.25 * tDelta);
			
		}
		
	}
	//input check - SPACE
	if (InFire)
	{
		if (firecooldown < 0.1f)
		{
			Fire();
			firecooldown = 1.5f;
		}
		std::cout << (firecooldown);
	}
	
	

	//wrap-around
	if (position.x > 3.0f) {
		position.x = -2.75f;
	}
	if (position.x < -3.0f) {
		position.x = 2.75f;
	}
	if (position.y > 3.0f) {
		position.y = -2.75f;
	}
	if (position.y < -3.0f) {
		position.y = 2.75f;
	}
	
	render();
	
}

