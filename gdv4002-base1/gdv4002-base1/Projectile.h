#pragma once

#include "GameObject2D.h"
class Projectile : public GameObject2D {

public:
	Projectile();
	Projectile(glm::vec2 initPos, float initRot);
	virtual void update(double tDelta) override;
private:
	glm::vec2		velocity = glm::vec2(0, 0);
	float speed = 2;
};