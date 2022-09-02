#include "Player.h"
#include "Engine.h"
#include "Bullet.h"
#include "Enemy.h"
#include "Pickup.h"

void Player::Update()
{
	// ** movement **
	// rotate left/right
	/*if (dbf::g_inputSystem.getKeyState(dbf::key_left) == dbf::inpSystem::keyState::Held)
	{
		m_transform.rotation -= math::Pi * dbf::g_time.deltaTime;
	}
	if (dbf::g_inputSystem.getKeyState(dbf::key_right) == dbf::inpSystem::keyState::Held)
	{
		m_transform.rotation += math::Pi * dbf::g_time.deltaTime;
	}*/
	dbf::Vector2 target = dbf::g_inputSystem.getMousePosition();
	target = target - m_transform.position; // direction vector towards target from ship
	m_transform.rotation = target.GetAngle();

	// set thrust speed
	m_speed = 0;
	if (dbf::g_inputSystem.getKeyState(dbf::key_w) == dbf::inpSystem::keyState::Held)
	{
		m_speed = m_maxSpeed;
	}

	// calculate force 
	dbf::Vector2 direction{ 1, 0 };
	direction = dbf::Vector2::Rotate(direction, m_transform.rotation);
	dbf::Vector2 force = direction * m_speed * dbf::g_time.deltaTime;
	// apply force to velocity
	m_velocity += force;
	// apply drag
	m_velocity *= 1.0f / (1.0f + m_damping * dbf::g_time.deltaTime);

	// move
	m_transform.position += m_velocity * dbf::g_time.deltaTime;

	// wrap
	if (m_transform.position.x > dbf::g_renderer.GetWidth()) m_transform.position.x = 0;
	if (m_transform.position.x < 0) m_transform.position.x = (float)dbf::g_renderer.GetWidth();
	if (m_transform.position.y > dbf::g_renderer.GetHeight()) m_transform.position.y = 0;
	if (m_transform.position.y < 0) m_transform.position.y = (float)dbf::g_renderer.GetHeight();

	//weapons system
	switch (weaponType)
	{
	case 0:
		// fire bullet
		if (dbf::g_inputSystem.getButtonState(dbf::button_left) == dbf::inpSystem::keyState::Pressed)
		{
			// fire
			dbf::Transform transform = m_transform;
			transform.scale = 1;
			std::unique_ptr<Bullet> bullet = std::make_unique<Bullet>(dbf::Model{ "bullet.txt" }, transform);
			dbf::g_audio.PlayAudio("laser");
			bullet->SetTag("player");
			m_scene->Add(std::move(bullet));
		}
		break;
	case 1:
		// fire bullets rapid
		if (dbf::g_inputSystem.getButtonState(dbf::button_left) == dbf::inpSystem::keyState::Held)
		{
			m_weapontimer -= dbf::g_time.deltaTime;
			// fire
			dbf::Transform transform = m_transform;
			transform.scale = 2;
			std::unique_ptr<Bullet> bullet = std::make_unique<Bullet>(dbf::Model{ "bullet.txt" }, transform);
			dbf::g_audio.PlayAudio("laser",0);
			bullet->SetTag("player");
			m_scene->Add(std::move(bullet));
		}
		break;
	case 2:
		// fire bullet radius
		if (dbf::g_inputSystem.getButtonState(dbf::button_left) == dbf::inpSystem::keyState::Held)
		{
			m_weapontimer -= dbf::g_time.deltaTime;
			// fire
			for (int i = 0; i < 4; i++) {
				dbf::Transform transform = m_transform;
				transform.scale = 2;
				m_transform.rotation += 90;
				std::unique_ptr<Bullet> bullet = std::make_unique<Bullet>(dbf::Model{ "bullet.txt" }, transform);
				dbf::g_audio.PlayAudio("laser");
				bullet->SetTag("player");
				m_scene->Add(std::move(bullet));
			}
		}
		break;
	}
	
	if (m_scene->GetGame()->getHealth() <= 0) {
		
		
			dbf::g_audio.StopAudio(endingSound);
			endingSound = true;
			m_destroy = true;
			//dbf::g_audio.PlayAudio("playerdie", false);
			//endingSound = false;
		
		//dbf::g_audio.
	}
	//weapon timer
	
	if (m_weapontimer <= 0) {
		weaponType = 0;
		m_weapontimer = 5;
	}
}

void Player::OnCollision(Actor* other)
{
	if (dynamic_cast<Bullet*>(other) && other->GetTag() == "enemy")
	{
		m_scene->GetGame()->hit(1);
		//if (m_scene->GetGame()->getHealth() <= 0) m_destroy = true;
	}
	if (dynamic_cast<Enemy*>(other)&& dynamic_cast<Enemy*>(other)->getETag() == 1)
	{
		m_scene->GetGame()->hit(m_scene->GetGame()->getHealth() / 2);
	}
	if (dynamic_cast<Pickup*>(other)&& dynamic_cast<Pickup*>(other)->getTag()<3)
	{
		weaponType = dynamic_cast<Pickup*>(other)->getTag();
		
	}
	if (dynamic_cast<Pickup*>(other) && dynamic_cast<Pickup*>(other)->getTag() == 3)
	{
		m_scene->GetGame()->addPoint(250);

	}
	if (dynamic_cast<Pickup*>(other) && dynamic_cast<Pickup*>(other)->getTag() == 4)
	{
		m_scene->GetGame()->heal();

	}
}


// face target
//dbf::Vector2 target = neu::g_inputSystem.GetMousePosition();
//target = target - m_transform.position; // direction vector towards target from ship
//m_transform.rotation = target.GetAngle();
