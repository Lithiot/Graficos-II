#pragma once
#include <vector>
class Node
{
private:
	std::vector<Node*>* childs;
public:
	Node();
	~Node();
	void AddChild(Node* child);
	Node* GetChildAtIndex(unsigned int i);
	void RemoveNodeAtIndex(unsigned int i);
	void Update();
	void Draw();
};