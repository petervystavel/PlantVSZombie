#include "GameScene.h"

#include "GameManager.h"
#include "Plant.h"
#include "Zombie.h"
#include "Debug.h"

#include <SFML/Window/Event.hpp>

void GameScene::Initialize()
{
	int width = GetWindowWidth();
	int height = GetWindowHeight();

	int plantRadius = 50;
	int plantHeight = plantRadius * 2;
	int spaceBetweenPlants = 20;

	int totalHeight = (spaceBetweenPlants * 2) + (plantHeight * 3);
	int spacing = height - totalHeight;

	int startX = plantRadius * 2;
	int startY = plantRadius + (spacing / 2);

	for (int i = 0; i < 3; i++) 
	{
		mpPlants[i] = CreateEntity<Plant>(startX, startY, plantRadius, sf::Color::Green);
		mpPlants[i]->SetAreaIndex(i);

		int xMin = startX + plantHeight;
		int yMin = startY - plantRadius;
		int xMax = width;
		int yMax = startY + plantRadius;

		mAreas[i] = { xMin, yMin, xMax, yMax };

		startY += plantHeight + spaceBetweenPlants;
	}
}

void GameScene::Update()
{
	for (int i = 0; i < 3; i++)
	{
		const AABB& aabb = mAreas[i];

		Debug::DrawRectangle(aabb.xMin, aabb.yMin, aabb.xMax - aabb.xMin, aabb.yMax - aabb.yMin, sf::Color::Red);
	}

	for (int i = 0; i < 3; i++) 
	{
		for (auto it = mZombies[i].begin(); it != mZombies[i].end();)
		{
			if ((*it)->ToDestroy() == false) 
			{
				it++;
				continue;
			}

			it = mZombies[i].erase(it);
		}
	}
}

int GameScene::GetClickedArea(int x, int y) const
{
	for (int i = 0; i < 3; i++)
	{
		const AABB* aabb = &mAreas[i];

		if (x >= aabb->xMin && x <= aabb->xMax && y >= aabb->yMin && y <= aabb->yMax)
			return i;
	}

	return -1;
}

void GameScene::HandleInput(const sf::Event& event)
{
	if (event.type != sf::Event::EventType::MouseButtonPressed)
		return;

	int index = GetClickedArea(event.mouseButton.x, event.mouseButton.y);

	if(index == -1)
		return;

	const AABB* clickedArea = &mAreas[index];

	int y = clickedArea->yMin + (clickedArea->yMax - clickedArea->yMin) / 2;

	Zombie* pZombie = CreateEntity<Zombie>(event.mouseButton.x, y, 25, sf::Color::Red);
	mZombies[index].push_back(pZombie);
}

bool GameScene::IsZombieInArea(int index) const
{
	return mZombies[index].size() > 0;
}