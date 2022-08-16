#pragma once
#include "Component.h"
#include "Renderer/renderer.h"
namespace dbf
{
	class RenderComponent : public Component
	{
		void Update();
		void Draw(Renderer& renderer);
	};
}