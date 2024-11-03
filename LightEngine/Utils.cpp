#include <SFML/System/Vector2.hpp>

#include <cmath>

namespace Utils 
{
    sf::Vector2f Vector2Normalize(const sf::Vector2f& vector)
    {
        float magnitude = std::sqrt(vector.x * vector.x + vector.y * vector.y);

        if (magnitude == 0) {
            return { 0, 0 };
        }

        sf::Vector2f normalized = { vector.x / magnitude, vector.y / magnitude };

        return normalized;
    }

	float GetDeltaTime()
	{
		return 0.016f;
	}
}