#pragma once

#include "GameObject2D.h"
class ReferencePoint : public GameObject2D {

public:
	ReferencePoint();
	ReferencePoint(glm::vec2 initPos, float initRot, glm::vec2 initSize, GLuint initTextureID);
	virtual void update(double tDelta) override;
private:
	float TimeToAsteroid = 0;
	float AsteroidThreshold = 2;
};