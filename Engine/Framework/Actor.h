#pragma once
#include "GameObject.h"
#include "../Renderer/Model.h"

namespace dbf
{
	class Scene;

	class Actor : public GameObject
	{
	public:
		Actor() = default;
		Actor(const Model& model, const Transform& transform) : 
			GameObject{ transform },
			m_model{ model } {}
		std::string GetTag() { return m_tag; }
		void SetTag(std::string tag) { m_tag = tag; }
		virtual void Update() override {}
		virtual void Draw(Renderer& renderer);
		virtual void OnCollision(Actor* other) {}
		float getRad() { return m_model.getRadius() * m_transform.scale; }
		friend class Scene;
		//float GetRadius();

	protected:
		//float m_health;
		std::string m_tag;
		bool m_destroy = false;
		// physics
		Vector2 m_velocity;
		float m_damping = 1;

		Scene* m_scene = nullptr;
		Model m_model;
	};
}