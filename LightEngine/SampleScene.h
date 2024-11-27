#pragma once

#include "Scene.h"

class DummyEntity;
class ShieldBadGuy;

class SampleScene : public Scene
{
	DummyEntity* pPlayer;
	ShieldBadGuy* pEnemy;

private:
	void TrySetSelectedEntity(DummyEntity* pEntity, int x, int y);

public:
	void OnInitialize() override;
	void OnEvent(const sf::Event& event) override;
	void OnUpdate() override;
	DummyEntity* GetPlayer() const;
};


