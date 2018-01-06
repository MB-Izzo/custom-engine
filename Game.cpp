#include "SFML/Graphics.hpp"
#include "Game.h"
#include "GameState.h"

Game::Game()
{
    window.create(sf::VideoMode(800,600), "Sick Game");
    window.setFramerateLimit(60);
}

void Game::PushState(GameState* state)
{
    states.push_back(state);
}

void Game::PopState()
{
    states.back(); // return a reference to the last element in the vector.
    delete states.back();
    states.pop_back();
}

GameState* Game::GetCurrentState()
{
    if (states.empty())
    {
        return nullptr; // exception handling.
    }
    else
    {
        return states.back(); // last element in the vector.
    }
    
}

void Game::GameLoop()
{
    sf::Clock clock;
    while (window.isOpen())
    {
        // control framerate.
        sf::Time elapsed = clock.restart();
        float dt = elapsed.asSeconds();
        
        if (GetCurrentState() == nullptr)
            continue;
        
        GetCurrentState()->HandleInput();
        GetCurrentState()->Update(dt);
        window.clear();
        GetCurrentState()->Draw(dt);
        window.display();
    }
}

Game::~Game()
{
    while (!states.empty())
    {
        PopState();
    }
}
