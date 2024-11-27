#pragma once

#include "GameManager.h"
#include "Scene.h"
#include <cassert>

template<typename T>
void GameManager::LaunchScene()
{
	static_assert(std::is_base_of<Scene, T>::value, "T must be derived from Scene");
	assert(mpScene == nullptr);

	T* newScene = new T();

	mpScene = newScene;

	mpScene->SetGameManager(this);
	mpScene->OnInitialize();

	Run();
}
