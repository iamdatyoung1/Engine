#include "GameScene.h"
//come back to this
GameScene::GameScene()  :shape(nullptr)
{
}

GameScene::~GameScene()
{
	delete shape;
	shape = nullptr;
}

bool GameScene::OnCreate()
{
	Debug::Info("Creating GameScene", "GameScene.cpp", __LINE__);

	Vertex v;
	std::vector<Vertex> vertexList;
	//reservers the element
	//first triangle
	vertexList.reserve(6);
	v.position = glm::vec3(0.5f, 0.5f, 0.0f);
	v.colour = glm::vec3(1.0f, 0.0f, 0.0f);
	vertexList.push_back(v);
	v.position = glm::vec3(-0.5f, -0.5f, 0.0f);
	v.colour = glm::vec3(1.0f, 2.0f, 0.0f);
	vertexList.push_back(v);
	v.position = glm::vec3(0.5f, -0.5f, 0.0f);
	v.colour = glm::vec3(1.0f, 0.0f, 3.0f);
	vertexList.push_back(v);
	//second triangle
	v.position = glm::vec3(-0.5, 0.5, 0.0f);
	v.colour = glm::vec3(1.0f, 0.0f, 0.0f);
	vertexList.push_back(v);
	v.position = glm::vec3(-0.5, -0.5, 0.0f);
	v.colour = glm::vec3(1.0f, 2.0f, 0.0f);
	vertexList.push_back(v);
	v.position = glm::vec3(0.5, 0.5, 0.0f);
	v.colour = glm::vec3(1.0f, 0.0f, 3.0f);
	vertexList.push_back(v);

	//passes shader name
	Model* model = new Model(ShaderHandler::GetInstance()->GetShader("colourShader"));
	model->AddMesh(new Mesh(vertexList));
	shape = new GameObject(model);
	return true;
}

void GameScene::Update(const float deltaTime_)
{
}

void GameScene::Render()
{
	shape->Render();
}
