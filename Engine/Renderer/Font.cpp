#include "Font.h"
#include <SDL_ttf.h>
namespace dbf
{
	Font::Font(const std::string& filename, int fontSize)
	{
		Load(filename, fontSize);
	}
	Font::~Font()
	{
		if (m_ttfFont)
		{
			TTF_CloseFont(m_ttfFont);
			m_ttfFont = nullptr;
		}
	}
	bool Font::Create(std::string filename, int size, ...)
	{
		// va_list - type to hold information about variable arguments 
		va_list args;

		// va_start - enables access to variadic function arguments 
		va_start(args, filename);

		// va_end - ends traversal of the variadic function arguments 
		va_end(args);

		// create font (returns true/false if successful) 
		Load(filename, size);
		return true;
	}
	void Font::Load(const std::string& filename, int fontSize)
	{
		m_ttfFont = TTF_OpenFont(filename.c_str(), fontSize);
	}
	_TTF_Font* Font::getFont()
	{
		return this->m_ttfFont;
	}
}