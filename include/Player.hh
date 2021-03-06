#ifndef __PLAYER_HH__
#define __PLAYER_HH__

#include <SFML/System/Vector2.hpp>
#include "Block.hh"
#include "Ressource.hh"

#include "Camera.hh"

class Player
{
public:
  Player(const sf::Vector3f &position, Camera *cam);
  ~Player();

  void	update();
  void	draw();
  void	up();
  void	run();
  bool	space();
  void	down();
  void	left();
  void	right();
  Ressource	getRessource();
  sf::Color	getColor() const;
  sf::Vector3f	getPos() const;
private:
  sf::Color	_color;
  Block		_block;
  sf::Vector3f	_position;
  sf::Vector3f  _r;
  sf::Vector3f  _v;
  Ressource	_ressource;
  double	_avance;
  double	_cote;
  Camera *	_cam;
  int		_speed;
};

#endif
