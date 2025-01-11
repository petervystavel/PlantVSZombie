#pragma once

#include "GameManager.h"

#include <list>

#define PLAN_COUNT 3

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

	AABB mAreas[PLAN_COUNT];
	Plant* mpPlants[PLAN_COUNT];

private:
	int GetClickedArea(int x, int y) const;
	void CreateZombie(int index, int x);

public:
	void OnInitialize() override;
	void OnEvent(const sf::Event& event) override;
	void OnUpdate() override;

};

