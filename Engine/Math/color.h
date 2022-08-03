#pragma once
#include <cstdint>
#include <string>

namespace dbf
{
	struct Color
	{
		uint8_t r;
		uint8_t g;
		uint8_t b;
		uint8_t a;

		friend std::istream& operator >> (std::istream& stream, Color& color);
	};

	inline std::istream& operator >> (std::istream& stream, Color& color)
	{
		std::string line;
		std::getline(stream, line);

		std::string col;

			//r
			col = line.substr(line.find("{") + 1, line.find(",") - (line.find("{") + 1));
			color.r = (std::uint8_t)(std::stof(col) * 255);

			//#g,#b
			line = line.substr(line.find(",") + 1);

			//g
			col = line.substr(line.find("{") + 1, line.find(",") - (line.find("{") + 1));
			color.g = (std::uint8_t)(std::stof(col) * 255);
			
			//g
			col = line.substr(line.find(",") + 1, line.find("}") - (line.find(",") + 1));
			color.b = (std::uint8_t)(std::stof(col) * 255);


		//color.r = 255;
		//color.g = 255;
		//color.b = 255;
		color.a = 255;

		return stream;
	}
}