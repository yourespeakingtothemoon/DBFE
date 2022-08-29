#include "Engine.h"
#include "DinoGame.h"
#include <iostream>

int main()
{
	dbf::initializeMemory();
	dbf::SetFilePath("../Assets");

	//systems initilization
	dbf::g_renderer.init();
	dbf::g_inputSystem.init();
	dbf::g_audioSystem.init();
	dbf::g_physicsSystem.init();
	dbf::g_resourceManager.init();

	dbf::Engine::instance().reg();

	//render window
	int width = 800;
	int height = 600; 
	dbf::g_renderer.generateWindow("DinoTest", width, height);
	dbf::g_renderer.setClearColor(dbf::Color::black);
	std::unique_ptr<DinoGame> game = std::make_unique<DinoGame>();
	game->init();

	bool exit = false;
	//start loop
	while (!exit)
	{
		//systems update
		dbf::g_time.gameTick();
		dbf::g_inputSystem.update();
		dbf::g_audioSystem.update();
		dbf::g_physicsSystem.update();
		//test for exit
		if (dbf::g_inputSystem.queryKeyDown(dbf::key_escape)) exit = true;
		//game update
		game->update();
		//draw screen
		dbf::g_renderer.openFrame();
		game->draw(dbf::g_renderer);
		dbf::g_renderer.closeFrame();
	}
	game->shutdown();
	game.reset();

	dbf::Factory::instance().shutdown();

	//exit
	dbf::g_resourceManager.shutdown();
	dbf::g_physicsSystem.shutdown();
	dbf::g_audioSystem.shutdown();
	dbf::g_inputSystem.shutdown();
	dbf::g_renderer.shutdown();
}


