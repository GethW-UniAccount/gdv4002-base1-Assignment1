#include "PlayerShip.h"
#include "Engine.h"
#include "Projectile.h"
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



void PlayerShip::update(double tDelta) {

	
	velocity = glm::vec2(linearVelocity * cos(orientation), linearVelocity * sin(orientation));

	glm::vec2 VelocityTDelta = glm::vec2(velocity.x * tDelta, velocity.y * tDelta);

	//apply velocity
	position += VelocityTDelta;
	orientation += rotationVelocity;
	
	//Decay velocity based on TDelta
	float velocityDecay = 1.0f * static_cast<float>(tDelta);
	if (velocity.x > 0.0f)
	{
		velocity.x -= velocityDecay;
	}
	else if (velocity.x < 0.0f)
	{
		velocity.x += velocityDecay;
	}
	if (velocity.y > 0.0f)
	{
		velocity.y -= velocityDecay;
	}
	else if (velocity.y < 0.0f)
	{
		velocity.y += velocityDecay;
	}
	if (rotationVelocity > 0.0f)
	{
		rotationVelocity -= velocityDecay;
	}
	else if (rotationVelocity < 0.0f)
	{
		rotationVelocity += velocityDecay;
	}
	//Cooldown for firing
	if (firecooldown > 0.01f)
	{
		firecooldown -= (0.1f * tDelta);
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
			rotationVelocity -= (1.0f * tDelta);
		}
	}
	//input check - D
	if (InRight)
	{
		rotationVelocity += (1.0f * tDelta);
	}
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
		if (firecooldown < 0.01f)
		{
			Fire();
			firecooldown = 1.0f;
		}
	}
	
	if (position.x > 3.0f) //576px
	{
		position.x = -2.75f; //544px
	}
	else if (position.x < -3.0f) //576px
	{
		position.x = 2.75; //544px
	}
	if (position.y > 3.0f) //576px
	{
		position.y = -2.75; //544px
	}
	else if (position.y < -3.0f) //576px
	{
		position.y = 2.75; //544px
	}

	render();
}

