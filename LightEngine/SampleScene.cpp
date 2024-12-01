#include "SampleScene.h"

#include "DummyEntity.h"
#include "ShieldBadGuy.h"

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

	if (event.mouseButton.button == sf::Mouse::Button::Left)
	{
		pPlayer->GoToPosition(event.mouseButton.x, pPlayer->GetPosition().y, 300.f);
	}
}

void SampleScene::OnUpdate()
{

}

DummyEntity* SampleScene::GetPlayer() const
{
	return pPlayer;
}
