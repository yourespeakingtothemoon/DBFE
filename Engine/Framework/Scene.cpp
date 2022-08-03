#include "Scene.h"
#include <algorithm>
#include <iostream>

namespace dbf
{
	void Scene::Update()
	{
		auto iter = m_actors.begin();
		while (iter != m_actors.end())
		{
			(*iter)->Update();
			if ((*iter)->m_destroy)
			{
				iter = m_actors.erase(iter);
			}
			else 
			{
				iter++;
			}
		}
		//check collide
		for (auto iter1 = m_actors.begin(); iter1 != m_actors.end(); iter1++)
		{
			for (auto iter2 = m_actors.begin(); iter2 != m_actors.end(); iter2++)
			{
				if (iter1 == iter2) continue;

				float rad = (*iter1)->getRad() + (*iter2)->getRad();
				float dis = (*iter1)->m_transform.position.Distance((*iter2)->m_transform.position);

				if (dis < rad)
				{
					//std::cout << "collide!" << std::endl;
					(*iter1)->OnCollision((*iter2).get());
				}
			}
		}
	}

	void Scene::Draw(Renderer& renderer)
	{
		for (auto& actor : m_actors)
		{
			actor->Draw(renderer);
		}
	}

	void Scene::Add(std::unique_ptr<Actor> actor)
	{
		actor->m_scene = this;
		m_actors.push_back(std::move(actor));
	}

}
