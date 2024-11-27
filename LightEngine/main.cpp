
#include <SFML/Graphics.hpp>
#include <iostream>

#include "GameManager.h"
#include "SampleScene.h"
#include "GameScene.h"

#include <cstdlib>
int main() 
{
    GameManager* pInstance = GameManager::Get();

	pInstance->CreateWindow(1280, 720, "PVZ");
	
	pInstance->LaunchScene<SampleScene>();

	return 0;
}