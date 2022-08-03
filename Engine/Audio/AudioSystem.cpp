#include "AudioSystem.h"
#include <fmod.hpp>
namespace dbf {
	void AudioSystem::Initialize()
	{
		FMOD::System_Create(&m_fmodSystem);

		void* extraDriverData = nullptr;
		m_fmodSystem->init(32, FMOD_INIT_NORMAL, extraDriverData);

	}

	void AudioSystem::Shutdown()
	{
		for (auto& sound : m_sounds)
		{
			sound.second->release();
		}
		m_sounds.clear();

		m_fmodSystem->close();
		m_fmodSystem->release();
	}


	void AudioSystem::Update()
	{
		m_fmodSystem->update();
	}

	void AudioSystem::AddAudio(const std::string& name, const std::string& filename)
	{
		if (m_sounds.find(name) == m_sounds.end())
		{
			FMOD::Sound* sound = nullptr;
			m_fmodSystem->createSound(filename.c_str(), FMOD_DEFAULT, 0, &sound);
			m_sounds[name] = sound;
		}
	}
	void AudioSystem::PlayAudio(const std::string& name, bool loop)
	{
		auto iter = m_sounds.find(name);
		if (iter != m_sounds.end())
		{
			FMOD::Sound* sound = iter->second;
			if (loop) {
				sound->setMode(FMOD_LOOP_NORMAL);
			}
			else {
				sound->setMode(FMOD_LOOP_OFF);
			}

			FMOD::Channel* channel;
			m_fmodSystem->playSound(sound, 0, false, &channel);
		}
	}
	void AudioSystem::StopAudio(bool played)
	{
		//int* NumChannels=nullptr;
		//m_fmodSystem->getChannelsPlaying(NumChannels);
		//FMOD_CHANNELCONTROL_CHANNELGROUP
		
		if (!played) {
			const int NumChannels = 32;

			for (int i = 0; i < NumChannels; i++)
			{
				FMOD::Channel* pChannel = nullptr;
				FMOD_RESULT res = m_fmodSystem->getChannel(i, &pChannel);

				if (res == FMOD_OK && pChannel)
				{
					pChannel->stop();
				}
			}

			PlayAudio("playerdie", false);
			played = true;
		}
	}
}