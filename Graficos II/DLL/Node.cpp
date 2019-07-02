#include "Node.h"

Node::Node() : childs(new std::vector<Node*>)
{
}

Node::~Node()
{
	delete childs;
}

void Node::AddChild(Node* child) 
{
	childs->push_back(child);
}

Node* Node::GetChildAtIndex(unsigned int i)
{
	return childs->at(i);
}

void Node::RemoveNodeAtIndex(unsigned int i) 
{
	int size = childs->size - 1;
	delete childs->at(i);
	childs->resize(size);
}

void Node::Update() 
{
	for (int i = 0; i < childs->size; i++)
	{
		childs->at(i)->Update();
	}
}
void Node::Draw() 
{
	for (int i = 0; i < childs->size; i++)
	{
		childs->at(i)->Draw();
	}
}
