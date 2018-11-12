#include "Square.h"

Square::Square(Renderer* rend) : Shape(rend)
{
	type = 's';
	cantVertex = 4;

	vertexes = new float[cantVertex * 3]{
		-1.0f, -1.0f, 0.0f,
		1.0f, -1.0f, 0.0f,
		-1.0f,  1.0f, 0.0f,
		1.0f, 1.0f, 0.0f
	};

	vertexColors = new float[cantVertex * 3]{
		0.583f,  0.771f,  0.014f,
		0.609f,  0.115f,  0.436f,
		0.327f,  0.483f,  0.844f,
		0.822f,  0.569f,  0.201f,
	};

	SetVertex(vertexes, cantVertex);
	SetColors(vertexColors, cantVertex);
}

Square::~Square()
{
}