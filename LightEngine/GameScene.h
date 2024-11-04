#pragma once

#include "GameManager.h"

class Plant;
class Zombie;

namespace sf 
{
	class Event;
}

struct AABB 
{
	int xMin;
	int yMin;
	int xMax;
	int yMax;
};

class GameScene : public Scene
{
	Plant* mpPlants[3];
	AABB mAreas[3];

private:
	const AABB* GetClickedArea(int x, int y) const;

public:
	void Initialize() override;
	void HandleInput(const sf::Event& event) override;
	void Update() override;
};

