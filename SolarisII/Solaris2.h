#pragma once
#include "Framework/Game.h"
#include "Renderer/Text.h"
#include "Renderer/Font.h"

class Solaris2 : public dbf::Game
{
public:

	//Solaris2() = default;
	Solaris2() {}
	~Solaris2() = default;

	// Inherited via Game
	virtual void Initialize() override;

	virtual void Shutdown() override;


	virtual void Update() override;


	virtual void Draw(dbf::Renderer& renderer) override;

	bool end = false;
private:
	float m_spawnTimer = 3;
	std::unique_ptr<dbf::Font> m_font;
	std::unique_ptr<dbf::Font> s_font;
	std::unique_ptr<dbf::Text> title;
	std::unique_ptr<dbf::Text> smallTitle;
	std::string scoretxt;
	std::string healthtxt="health: ";
	std::unique_ptr<dbf::Text> score;
	std::unique_ptr<dbf::Text> health;
	float titleTimer = 30;
	
};