#include "InputSystem.h"
#include <SDL.h>
#include <iostream>

namespace dbf
{
	const uint32_t button_left = 0;
	const uint32_t button_middle = 1;
	const uint32_t button_right = 2;

	const uint32_t key_space = SDL_SCANCODE_SPACE;
	const uint32_t key_enter = SDL_SCANCODE_RETURN;
	const uint32_t key_escape = SDL_SCANCODE_ESCAPE;
	const uint32_t key_up = SDL_SCANCODE_UP;
	const uint32_t key_w = SDL_SCANCODE_W;
	const uint32_t key_a = SDL_SCANCODE_A;
	const uint32_t key_s = SDL_SCANCODE_S;
	const uint32_t key_d = SDL_SCANCODE_D;
	const uint32_t key_down = SDL_SCANCODE_DOWN;
	const uint32_t key_left = SDL_SCANCODE_LEFT;
	const uint32_t key_right = SDL_SCANCODE_RIGHT;

	void inpSystem::initialize()
	{
		int numKeys;
		// get pointer to sdl keyboard states and number of keys
		const uint8_t* keyboardState = SDL_GetKeyboardState(&numKeys);

		// resize of keyboard state using numKeys for size
		m_keyboardState.resize(numKeys);

		// copy the sdl key states to keyboard state
		std::copy(keyboardState, keyboardState + numKeys, m_keyboardState.begin());

		// set previous keyboard state to current keyboard state
		m_prevKeyboardState = m_keyboardState;
	}

	void inpSystem::shutdown()
	{
		//
	}

	void inpSystem::update()
	{
		SDL_Event event;
		SDL_PollEvent(&event);

		// save previous keyboard state
		m_prevKeyboardState = m_keyboardState;

		// get current keyboard state
		const uint8_t* keyboardState = SDL_GetKeyboardState(nullptr);
		std::copy(keyboardState, keyboardState + m_keyboardState.size(), m_keyboardState.begin());

		// mouse
		m_prevMouseButtonState = m_mouseButtonState;
		int x, y;
		uint32_t buttons = SDL_GetMouseState(&x, &y);
		m_mousePosition = dbf::Vector2{ (float)x , (float)y };
		m_mouseButtonState[0] = buttons & SDL_BUTTON_LMASK; // buttons [0001] & [0RML]
		m_mouseButtonState[1] = buttons & SDL_BUTTON_MMASK; // buttons [0010] & [0RML]
		m_mouseButtonState[2] = buttons & SDL_BUTTON_RMASK; // buttons [0100] & [0RML]
	}

	inpSystem::keyState inpSystem::getKeyState(uint32_t key)
	{
		keyState keyState = keyState::Idle;

		bool keyDown = getKeyDown(key);
		bool prevKeyDown = getPreviousKeyDown(key);

		if (keyDown)
		{
			keyState = (prevKeyDown) ? keyState::Held : keyState::Pressed;
		}
		else
		{
			keyState = (prevKeyDown) ? keyState::Released : keyState::Idle;
		}

		return keyState;
	}

	inpSystem::keyState inpSystem::getKeyState(const std::string& key)
	{
		//if (m_keyMap.find(key) != m_keyMap.end())
		//{
		//	return GetKeyState(m_keyMap[key]);
		//}

		return keyState::Idle;
	}

	bool inpSystem::getKeyDown(const std::string& key)
	{
		//if (m_keyMap.find(key) != m_keyMap.end())
		//{
		//	return m_keyboardState[m_keyMap[key]];
		//}
		
		return false;
	}

	bool inpSystem::getPreviousKeyDown(const std::string& key)
	{
		//if (m_keyMap.find(key) != m_keyMap.end())
		//{
		//	return m_prevKeyboardState[m_keyMap[key]];
		//}

		return false;
	}


	inpSystem::keyState inpSystem::getButtonState(uint32_t button)
	{
		keyState keyState = keyState::Idle;

		bool buttonDown = getButtonDown(button);
		bool prevButtonDown = getPreviousButtonDown(button);

		if (buttonDown)
		{
			keyState = (prevButtonDown) ? keyState::Held : keyState::Pressed;
		}
		else
		{
			keyState = (prevButtonDown) ? keyState::Released : keyState::Idle;
		}

		return keyState;
	}
}
