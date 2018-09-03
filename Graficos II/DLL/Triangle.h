#pragma once
#include "Entity.h"
#include "Material.h"
class Triangle : public Entity
{
private:
	float* vertexes;
	float* bufferID;
	Material* material;
protected:
	Triangle();
public:
	
	void Draw() override;

	~Triangle();
};

