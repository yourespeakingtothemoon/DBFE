#pragma once
#include "Framework/GameObject.h"
namespace dbf
{
	class Actor;
	class Component : public GameObject{
	public:
		Component() = default;

		friend class Actor;

	protected:
		Actor* m_owner = nullptr;
	};
}