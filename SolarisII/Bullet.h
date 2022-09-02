#pragma once
#include "Framework/Actor.h"

class Bullet : public dbf::Actor
{
public:
	Bullet() = default;
	Bullet(const dbf::Model& model, const dbf::Transform& transform, float damage = 1) :
		Actor{ model, transform },
		m_damage{damage} {}

	void update() override;
	void OnCollision(Actor* other) override;
	float GetDamage() { return m_damage; }
	//void SetTag(std::string tag) { m_tag = tag; }
private:
	//std::string m_tag;
	float m_damage = 1;
	float m_speed = 200;
	float m_lifespan = 2;
};
