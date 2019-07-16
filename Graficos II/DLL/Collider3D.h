#pragma once
#include "Exports.h"
#include "Renderer.h"
#include <iostream>
#include "../external/glm-0.9.9.0/glm/glm.hpp"
#include "../external/glm-0.9.9.0/glm/gtc/matrix_transform.hpp"

using namespace std;
using namespace glm;

#define CANT_COLLIDER_VERTEX 8

class ENGINE_API Collider3D
{
private:
	vec3 collider3d [CANT_COLLIDER_VERTEX];
	Renderer* rend;
public:
	Collider3D(Renderer* rend);
	~Collider3D();

	vec3 GetVertex(int index);
	void SetVertex(glm::vec3 _collider3d[CANT_COLLIDER_VERTEX]);
	bool loaded;
};

