#pragma once
#include "Framework/Game.h"

class DinoGame : public dbf::Game
{
public:
	// Inherited via Game
	virtual void init() override;
	virtual void shutdown() override;
	virtual void update() override;
	virtual void draw(dbf::Renderer& renderer) override;
};