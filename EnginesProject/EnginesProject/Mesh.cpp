#include "Mesh.h"
//VBO and VAO has to be 0 cause it cant go higher
// sets to empty vector


Mesh::Mesh(std::vector<Vertex>& vertexList_) : VAO(0), VBO(0), vertexList(std::vector<Vertex>())
{
	vertexList = vertexList_;
	GenerateBuffers();
}

Mesh::~Mesh()
{
	//deletes the vao and vbo because opengl has its own way of deleteting
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	//clearing vertex list
	vertexList.clear();
}

void Mesh::Render()
{
	glBindVertexArray(VAO);

	glDrawArrays(GL_TRIANGLES, 0, vertexList.size());

	glBindVertexArray(0);
}

void Mesh::GenerateBuffers()
{
	//generate our vao and vbo
	//only want to make 1
	//Vbo hold the data and vao splits it up
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glBindVertexArray(VAO);
	//We are then binding it to array buffer
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, vertexList.size() * sizeof(Vertex),
		&vertexList[0], GL_STATIC_DRAW);

	//Position
	glEnableVertexAttribArray(0);
	//this tells us how its created
	//first part is the position and the second is the size
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)0);

	//Normal
	//we increase each time
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)offsetof(Vertex, normal));

	//Tex Coords
	glEnableVertexAttribArray(2);
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)offsetof(Vertex, textureCoordinates));

	//colour
	//bind the buffer rate to zero
	glEnableVertexAttribArray(3);
	glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)offsetof(Vertex, colour));

	glBindVertexArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}
