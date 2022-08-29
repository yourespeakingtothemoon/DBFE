#pragma once
#include "Component.h"
#include "Math/Rectangle.h"
namespace dbf
{
	class Renderer;

	class RenderComponent : public Component
	{
	public:
		virtual void draw(Renderer& renderer) = 0;

		virtual Rectangle& GetSource() { return source; }

	protected:
		Rectangle source;
	};
}