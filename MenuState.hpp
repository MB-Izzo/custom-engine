//
//  MenuState.hpp
//  SFML Engine
//
//  Created by Mathieu Bouchonnet on 06/01/2018.
//  Copyright © 2018 Mathieu Bouchonnet. All rights reserved.
//

#ifndef MenuState_hpp
#define MenuState_hpp

#include <SFML/Graphics.hpp>
#include "GameState.h"  //we will be deriving this abstract classes functions.

class MenuState : public GameState
{
public:
    MenuState(Game* game);
    virtual void Draw(const float dt);
    virtual void Update(const float dt);
    virtual void HandleInput();
    
private:
    sf::View view;
    void LoadGame(); // On "play" button.
};

#endif /* MenuState_hpp */
