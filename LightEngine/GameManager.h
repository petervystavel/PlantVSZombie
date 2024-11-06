#pragma once

#include <list>

#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Text.hpp>

class Entity;
class Scene;
class Debug;

namespace sf 
{
	class RenderWindow;
	class Event;
}

class GameManager
{
	std::list<Entity*> mEntities;
	std::list<Entity*> mEntitiesToDestroy;

	sf::RenderWindow* mpWindow;
	sf::Font mFont;

	Scene* mpScene;

	float mDeltaTime;

	int mWindowWidth;
	int mWindowHeight;

private:
	GameManager();

	void Run();
	void HandleInput();
	void Update();
	void Draw();
	void SetDeltaTime(float deltaTime) { mDeltaTime = deltaTime; }

	template<typename T>
	T* CreateEntity(float x, float y, float radius, const sf::Color& color);

	sf::RenderWindow* GetWindow() const { return mpWindow; }

public:
	~GameManager();
	static GameManager* Get();

	void CreateWindow(unsigned int width, unsigned int height, const char* title, int fpsLimit = 60);

	template<typename T>
	void LaunchScene();

	float GetDeltaTime() const { return mDeltaTime; }
	Scene* GetScene() const { return mpScene; }
	sf::Font& GetFont() { return mFont; };

	friend Debug;
	friend Scene;
};

template<typename T>
void GameManager::LaunchScene()
{
	static_assert(std::is_base_of<Scene, T>::value, "T must be derived from Scene");
	_ASSERT(mpScene == nullptr);

	T* newScene = new T();
	newScene->SetGameManager(this);
	newScene->Initialize();

	mpScene = newScene;

	Run();
}

template<typename T>
T* GameManager::CreateEntity(float x, float y, float radius, const sf::Color& color)
{
	static_assert(std::is_base_of<Entity, T>::value, "T must be derived from Entity");

	T* newEntity = new T(x, y, radius, color);
	mEntities.push_back(newEntity);

	return newEntity;
}

class Scene
{
private:
	GameManager* mpGameManager;

private:
	void SetGameManager(GameManager* pGameManager) { mpGameManager = pGameManager; }
	virtual void Initialize() = 0;

protected:
	Scene() = default;

	virtual void HandleInput(const sf::Event& event) = 0;
	virtual void Update() = 0;

public:
	template<typename T>
	T* CreateEntity(float x, float y, float radius, const sf::Color& color);

	int GetWindowWidth() const;
	int GetWindowHeight() const;

	friend GameManager;
};

template<typename T>
T* Scene::CreateEntity(float x, float y, float radius, const sf::Color& color)
{
	return mpGameManager->CreateEntity<T>(x, y, radius, color);
}

