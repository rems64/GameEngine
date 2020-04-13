#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include "SceneComponent.h"

using namespace std;

SceneComponent::SceneComponent()
{
}

SceneComponent::~SceneComponent()
{
}

std::vector<sf::Sprite*> SceneComponent::getDraw()
{
  std::vector<sf::Sprite*> toReturn;
  toReturn.push_back(&m_sprite);
  return toReturn;
}

sf::Sprite* SceneComponent::getSprite(){
  return &m_sprite;
};


void SceneComponent::updateComponent()
{
  //cout << "Parent overriden" << endl;
}
