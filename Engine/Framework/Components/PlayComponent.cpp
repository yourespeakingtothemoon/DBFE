#include "PlayComponent.h"
#include "Engine.h"
#include <iostream>

namespace dbf
{
	void PlayComponent::init()
	{
		auto component =  m_owner->getComponent<CollisionComponent>();
		if (component)
		{
			component->setCollideEnter(std::bind(&PlayComponent::enterCollide, this, std::placeholders::_1));
			component->setCollideExit(std::bind(&PlayComponent::exitCollide, this, std::placeholders::_1));
		}
	}

	void PlayComponent::update()
	{
		Vector2 direction = Vector2::zero;
		//input
			//check
		bool left = dbf::g_inputSystem.queryKeyState(dbf::key_a) == dbf::InpSystem::keyState::Held;
		bool right = dbf::g_inputSystem.queryKeyState(dbf::key_d) == dbf::InpSystem::keyState::Held;
		bool jump = dbf::g_inputSystem.queryKeyState(dbf::key_space) == dbf::InpSystem::keyState::Pressed;
			//act
		if (left)	direction = Vector2::left;
		if (right) direction = Vector2::right;
		if (jump)
		{
			auto component = m_owner->getComponent<PhysicsComponent>();
			if (component)
			{
				component->applyForce(Vector2::up * 500);
			}

		}
		//physics
		auto component = m_owner->getComponent<PhysicsComponent>();
		if (component)
		{
			component->applyForce(direction * spd);
		}

		//update
		m_owner->m_transform.position += direction * 300 * g_time.deltaTime;



	}
	bool PlayComponent::write(const rapidjson::Value& value) const
	{
		return true;
	}

	bool PlayComponent::read(const rapidjson::Value& value)
	{
		READ_DATA(value, spd);
		return true;
	}

	void PlayComponent::enterCollide(Actor* other)
	{
		//if coind
		//Event event;
		//event.name="event_add_points";
		//event.data = 100;

		//g_eventManager.Notify(event);

		//other->flipDestroy();
		//std::cout << "Player enter\n";
	}
	void PlayComponent::exitCollide(Actor* other)
	{
		std::cout << "Player exit\n";
	}
}
