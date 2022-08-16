#include "Actor.h"


namespace dbf
{
	void Actor::Draw(Renderer& renderer)
	{
		//m_model.Draw(renderer, m_transform.position, m_transform.rotation, m_transform.scale);
		//for (auto& component : m_components)
		//{
			//component->Update();
		//}
	}

	/*void Actor::Update()
	{
		for (auto& component : m_components)
		{
			//&component->Update();
		}
	}*/

	/*void Actor::addComponent(std::unique_ptr<Component> component)
	{
		component->m_owner = this;
		m_components.push_back(*std::move(component));
	}*/

	//float Actor::GetRadius() { return m_model.getRadius() * m_transform.scale; }

}
