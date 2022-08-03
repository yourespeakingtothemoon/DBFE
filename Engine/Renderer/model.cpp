#include "Model.h"
#include "../Core/File.h"

#include <iostream>
#include <sstream>

namespace dbf
{
	Model::Model(const std::string& filename)
	{
		Load(filename);
		m_hitbox = CalculateRadius();
	}

	void Model::Draw(Renderer& renderer, const Vector2& position, float angle, float scale)
	{
		// draw model points
		for (size_t i = 0; i < m_points.size() - 1; i++)
		{
			dbf::Vector2 p1 = Vector2::Rotate((m_points[i] * scale), angle) + position;
			dbf::Vector2 p2 = Vector2::Rotate((m_points[i + 1] * scale), angle) + position;

			renderer.DrawLine(p1, p2, m_color);
		}
	}

	void Model::Load(const std::string& filename)
	{
		std::string buffer;

		dbf::ReadFile(filename, buffer);

		// read color
		std::istringstream stream(buffer);
		stream >> m_color;

		// read number of points
		std::string line;
		std::getline(stream, line);

		size_t numPoints = std::stoi(line);

		// read model points
		for (size_t i = 0; i < numPoints; i++)
		{
			Vector2 point;

			stream >> point;
			m_points.push_back(point);
		}
	}

	float Model::CalculateRadius()
	{
		float rad = 0;

		for (auto& point : m_points)
		{
			if (point.Length() > rad) rad = point.Length();
		}

		return rad;
	}

}
