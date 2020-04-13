#ifndef DEF_GAME
#define DEF_GAME

#include <SFML/Graphics.hpp>
#include "Camera.h"
#include "GameObject.h"
#include "SceneComponent.h"
#include "Actor.h"

using namespace std;

class Game
{
  public:
    Game();
    Game(float, sf::Vector2i, string);
    void newLoop();
    void endLoop();
    sf::RenderWindow * getMainWindow();
    void updateLogic();
    void updateDraw();
    void close();
    bool isAlive();
    void setCanClose(bool);
    void setMainCamera(Camera*);
    Camera* m_currentCamera;
    sf::RenderWindow m_window;

    void updatePhysics();

    bool newSceneComponent(SceneComponent*);
    bool newActor(Actor*);
    void draw(sf::Sprite *);
    void setBackgroundColor(sf::Color);
  private:
    sf::Text m_txtFPS;
    bool m_canCloseMainWindow;
    bool m_isOpen = true;
    sf::Clock m_clock;
    float m_framerate;
    sf::Time m_startLoopTime;
    vector<SceneComponent *> m_gameObjects;
    vector<Actor *> m_gameActors;
    sf::Color m_backgroundColor;
};

#endif
