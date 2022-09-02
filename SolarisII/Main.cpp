#include "Player.h"
#include "Enemy.h"
#include "Solaris2.h"
#include "Engine.h"

#include <iostream>
#include <vector>
#include <array>
#include <list>
#include <algorithm>


using namespace std;

int main()
{
	dbf::initalizeMemory();

	dbf::SetFilePath("../Assets");

	// create window
	dbf::g_renderer.CreateWindow("Solaris II", 800, 800);
	dbf::g_renderer.SetClearColor(dbf::Color{ 0, 0, 0, 255 });
	// initialize systems
	dbf::g_renderer.Initialize();
	dbf::g_inputSystem.initialize();
	dbf::g_audio.Initialize();

	{
		bool quit = false;
			while (!quit) {
				Solaris2 game;
				game.Initialize();

				//float spawnTimer = 3;
				bool reset = false;
				//bool end = false;
				while (!reset)
				{
					/*if (dbf::g_inputSystem.getKeyState(dbf::key_enter) == dbf::inpSystem::keyState::Pressed)
					{
						if (!pause) {
							pause = true;
						}if (pause) {
							pause = false;
						}

					}*/
					if (game.end && dbf::g_inputSystem.getKeyState(dbf::key_enter) == dbf::inpSystem::keyState::Pressed) {
						reset = true;
					}
					if (dbf::g_inputSystem.getKeyState(dbf::key_escape) == dbf::inpSystem::keyState::Pressed) { reset = true; quit = true; };
					// update (engine)
					dbf::g_inputSystem.update();

					dbf::g_time.gameTick();
					dbf::g_audio.Update();
					game.Update();

					// render
					dbf::g_renderer.BeginFrame();

					game.Draw(dbf::g_renderer);

					dbf::g_renderer.EndFrame();

				}
			}
	}
	dbf::g_renderer.Shutdown();
	dbf::g_audio.Shutdown();
}
