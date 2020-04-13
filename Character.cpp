#include "Character.h"
#include <SFML/Graphics.hpp>
#include "DynamicSprite.h"
#include "Actor.h"

using namespace std;

Character::Character()
{
}

Character::Character(sf::Vector2f location, sf::Vector2f desiredSize, sf::Texture *texture, int nbrColumns, int nbrRow, int nbrFrames, int framerate)
{
  setVisibility(true);
  m_simulatePhysics=true;
  m_location = location;
  m_characterSprite = DynamicSprite(location, desiredSize, texture, nbrColumns, nbrRow, nbrFrames, framerate);
}

Character::~Character()
{
}



void Character::updateComponent()
{
  m_characterSprite.updateComponent();
}


void Character::setPlayForward(bool playForward)
{
  m_characterSprite.setPlayForward(playForward);
}




std::vector<sf::Sprite*> Character::getDraw()
{
  std::vector<sf::Sprite*> toReturn;
  toReturn.push_back(m_characterSprite.getSprite());
  return toReturn;
}





void Character::jump()
{
}
