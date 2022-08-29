#include "DinoGame.h"
#include "Engine.h"

void DinoGame::init()
{
	m_scene = std::make_unique<dbf::Scene>();

	rapidjson::Document document;

	std::vector<std::string> sceneNames = { "scenes/level.txt", "scenes/tilemap.txt"};

	for (auto& sceneName : sceneNames)
	{
		bool success = dbf::json::Load(sceneName, document);
		if (!success)
		{
			LOG("could not load scene %s", sceneName.c_str());
			continue;
		}
		//assert(success);
		m_scene->read(document);
	}
	m_scene->init();

	//coins
	/*for (int i = 0; i < 10; i++)
	{
		auto actor = dbf::Factory::instance().Create<dbf::Actor>("Coin");
		actor->m_transform.position = { dbf::randomf(0, 800), 100.0f };
		actor->init();

		m_scene->Add(std::move(actor));
	}*/
}

void DinoGame::shutdown()
{
	m_scene->RemoveAll();
}

void DinoGame::update()
{
	m_scene->update();

}

void DinoGame::draw(dbf::Renderer& renderer)
{
	m_scene->draw(renderer);
}
