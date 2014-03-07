#include "Window.hpp"

Window::Window()
{
  
}

Window::~Window()
{
  
}

sf::RenderWindow &
Window::instance()
{
  static sf::RenderWindow _instance(sf::VideoMode(1920, 1080), "GalaskyMotor", sf::Style::Fullscreen);

  return _instance;
}
