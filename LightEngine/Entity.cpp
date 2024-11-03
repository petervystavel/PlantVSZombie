#include "Entity.h"

#include "GameManager.h"
#include "Utils.h"

#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/CircleShape.hpp>

Entity::Entity(float x, float y, float radius, const sf::Color& color)
{
	mDirection = sf::Vector2f(0.0f, 0.0f);
	mSpeed = 0.0f;
	mToDestroy = false;

	mShape.setOrigin(radius, radius);
	mShape.setPosition(x, y);
	mShape.setRadius(radius);
	mShape.setFillColor(color);
}

void Entity::Destroy()
{
	mToDestroy = true;
}

bool Entity::ToDestroy() const
{
	return mToDestroy;
}

bool Entity::IsColliding(Entity* other) const
{
	sf::Vector2f distance = GetPosition() - other->GetPosition();

	float sqrLength = (distance.x * distance.x) + (distance.y * distance.y);

	float radius1 = mShape.getRadius();
	float radius2 = other->mShape.getRadius();

	float sqrRadius = (radius1 + radius2) * (radius1 + radius2);

	return sqrLength < sqrRadius;
}

void Entity::SetPosition(float x, float y)
{
	mShape.setPosition(x, y);
}

const sf::Vector2f& Entity::GetPosition() const
{
	return mShape.getPosition();
}

void Entity::GoToPosition(float x, float y)
{
	mDirection = Utils::Vector2Normalize(sf::Vector2f(x, y) - GetPosition());
}

void Entity::SetSpeed(float speed)
{
	mSpeed = speed;
}

void Entity::SetDirection(float x, float y)
{
	mDirection = Utils::Vector2Normalize(sf::Vector2f(x, y));
}

sf::Shape* Entity::GetShape()
{
	return &mShape;
}

void Entity::Update()
{
	InternalUpdate();

	float dt = GameManager::Get()->GetDeltaTime();

	sf::Vector2f newPosition;

	newPosition.x += dt * mSpeed * mDirection.x;
	newPosition.y += dt * mSpeed * mDirection.y;

	mShape.move(newPosition);
}