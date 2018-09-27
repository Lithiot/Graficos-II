#pragma once
#include "Exports.h"
#include <glm/gtc/matrix_transform.hpp>

class ENGINE_API Material
{
private:
	unsigned int programID;
public:
	Material();
	~Material();
	unsigned int LoadShaders(const char* vertex_file_path, const char* fragment_file_path);
	void Bind(glm::mat4 mvp);
};

