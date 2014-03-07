#ifndef __CAMERA_HH__
#define __CAMERA_HH__

#include <SFML/System/Vector3.hpp>
#include <SFML/Graphics.hpp>

class Camera
{
public:
  Camera(const sf::Vector3f &pl);
  ~Camera();

  void	up();
  void	down();
  void	left();
  void	right();
  void	scroll(float);
  void	update();
  void	setPl(const sf::Vector3f &);
  sf::Vector3f	getR() const;

  sf::Vector3f	pos;
private:
  bool		_scroll;
  double	_elapsedTime;
  double	_sec;
  sf::Clock	_clock;
  sf::Vector3f	_r;
  sf::Vector3f	_pl;
  sf::Vector3f	_b;
  double	_k;
  double	_x;
  double	_y;
};

#endif
