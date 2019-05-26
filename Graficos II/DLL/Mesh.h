#pragma once

#include "Shape.h"
#include "Exports.h"
#include "MeshLoader.h"
#include "TextureLoader.h"

class ENGINE_API Mesh : public Shape
{
private:
	char* texturePath;
	vector<MeshEntry> meshEntries;
	vector<InfoBMP> meshTextures;
	vector<unsigned int> buffersTextureID;

public:
	void Draw() override;
	void Update();
	Mesh(string _modelPath, string _texturePath, Renderer* _renderer);
	~Mesh();
};

