#include "Entity.h"

Entity::Entity(Renderer* rend) : renderer(rend), mvp(GenerateMVP())
{
}

Entity::~Entity()
{
}

glm::mat4 Entity::GenerateMVP() 
{
	glm::mat4 Projection = glm::perspective(glm::radians(45.0f), 4.0f / 3.0f, 0.1f, 100.0f);

	glm::mat4 View = glm::lookAt(
		glm::vec3(4, 3, 3),
		glm::vec3(0, 0, 0),
		glm::vec3(0, 1, 0) 
	);

	glm::mat4 Model = glm::mat4(1.0f);
	
	glm::mat4 mvp = Projection * View * Model;

	return mvp;
}