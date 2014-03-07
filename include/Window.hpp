#ifndef	__WINDOW_HPP__
#define	__WINDOW_HPP__

#include <SFML/Graphics.hpp>

class	Window
{
public:
  static sf::RenderWindow &instance();
private:
  Window();
  ~Window();
};

#endif
