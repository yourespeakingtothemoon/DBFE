#pragma once 
#include "..\Math\Vector2.h" 
#include "renderer.h"
#include "Resource\Resource.h"
#include <string> 

struct SDL_Texture;
//class Renderer;

namespace dbf
{
	// !! forward declaration for Renderer below 

	class Renderer;

	class Texture : public Resource
	{
		
		
	public:
		Texture() = default;
		~Texture();

		bool Create(Renderer& renderer, const std::string& filename);
		bool Create(std::string filename, ...) override;

		Vector2 GetSize() const;

		// !! allow Renderer to access private texture data (friend) 

	private:
		SDL_Texture* m_texture = nullptr;


		friend class Renderer;
	};
}