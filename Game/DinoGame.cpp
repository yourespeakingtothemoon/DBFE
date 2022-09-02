#include "DinoGame.h"
#include "GameComponents/EnemyComponent.h"
#include "Math/Vector2.h"
#include "Engine.h"


void DinoGame::init()
{
	dbf::REGISTER_CLASS(EnemyComponent);

	m_scene = std::make_unique<dbf::Scene>();

	rapidjson::Document document;

	std::vector<std::string> sceneNames = { "scenes/level.txt", "scenes/tilemap.txt","scenes/Prefabs.txt" };

	for (auto& sceneName : sceneNames)
	{
		bool success = dbf::json::Load(sceneName, document);
		if (!success)
		{
			LOG("could not load scene %s", sceneName.c_str());
			continue;
		}
		m_scene->read(document);
	}
	m_scene->init();

	switch (dbf::random(1, 2)) {
	case 1:
		for (int i = 0; i < 3; i++)
		{
			auto actor = dbf::Factory::instance().Create<dbf::Actor>("Skelly");
			actor->m_transform.position = { dbf::randomf(10, 2300), 100.0f };
			actor->init();

			m_scene->Add(std::move(actor));
		}
		break;
	case 2:
		for (int i = 0; i < 3; i++)
		{
			auto actor = dbf::Factory::instance().Create<dbf::Actor>("Ghosty");
			actor->m_transform.position = { dbf::randomf(10, 2300), 100.0f };
			actor->init();

			m_scene->Add(std::move(actor));
		}
		break;
	}

	

	//coins
	/*for (int i = 0; i < 10; i++)
	{
		auto actor = dbf::Factory::instance().Create<dbf::Actor>("Coin");
		actor->m_transform.position = { dbf::randomf(0, 800), 100.0f };
		actor->init();

		m_scene->Add(std::move(actor));
	}*/

	

	//dbf::g_eventManager.subscribe("event_add_points", std::bind(&DinoGame::onAddScore, this, std::placeholders::_1) );

	
}

void DinoGame::shutdown()
{
	m_scene->RemoveAll();
}

void DinoGame::update()
{
	if (spawnCounter > 5) {
		
		//gives chance for both to spawn
		if (dbf::random(1, 2) == 1) {
			auto actor = dbf::Factory::instance().Create<dbf::Actor>("Skelly");
			actor->m_transform.position = { dbf::randomf(10, 2300), 100.0f };
			actor->init();

			m_scene->Add(std::move(actor));
		}
		if (dbf::random(1, 2) == 2) {
			auto actor = dbf::Factory::instance().Create<dbf::Actor>("Ghosty");
			actor->m_transform.position = { dbf::randomf(0, 800), 200.0f };
			actor->init();

			m_scene->Add(std::move(actor));
			spawnCounter = 0;
		}

		}
	

	spawnCounter+=dbf::g_time.deltaTime; 

	m_scene->update();


}

void DinoGame::draw(dbf::Renderer& renderer)
{
	m_scene->draw(renderer);
}

/*void DinoGame::onAddScore(const dbf::Event& event)
{
	//std::get<int>(_event.data)
}*/
