#include "LoadMap.h"
#include "states/MainMenuState.h"
#include "states/LevelTwoState.h"

#include <string>
#include <stack>


int main()
{
    std::stack<GameState*> states;

    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Neon Jumper", sf::Style::Fullscreen);

    window.setFramerateLimit(60.0f);

    //GameState currentState = MainMenuState();
    states.push(new MainMenuState(&states));

    sf::Clock deltaClock;
    sf::Time deltaTime;
    while (window.isOpen()) {
        deltaTime = deltaClock.restart();
        sf::Event event;
        if (window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
                window.close();
        }
        // Check if state wants to end
        if(states.top()->getEndState()) {
            states.pop();
            // If no states left, exit the app
            if (states.empty())
                window.close();
        }
        if (states.top()->getGoNextLevel()) {
            states.pop();
            states.push(new LevelTwoState(&states));
        }

        states.top()->update(deltaTime.asSeconds());

        window.clear();

        states.top()->render(window);
        window.display();
    }
}