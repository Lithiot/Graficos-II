#pragma once
#include "Entity.h"
#include "Material.h"
#include "TextureLoader.h"
class ENGINE_API Shape : public Entity
{
private:
	
protected:
	InfoBMP header;
	char type;
	float* vertexes;
	float* vertexColors;
	float* vertexUVTexture;
	int cantVertex;
	unsigned int vertexBufferID;
	unsigned int colorBufferID;
	unsigned int textureBufferId;
	unsigned int textureUVBufferId;
	Material* material;
	virtual void Draw() = 0;
public:
	Shape(Renderer* rend);
	~Shape();
	void SetMaterial(Material* mat);
	void SetColors(float* vColor, int cant);
	void SetVertex(float* vertex, int cant);

};