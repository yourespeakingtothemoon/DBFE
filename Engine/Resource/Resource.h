#pragma once
#include <string>
#include <cstdarg>
namespace dbf
{
	class Resource
	{
	public:
		virtual bool Create(std::string name, ...) = 0;
	};
}