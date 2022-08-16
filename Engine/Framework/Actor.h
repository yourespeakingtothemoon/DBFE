#pragma once
#include "GameObject.h"
#include "Components/Component.h"
#include "../Renderer/Model.h"

namespace dbf
{
	class Scene;

	class Actor : public GameObject
	{
	public:
		Actor() = default;
		Actor(const Transform& transform) : m_transform{transform } {}
		
		std::string GetTag() { return m_tag; }
		void SetTag(std::string tag) { m_tag = tag; }
		virtual void Update() override {}
		virtual void Draw(Renderer& renderer);
		virtual void OnCollision(Actor* other) {}
		float getRad() { return m_model.getRadius() * std::max(m_transform.scale.x,m_transform.scale.y); }
		//void addComponent(std::unique_ptr<Component> component);
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
		Transform m_transform;

		//std::vector<Component&> m_components;
	};
}