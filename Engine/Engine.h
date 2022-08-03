#pragma once
//core
#include "Core/memMgmt.h"
#include "Core/File.h"
#include "Core/timeMgmt.h"
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
	extern inpSystem g_inputSystem;
	extern timeMgmt g_time;
	extern AudioSystem g_audio;
}