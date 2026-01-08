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
			
		}
	}
	//input check - A
	if (InLeft)
	{
		GameObject2D::orientation -= (1 * tDelta);
	}
	//input check - D
	if (InRight)
	{
		GameObject2D::orientation += (1 * tDelta);
	}
	//input check - SPACE
	if (InFire)
	{
		if (firecooldown < 0.0001)
		{
			Fire();
		}
	}
	
		

	//This section is for textures, it's a lot of if statements that will be a pain to untangle,
	//though unfortunately, I don't see much of an alternative, i may just leave this out and use the one base ship texture and its shielded variant instead though.

	render();
}

