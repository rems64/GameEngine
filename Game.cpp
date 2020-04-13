#include "Game.h"
#include "Camera.h"
#include <chrono>
#include <SFML/Graphics.hpp>
#include <string>
#include "GameObject.h"
#include "SceneComponent.h"
#include <iostream>

using namespace std;

Game::Game() : m_window(sf::VideoMode(640, 480), "name"), m_isOpen(true), m_canCloseMainWindow(true), m_backgroundColor(sf::Color (0, 0, 0))
{
  //m_window.setFramerateLimit(60);
  cout << "[INFO] Lancement du jeu" << endl;
}

Game::Game(float framerate, sf::Vector2i size, string name): m_window(sf::VideoMode(size.x, size.y), name), m_framerate(framerate), m_backgroundColor(sf::Color (0, 0, 0))
{
  cout << "[INFO] Lancement du jeu" << endl;
  //m_window.setFramerateLimit(60);
}

void Game::newLoop(){
  m_startLoopTime = m_clock.getElapsedTime();
}

void Game::endLoop(){
  sf::Time delta;
  delta = m_clock.getElapsedTime() - m_startLoopTime;
  float timeToWait;
  timeToWait = (1000/m_framerate)-delta.asMilliseconds();
  m_txtFPS.setString(std::to_string(delta.asMilliseconds()));
  if(timeToWait>0){
    sf::sleep(sf::milliseconds(timeToWait));
  };
}

sf::RenderWindow * Game::getMainWindow()
{
  return &m_window;
}




void Game::updateLogic()
{
  sf::Event event;
  while (m_window.pollEvent(event)){
    if (event.type == sf::Event::Closed)
    {
      cout << "[INFO] Fermeture conventionnelle détectée" << endl;
      this->close();
    }
  }

}





void Game::updatePhysics()
{
  for(int i(0); i<(m_gameObjects.size()); ++i) {
    (*m_gameObjects[i]).updateComponent();
    //(*m_gameObjects[i]).updatePhysicsTick(1.f);
  }
  for(int i(0); i<(m_gameActors.size()); ++i) {
    (*m_gameActors[i]).updateComponent();
    //cout << "Hit the road, Jack!" << endl;
    //(*m_gameObjects[i]).updatePhysicsTick(1.f);
  }
}





void Game::updateDraw()
{
  m_window.clear(m_backgroundColor);
  //view = (*(myGame.m_currentCamera)).getView();
  //view1.setSize(window.getSize().x, window.getSize().y);

  //sf::View view1(sf::FloatRect(0.f, 0.f, 0.f, 0.f));
  //view1.setSize(m_window.getSize().x, m_window.getSize().y);
  //m_window.setView(view1);
  (*m_currentCamera).setWinScale(m_window.getSize().x, m_window.getSize().y);
  m_window.setView((*m_currentCamera).getView());
  std::vector<sf::Sprite*> toDraw;
  for(int i(0); i<(m_gameObjects.size()); ++i) {
    if( m_gameObjects[i]->isVisible() )
    {
      toDraw = (*m_gameObjects[i]).getDraw();
      for(int j(0); j<(toDraw.size()); ++j)
      {
        m_window.draw(*(toDraw[j]));
      }
    }
  }
  for(int i(0); i<(m_gameActors.size()); ++i) {
    toDraw = (*m_gameActors[i]).getDraw();
    for(int j(0); j<(toDraw.size()); ++j)
    {
      m_window.draw(*(toDraw[j]));
    }
  }
  //m_txtFPS.setFillColor(sf::Color::White);
  //m_txtFPS.setString("Bonjour la familia");
  //m_window.draw(m_txtFPS);
  m_window.display();
}




void Game::draw(sf::Sprite * toDraw)
{
  m_window.draw((*toDraw));
}




void Game::close()
{
  m_window.close();
  m_isOpen = false;
  cout << "[INFO] Jeu fermé" << endl;
}




bool Game::isAlive()
{
  return m_isOpen;
}




void Game::setCanClose(bool can)
{
  m_canCloseMainWindow = can;
}




bool Game::newSceneComponent(SceneComponent* newScComp)
{
  m_gameObjects.push_back(newScComp);
  return true;
}




bool Game::newActor(Actor* newActor)
{
  m_gameActors.push_back(newActor);
  return true;
}




void Game::setMainCamera(Camera* newCam)
{
  m_currentCamera=newCam;
}




void Game::setBackgroundColor(sf::Color col)
{
  m_backgroundColor=col;
}
