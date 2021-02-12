#include "Model.h"

Model::Model() : meshes(std::vector<Mesh*>())
{
}

Model::~Model()
{
	if (meshes.size() > 0) {
		//This will create temp local var
		//auto means will auto set key type
		//auto is not needed but do it anyways
		for (auto m : meshes) {
			delete m;
			m = nullptr;
		}
		meshes.clear();
	}
}

void Model::Render()
{
	//render child meshes
	for (auto m : meshes) {
		m->Render();
	}
}

void Model::AddMesh(Mesh* mesh_)
{
	//adds the mesh
	meshes.push_back(mesh_);
}
