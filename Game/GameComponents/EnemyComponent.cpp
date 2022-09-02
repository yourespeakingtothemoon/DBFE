#include "EnemyComponent.h"
#include "Engine.h"
#include "Math/Vector2.h"
#include <iostream>

void EnemyComponent::init()
{
    CharComponent::init();
}

void EnemyComponent::update()
{
    dbf::Vector2 velocity;
    dbf::Vector2 direction;
   
    if (m_owner->getName() == "Skelly") {
        switch (dbf::random(1, 2))
        {
        case 1:
            direction = dbf::Vector2::left;
            break;
        case 2:
            direction = dbf::Vector2::right;
            break;
        }
        //physics
        auto component = m_owner->getComponent<dbf::PhysicsComponent>();
        if (component)
        {
            component->applyForce(direction * speed);
            velocity = component->velocity;
        }
        //update
        m_owner->m_transform.position += direction * 300 * dbf::g_time.deltaTime;

       
    }else{
        auto actor = m_owner->getScene()->getActorByName("Player");
        if (actor)
        {
            dbf::Vector2 direction = actor->m_transform.position - m_owner->m_transform.position;
            dbf::Vector2 force = direction.Normalized() * speed;

            auto component = m_owner->getComponent<dbf::PhysicsComponent>();
            if (component) component->applyForce(force);
        }
        }
   

	//sequence set
	auto animComponent = m_owner->getComponent<dbf::SpriteAnimComponent>();

	if (animComponent)
	{
			if (velocity.x != 0) animComponent->setFlipHoriz(velocity.x < 0);
            
			if (velocity.y > 0)
			{
				animComponent->setSequence("fall");

			}

            if (std::fabs(velocity.x) > 0)
            {
                animComponent->setSequence("run");
            }
				else
				{
					animComponent->setSequence("idle");
				}

			}



		}
	


    


void EnemyComponent::enterCollide(dbf::Actor* other)
{
    if (other->getTag() == "Hitbox")
    {
        std::cout << "hit!" << std::endl;
        m_owner->flipDestroy();
    }
}

void EnemyComponent::exitCollide(dbf::Actor* other)
{
    if (other->getTag() == "Damage")
    {
        m_owner->flipDestroy();
    }
}

void EnemyComponent::OnNotify(const dbf::Event& event)
{
   

}

bool EnemyComponent::write(const rapidjson::Value& value) const
{
    return true;
}

bool EnemyComponent::read(const rapidjson::Value& value)
{
    CharComponent::read(value);

    return true;
}