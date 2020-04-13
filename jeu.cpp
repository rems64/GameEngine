#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include "Actor.h"
#include "StaticSprite.h"
#include "InputManager.h"
#include <time.h>

using namespace std;
using namespace sf;

int main(){
  RenderWindow window(sf::VideoMode(300, 200), "Jeu");
  InputManager monManager;
  Texture texture;
  if (!texture.loadFromFile("Textures/mine.png"))
  {
    cout << "Error lors de l'import de la Texture" << endl;
  };
  texture.setRepeated(true);

  StaticSprite monStatic(&window, sf::Vector2f(0.0, 0.0), sf::Vector2f(100.f, 100.f), &texture);
  StaticSprite monStatic2(&window, sf::Vector2f(100.0, 0.0), sf::Vector2f(100.f, 100.f), &texture);
  StaticSprite monStatic3(&window, sf::Vector2f(0.0, 100.0), sf::Vector2f(100.f, 100.f), &texture);
  StaticSprite monStatic4(&window, sf::Vector2f(100.0, 100.0), sf::Vector2f(100.f, 100.f), &texture);
  //StaticSprite monStatic;
  sf::View view1(sf::FloatRect(50.f, 50.f, 0.f, 0.f));
  window.setView(view1);
  float framerate(30);
  while (window.isOpen())
  {
      sf::Event event;
      if (monManager.isKeyPressed(sf::Keyboard::Left)) {
        //if (monManager.isMouseCaptured()) {
          window.close();
        }
      while (window.pollEvent(event)){
        // get the local mouse position (relative to a window)
        if (event.type == Event::Closed)
            window.close();
      }

      window.clear();
      //monStatic.draw();
      view1.setSize(window.getSize().x, window.getSize().y);
      window.setView(view1);
      window.draw(*monStatic.getSprite());
      window.draw(*monStatic2.getSprite());
      window.draw(*monStatic3.getSprite());
      window.draw(*monStatic4.getSprite());

      window.display();
      sf::sleep(sf::milliseconds(1000/framerate));
  }
  return 0;
}
