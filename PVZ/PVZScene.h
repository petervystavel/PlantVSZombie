#pragma once

#include "GameManager.h"

#include <list>

#define PLANT_COUNT 3

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

class PVZScene : public Scene
{
public:
	enum Tag
	{
		PLANT,
		ZOMBIE,
		PROJECTILE
	};

	int mLaneZombieCount[PLANT_COUNT] = {0};
	AABB mAreas[PLANT_COUNT];

private:
	int GetClickedArea(int x, int y) const;

public:
	void OnInitialize() override;
	void OnEvent(const sf::Event& event) override;
	void OnUpdate() override;

	bool IsZombieInArea(int index) const;
	void OnDestroyZombie(int lane);
};
