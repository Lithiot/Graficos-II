#pragma once
#include <string>
#include <vector>
#include "Transform.h"
#include "Renderer.h"
class Node
{
private:
	Renderer* rend;

	string name;
	Transform* transform;
	std::vector<Node*>* childs;
public:
	Node(string name, Renderer* rend);
	~Node();
	void AddChild(Node* child);
	Node* GetChildAtIndex(unsigned int i);
	void RemoveNodeAtIndex(unsigned int i);
	void Update();
	void Draw();
	string GetName();
};