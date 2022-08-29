#include "InputSystem.h"
#include <SDL.h>
#include <iostream>

namespace dbf 
{
	const uint32_t key_space = SDL_SCANCODE_SPACE;
	const uint32_t key_up = SDL_SCANCODE_UP;
	const uint32_t key_down = SDL_SCANCODE_DOWN;
	const uint32_t key_left = SDL_SCANCODE_LEFT;
	const uint32_t key_right = SDL_SCANCODE_RIGHT;
	const uint32_t key_escape = SDL_SCANCODE_ESCAPE;

	//WASD
	const uint32_t key_w = SDL_SCANCODE_W;
	const uint32_t key_a = SDL_SCANCODE_A;
	const uint32_t key_s = SDL_SCANCODE_S;
	const uint32_t key_d = SDL_SCANCODE_D;

	const uint32_t key_1 = SDL_SCANCODE_1;
	const uint32_t key_2 = SDL_SCANCODE_2;
	const uint32_t key_3 = SDL_SCANCODE_3;

	//mouse
	const uint32_t button_left = 0;
	const uint32_t button_middle = 1;
	const uint32_t button_right = 2;

	void InpSystem::init()
	{
		const uint8_t* keyboardState = SDL_GetKeyboardState(&m_numKeys);

		m_keyboardState.resize(m_numKeys);
		std::copy(keyboardState, keyboardState + m_numKeys, m_keyboardState.begin());

		m_prevKeyboardState = m_keyboardState;
	}
	
	void InpSystem::shutdown()
	{
		//

	}
	
	void InpSystem::update()
	{
		SDL_Event event;
		SDL_PollEvent(&event);

		//save previous keyboard state
		m_prevKeyboardState = m_keyboardState;

		//get current keyboard state
		const uint8_t* keyboardState = SDL_GetKeyboardState(nullptr);
		std::copy(keyboardState, keyboardState + m_numKeys, m_keyboardState.begin());

		//std::cout << (bool)m_keyboardState[SDL_SCANCODE_SPACE] << std::endl;
		/*for (auto state : m_keyboardState)
		{
			std::cout << (bool)state << std::endl;
		}
		std::cout << std::endl;
		*/

		//Mouse
		m_prevMouseButtonState = m_mouseButtonState;
		int x, y;
		uint32_t buttons = SDL_GetMouseState(&x, &y);
		m_mousePosition = dbf::Vector2{ x , y };
		m_mouseButtonState[0] = buttons & SDL_BUTTON_LMASK; // buttons [0001] & [0RML] 
		m_mouseButtonState[1] = buttons & SDL_BUTTON_MMASK; // buttons [0010] & [0RML] 
		m_mouseButtonState[2] = buttons & SDL_BUTTON_RMASK; // buttons [0100] & [0RML] 



	}

	InpSystem::keyState InpSystem::queryKeyState(uint32_t key)
	{
		keyState keyState;

		bool keyDown = queryKeyDown(key);
		bool prevKeyDown = GetPreviousKeyDown(key);

		if (keyDown && prevKeyDown) keyState = keyState::Held;
		if (keyDown && !prevKeyDown) keyState = keyState::Pressed;
		if (!keyDown && prevKeyDown) keyState = keyState::Released;
		if (!keyDown && !prevKeyDown) keyState = keyState::Idle;
	

		return keyState;
	}


	InpSystem::keyState InpSystem::GetButtonState(uint32_t button)
	{
		keyState buttonState = keyState::Idle;

		bool buttonDown = GetButtonDown(button);
		bool prevButtonDown = GetPreviousButtonDown(button);

		if (buttonDown && prevButtonDown) buttonState = keyState::Held;
		if (buttonDown && !prevButtonDown) buttonState = keyState::Pressed;
		if (!buttonDown && prevButtonDown) buttonState = keyState::Released;
		if (!buttonDown && !prevButtonDown) buttonState = keyState::Idle;


		return buttonState;
	}

}