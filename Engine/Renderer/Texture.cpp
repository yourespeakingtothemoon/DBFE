#include "Texture.h" 
#include "Renderer.h" 
#include "Core\Logger.h"

#include <SDL.h> 
#include <SDL_image.h> 

namespace dbf
{
    Texture::~Texture()
    {
        if (m_texture) SDL_DestroyTexture(m_texture);
    }

    bool Texture::Create(Renderer& renderer, const std::string& filename)
    {
        // load surface 
        SDL_Surface* surface = IMG_Load(filename.c_str());// !! call IMG_Load with c-string of filename 
        if (surface == nullptr)
        {
            LOG(SDL_GetError());
            SDL_FreeSurface(surface);
            return false;
        }
        // create texture 
        // !! call SDL_CreateTextureFromSurface passing in renderer and surface 
      
        // !! the first parameter takes in the m_renderer from renderer 
        m_texture = SDL_CreateTextureFromSurface(renderer.getRenderer(), surface);

            // !! call SDL_FreeSurface with surface as the parameter 
        SDL_FreeSurface(surface);
            // !! no need to keep surface after texture is created 

            return true;
    }

    bool Texture::Create(std::string filename, ...)
    {
        // va_list - type to hold information about variable arguments 
        va_list args;

        // va_start - enables access to variadic function arguments 
        va_start(args, filename);

        // va_arg - accesses the next variadic function arguments 
        Renderer& renderer = va_arg(args, Renderer);

        // va_end - ends traversal of the variadic function arguments 
        va_end(args);

        // create texture (returns true/false if successful) 
        return Create(renderer, filename);
    }

    Vector2 Texture::GetSize() const
    {
        SDL_Point point;
        SDL_QueryTexture(m_texture, nullptr, nullptr, &point.x, &point.y);

        return Vector2(point.x, point.y);
    }
}