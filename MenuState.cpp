#include "SFML/Graphics.hpp"
#include <iostream>
#include "MenuState.hpp"
#include "PlayState.hpp"
#include"GameState.h"

MenuState::MenuState(Game* game)
{
    this->game = game;
}

void MenuState::HandleInput()
{
    sf::Event event;
    while(game->window.pollEvent(event))
    {
        switch(event.type)
        {
            case sf::Event::Closed:
                game->window.close();
                break;
            case sf::Event::KeyPressed:
                if(event.key.code == sf::Keyboard::Escape)
                    game->window.close();
                else if (event.key.code == sf::Keyboard::Return)
                    LoadGame();
                break;
        }
    }
}

void MenuState::Update(const float dt)
{
    
}

void MenuState::Draw(const float dt)
{
    
}

void MenuState::LoadGame()
{
    game->PushState(new PlayState(game));
}
