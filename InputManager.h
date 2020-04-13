#ifndef DEF_INPUTMANAGER
#define DEF_INPUTMANAGER

#include <SFML/Graphics.hpp>

class InputManager
{
  public:
    InputManager();
    bool isMouseCaptured();
    bool setCaptureMouse(bool);
    bool isKeyPressed(sf::Keyboard::Key);
  private:
    bool m_isMouseCaptured;
};

#endif
