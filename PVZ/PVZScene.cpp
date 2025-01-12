#include "PVZScene.h"

#include "Plant.h"
#include "Zombie.h"
#include "Debug.h"

void PVZScene::OnInitialize()
{
	int width = GetWindowWidth();
	int height = GetWindowHeight();

	float plantRadius = height * 0.075f;

	float plantStartY = height / (PLANT_COUNT * 2.f);
	float plantGapY = height / (float)PLANT_COUNT;

	float plantStartX = width * 0.05f;

	for (int i = 0; i < PLANT_COUNT; i++)
	{
		mpPlants[i] = CreateEntity<Plant>(plantRadius, sf::Color::Green);
		mpPlants[i]->SetPosition(plantStartX, plantStartY, 0.f, 0.5f);

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
	for (int i = 0; i < PLANT_COUNT; i++)
	{
		const AABB& aabb = mAreas[i];

		Debug::DrawRectangle(aabb.xMin, aabb.yMin, aabb.xMax - aabb.xMin, aabb.yMax - aabb.yMin, sf::Color::Red);
	}
}

int PVZScene::GetClickedArea(int x, int y) const
{
	for (int i = 0; i < PLANT_COUNT; i++)
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

	switch (event.mouseButton.button) {
	case sf::Mouse::Button::Left:
	{
		int index = GetClickedArea(event.mouseButton.x, event.mouseButton.y);

		if (index != -1)
		{
			Plant* pPlant = mpPlants[index];
			pPlant->Shoot();
		}

		break;
	}
	case sf::Mouse::Button::Right:
	{
		int index = GetClickedArea(event.mouseButton.x, event.mouseButton.y);

		if (index != -1)
		{
			CreateZombie(index, event.mouseButton.x);
		}

		break;
	}
	case sf::Mouse::Button::Middle:
	{
		int index = GetClickedArea(event.mouseButton.x, event.mouseButton.y);

		if (index != -1)
		{
			Plant* pPlant = mpPlants[index];
			pPlant->Reload();
		}

		break;
	}
	}
}

void PVZScene::CreateZombie(int index, int x)
{
	const AABB* clickedArea = &mAreas[index];

	int y = clickedArea->yMin + (clickedArea->yMax - clickedArea->yMin) / 2;

	Zombie* pZombie = CreateEntity<Zombie>(25, sf::Color::Red);
	pZombie->SetPosition(x, y, 0.5f, 0.5f);
	pZombie->SetLane(index);
}
