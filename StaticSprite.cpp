#include "StaticSprite.h"
#include "SceneComponent.h"
#include <vector>
#include <SFML/Graphics.hpp>

using namespace std;

StaticSprite::StaticSprite(sf::Vector2f location, sf::Texture *texture)
{
  setVisibility(true);
  m_sprite.move(location);
  m_location = location;
  m_texture = texture;
  m_sprite.setTexture(*m_texture);
};

StaticSprite::StaticSprite(sf::Vector2f location, sf::Vector2f desiredSize, sf::Texture *texture)
{
  setVisibility(true);
  m_sprite.move(location);
  m_location = location;
  m_texture = texture;
  m_sprite.setTexture(*m_texture);
  sf::Vector2f scale;
  scale.x = desiredSize.x / m_texture->getSize().x;
  scale.y = desiredSize.y / m_texture->getSize().y;
  m_sprite.setScale(scale);
};

StaticSprite::~StaticSprite()
{
}
