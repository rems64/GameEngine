#ifndef DEF_SCENECOMPONENT
#define DEF_SCENECOMPONENT

#include <vector>
#include <SFML/Graphics.hpp>
#include "GameObject.h"

class SceneComponent : public GameObject
{
  public:
    using GameObject::GameObject;
    SceneComponent();
    ~SceneComponent();
    sf::Vector2f m_location;
    float m_rotation;
    sf::Vector2f m_size;
    sf::Sprite * getSprite();
    sf::Sprite m_sprite;
    sf::Texture *m_texture;
    std::vector<sf::Sprite *> getDraw();
    virtual void updateComponent();
  private:
};

#endif
