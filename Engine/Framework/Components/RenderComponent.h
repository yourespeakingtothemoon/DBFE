#pragma once
#include "Component.h"
namespace dbf
{
	class Renderer;

	class RenderComponent : public Component
	{
	public:
		virtual void draw(Renderer& renderer) = 0;
	};
}