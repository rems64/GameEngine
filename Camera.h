#ifndef DEF_CAMERA
#define DEF_CAMERA

#include <SFML/Graphics.hpp>

using namespace std;

class Camera
{
  public:
    //using Actor::Actor;
    Camera();
    Camera(sf::Vector2i);
    sf::View getView();
    void setWinScale(float, float);
    void move(sf::Vector2f);
    void setZoom(float);
    float getZoom();
    void zoom(float);
  private:
    sf::View m_currentView;
    float m_zoomLevel;
};

#endif
