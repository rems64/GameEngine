#ifndef DEF_ACTOR
#define DEF_ACTOR

#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include "GameObject.h"
#include "SceneComponent.h"


using namespace std;

class Actor : public GameObject
{
  public:
    using GameObject::GameObject;
    Actor();
    ~Actor();
    Actor(sf::Vector2f);

    void setLocation(sf::Vector2f);
    void move(sf::Vector2f);
    sf::Vector2f getLocation();

    vector<sf::Sprite *> getSprites();
    virtual std::vector<sf::Sprite *> getDraw();

    bool addChild(SceneComponent*);

    void setSimulatePhysics(bool);

    void updatePhysicsTick(float);
    virtual void updateComponent();
  private:
    std::vector<SceneComponent> m_childs;
    bool m_simulatePhysics;
    std::vector<sf::Vector2f> m_totalExtForces;
    float m_mass;
    float creationTime = 0;
    sf::Vector2f m_location;
    sf::Clock m_clock;
    sf::Time m_physicLastTime;
    sf::Vector2f m_velocity;
};

#endif
