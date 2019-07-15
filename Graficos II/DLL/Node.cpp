#include "Node.h"

Node::Node(string name, Renderer* rend) : childs(new std::vector<Node*>), components(new std::vector<Component*>), transform(new Transform(rend)), name(name), rend(rend)
{
	AddComponent(transform);
}

Node::~Node()
{
	delete childs;
}

void Node::AddChild(Node* child) 
{
	childs->push_back(child);
}

void Node::AddComponent(Component* component) 
{
	components->push_back(component);
}

Node* Node::GetChildAtIndex(unsigned int i)
{
	return childs->at(i);
}

void Node::RemoveNodeAtIndex(unsigned int i)
{
	int size = childs->size() - 1;
	delete childs->at(i);
	childs->resize(size);
}

void Node::Update() 
{
	for (int i = 0; i < components->size(); i++)
	{
		components->at(i)->Update();
	}

	for (int i = 0; i < childs->size(); i++)
	{
		childs->at(i)->Update();
	}
}

void Node::Draw() 
{
	glm::mat4 originalModel = rend->GetModel();
	glm::mat4 originalProjection = rend->GetProjection();
	glm::mat4 originalView = rend->GetViewMatrix();
	rend->MultiplyModel(transform->GetModel());

	for (int i = 0; i < components->size(); i++)
	{
		components->at(i)->Draw();
	}

	for (int i = 0; i < childs->size(); i++)
	{
		childs->at(i)->Draw();
	}

	rend->SetModel(originalModel);
	rend->SetViewMatrix(originalView);
	rend->SetProjectionMatrix(originalProjection);
}

string Node::GetName() 
{
	return name;
}

Transform* Node::GetTransform() 
{
	return transform;
}