#include "Actor.h"


namespace dbf
{
	void Actor::Draw(Renderer& renderer)
	{
		m_model.Draw(renderer, m_transform.position, m_transform.rotation, m_transform.scale);
	}

	//float Actor::GetRadius() { return m_model.getRadius() * m_transform.scale; }

}
