#include "Text.h" 
#include "Font.h" 
#include "Renderer.h" 
#include <SDL.h> 
#include <SDL_ttf.h> 

namespace dbf {

	 Text::~Text()
	 {
		// !! if m_texture not null, destroy texture (SDL_DestroyTexture) 
		 if (m_texture != nullptr)
		 {
			SDL_DestroyTexture(m_texture);
	 }
	 }

	   void Text::Create(Renderer & renderer, const std::string & text, const Color & color)
	   {
		SDL_Color c{ color.r, color.g, color.b, color.a };
		SDL_Surface* surface = TTF_RenderText_Solid(m_font->getFont(), text.c_str(), c);

	   m_texture = SDL_CreateTextureFromSurface(renderer.getRenderer(), surface);
	   SDL_FreeSurface(surface);
	   }

	   void Text::Draw(Renderer & renderer, const Vector2 & position)
	   {
		int width, height;
		SDL_QueryTexture(m_texture, nullptr, nullptr, &width, &height);

		SDL_Rect rect{ (int)position.x, (int)position.y, width, height };

		SDL_RenderCopy(renderer.getRenderer(), m_texture, NULL, &rect);
	   }
}
