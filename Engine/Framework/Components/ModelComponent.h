#pragma once
#include "RenderComponent.h"


namespace dbf
{
	class Model;

	class ModelComponent : public RenderComponent
	{
	public:
		virtual void Update() override;
		virtual void Draw(Renderer& renderer);
	};
}