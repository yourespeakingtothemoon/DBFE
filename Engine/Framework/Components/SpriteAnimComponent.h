#pragma once
#include "RenderComponent.h"
#include "Math/Rectangle.h"

namespace dbf
{
	class Texture;

	class SpriteAnimComponent : public RenderComponent
	{
	public:
		CLASS_DECLARATION(SpriteAnimComponent)

		virtual void update() override;
		virtual void draw(Renderer& renderer) override;

		virtual bool write(const rapidjson::Value& value) const override;
		virtual bool read(const rapidjson::Value& value) override;

	public:
		float fps = 0;
		int num_columns = 0;
		int num_rows = 0;

		int start_frame = 0;
		int end_frame = 0;


		int frame = 0;
		float frameTimer = 0;

		Rectangle source;
		std::shared_ptr<Texture> m_texture;


	protected:




	};
}