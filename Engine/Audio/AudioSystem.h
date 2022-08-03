#pragma once
#pragma once 
#include<string>
#include<map>
namespace FMOD
{
	class System;
	class Sound;
}

namespace dbf
{
	class AudioSystem
	{
	public:
		AudioSystem() = default;
		~AudioSystem() = default;

		void Initialize();
		void Shutdown();

		void Update();

		void AddAudio(const std::string& name, const std::string& filename);
		void PlayAudio(const std::string& name,bool loop=0);

		void StopAudio(bool played);

	private:
		FMOD::System* m_fmodSystem;
		std::map<std::string, FMOD::Sound*> m_sounds;

	};
}