#include "MeshImporter.h"

//MeshEntry::MeshEntry() : vertexBuffer(NULL), indexBuffer(NULL), cantIndex(0)
//{
//}
//
//MeshEntry::~MeshEntry()
//{
//	if (vertexBuffer)
//		glDeleteBuffers(1, &vertexBuffer);
//	if (indexBuffer)
//		glDeleteBuffers(1, &indexBuffer);
//}
//
//void MeshEntry::Init(const vector<Vertex>& vertex, const vector<unsigned int>& index, Renderer* rend)
//{
//	cantIndex = index.size();
//	float* meshPositions = new float[vertex.size() * 3];
//	float* meshTextures = new float[vertex.size() * 2];
//	float* meshNormals = new float[vertex.size() * 3];
//
//	for (int i = 0; i < vertex.size(); i++)
//	{
//		meshPositions[i * 3] = vertex[i].vertexPos.x;
//		meshPositions[i * 3 + 1] = vertex[i].vertexPos.y;
//		meshPositions[i * 3 + 2] = vertex[i].vertexPos.z;
//
//		meshTextures[i * 2] = vertex[i].vertexTexture.x;
//		meshTextures[i * 2 + 1] = vertex[i].vertexTexture.y;
//
//		meshNormals[i * 3] = vertex[i].vertexNormal.x;
//		meshNormals[i * 3 + 1] = vertex[i].vertexNormal.y;
//		meshNormals[i * 3 + 2] = vertex[i].vertexNormal.z;
//	}
//
//	vertexBuffer = rend->GenVertexBuffer(meshPositions, sizeof(float) * vertex.size() * 3);
//	indexBuffer = rend->GenIndexBuffer(index);
//	uvBuffer = rend->GenVertexBuffer(meshTextures, sizeof(float) * vertex.size() * 2);
//}