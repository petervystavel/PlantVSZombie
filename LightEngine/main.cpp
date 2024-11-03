
#include <SFML/Graphics.hpp>
#include <iostream>

#include "GameManager.h"
#include "TestEntity.h"

#include "Behaviour.hpp"

int main(void)
{
    sf::RenderWindow window(sf::VideoMode(1280, 720), "SFML");

    window.setFramerateLimit(60);

    sf::Font font;
    if (!font.loadFromFile("Hack-Regular.ttf"))
    {
        std::cerr << "Failed to load font" << std::endl;
        return -1;
    }

	GameManager* pGameManager = GameManager::Get();

    pGameManager->SetWindow(&window);

    Entity* pEntity1 = pGameManager->CreateEntity<TestEntity>(100, 360, 50, sf::Color::Blue);
    Entity* pEntity2 = pGameManager->CreateEntity<TestEntity>(1180, 360, 50, sf::Color::Red);

    pEntity1->SetSpeed(100);
	pEntity1->SetDirection(1, 0);

    pEntity2->SetSpeed(100);
    pEntity2->SetDirection(-1, 0);

    sf::Clock clock;

    while (window.isOpen())
    {
        sf::Time dt = clock.restart();

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed || 
                (event.type == sf::Event::KeyPressed &&
                event.key.code == sf::Keyboard::Escape))
            {
                window.close();
            }
        }

        window.clear();

        GameManager::Get()->Update();
        GameManager::Get()->Draw();

        window.display();

        GameManager::Get()->SetDeltaTime(dt.asSeconds());
    }
}
