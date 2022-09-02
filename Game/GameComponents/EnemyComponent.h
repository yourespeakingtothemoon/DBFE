#pragma once
#include "Engine.h"

class EnemyComponent: public dbf::CharComponent
{
public:
	CLASS_DECLARATION(EnemyComponent)

		virtual void init() override;
	virtual void update() override;

	virtual void enterCollide(dbf::Actor* other) override;
	virtual void exitCollide(dbf::Actor* other) override;

	virtual void OnNotify(const dbf::Event& event) override;

	virtual bool write(const rapidjson::Value& value) const override;
	virtual bool read(const rapidjson::Value& value) override;

protected:
};