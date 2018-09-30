#pragma once
#include "Entity.h"
#include "Material.h"
class ENGINE_API Triangle : public Entity
{
private:
	float* vertexes;
	float* vertexColors;
	int cantVertex;
	unsigned int vertexBufferID;
	unsigned int colorBufferID;
	Material* material;
	void SetVertex(float* vertex, int cant);
public:
	Triangle (Renderer* rend);
	~Triangle ();
	void Draw() override;
	void SetColors(float* vColor, int cant);
	void SetMaterial (Material* mat);
};
