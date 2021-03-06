#ifndef __GAME_HH__
#define __GAME_HH__

#include <SFML/Graphics.hpp>
#include <GL/gl.h>
#include <GL/glu.h>
#include "World.hh"

class Game
{
public:
  static Game	&instance();
  ~Game();

  void		run();
  double	getTick() const;
private:
  Game();

  double		_elapsedTime;
  double		_sec;
  World			_world;
};

#endif
