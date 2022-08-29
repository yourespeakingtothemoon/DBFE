#pragma once

#include "../Math/Vector2.h"
#include <cstdint>
#include <vector>
#include <array>

namespace dbf
{
	class InpSystem
	{
	public:
		enum class keyState
		{
			Idle,
			Pressed,
			Held,
			Released
		};

	public:
		InpSystem() = default;
		~InpSystem() = default;

		void init();
		void shutdown();

		void update();

		keyState queryKeyState(uint32_t key);
		bool queryKeyDown(uint32_t key) { return m_keyboardState[key]; }
		bool GetPreviousKeyDown(uint32_t key) { return m_prevKeyboardState[key]; }
		//old
		//bool GetKeyDown(int key) { return m_keyboardState[key]; }

		//mouse
		const Vector2& GetMousePosition() const { return m_mousePosition; }

		keyState GetButtonState(uint32_t button);
		bool GetButtonDown(uint32_t button) { return m_mouseButtonState[button]; }
		bool GetPreviousButtonDown(uint32_t button) { return m_prevMouseButtonState[button]; }


	private:
		int m_numKeys;

		std::vector<uint8_t> m_keyboardState;
		std::vector<uint8_t> m_prevKeyboardState;
		
		//Mouse
		dbf::Vector2 m_mousePosition;

		std::array<uint8_t, 3> m_mouseButtonState;
		std::array<uint8_t, 3> m_prevMouseButtonState;

	};

	extern const uint32_t key_space;
	extern const uint32_t key_up;
	extern const uint32_t key_down;
	extern const uint32_t key_left;
	extern const uint32_t key_right;
	extern const uint32_t key_escape;
	
	extern const uint32_t key_w;
	extern const uint32_t key_a;
	extern const uint32_t key_s;
	extern const uint32_t key_d;

	extern const uint32_t key_1;
	extern const uint32_t key_2;
	extern const uint32_t key_3;

	extern const uint32_t button_left;
	extern const uint32_t button_middle;
	extern const uint32_t button_right;

}