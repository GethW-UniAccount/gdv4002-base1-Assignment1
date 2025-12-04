#pragma once

#include "GameObject2D.h"
class PlayerShip : public GameObject2D {

public:
	//idea to use Enums from C++ Forums and Medium:
	//https://cplusplus.com/forum/general/1590/
	//https://dietertack.medium.com/using-bit-flags-in-c-d39ec6e30f08
	//  "00000000 -> Our current flag value is 0
	//| 00000100->Do or operation with Flag3, which has a value of 4
	//	= 00000100->The bit for Flag3 gets set to 1, flag value is now 4"
	static enum Inputs {
		InForward	= 0x01,
		InLeft		= 0x02,
		InDown		= 0x04,
		InRight		= 0x08,
		InFire		= 0x10
		//Unused		= 0x20,
		//Unused		= 0x40,
		//Unused		= 0x80,
	};
	float		acceleration = 1.0f;
	float		fireRate = 1.0f;
	int			extraLives = 2;
	bool		shield = false;
	bool		scatterLaser = false;
	PlayerShip();
	PlayerShip(glm::vec2 initPos, float initRot, glm::vec2 initSize, GLuint initTextureID);
	virtual void update(double tDelta) override;
private:
	glm::vec2		velocity = glm::vec2(0,0);
	float			angularVelocity = 0.0f;
};