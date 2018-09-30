#pragma once
#include "Entity.h"
#include "Material.h"
class ENGINE_API Square : public Entity
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
	Square(Renderer* rend);
	~Square();
	void Draw() override;
	void SetMaterial(Material* mat);
	void SetColors(float* vColor, int cant);
};

