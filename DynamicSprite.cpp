#include "DynamicSprite.h"
#include "SceneComponent.h"
#include <vector>
#include <SFML/Graphics.hpp>

using namespace std;

DynamicSprite::DynamicSprite(): m_currentFrame(0), m_playForward(true)
{
}

DynamicSprite::DynamicSprite(sf::Vector2f location, sf::Texture *texture): m_currentFrame(0), m_playForward(true)
{
  setVisibility(true);
  m_sprite.move(location);
  m_location = location;
  m_texture = texture;
  m_sprite.setTexture(*m_texture);
};

DynamicSprite::DynamicSprite(sf::Vector2f location, sf::Vector2f desiredSize, sf::Texture *texture): m_currentFrame(0), m_playForward(true)
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

DynamicSprite::DynamicSprite(sf::Vector2f location, sf::Vector2f desiredSize, sf::Texture *texture, int nbrColumns, int nbrRow, int nbrFrames, int framerate): m_currentFrame(0), m_playForward(true)
{
  setVisibility(true);
  m_sprite.move(location);
  m_location = location;
  m_texture = texture;
  m_sprite.setTexture(*m_texture);
  m_framerate = framerate;

  m_nbrRow=nbrRow;
  m_nbrColumns=nbrColumns;
  m_nbrFrames=nbrFrames;
  if (m_currentFrame<m_nbrFrames) {
    m_frameWidth = ((m_texture->getSize().x)/m_nbrColumns);
    m_frameHeight = ((m_texture->getSize().y)/m_nbrRow);
    float desiredFrameX = (m_currentFrame-2)-(int(m_currentFrame/(m_nbrColumns-1))*(m_nbrColumns-1))+2;
    float desiredFrameY = (m_currentFrame)/(m_nbrColumns);
    m_sprite.setTextureRect(sf::IntRect((m_frameWidth*desiredFrameX), (m_frameHeight*desiredFrameY), m_frameWidth, m_frameHeight));
  }

  sf::Vector2f scale;
  scale.x = desiredSize.x / m_frameWidth;
  scale.y = desiredSize.y / m_frameHeight;
  m_sprite.setScale(scale);
};


DynamicSprite::~DynamicSprite()
{
}

void DynamicSprite::setPlayForward(bool playForward)
{
  m_playForward = playForward;
}

void DynamicSprite::updateComponent(){
  if(m_timer.getElapsedTime().asMilliseconds()>=(1000/m_framerate)){
    m_timer.restart();
    if(m_playForward){m_currentFrame+=1;}
    else{m_currentFrame-=1;}
    if (m_currentFrame>=m_nbrFrames) {
      m_currentFrame=0;
    }
    if (m_currentFrame<0) {
      m_currentFrame=m_nbrFrames-1;
    }
    //m_frameWidth = ((m_texture->getSize().x)/m_nbrColumns);
    //m_frameHeight = ((m_texture->getSize().y)/m_nbrRow);
    float desiredFrameX = (m_currentFrame-2)-(int(m_currentFrame/(m_nbrColumns-0))*(m_nbrColumns-0))+2;
    float desiredFrameY = (m_currentFrame)/(m_nbrColumns);
    m_sprite.setTextureRect(sf::IntRect((m_frameWidth*desiredFrameX), (m_frameHeight*desiredFrameY), m_frameWidth, m_frameHeight));
  }
}
