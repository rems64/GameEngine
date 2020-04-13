#include "Actor.h"
#include "Game.h"
#include <vector>
#include <SFML/Graphics.hpp>

using namespace std;

Actor::Actor()
{
  m_location = sf::Vector2f(0.0f, 0.0f);
  m_totalExtForces.push_back(sf::Vector2f {0.f, (9.81f*m_mass)});
  m_totalExtForces.push_back(sf::Vector2f {0.f, 0.f});
  m_totalExtForces.push_back(sf::Vector2f {0.f, 0.f});
}

Actor::~Actor()
{
}

Actor::Actor(sf::Vector2f initialLocation)
{
  m_location = initialLocation;
}

void Actor::setLocation(sf::Vector2f location){
  m_location=location;
}

void Actor::move(sf::Vector2f offset)
{
  m_location+=offset;
}

sf::Vector2f Actor::getLocation(){
  return m_location;
}

std::vector<sf::Sprite*> Actor::getDraw()
{
  std::vector<sf::Sprite*> toReturn;
  std::vector<sf::Sprite*> tmp;
  for(int i(0); i<(m_childs.size()); ++i) {
    tmp=m_childs[i].getDraw();
    for (int j = 0; j < tmp.size(); j++) {
      toReturn.push_back(tmp[j]);
    }
  }
  return toReturn;
}


void Actor::setSimulatePhysics(bool simulatePhysics)
{
  m_simulatePhysics=simulatePhysics;
}


void Actor::updateComponent()
{
  //cout << "Parent overriden" << endl;
}



void Actor::updatePhysicsTick(float dTime)
{
  if(m_simulatePhysics)
  {
    float delta;
    delta = (m_clock.getElapsedTime().asMilliseconds())/1000.f;
    //m_velocity = m_velocity;
    sf::Vector2f sum = {0.f, 0.f};
    for(int i(0); i<(m_totalExtForces.size()); ++i) {
      sum += m_totalExtForces[i];
    }
    m_velocity = (sum*delta)/m_mass+m_velocity;
    m_location+=m_velocity;
    //m_sprite.setPosition(m_location);
    m_clock.restart();
  }
}


bool Actor::addChild(SceneComponent* newChild)
{
  m_childs.push_back(*newChild);
  return true;
}
