#pragma once

class GameManager;

namespace sf
{
	class Event;
	class Color;
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

#include "Scene.inl"