#pragma once

#include <list>
#include <SFML/Graphics/Color.hpp>

class Entity;

namespace sf 
{
	class RenderWindow;
}

class GameManager
{
	std::list<Entity*> mEntities;
	std::list<Entity*> mEntitiesToDestroy;

	sf::RenderWindow* mWindow;
	float mDeltaTime;

	GameManager();

public:
	static GameManager* Get();

	template<typename T>
	Entity* CreateEntity(float x, float y, float radius, const sf::Color& color)
	{
		static_assert(std::is_base_of<Entity, T>::value, "T must be derived from Entity");

		T* newEntity = new T(x, y, radius, color);
		mEntities.push_back(newEntity);

		return newEntity;
	}

	void Update();
	void Draw();
	void SetWindow(sf::RenderWindow* window);
	void SetDeltaTime(float deltaTime);
	float GetDeltaTime() const;
};

