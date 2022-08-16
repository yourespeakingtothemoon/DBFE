#pragma once
#include "Component.h"

namespace dbf
{
	class PlayerComponent : public Component
	{
	public:
		PlayerComponent() = default;

		void Update() override;
	};
}