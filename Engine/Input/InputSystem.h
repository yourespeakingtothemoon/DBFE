#pragma once
#include "../Math/Vector2.h"
#include <cstdint>
#include <vector>
#include <map>
#include <array>
#include <string>

namespace dbf
{
	class inpSystem
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
		inpSystem() = default;
		~inpSystem() = default;

		void initialize();
		void shutdown();

		void update();

		keyState getKeyState(uint32_t key);
		keyState getKeyState(const std::string& key);

		bool getKeyDown(uint32_t key) { return m_keyboardState[key]; }
		bool getKeyDown(const std::string& key);

		bool getPreviousKeyDown(uint32_t key) { return m_prevKeyboardState[key]; }
		bool getPreviousKeyDown(const std::string& key);

		const Vector2& getMousePosition() const { return m_mousePosition; }
		
		keyState getButtonState(uint32_t button);
		bool getButtonDown(uint32_t button) { return m_mouseButtonState[button]; }
		bool getPreviousButtonDown(uint32_t button) { return m_prevMouseButtonState[button]; }

	private:
		// keyboard
		std::vector<uint8_t> m_keyboardState;
		std::vector<uint8_t> m_prevKeyboardState;

		// mouse
		Vector2 m_mousePosition;
		
		std::array<uint8_t, 3> m_mouseButtonState;
		std::array<uint8_t, 3> m_prevMouseButtonState;

	};

	extern const uint32_t button_left;
	extern const uint32_t button_middle;
	extern const uint32_t button_right;

	extern const uint32_t key_space;
	extern const uint32_t key_escape;
	extern const uint32_t key_enter;
	extern const uint32_t key_up;
	extern const uint32_t key_w;
	extern const uint32_t key_a;
	extern const uint32_t key_s;
	extern const uint32_t key_d;
	extern const uint32_t key_down;
	extern const uint32_t key_left;
	extern const uint32_t key_right;
}
