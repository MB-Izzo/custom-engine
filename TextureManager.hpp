#ifndef TextureManager_hpp
#define TextureManager_hpp

#include <stdio.h>
#include "ResourceManager.hpp"
#include "SFML/Graphics.hpp"

class TextureManager : public ResourceManager<TextureManager, sf::Texture>
{
public:
    TextureManager(): ResourceManager("Textures.txt") {} // copy constructor.
    sf::Texture* Load(const std::string& file_name)
    {
        sf::Texture* texture = new sf::Texture(); // allocate mem on the heap.
        // if load fails, delete allocated memory and reset it to null.
        if (!texture->loadFromFile(file_name))
        {
            delete texture;
            texture = NULL;
            std::cerr << "failed to load texture" << std::endl;
        }
        
        return texture;
    }
};


#endif /* TextureManager_hpp */
