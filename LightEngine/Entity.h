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
protected:
    sf::CircleShape mShape;
    sf::Vector2f mDirection;
	sf::Vector2f mTarget;
    bool mHasTarget;

    float mSpeed;
    bool mToDestroy;
    int mTag;

public:
	void GoToDirection(float x, float y, float speed);
    void GoToPosition(float x, float y, float speed);
    void SetPosition(float x, float y, float ratioX = 0.f, float ratioY = 0.f);
	void SetSpeed(float speed) { mSpeed = speed; }
    void SetTag(int tag);

    sf::Vector2f GetPosition(float ratioX = 0.f, float ratioY = 0.f) const;
	sf::Shape* GetShape();

    bool IsTag(int tag) const;
    bool IsColliding(Entity* other) const;

    void Destroy();
    bool ToDestroy() const;
	
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