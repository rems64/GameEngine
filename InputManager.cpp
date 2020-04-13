#include "InputManager.h"

#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;

InputManager::InputManager()
{
}

bool InputManager::isMouseCaptured(){
  if(m_isMouseCaptured==true){
    return true;
  }
  else{
    return false;
  }
};

bool InputManager::setCaptureMouse(bool capture){
  if(capture){
    m_isMouseCaptured = true;
  }
  else{
    m_isMouseCaptured = false;
  }
  return m_isMouseCaptured;
};

bool InputManager::isKeyPressed(sf::Keyboard::Key key){
  if(sf::Keyboard::isKeyPressed(key)){
    return true;
  }
  else{
    return false;
  }
};
