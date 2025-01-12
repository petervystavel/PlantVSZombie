#include <SFML/System/Vector2.hpp>

#include <cmath>

namespace Utils 
{
    bool Normalize(sf::Vector2f& vector)
    {
        float magnitude = std::sqrt(vector.x * vector.x + vector.y * vector.y);

		if (magnitude != 0)
		{
			vector.x /= magnitude;
			vector.y /= magnitude;
		
			return true;
		}

		return false;
    }

	float GetDistance(int x1, int y1, int x2, int y2)
	{
		int x = x2 - x1;
		int y = y2 - y1;

		return std::sqrt(x * x + y * y);
	}
}