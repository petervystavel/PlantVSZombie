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

	/* TODO */

	// Create plants
	// Create areas
}

void PVZScene::OnUpdate()
{
	/* TODO */
	
	// Draw areas
}

int PVZScene::GetClickedArea(int x, int y) const
{
	/* TODO */

	// Return the index of the clicked area

	return -1;
}

void PVZScene::OnEvent(const sf::Event& event)
{
	if (event.type != sf::Event::EventType::MouseButtonPressed)
		return;

	switch (event.mouseButton.button) {
	case sf::Mouse::Button::Left:
	{
		/* TODO */

		// Plant in the clicked area shoot a projectile

		break;
	}
	case sf::Mouse::Button::Right:
	{
		/* TODO */
		
		// Create a zombie in the clicked area

		break;
	}
	case sf::Mouse::Button::Middle:
	{
		/* TODO */

		// Reload the plant in the clicked area

		break;
	}
	}
}

void PVZScene::CreateZombie(int index, int x)
{
	/* TODO */

	// Create a zombie in the specified area
}
