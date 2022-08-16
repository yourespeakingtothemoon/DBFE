#pragma once
#include "renderer.h"
#include "Resource\Resource.h"
#include <vector>
#include <string>

namespace dbf
{
	class Model : public Resource
	{
	public:
		Model() = default;
		Model(const std::vector<dbf::Vector2>& points, const dbf::Color& color) :
			m_points{ points },
			m_color{ color }
		{
		}
		Model(const std::string& filename);

		//bool Create(const std::string& filename);
		bool Create(std::string filename, ...) override;

		void Draw(Renderer& renderer, const Vector2& position, float angle, const Vector2& vector = Vector2 {1,1});
		void Draw(Renderer& renderer, const Transform& transform);

		bool Load(const std::string& filename);
		float CalculateRadius();
		float getRadius() { return m_hitbox; }

	private:
		dbf::Color m_color{ 0, 0, 0, 0 };
		std::vector<dbf::Vector2> m_points;
		float m_hitbox = 0;
	};
}
