#pragma once
#include "Framework/Game.h"
#include "Framework/EventSystem/Event.h"

class DinoGame : public dbf::Game
{
public:
	enum class GameState
	{
		titleScr,
		startLvl,
		gameOver
	};
public:
	
	virtual void init() override;
	virtual void shutdown() override;
	virtual void update() override;
	virtual void draw(dbf::Renderer& renderer) override;
	//void onAddScore(const dbf::Event& event);

private:
	float spawnCounter=0;
	//Time gameTime;
	GameState state=DinoGame::GameState::titleScr;
	//GameState create to make switch statement for different screens. in update, use event system to get game state.


};