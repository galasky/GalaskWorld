#ifndef __WORLD_HH__
#define __WORLD_HH__

#include <vector>
#include "Block.hh"
#include "Player.hh"
#include "Camera.hh"
//#include <SFML/System/Vector2.hpp>

#define	SIZE_MAP	200

class World
{
public:
  World();
  ~World();

  void	init();
  void	load();
  void	draw();
  void	update();
  void	space();
  void	testZone();
private:
  std::vector<std::vector<Block *> >	_map;
  sf::Image				image;
  sf::Texture				_texture;
  Player				_player;
  Camera				_cam;
  sf::Vector2i				_mouse;
  GLuint				texture;
  std::map<std::string, bool>		_key;
};

#endif
