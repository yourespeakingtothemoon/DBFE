#include "Model.h"
#include "Core/File.h"
#include "Core/Logger.h"
#include "Math/Transform.h"
#include "Math/mathUtils.h"
#include <iostream>
#include <sstream>


namespace dbf
{
	Model::Model(const std::string& filename)
	{
		Load(filename);
		m_hitbox = CalculateRadius();
	}


	bool Model::Create(std::string filename, ...)
	{
		// va_list - type to hold information about variable arguments 
		va_list args;

		// va_start - enables access to variadic function arguments 
		va_start(args, filename);

		// va_arg - accesses the next variadic function arguments 
		Renderer& renderer = va_arg(args, Renderer);

		// va_end - ends traversal of the variadic function arguments 
		va_end(args);

		// create model (returns true/false if successful) 
		if (!Load(filename))
		{
			LOG("Error could not create model to", filename.c_str());
			return false;
		}

		return true;
	}

	void Model::Draw(Renderer& renderer, const Vector2& position, float angle, const Vector2& scale)
	{
		// draw model points
		for (size_t i = 0; i < m_points.size() - 1; i++)
		{
			dbf::Vector2 p1 = Vector2::Rotate((m_points[i] * scale), angle) + position;
			dbf::Vector2 p2 = Vector2::Rotate((m_points[i + 1] * scale), angle) + position;

			renderer.DrawLine(p1, p2, m_color);
		}
	}

	void Model::Draw(Renderer& renderer, const Transform& transform)
	{
		Mat3x3 mx = transform.matrix;
		for (size_t i = 0; i < m_points.size() - 1; i++)
		{
			dbf::Vector2 p1 = Vector2::Rotate((m_points[i] * transform.scale), math::DegToRad(transform.rotation)) + transform.position;
			dbf::Vector2 p2 = Vector2::Rotate((m_points[i + 1] * transform.scale), math::DegToRad(transform.rotation)) + transform.position;

			renderer.DrawLine(p1, p2, m_color);
		}
	}

	bool Model::Load(const std::string& filename)
	{
		std::string buffer;

		if (!dbf::ReadFile(filename, buffer))
		{
			LOG("Error could not read model to", filename.c_str());
		}

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
		return true;
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
