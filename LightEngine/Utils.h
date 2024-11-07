#pragma once

#include <SFML/System/Vector2.hpp>

namespace Utils
{
	bool Normalize(sf::Vector2f& vector);
	bool IsCollinear(const sf::Vector2f& a, const sf::Vector2f& b);
}