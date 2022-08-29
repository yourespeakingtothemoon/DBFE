#pragma once
#include "Component.h"
#include "Physics/Collision.h"

namespace dbf
{
	class PlayComponent : public Component, public ICollision
	{
	public:
		PlayComponent() = default;

		CLASS_DECLARATION(PlayComponent)

		void init() override;
		void update() override;
		//collision
		virtual void enterCollide(Actor* other) override;
		virtual void exitCollide(Actor* other) override;
		//serialization
		virtual bool write(const rapidjson::Value& value) const override;
		virtual bool read(const rapidjson::Value& value) override;

	public:
		float spd = 0;

	};
}