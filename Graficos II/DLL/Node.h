#pragma once
#include <string>
#include <vector>
#include "Transform.h"
#include "Renderer.h"
#include "Camera.h"

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
	std::vector<Node*>* GetChildsVector();
	Component* GetComponentByType(Type type);
	void RemoveNodeAtIndex(unsigned int i);
	void Update();
	void Draw();
	string GetName();
	Transform* GetTransform();
	void Move(float x, float y, float z);
	void RotateX(float x);
	void RotateY(float y);
	void RotateZ(float z);
};