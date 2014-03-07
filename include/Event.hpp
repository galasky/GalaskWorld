#ifndef	__EVENT_HPP__
#define	__EVENT_HPP__

#include <SFML/Graphics.hpp>

class	Event
{
public:
  static sf::Event &instance();
private:
  Event();
  ~Event();
};

#endif
