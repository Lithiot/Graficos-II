#pragma once
#include <string>
#include "Exports.h"
#include "Renderer.h"

using namespace std;

class Node;

enum Type 
{
	MESH_COMPONENT, CAMERA, TRANSFORM
};

class ENGINE_API Component
{
private:
	string name;
	Type type;
protected:
	Renderer* rend;
	Node* owner;

public:
	Component(Renderer* renderer, Type type);
	~Component();

	virtual void Start() = 0;
	virtual void Destroy() = 0;
	virtual bool Draw() = 0;
	virtual void Update() = 0;

	string GetName();
	Type GetType();
	Node* GetOwner();

	void SetOwner(Node* _owner);
};

