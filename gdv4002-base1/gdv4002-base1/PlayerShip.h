#pragma once

#include "GameObject2D.h"
class PlayerShip : public GameObject2D {

public:

	//Player speed
	float		Acceleration = 1.0f;
	float		FireRate = 1.0f;
	int			ExtraLives = 2;
	bool		Shield = false;
	bool		ScatterLaser = false;
	PlayerShip();
	PlayerShip(glm::vec2 initPos, float initRot, glm::vec2 initSize, GLuint initTextureID);
};