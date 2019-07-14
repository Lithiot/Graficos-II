#pragma once

#include "Component.h"
#include "Exports.h"
#include "MeshLoader.h"
#include "TextureLoader.h"

class ENGINE_API MeshComponent : public Component
{
private:
	char* texturePath;
	vector<MeshEntry> meshEntries;
	vector<InfoBMP> meshTextures;
	vector<unsigned int> buffersTextureID;

public:
	MeshComponent(string modelPath, string _texturePath, Renderer* rend);
	~MeshComponent();

	void Start() override;
	void Update() override;
	void Draw() override;
	void Destroy() override;
};

