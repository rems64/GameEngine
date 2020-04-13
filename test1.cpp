#include <SFML/Graphics.hpp>
#include "InputManager.h"

using namespace sf;

int main()
{
    RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    CircleShape shape(100.f);
    InputManager monManager;
    shape.setFillColor(Color::Green);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event)){
          // get the local mouse position (relative to a window)
          if (monManager.isKeyPressed(sf::Keyboard::Left)) {
          //if (monManager.isMouseCaptured()) {
            window.close();
          }
          if (event.type == Event::Closed)
              window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}
