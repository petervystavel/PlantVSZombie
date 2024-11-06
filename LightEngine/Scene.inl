#pragma once

#include "Scene.h"
#include "GameManager.h"

template<typename T>
T* Scene::CreateEntity(float x, float y, float radius, const sf::Color& color)
{
	static_assert(std::is_base_of<Entity, T>::value, "T must be derived from Entity");

	T* newEntity = new T(x, y, radius, color);
	
	mpGameManager->mEntities.push_back(newEntity);

	return newEntity;
}
