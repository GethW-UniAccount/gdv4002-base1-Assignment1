#pragma once

#include "GameObject2D.h"
class PlayerShip : public GameObject2D {

public:
	//idea to use Enums from C++ Forums and Medium:
	//https://cplusplus.com/forum/general/1590/
	//https://dietertack.medium.com/using-bit-flags-in-c-d39ec6e30f08
	// "
	//	  00000000 -> Our current flag value is 0
	//	| 00000100 ->Do or operation with Flag3, which has a value of 4
	//	= 00000100 ->The bit for Flag3 gets set to 1, flag value is now 4
	// "

	//inputs:

	bool InForward;//W
	bool InLeft;//A
	bool InDown;//S
	bool InRight;//D
	bool InFire;//SPACE

	float		speedCap = 10.0f;
	float		turnSpeedCap = 10.0f;
	float		fireRate = 1.0f;
	PlayerShip();
	PlayerShip(glm::vec2 initPos, float initRot, glm::vec2 initSize, GLuint initTextureID);
	virtual void update(double tDelta) override;
private:
	glm::vec2		velocity = glm::vec2(0,0);
	float			rotationVelocity = 0.0f;
	float			linearVelocity = 0.0f;
	float			firecooldown = 0.0f;
	void Fire();
};