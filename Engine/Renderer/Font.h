#pragma once
#include "Resource/Resource.h"
#include <string>


struct _TTF_Font;
namespace dbf
{
	class Font : public Resource
	{
	public:
		Font() = default;
		Font(const std::string& filename, int fontSize);
		~Font();

		bool Create(std::string filename, int size, ...) override;
		void Load(const std::string& filename, int fontSize);

		_TTF_Font* getFont();

	private:
		_TTF_Font* m_ttfFont = nullptr;
	};
}