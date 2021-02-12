#ifndef MESH_H
#define MESH_H
//acces to all opengl api
#include <glew.h>
//dynamic size array
#include <vector>
//anytime want to acces start with glm/glm the hpp means its a c++ file
#include <glm/glm.hpp>


struct Vertex {
	//you could use using namespace
	glm::vec3 position;
	glm::vec3 normal;
	//has to be vec2
	glm::vec2 textureCoordinates;
	//it will be removed later but for now keep
	glm::vec3 colour;

};
class Mesh
{
public: 
	//taking in a vector of type vertex
	Mesh(std::vector<Vertex>& vertexList_);
	~Mesh();

	void Render();

private:
	void GenerateBuffers();
	//VAO stands for vertex array object and VBO stands for object buffer
	GLuint VAO, VBO;
	std::vector<Vertex> vertexList;
};
#endif
