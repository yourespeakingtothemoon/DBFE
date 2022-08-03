#include "Engine.h"

#include <iostream>
#include <vector>
#include <array>
#include <list>
#include <algorithm>

using namespace std;

int main()
{
	//std::cout << "Preeow World!" << std::endl;
	

//init mem
	dbf::initalizeMemory();

//file
	dbf::SetFilePath("../Assets");

//Engine init
	// initialize systems
	dbf::g_renderer.Initialize();
	dbf::g_inputSystem.initialize();
	dbf::g_audio.Initialize();
	// create window
	dbf::g_renderer.CreateWindow("Drachenblut FE", 800, 800);
	dbf::g_renderer.SetClearColor(dbf::Color{ 255, 10, 100, 255 });
	std::shared_ptr<dbf::Texture> dbfeLogo = std::make_shared<dbf::Texture>();
	dbfeLogo->Create(dbf::g_renderer, "Images/logo.png");
	bool quit = false;
//game loop
	while (!quit)
	{
		//update
		dbf::g_time.gameTick();
		dbf::g_inputSystem.update();
		dbf::g_audio.Update();
		//check for esc
		if (dbf::g_inputSystem.getKeyState(dbf::key_escape) == dbf::inpSystem::keyState::Pressed) quit = true;
		
		// render
		dbf::g_renderer.BeginFrame();
		dbf::g_renderer.Draw(dbfeLogo, { 200, 200 }, 0);
		dbf::g_renderer.EndFrame();
}
	dbf::g_inputSystem.shutdown();
	dbf::g_renderer.Shutdown();
	dbf::g_audio.Shutdown();
}

