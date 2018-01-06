#include "SFML/Graphics.hpp"
#include "Game.h"
#include "MenuState.hpp"

int main()
{
    Game game;
    game.PushState(new MenuState(&game));
    game.GameLoop();
    
    return 0;
    
}
