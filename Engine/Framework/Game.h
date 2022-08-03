#pragma once
#include <memory>
namespace dbf {

	class Renderer;
	class Scene;

	class Game
	{
	public:
		Game() = default;
		virtual ~Game() = default;

		virtual void Initialize() = 0;
		virtual void Shutdown() = 0;

		virtual void Update() = 0;
		virtual void Draw(Renderer& renderer) = 0;

		int getScore() { return m_score; }
		float getHealth() { return playerHealth; }
		void addPoint(int points) { m_score += points; }
		void hit(int damage) { playerHealth-=damage;}
		void heal() { playerHealth += 5; }
	protected:
		float playerHealth = 10;
		std::unique_ptr<Scene> m_scene;
		int m_score = 0;
		int m_hiScore = 0;
	};
}