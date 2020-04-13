#ifndef DEF_STATIC_SPRITE
#define DEF_STATIC_SPRITE

#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include "SceneComponent.h"

using namespace std;

class StaticSprite : public SceneComponent
{
  public:
    using SceneComponent::SceneComponent;
    StaticSprite();
    ~StaticSprite();
    StaticSprite(sf::Vector2f, sf::Texture *);
    StaticSprite(sf::Vector2f, sf::Vector2f, sf::Texture *);
  private:
};

#endif
