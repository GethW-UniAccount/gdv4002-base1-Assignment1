#pragma once

#include "GameObject2D.h"
class Asteroid : public GameObject2D {

public:
	Asteroid();
	Asteroid(glm::vec2 initPos, float initRot, glm::vec2 initSize, GLuint initTextureID);
	Asteroid(glm::vec2 initPos, float initRot, glm::vec2 initSize, GLuint initTextureID, glm::vec2 initVelocity);
	virtual void update(double tDelta) override;
private:
	glm::vec2		velocity = glm::vec2(0, 0);
	float			rotationVelocity = 0.0f;
	float			linearVelocity = 0.0f;
	float			firecooldown = 0.0f;
};