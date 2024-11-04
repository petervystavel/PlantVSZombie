
#include <SFML/Graphics.hpp>
#include <iostream>

#include "GameManager.h"
#include "GameScene.h"

int main() 
{
    GameManager* pInstance = GameManager::Get();

	pInstance->CreateWindow(1280, 720, "Plant VS Zombie");
	pInstance->LaunchScene<GameScene>();
}