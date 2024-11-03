#include "GameManager.h"

#include "Entity.h"

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Shape.hpp>

GameManager::GameManager()
{
	mWindow = nullptr;
	mDeltaTime = 0.0f;
}

GameManager* GameManager::Get()
{
	static GameManager* mInstance = new GameManager();

	return mInstance;
}

void GameManager::SetWindow(sf::RenderWindow* window)
{
	mWindow = window;
}

void GameManager::Update()
{
    //Update
    for (auto it = mEntities.begin(); it != mEntities.end(); )
    {
		Entity* entity = *it;

        entity->Update();

        if (entity->ToDestroy() == false)
        {
            ++it;
            continue;
        }

        mEntitiesToDestroy.push_back(entity);
        it = mEntities.erase(it);
    }

    //Collision
    for (auto it1 = mEntities.begin(); it1 != mEntities.end(); ++it1)
    {
        auto it2 = it1;
        ++it2;
        for (; it2 != mEntities.end(); ++it2)
        {
            Entity* entity = *it1;
            Entity* otherEntity = *it2;

            if (entity->IsColliding(otherEntity))
            {
                entity->OnCollision(otherEntity);
                otherEntity->OnCollision(entity);
            }
        }
    }

    mEntitiesToDestroy.clear();
}

void GameManager::Draw()
{
	for (Entity* entity : mEntities)
	{
		mWindow->draw(*entity->GetShape());
	}
}

void GameManager::SetDeltaTime(float deltaTime)
{
	mDeltaTime = deltaTime;
}

float GameManager::GetDeltaTime() const
{
	return mDeltaTime;
}
