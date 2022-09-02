#include "Enemy.h"
#include "Bullet.h"
#include "Player.h"
#include "Engine.h"

void Enemy::Initialize()
{
	m_fireTimer = dbf::randomf(0, 2);
	m_speed = dbf::randomf(20, 150);
}

void Enemy::Update()
{
	dbf::Vector2 direction{ 1, 0 };
	direction = dbf::Vector2::Rotate(direction, m_transform.rotation);
	dbf::Vector2 velocity = direction * m_speed * dbf::g_time.deltaTime;
	Player* player = m_scene->GetActor<Player>();
	switch (e_tag)
	{

	case 1:
		// calculate velocity 
		direction = dbf::Vector2::Rotate(direction, m_transform.rotation);
		velocity = direction * m_speed * dbf::g_time.deltaTime;
		// move
		m_transform.position += velocity;

		if (m_transform.position.x > dbf::g_renderer.GetWidth()) m_transform.position.x = 0;
		if (m_transform.position.x < 0) m_transform.position.x = (float)dbf::g_renderer.GetWidth();
		if (m_transform.position.y > dbf::g_renderer.GetHeight()) m_transform.position.y = 0;
		if (m_transform.position.y < 0) m_transform.position.y = (float)dbf::g_renderer.GetHeight();
		break;
		
	case 2:// fire weapon
		m_fireTimer -= dbf::g_time.deltaTime;
		if (m_fireTimer <= 0)
		{
			m_fireTimer = dbf::randomf(2, 4);
			dbf::Transform transform = m_transform;
			transform.scale = 1;
			std::unique_ptr<Bullet> bullet = std::make_unique<Bullet>(dbf::Model{ "ebullet.txt" }, transform);
			bullet->SetTag("enemy");
			m_scene->Add(std::move(bullet));
			dbf::g_audio.PlayAudio("laser", false);
		}

		// set rotation towards player
		//Player* player = m_scene->GetActor<Player>();
		if (player)
		{
			dbf::Vector2 direction = player->m_transform.position - m_transform.position;
			m_transform.rotation = direction.GetAngle();
		}

		// calculate velocity 
		direction = dbf::Vector2::Rotate(direction, m_transform.rotation);
		velocity = direction * (m_speed * 1.5) * dbf::g_time.deltaTime;
		// move
		m_transform.position += velocity;

		if (m_transform.position.x > dbf::g_renderer.GetWidth()) m_transform.position.x = 0;
		if (m_transform.position.x < 0) m_transform.position.x = (float)dbf::g_renderer.GetWidth();
		if (m_transform.position.y > dbf::g_renderer.GetHeight()) m_transform.position.y = 0;
		if (m_transform.position.y < 0) m_transform.position.y = (float)dbf::g_renderer.GetHeight();
		break;
		
	case 3:
		// fire weapon
		m_fireTimer -= dbf::g_time.deltaTime;
		if (m_fireTimer <= 0)
		{
			m_fireTimer = .2;
			dbf::Transform transform = m_transform;
			transform.scale = 1;
			std::unique_ptr<Bullet> bullet = std::make_unique<Bullet>(dbf::Model{ "ebullet.txt" }, transform);
			bullet->SetTag("enemy");
			m_scene->Add(std::move(bullet));
			dbf::g_audio.PlayAudio("laser", 0);
		}
		//Player* player = m_scene->GetActor<Player>();
		//spinning, thats a neat trick
			//dbf::Vector2 direction = player->m_transform.position - m_transform.position;
		m_transform.rotation += m_speed;
		break;
	
		

	}

}

void Enemy::OnCollision(Actor* other)
{
	if (dynamic_cast<Bullet*>(other) && other->GetTag() == "player")
	{
		m_health -= dynamic_cast<Bullet*>(other)->GetDamage();
		
		if (m_health <= 0) {
			dbf::g_audio.PlayAudio("enemydie",false);
			m_destroy = true;
			m_scene->GetGame()->addPoint((10*e_tag));
		}


	}
	if (e_tag==1&&dynamic_cast<Player*>(other))
	{
		dbf::g_audio.PlayAudio("enemydie",false);
		m_destroy = true;
	}
}
