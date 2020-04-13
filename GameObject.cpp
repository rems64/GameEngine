#include "GameObject.h"
#include <iostream>

using namespace std;

GameObject::GameObject(): m_isVisible(false)
{
}

void GameObject::draw(){
  if(m_isVisible)
  {
    cout << "[INFO] Drawing a basic GameObject which is NOT RECOMMENDED. You may want to set this to unvisible" << endl;
  }
}

void GameObject::setVisibility(bool shouldBeVisible)
{
  m_isVisible=shouldBeVisible;
}

bool GameObject::isVisible()
{
  return m_isVisible;
}

void GameObject::toggleVisibility()
{
  if(m_isVisible){m_isVisible=false;}
  else{m_isVisible=true;}
}
