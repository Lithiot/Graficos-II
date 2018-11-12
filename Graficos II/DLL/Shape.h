#pragma once
#include "Entity.h"
#include "Material.h"
class ENGINE_API Shape : public Entity
{
private:

protected:
	char type;
	float* vertexes;
	float* vertexColors;
	float* vertexTexture;
	int cantVertex;
	unsigned int vertexBufferID;
	unsigned int colorBufferID;
	unsigned int textureBufferId;
	Material* material;
	virtual void Draw() = 0;
public:
	Shape(Renderer* rend);
	~Shape();
	void SetMaterial(Material* mat);
	void SetColors(float* vColor, int cant);
	void SetVertex(float* vertex, int cant);
	void SetTextures(float* vertex, int cant);
};