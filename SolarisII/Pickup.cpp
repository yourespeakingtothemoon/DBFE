#include "Pickup.h"
#include "Player.h"
#include "Engine.h"


void Pickup::Update(){
	//
	m_lifespan -= dbf::g_time.deltaTime;
	if (m_lifespan <= 0) m_destroy = true;

	// calculate velocity 
	dbf::Vector2 direction{ 1, 0 };
	direction = dbf::Vector2::Rotate(direction, m_transform.rotation);
	dbf::Vector2 velocity = direction * m_speed * dbf::g_time.deltaTime;
	// move
	m_transform.position += velocity;



	// wrap
	if (m_transform.position.x > dbf::g_renderer.GetWidth()) m_transform.position.x = 0;
	if (m_transform.position.x < 0) m_transform.position.x = (float)dbf::g_renderer.GetWidth();
	if (m_transform.position.y > dbf::g_renderer.GetHeight()) m_transform.position.y = 0;
	if (m_transform.position.y < 0) m_transform.position.y = (float)dbf::g_renderer.GetHeight();
}

void Pickup::OnCollision(Actor* other)
{
	
	if (dynamic_cast<Player*>(other))
	{
		m_destroy = true;
		dbf::g_audio.PlayAudio("pup",false);

	}
}