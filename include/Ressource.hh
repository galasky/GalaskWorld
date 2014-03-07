#ifndef __RESSOURCE_HH__
#define __RESSOURCE_HH__

#include <SFML/Graphics.hpp>

class Ressource
{
public:
  Ressource();
  ~Ressource();

  void	setBlock(int);
  int	getBlock() const;
  void	setMatier(int);
  int	getMatier() const;
  void	setPower(int);
  int	getPower() const;
  void	setPow(int);
  int	getPow() const;
  void	update();
  void	draw();
private:
  int		_block;
  int		_matier;
  int		_power;
  int		_pow;
  sf::Text	_tBlock;
  sf::Text	_tMatier;
  sf::Text	_tPower;
  sf::Text	_tPow;
  sf::Font	_font;
  double	_sec;
  double	_sec2;
};

#endif
