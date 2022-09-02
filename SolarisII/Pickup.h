#pragma once
#include "Framework/Actor.h"

class Pickup : public dbf::Actor
{
public:
	Pickup() = default;
	Pickup(const dbf::Model& model, const dbf::Transform& transform, int tag) :
		Actor{ model, transform } {
		p_tag = tag;
	};
	void Update() override;
	int getTag() { return p_tag; }
	void OnCollision(Actor* other) override;
private:
	int p_tag = 1;
	float m_speed = 50;
	float m_lifespan = 5;
};
