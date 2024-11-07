#include "SampleScene.h"

#include "Zombie.h"

#include "Debug.h"

void SampleScene::Initialize()
{
	mpZombie = CreateEntity<Zombie>(100, sf::Color::Red);
}

void SampleScene::HandleInput(const sf::Event& event)
{
	if (event.type != sf::Event::EventType::MouseButtonPressed)
		return;

	mPosition = { (float) event.mouseButton.x, (float) event.mouseButton.y };

	mpZombie->GoToPosition(mPosition.x, mPosition.y);
}

void SampleScene::Update()
{
	Debug::DrawCircle(mPosition.x, mPosition.y, 10, sf::Color::Blue);
}