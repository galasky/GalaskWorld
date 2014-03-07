#include "Player.hh"
#include "rotation.h"

Player::Player(const sf::Vector3f &position, Camera *cam)
  : _position(position),
    _color(sf::Color(255, 125, 0)),
    _block(position, sf::Vector3f(1, 1, 1), _color)
{
  _avance = 0;
  _cote = 0;
  _v.x = 1;
  _v.y = 0;
  _v.z = 0;

  _cam = cam;
  _speed = 1;
  _ressource.setBlock(42);
  _ressource.setPow(42);
  _ressource.setMatier(3);
  _ressource.setPower(5);
}

Player::~Player()
{

}

void
Player::draw()
{
  _block.draw();
}

void
Player::run()
{
  if (_ressource.getPow() > 0)
    {
      _speed = 3;
      _ressource.setPow(_ressource.getPow() - 1);
    }
}

bool
Player::space()
{
  if (_ressource.getBlock() > 0)
    {
      _ressource.setBlock(_ressource.getBlock() - 1);
      return (true);
    }
  return (false);
}

Ressource
Player::getRessource()
{
  return (_ressource);
}

sf::Color
Player::getColor() const
{
  return (_color);
}

void
Player::update()
{
  _ressource.update();
  _r = _cam->getR();

  _v.x = 1;
  _v.y = 0;
  _v.z = 0;
  rotation_z(_r.z, _v);
  if (_avance != 0)
    {
      _avance = (_avance < 0 ? _avance +  0.01 : _avance - 0.01);
      if (_avance >= -.01 && _avance <= .01)
        {
          _avance = 0;
        }
      _position.x += _v.x * _avance * _speed;
      _position.y += _v.y * _avance * _speed;
      _cam->setPl(_position);
      _block.setPosition(_position);
    }
  if (_cote != 0)
    {
      rotation_z(-PI / 2, _v);
      _cote = (_cote < 0 ? _cote +  0.01 : _cote - 0.01);
      if (_cote >= -.01 && _cote <= .01)
        {
          _cote = 0;
        }
      _position.x += _v.x * _cote * _speed;
      _position.y += _v.y * _cote * _speed;
      _cam->setPl(_position);
      _block.setPosition(_position);
    }
  _speed = 1;
}

void
Player::up()
{
  _avance = -0.2;
  /*  _position.x -= _v.x * 0.1;
  _position.y -= _v.y * 0.1;
  _cam->setPl(_position);
  _block.setPosition(_position);*/
}

void
Player::down()
{
  _avance = 0.2;
}

void
Player::left()
{
  _cote = 0.2;
}

void
Player::right()
{
  _cote = -0.2;
}

sf::Vector3f
Player::getPos() const
{
  return (_position);
}
