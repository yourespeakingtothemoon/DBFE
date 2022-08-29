#include "Engine.h"

namespace dbf 
{
	InpSystem g_inputSystem;
	Renderer g_renderer;
	TimeMgmt g_time;
	AudioSystem g_audioSystem;
	ResourceMgmt g_resourceManager;
	PhysicsSystem g_physicsSystem;
	EventMgmt g_eventManager;
	

	void Engine::reg()
	{
		REGISTER_CLASS(Actor); 
		REGISTER_CLASS(AudioComponent);
		REGISTER_CLASS(ModelComponent);
		REGISTER_CLASS(CollisionComponent);
		REGISTER_CLASS(PhysicsComponent);
		REGISTER_CLASS(RBPhysicsComponent);
		REGISTER_CLASS(PlayComponent);
		REGISTER_CLASS(SpriteComponent);
		REGISTER_CLASS(TextComponent);
		REGISTER_CLASS(TilemapComponent);
		REGISTER_CLASS(SpriteAnimComponent);
	}
}