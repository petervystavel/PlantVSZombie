#include "Debug.h"

#include "GameManager.h"

std::vector<Line> Debug::mLines;

void Debug::DrawLine(float x1, float y1, float x2, float y2, const sf::Color& color)
{
	Line line;

	line.start = sf::Vertex(sf::Vector2f(x1, y1));
	line.start.color = color;

	line.end = sf::Vertex(sf::Vector2f(x2, y2));
	line.end.color = color;

	mLines.push_back(line);
}

void Debug::DrawRectangle(float x, float y, float width, float height, const sf::Color& color)
{
	DrawLine(x, y, x + width, y, color);
	DrawLine(x + width, y, x + width, y + height, color);
	DrawLine(x + width, y + height, x, y + height, color);
	DrawLine(x, y + height, x, y, color);
}

std::vector<Line>& Debug::GetLines()
{
	return Debug::mLines;
}

void Debug::ClearLines()
{
	mLines.clear();
}