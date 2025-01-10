#include "SampleScene.h"

#include "DummyEntity.h"

#include "Debug.h"

void SampleScene::OnInitialize()
{
	pPlayer = CreateEntity<DummyEntity>(50, sf::Color::Red);
	pPlayer->SetPosition(100, 180);

	pEnemy = CreateEntity<ShieldBadGuy>(50, sf::Color::Green);
	pEnemy->SetPosition(500, 180);
	//pEnemy->SetSpeed(50.f);
	pEnemy->SetState(ShieldBadGuy::State::Roam);
}

void SampleScene::OnEvent(const sf::Event& event)
{
	if (event.type != sf::Event::EventType::MouseButtonPressed)
		return;

	if (event.mouseButton.button == sf::Mouse::Button::Right)
	{
		TrySetSelectedEntity(pEntity1, event.mouseButton.x, event.mouseButton.y);
		TrySetSelectedEntity(pEntity2, event.mouseButton.x, event.mouseButton.y);
	}

	if (event.mouseButton.button == sf::Mouse::Button::Left)
	{
		if (pEntitySelected != nullptr) 
		{
			pEntitySelected->GoToPosition(event.mouseButton.x, event.mouseButton.y, 100.f);
		}
	}
}

void SampleScene::TrySetSelectedEntity(DummyEntity* pEntity, int x, int y)
{
	if (pEntity->IsInside(x, y) == false)
		return;

	pEntitySelected = pEntity;
}

void SampleScene::OnUpdate()
{
	if(pEntitySelected != nullptr)
	{
		sf::Vector2f position = pEntitySelected->GetPosition();
		Debug::DrawCircle(position.x, position.y, 10, sf::Color::Blue);
	}
}