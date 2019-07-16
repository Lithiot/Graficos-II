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

std::vector<Node*>* Node::GetChildsVector() 
{
	if (childs == nullptr || childs->size() == 0)
	{
		return nullptr;
	}
	return childs;
}

Component * Node::GetComponentByType(Type type)
{
	for (int i = 0; i < components->size(); i++)
	{
		if (components->at(i)->GetType() == type)
		{
			return components->at(i);
		}
	}

	return NULL;
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

void Node::Move(float x, float y, float z)
{
	x = transform->position[0] + x;
	y = transform->position[1] + y;
	z = transform->position[2] + z;

	transform->Translate(x, y ,z);

	Camera* cam = (Camera*)GetComponentByType(Type::CAMERA);

	if (cam)
	{
		cam->SetPosition(transform->position);
	}
}

void Node::RotateX(float x) 
{
	Camera* cam = (Camera*)GetComponentByType(Type::CAMERA);

	if (cam)
	{
		cam->Yaw(x);
	}

	x = transform->rotation[0] + x;
	transform->SetRotationX(x);
}

void Node::RotateY(float y) 
{
	Camera* cam = (Camera*)GetComponentByType(Type::CAMERA);

	if (cam)
	{
		cam->Pitch(y);
	}

	y = transform->rotation[1] + y;
	transform->SetRotationY(y);
}

void Node::RotateZ(float z) 
{
	Camera* cam = (Camera*)GetComponentByType(Type::CAMERA);

	if (cam)
	{
		cam->Roll(z);
	}

	z = transform->rotation[2] + z;
	transform->SetRotationZ(z);
}