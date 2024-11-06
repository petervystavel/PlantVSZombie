#include "Entity.h"

#include "GameManager.h"

template<typename T>
T* Entity::GetScene() const
{
	T* pScene = dynamic_cast<T*>(GetScene());

	_ASSERT(pScene != nullptr);

	return pScene;
}

template<typename T>
T* Entity::CreateEntity(float x, float y, float radius, const sf::Color& color)
{
	Scene* pScene = GetScene();

	return pScene->CreateEntity<T>(x, y, radius, color);
}
