
#include <SFML/Graphics.hpp>
#include <iostream>

#include "GameManager.h"
#include "GameScene.h"
#include "SampleScene.h"

#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>

// Redéfinition de 'new' pour inclure les informations de fichier et de ligne
#define DEBUG_NEW new( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#define new DEBUG_NEW

int main() 
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

    GameManager* pInstance = GameManager::Get();

	pInstance->CreateWindow(1280, 720, "Plant VS Zombie");
	
	pInstance->LaunchScene<SampleScene>();

	return 0;
}