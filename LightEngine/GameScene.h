#pragma once

#include "GameManager.h"

#include <list>

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
public:
	enum Tag
	{
		PLANT,
		ZOMBIE,
		PROJECTILE
	};

	Plant* mpPlants[3];
	std::list<Zombie*> mZombies[3];
	AABB mAreas[3];

private:
	int GetClickedArea(int x, int y) const;

public:
	void Initialize() override;
	void HandleInput(const sf::Event& event) override;
	void Update() override;

	bool IsZombieInArea(int index) const;
};

