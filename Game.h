//
//  Game.h
//  SFML Engine
//
//  Created by Mathieu Bouchonnet on 06/01/2018.
//  Copyright © 2018 Mathieu Bouchonnet. All rights reserved.
//

#ifndef Game_h
#define Game_h

#include <vector>
#include "SFML/Graphics.hpp"

class GameState;

class Game
{
public:
    sf::RenderWindow window;
    
    Game();
    ~Game();
    
    // To change game state.
    void PushState(GameState* state);
    void PopState();
    
    // Get current state.
    GameState* GetCurrentState();
    
    void GameLoop();
    
private:
    std::vector<GameState*> states;
    
};

#endif /* Game_h */
