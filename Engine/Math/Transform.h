#pragma once
#include "Vector2.h"

namespace dbf
{
	struct Transform
	{
		Vector2 position;
		float rotation{ 0 };
		float scale{ 1 };
	};
}
