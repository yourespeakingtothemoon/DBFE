#pragma once
#include "Framework/Actor.h"

class Enemy : public dbf::Actor
{
public:
	Enemy() = default;
	Enemy(const dbf::Model& model, const dbf::Transform& transform, int tag, float health=1 ) :
		Actor{ model, transform },
		m_health{health},
		e_tag{tag}{
		Initialize();
	}
	int getETag() { return e_tag; }
	void Initialize();
	void Update() override;

	void OnCollision(Actor* other) override;

private:
	int e_tag=1;
	float m_health{ 1 };
	float m_speed = 50;
	float m_fireTimer = 0;
};