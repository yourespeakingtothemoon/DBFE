#pragma once
#include "Framework/Actor.h"

class Player : public dbf::Actor
{
public:
	Player() = default;
	Player(const dbf::Model& model, const dbf::Transform& transform) :
		Actor{ model, transform } {}

	void Update() override;

	void OnCollision(Actor* other) override;

private:

	int weaponType = 0;
	float m_health{ 10 };
	float m_weapontimer{ 5 };
	//float m_damage = 1;
	float m_speed{ 0 };
	float m_maxSpeed{ 400 };
	bool endingSound = false;
};