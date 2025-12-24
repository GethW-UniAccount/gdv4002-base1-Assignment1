#pragma once

#include "GameObject2D.h"
class Asteroid : public GameObject2D {

public:
	
	float		acceleration = 0.1f;
	float		speedCap = 10.0f;
	float		turnSpeed = 1.0f;
	float		turnSpeedCap = 10.0f;
	float		fireRate = 1.0f;
	int			extraLives = 2;
	bool		shield = false;
	bool		scatterLaser = false;
	Asteroid();
	Asteroid(glm::vec2 initPos, float initRot, glm::vec2 initSize, GLuint initTextureID);
	virtual void update(double tDelta) override;
private:
	glm::vec2		velocity = glm::vec2(0, 0);
	float			rotationVelocity = 0.0f;
	float			linearVelocity = 0.0f;
	float			firecooldown = 0.0f;
};