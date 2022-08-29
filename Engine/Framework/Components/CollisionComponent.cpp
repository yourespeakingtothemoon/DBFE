#include "CollisionComponent.h"
#include"Engine.h"
#include <iostream>

namespace dbf
{
    void CollisionComponent::init()
    {
        auto component = m_owner->getComponent<RBPhysicsComponent>();
        if (component)
        {
            g_physicsSystem.SetCollisionBox(component->m_body, data, m_owner);
        }

    }

    void CollisionComponent::update()
    {

    }

    void CollisionComponent::enterCollide(Actor* other)
    {
        std::cout << other->getName() << std::endl;
        if (m_enterFunction) m_enterFunction(other);
    }

    void CollisionComponent::exitCollide(Actor* other)
    {
        std::cout << other->getName() << std::endl;
        if(m_exitFunction) m_exitFunction(other);
    }

    bool CollisionComponent::write(const rapidjson::Value& value) const
    {
        return true;
    }

    bool CollisionComponent::read(const rapidjson::Value& value)
    {
        READ_DATA(value, data.size);
        READ_DATA(value, data.density);
        READ_DATA(value, data.friction);
        READ_DATA(value, data.restitution);
        READ_DATA(value, data.is_trigger);

        return true;
    }
}
