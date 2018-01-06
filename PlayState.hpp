//
//  PlayState.hpp
//  SFML Engine
//
//  Created by Mathieu Bouchonnet on 06/01/2018.
//  Copyright © 2018 Mathieu Bouchonnet. All rights reserved.
//

#ifndef PlayState_hpp
#define PlayState_hpp

#include <SFML/Graphics.hpp>
#include "GameState.h"

class PlayState : public GameState
{
public:
    PlayState(Game* game);

    virtual void Draw(const float dt);
    virtual void Update(const float dt);
    virtual void HandleInput();
    
private:
    void PauseGame();
};

#endif /* PlayState_hpp */
