#pragma once

#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/CircleShape.hpp>

namespace sf 
{
	class Shape;
    class Color;
}

class Entity
{
protected:
    sf::CircleShape mShape;
    sf::Vector2f mDirection;
    float mSpeed;
    bool mToDestroy;

public:
    void GoToPosition(float x, float y);
    void SetPosition(float x, float y);
    const sf::Vector2f& GetPosition() const;
    void SetSpeed(float speed);
	void SetDirection(float x, float y);

    sf::Shape* GetShape();
    void Destroy();
    bool ToDestroy() const;
	bool IsColliding(Entity* other) const;

protected:
    virtual ~Entity() {};
    Entity(float x, float y, float radius, const sf::Color& color);

    virtual void OnUpdate() = 0;
    virtual void OnCollision(Entity* collidedWith) = 0;
	
private:
    void Update();

    friend class GameManager;
};
