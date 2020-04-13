#ifndef DEF_DYNAMICSPRITE
#define DEF_DYNAMICSPRITE

#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include "SceneComponent.h"

using namespace std;

class DynamicSprite : public SceneComponent
{
  public:
    using SceneComponent::SceneComponent;
    DynamicSprite();
    ~DynamicSprite();
    DynamicSprite(sf::Vector2f, sf::Texture *);
    DynamicSprite(sf::Vector2f, sf::Vector2f, sf::Texture *);
    DynamicSprite(sf::Vector2f, sf::Vector2f, sf::Texture *, int, int, int, int);
    void updateComponent();
    void setPlayForward(bool);
  private:
    int m_nbrRow;
    int m_nbrColumns;
    int m_nbrFrames;
    float m_frameWidth;
    float m_frameHeight;
    int m_currentFrame;
    float m_framerate;
    sf::Clock m_timer;
    bool m_playForward;
};


#endif
