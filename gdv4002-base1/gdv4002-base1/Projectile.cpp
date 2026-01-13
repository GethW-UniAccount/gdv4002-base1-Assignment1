#include "Projectile.h"
#include "Engine.h"
Projectile::Projectile()
{
	GameObject2D::position = glm::vec2(0, 0);
	GameObject2D::orientation = 0.0f;
	GameObject2D::size = glm::vec2(0.1f, 0.1f);
	GameObject2D::textureID = 4;
}
Projectile::Projectile(glm::vec2 initPos,float initRot)
{
	GameObject2D::position = initPos;
	GameObject2D::orientation = initRot;
	GameObject2D::size = glm::vec2(0.1f, 0.1f);
	GameObject2D::textureID = 4;
}
void Projectile::update(double tDelta) {

	//position update

	//update it FPS-independently via TDelta, casted to float
	//Thank you, https://www.geeksforgeeks.org/cpp/casting-operators-in-cpp/

	//Thanks, https://www.geeksforgeeks.org/dsa/program-to-convert-polar-co-ordinates-to-equivalent-cartesian-co-ordinates/
	//conversion form Polar coordinates to Cartesian
	velocity = glm::vec2(speed* cos(orientation), speed * sin(orientation));
	
	glm::vec2 VelocityTDelta = glm::vec2(velocity.x * tDelta, velocity.y * tDelta);

	position += (VelocityTDelta);

	
	//Delete when offscreen
	if (position.x > 3)
	{
		DeleteThis = true;
	}
	else if (position.x < -3)
	{
		DeleteThis = true;
	}
	if (position.y > 3)
	{
		DeleteThis = true;
	}
	else if (position.y < -3)
	{
		DeleteThis = true;
	}
	//additional way to delete the object,
	//since traditional position-based deletion seems not to work,
	//we delete it after 3 seconds.
	Timer += tDelta;

	render();
}
