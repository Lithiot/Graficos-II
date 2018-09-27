#pragma once
#include "Entity.h"
#include "Material.h"
class ENGINE_API Triangle : public Entity
{
private:
	float* vertexes;
	int cantVertex;
	unsigned int bufferID;
	Material* material;
protected:

public:
	Triangle (Renderer* rend);
	~Triangle ();
	void Draw() override;
	void setVertex (float* vertex, int cant);
	void SetMaterial (Material* mat);
};

