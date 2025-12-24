#include "PlayerShip.h"
#include "Engine.h"
PlayerShip::PlayerShip()
{
	GameObject2D::position = glm::vec2(0,0);
	GameObject2D::orientation = 0.0f;
	GameObject2D::size = glm::vec2(0.25f,0.25f);
	GameObject2D::textureID = loadTexture("Resources\\Textures\\Ship.png");
}

PlayerShip::PlayerShip(glm::vec2 initPos, float initRot, glm::vec2 initSize, GLuint initTextureID) {
	GameObject2D::position = initPos;
	GameObject2D::orientation = initRot;
	GameObject2D::size = initSize;
	GameObject2D::textureID = initTextureID;
	
}
void PlayerShip::Fire() {

}



void PlayerShip::update(double tDelta) {

	
	//position update
	//THANK YOU, https://www.mathsisfun.com/polar-cartesian-coordinates.html
	velocity = glm::vec2((cos(orientation) * linearVelocity), (sin(orientation) * linearVelocity));

	//update it FPS-independently via TDelta, casted to float
	//Thank you, https://www.geeksforgeeks.org/cpp/casting-operators-in-cpp/
	position += velocity * static_cast<float>(tDelta);

	//Decay velocity based on TDelta
	velocity -= (0.1f * static_cast<float>(tDelta));
	//Cooldown for firing
	if (firecooldown > 0.0001)
	{
		firecooldown -= (0.1 * tDelta);
	}
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
		if (firecooldown < 0.0001)
		{
			Fire();
		}
	}
	std::cout << "\nLinearVelocity\n"
		<< linearVelocity
		<< "\nRotationVelocity\n"
		<< rotationVelocity
		<< "\nvelocity as Vector\n"
		<< velocity.x
		<< "\n"
		<< velocity.y;
		

	//This section is for textures, it's a lot of if statements that will be a pain to untangle,
	//though unfortunately, I don't see much of an alternative, i may just leave this out and use the one base ship texture and its shielded variant instead though.

	render();
}

