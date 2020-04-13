#include "Camera.h"
#include "Actor.h"
#include <SFML/Graphics.hpp>

Camera::Camera(): m_currentView(sf::FloatRect(0.f, 0.f, 0.f, 0.f)), m_zoomLevel(1.0f)
{

};

Camera::Camera(sf::Vector2i): m_currentView(sf::FloatRect(0.f, 0.f, 0.f, 0.f)), m_zoomLevel(1.0f)
{

};

sf::View Camera::getView()
{
  return m_currentView;
}

void Camera::setWinScale(float x, float y)
{
  m_currentView.setSize(x*(1/m_zoomLevel), y*(1/m_zoomLevel));
}

void Camera::move(sf::Vector2f movement)
{
  m_currentView.move(movement);
}

float Camera::getZoom()
{
  return m_zoomLevel;
}

void Camera::setZoom(float zoom)
{
  if(zoom>=0.f)
  {
    m_zoomLevel=zoom;
  }
}

void Camera::zoom(float zoom)
{
  if(m_zoomLevel+zoom>=0.f)
  {
    m_zoomLevel+=zoom;
  }
}
