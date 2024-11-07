#pragma once

#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/CircleShape.hpp>

namespace sf 
{
	class Shape;
    class Color;
}

class Scene;

class Entity
{
private:
	bool HasTarget() const { return mTarget.x != -1.f && mTarget.y != -1.f; }

protected:
    sf::CircleShape mShape;
    sf::Vector2f mDirection;
	sf::Vector2f mTarget;

    float mSpeed;
    bool mToDestroy;
    int mTag;

public:
    void GoToPosition(float x, float y);
    void SetPosition(float x, float y, float ratioX = 0.f, float ratioY = 0.f);
    sf::Vector2f GetPosition(float ratioX = 0.f, float ratioY = 0.f) const;
    void SetSpeed(float speed);
	void SetDirection(float x, float y);
	void SetTag(int tag);
	bool IsTag(int tag) const;

    sf::Shape* GetShape();
    void Destroy();
    bool ToDestroy() const;
	bool IsColliding(Entity* other) const;

	template<typename T>
	T* GetScene() const;

    Scene* GetScene() const;

protected:
    virtual ~Entity() {};
    Entity(float radius, const sf::Color& color);

    virtual void OnUpdate() = 0;
    virtual void OnCollision(Entity* collidedWith) = 0;
	
private:
    void Update();
	void CheckTarget();

    friend class GameManager;
};

#include "Entity.inl"