#include "Solaris2.h"
#include "Player.h"
#include "Enemy.h"
#include "Pickup.h"
#include "Flare.h"
#include "Engine.h"
//#include <>

void Solaris2::Initialize()
{
	m_scene = std::make_unique<dbf::Scene>(this);
	//dbf::Renderer g_renderer;
	//dbf::inpSystem g_inputSystem;
	//dbf::timeMgmt g_time;

	

	// ** CREATE ACTOR **
	// transform
	dbf::Transform transform;
	transform.position = { 400, 300 };
	transform.rotation = 0;
	transform.scale = 6;

	std::unique_ptr<Player> player = std::make_unique<Player>(dbf::Model{ "player.txt" }, transform);
	m_scene->Add(std::move(player));
	std::unique_ptr<Flare> reticle = std::make_unique<Flare>(dbf::Model{ "flares/reticle/reticle.txt" }, transform, 1);
	m_scene->Add(std::move(reticle));

	// model
	/*for (int i = 0; i < 1; i++)
	{
		transform.position.x = dbf::randomf(800);
		transform.position.y = dbf::randomf(600);
		transform.rotation = dbf::randomf(math::TwoPi);
		std::unique_ptr<Enemy> enemy = std::make_unique<Enemy>(dbf::Model{ "enemy.txt" }, transform);
		m_scene->Add(std::move(enemy));
	}*/

	
	playerHealth = 15;
	for (int i = 0; i < playerHealth; i++) {
		healthtxt.push_back('|');
	}
	dbf::g_audio.AddAudio("laser", "Laser.wav");
	dbf::g_audio.AddAudio("playerdie", "Explosion.wav");
	dbf::g_audio.AddAudio("enemydie", "enemydie.wav");
	dbf::g_audio.AddAudio("intro", "Intro.wav");
	dbf::g_audio.AddAudio("music", "Background.wav");
	dbf::g_audio.AddAudio("pup", "Powerup.wav");
	m_font = std::make_unique<dbf::Font>("Fonts/SpaceRacer-DOPlR.ttf", 24);
	s_font = std::make_unique<dbf::Font>("Fonts/SpaceRacer-DOPlR.ttf", 12);
	title = std::make_unique<dbf::Text>(m_font.get());
	title->Create(dbf::g_renderer, "Solaris II", {0,225,225,225});
	score = std::make_unique<dbf::Text>(m_font.get());
	score->Create(dbf::g_renderer, "Score: 0", {225, 225, 225, 225});
	smallTitle = std::make_unique<dbf::Text>(s_font.get());
	smallTitle->Create(dbf::g_renderer, "Welcome to space.", {225, 225, 225, 225});
	health = std::make_unique<dbf::Text>(m_font.get());
	health->Create(dbf::g_renderer, healthtxt, { 255,10,100,255 });
	titleTimer = 5;
	dbf::g_audio.PlayAudio("intro",false);
	dbf::g_audio.PlayAudio("music",true);
	//pause = false;

	

	//set font
	//dbf::Font* font = new dbf::Font("Fonts/SpaceRacer-DOPlR.ttf", 24);
	
	//dbf::Text title(font);
	//title.Create(dbf::g_renderer, "Solaris II", { 255,255,255,255 });


}

void Solaris2::Shutdown()
{
}

void Solaris2::Update()
{
	
		titleTimer -= dbf::g_time.deltaTime;
		if (playerHealth <= 0) {
			
			title->Create(dbf::g_renderer, "Game Over", { 0,225,225,225 });
			smallTitle->Create(dbf::g_renderer, "Enter to Restart, Esc to Quit", { 0,225,225,225 });
			end = true;
			
		}
		
		m_spawnTimer -= dbf::g_time.deltaTime;
		if (m_spawnTimer <= 0)
		{
			m_spawnTimer = 2;
			std::unique_ptr<dbf::Actor> NPC;
			dbf::Transform transform;
			int type = dbf::randomf(1, 4);
			int spawnsel = dbf::randomf(0, 2);
			switch (spawnsel) {
			case 0:
				transform.position.x = dbf::randomf(800);
				transform.position.y = dbf::randomf(600);
				transform.rotation = dbf::randomf(math::TwoPi);
				transform.scale = 6;
				//int type = dbf::randomf(1, 4);
				if (type == 1) {
					for (int i = 0; i < 4; i++)
					{
						NPC = std::make_unique<Enemy>(dbf::Model{ "danger/enemy" + std::to_string(type) + ".txt" }, transform, type, type);
						m_scene->Add(std::move(NPC));

					}

				}
				else {
					NPC = std::make_unique<Enemy>(dbf::Model{ "danger/enemy" + std::to_string(type) + ".txt" }, transform, type, type);
					m_scene->Add(std::move(NPC));
				}
				break;
			case 1:
				//dbf::Transform transform;
				type = dbf::randomf(1, 5);
				transform.position.x = dbf::randomf(800);
				transform.position.y = dbf::randomf(600);
				transform.rotation = dbf::randomf(math::TwoPi);
				transform.scale = 6;

				NPC = std::make_unique<Pickup>(dbf::Model{ "pups/pup" + std::to_string(type) + ".txt" }, transform, type);
				m_scene->Add(std::move(NPC));
				break;
			}
		}
		//std::cout << dbf::g_time.deltaTime << std::endl;



		// update game objects
		m_scene->Update();
		scoretxt = "score: " + std::to_string(m_score);
		score->Create(dbf::g_renderer, scoretxt, { 255,255,255,255 });
		healthtxt = "health: ";
		for (int i = 0; i < playerHealth; i++) {
			healthtxt.push_back('|');
		}
		health->Create(dbf::g_renderer, healthtxt, { 255,10,100,255 });
	}


void Solaris2::Draw(dbf::Renderer& renderer)
{
	// render game objects
	//title.Draw(dbf::g_renderer, { 300,400 });

	m_scene->Draw(dbf::g_renderer);
	
	score->Draw(renderer, { 40,30 });
	health->Draw(renderer, { 40,700 });

	if (titleTimer > 0) {
		title->Draw(renderer, { 300,350 });
		smallTitle->Draw(renderer, { 300,380 });
	}
	if (end) {
		title->Draw(renderer, { 290,350 });
		smallTitle->Draw(renderer, { 250,380 });
	}

}
