#pragma once

#include "Scene.h"
#include "Zombie.h"
class SampleScene : public Scene
{
	sf::Vector2f mPosition;
	Zombie* mpZombie;

public:

	void Initialize() override;
	void HandleInput(const sf::Event& event) override;
	void Update() override;
};

