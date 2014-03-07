#include "Camera.hh"
#include "rotation.h"

Camera::Camera(const sf::Vector3f &pl)
{
  _scroll = false;
  _b.x = 10;
  _b.y = 0;
  _b.z = 0;
  
  _pl = pl;
  _pl.x += .5;
  _pl.y += .5;

  _r.x = -0.74;
  _r.y = 0;
  _r.z = 2.40159;
  rotation_x(_r.x, pos);
  rotation_y(_r.y, pos);
  rotation_z(_r.z, pos);
  pos = pl;
  _k = 0;
  _x = 0;
  _y = 0;
  _sec = 0;
  _elapsedTime = 0;
  _clock.restart();
}

Camera::~Camera()
{

}

void
Camera::down()
{
  _y = 2;
}

void
Camera::up()
{
  _y = -2;
}

void
Camera::left()
{
  _x = -2;
}

void
Camera::right()
{
  _x = 2;
}

sf::Vector3f
Camera::getR() const
{
  return (_r);
}

void
Camera::setPl(const sf::Vector3f &pl)
{
  _pl = pl;
  _pl.z = 10;
  _pl.x += .5;
  _pl.y += .5;
}

void
Camera::update()
{
  pos = _b;
  rotation_x(_r.x, pos);
  rotation_y(_r.y, pos);
  rotation_z(_r.z, pos);  
  pos += _pl;
  if (_k != 0)
    {
      _k = (_k < 0 ? _k +  0.05 : _k - 0.05);
      if (_k >= -.05 && _k <= .05)
	{
	  _k = 0;
	  _scroll = false;
	}
      _b.x += _k;
    }
  if (_x != 0)
    {
      _x = (_x < 0 ? _x +  0.05 : _x - 0.05);
      if (_x >= -.05 && _x <= .05)
	{
	  _x = 0;
	  _scroll = false;
	}
      _r.z += _x * 0.015;
    }
  if (_y != 0)
    {
      _y = (_y < 0 ? _y +  0.05 : _y - 0.05);
      if (_y >= -.05 && _y <= .05)
	{
	  _y = 0;
	  _scroll = false;
	}
      if (pos.z >= 5 && _y > 0)
	{
	  _r.y += _y * 0.015;
	}
      if (_r.y >= -PI / 2 - .2 && _y < 0)
	{
	  _r.y += _y * 0.015;
	}
    }
  _elapsedTime = _clock.getElapsedTime().asMilliseconds();
  _sec += _elapsedTime;
}

void
Camera::scroll(float k)
{
  _scroll = true;
  _k = k;
}
