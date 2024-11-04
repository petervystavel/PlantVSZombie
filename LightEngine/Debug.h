#pragma once

#include <vector>
#include <SFML/Graphics/Vertex.hpp>

class GameManager;

namespace sf
{
	class Color;
}

struct Line 
{
	sf::Vertex start;
	sf::Vertex end;
};

class Debug
{
	static std::vector<Line> mLines;

	static std::vector<Line>& GetLines();
	static void ClearLines();

public:
	static void DrawLine(float x1, float y1, float x2, float y2, const sf::Color& color);
	static void DrawRectangle(float x, float y, float width, float height, const sf::Color& color);

	friend GameManager;
};

