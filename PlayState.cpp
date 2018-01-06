#include "PlayState.hpp"
#include "MenuState.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>
#include "GameState.h"

void PlayState::Draw(const float dt)
{
    // rectangle test.
    sf::RectangleShape rect;
    rect.setPosition(sf::Vector2f(100, 100));
    rect.setSize(sf::Vector2f(100, 100));
    rect.setFillColor(sf::Color::Green);
    
    game->window.draw(rect);
}

void PlayState::Update(const float dt)
{
    
}

void PlayState::HandleInput()
{
    sf::Event event;
    
    while (this->game->window.pollEvent(event))
    {
        switch (event.type)
        {
                /* Close the window */
            case sf::Event::Closed:
                this->game->window.close();
                break;
                
                //pause game
            case sf::Event::KeyPressed:
                if (event.key.code == sf::Keyboard::Escape)
                    PauseGame();
                break;
                
        }
    }
}

PlayState::PlayState(Game* game)
{
    this->game = game;
}

void PlayState::PauseGame()
{
    
}
