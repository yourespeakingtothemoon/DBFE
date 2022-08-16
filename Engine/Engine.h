#pragma once
//core
#include "Core/MemoryMgmt.h"
#include "Core/File.h"
#include "Core/TimeMgmt.h"
//maths
#include "Math/MathUtils.h"
#include "Math/Random.h"
//other
#include "Input/InputSystem.h"
#include "Renderer/Renderer.h"
#include "Audio/AudioSystem.h"
#include "Framework/Scene.h"
#include "Framework/Game.h"
#include "Renderer/Text.h"
#include "Renderer/Font.h"

namespace dbf
{
	extern Renderer g_renderer;
	extern InpSystem g_inputSystem;
	extern TimeMgmt g_time;
	extern AudioSystem g_audio;
}