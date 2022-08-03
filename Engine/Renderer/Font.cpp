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
	void Font::Load(const std::string& filename, int fontSize)
	{
		m_ttfFont = TTF_OpenFont(filename.c_str(), fontSize);
	}
	_TTF_Font* Font::getFont()
	{
		return this->m_ttfFont;
	}
}