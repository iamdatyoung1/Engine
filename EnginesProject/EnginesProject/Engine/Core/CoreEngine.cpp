#include "CoreEngine.h"

std::unique_ptr<CoreEngine> CoreEngine::engineInstance = nullptr;

CoreEngine::CoreEngine() : window(nullptr), isRunning(false)
{
}

CoreEngine::~CoreEngine()
{
}

CoreEngine* CoreEngine::GetInstance() 
{
	if (engineInstance.get() == nullptr) {
		engineInstance.reset(new CoreEngine);
	}
	return engineInstance.get();
}

bool CoreEngine::OnCreate(std::string name_, int width_, int height_)
{
	window = new Window();
	//create window
	if (!window->OnCreate(name_, width_, height_)) {
		std::cout << "Window failed to initialize" << std::endl;
		//Destroy it to clean up
		OnDestroy();
		//return to vaule of false
		return isRunning = false;

	}
	//if the creation of the winodw works prroperly then return isRunning varrible to true 
	return isRunning = true;
}

void CoreEngine::Run()
{
	//Loop isRunning constaly update and render
	while (isRunning) {
		//always call update before anything for the purpose of always updating time
		//0.016 is actually 60 frames the reaon is because 1 deived by 60 would give you this number
		Update(0.016f);
		Render();
	}
	//if isRunning is not set in motion then just Destroy
	//dont really need !isrunning but we use it anyways to make it perfectly clear
	if (!isRunning) {
		OnDestroy();
	}
}

bool CoreEngine::GetIsRunning()
{

	return isRunning;
}

void CoreEngine::Update(const float deltaTime_)
{

}

void CoreEngine::Render()
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//Call Game Render
	SDL_GL_SwapWindow(window->GetWindow());

}

void CoreEngine::OnDestroy()
{
	delete window;
	window = nullptr;
	SDL_Quit();
	exit(0);
}
