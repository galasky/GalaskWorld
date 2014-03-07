#ifndef __BLOCK_HH__
#define __BLOCK_HH__

#include <SFML/System/Vector3.hpp>
#include <SFML/Graphics/Color.hpp>

class Block
{
public:
  Block(const sf::Vector3f &position, const sf::Vector3f &size, const sf::Color &color);
  ~Block();

  void	draw();
  void	setV(const sf::Vector3f &);
  void	setPosition(const sf::Vector3f &);
  void	setColor(const sf::Color &);
private:
  sf::Vector3f  _position;
  sf::Vector3f  _size;
  sf::Color	_color;
  sf::Vector3f	_v;
};

#endif
