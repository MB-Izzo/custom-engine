//
//  GameState.h
//  SFML Engine
//
//  Created by Mathieu Bouchonnet on 06/01/2018.
//  Copyright © 2018 Mathieu Bouchonnet. All rights reserved.
//

#ifndef GameState_h
#define GameState_h

#include "Game.h"

class GameState
{
public:
    Game* game;
    
    virtual void Draw(const float dt) = 0;
    virtual void Update(const float dt) = 0;
    virtual void HandleInput() = 0;
};


#endif /* GameState_h */
