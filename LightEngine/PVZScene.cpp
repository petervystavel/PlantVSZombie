#include "PVZScene.h"

#include "Plant.h"
#include "Zombie.h"
#include "Debug.h"

#define PLAN_COUNT 3

void PVZScene::OnInitialize()
{
	int width = GetWindowWidth();
	int height = GetWindowHeight();

	float plantRadius = height * 0.075f;

	float plantStartY = height / (PLAN_COUNT * 2.f);
	float plantGapY = height / (float)PLAN_COUNT;

	float plantStartX = width * 0.05f;

	Plant* pPlants[PLAN_COUNT];

	for (int i = 0; i < PLAN_COUNT; i++)
	{
		pPlants[i] = CreateEntity<Plant>(plantRadius, sf::Color::Green);
		pPlants[i]->SetPosition(plantStartX, plantStartY, 0.f, 0.5f);
		pPlants[i]->SetAreaIndex(i);

		int xMin = plantStartX + plantRadius * 3.f;
		int yMin = plantStartY - plantRadius;
		int xMax = width;
		int yMax = plantStartY + plantRadius;

		mAreas[i] = { xMin, yMin, xMax, yMax };

		plantStartY += plantGapY;
	}
}

void PVZScene::OnUpdate()
{
	for (int i = 0; i < PLAN_COUNT; i++)
	{
		const AABB& aabb = mAreas[i];

		Debug::DrawRectangle(aabb.xMin, aabb.yMin, aabb.xMax - aabb.xMin, aabb.yMax - aabb.yMin, sf::Color::Red);
	}
}

int PVZScene::GetClickedArea(int x, int y) const
{
	for (int i = 0; i < PLAN_COUNT; i++)
	{
		const AABB* aabb = &mAreas[i];

		if (x >= aabb->xMin && x <= aabb->xMax && y >= aabb->yMin && y <= aabb->yMax)
			return i;
	}

	return -1;
}

void PVZScene::OnEvent(const sf::Event& event)
{
	if (event.type != sf::Event::EventType::MouseButtonPressed)
		return;

	int index = GetClickedArea(event.mouseButton.x, event.mouseButton.y);

	if(index == -1)
		return;

	const AABB* clickedArea = &mAreas[index];

	int y = clickedArea->yMin + (clickedArea->yMax - clickedArea->yMin) / 2;

	Zombie* pZombie = CreateEntity<Zombie>(25, sf::Color::Red);
	pZombie->SetPosition(event.mouseButton.x, y, 0.5f, 0.5f);
	pZombie->SetLane(index);

	mLaneZombieCount[index]++;
}

bool PVZScene::IsZombieInArea(int index) const
{
	_ASSERT(index >= 0 && index < PLAN_COUNT);

	return mLaneZombieCount[index] > 0;
}

void PVZScene::OnDestroyZombie(int lane)
{
	_ASSERT(lane >= 0 && lane < PLAN_COUNT);
	if(mLaneZombieCount[lane] <= 0)
		return;

	mLaneZombieCount[lane]--;
}