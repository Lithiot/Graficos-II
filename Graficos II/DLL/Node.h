#pragma once
#include <string>
#include <vector>
#include "Transform.h"
#include "Renderer.h"
#include "Component.h"
class ENGINE_API Node
{
private:
	Renderer* rend;

	string name;
	Transform* transform;
	std::vector<Node*>* childs;
	std::vector<Component*>* components;
public:
	Node(string name, Renderer* rend);
	~Node();
	void AddChild(Node* child);
	void AddComponent(Component* component);
	Node* GetChildAtIndex(unsigned int i);
	void RemoveNodeAtIndex(unsigned int i);
	void Update();
	void Draw();
	string GetName();
	Transform* GetTransform();
};