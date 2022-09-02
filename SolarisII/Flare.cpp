#include "Flare.h"
#include "Enemy.h"
#include "Pickup.h"
#include "Engine.h"

void Flare::Update()
{
	if (p_tag = 1) {
		m_transform.position=dbf::g_inputSystem.getMousePosition();
		switch (overlap)
		{
		case 0:
			m_model = dbf::Model{ "flares/reticle/reticle.txt" };
			break;
		case 1:
			m_model = dbf::Model{ "flares/reticle/reticleFriendly.txt" };
			break;
		case 2:
			m_model = dbf::Model{ "flares/reticle/reticleEvil.txt" };
			break;

		}
	}
	overlap = 0;
}

void Flare::OnCollision(Actor* other)
{
	if (p_tag == 1 && dynamic_cast<Pickup*>(other)) {
		overlap = 1;
	}
	if (p_tag == 1 && dynamic_cast<Enemy*>(other)) {
		overlap = 2;
	}
}
