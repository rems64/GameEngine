#ifndef DEF_CHARACTER
#define DEF_CHARACTER

#include "Actor.h"
#include "DynamicSprite.h"
#include <vector>
#include <SFML/Graphics.hpp>

class Character : public Actor
{
  public:
    Character();
    ~Character();
    Character(sf::Vector2f, sf::Vector2f, sf::Texture *, int, int, int, int);
    DynamicSprite m_characterSprite;
    void jump();
    void moveForward(float speed);
    std::vector<sf::Sprite*> getDraw();
    void updateComponent();
    void setPlayForward(bool);
};

#endif
