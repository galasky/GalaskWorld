#include "Event.hpp"

Event::Event()
{
  
}

Event::~Event()
{
  
}

sf::Event &
Event::instance()
{
  static sf::Event _instance;

  return _instance;
}
