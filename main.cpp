#include "SFML/Graphics.hpp"
#include "Sprite.hpp"
#include "Game.h"
#include "MenuState.hpp"
#include "ResourceManager.hpp"
#include "TextureManager.hpp"


int main()
{
    TextureManager txtman;
    txtman.AddResource("img");
    
    
    sf::Sprite sprite;
    sprite.setTexture(*(txtman.GetResource("img")));
    
    
    
    sf::RenderWindow window(sf::VideoMode(1080, 720), "SFML works!");
    
    
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        
        
        window.clear();
        window.draw(sprite);
        window.display();
    }
    
    txtman.ReleaseResource("img");
    
    return 0;
}
