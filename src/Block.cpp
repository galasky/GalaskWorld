#include "Block.hh"
#include <GL/gl.h>
#include <GL/glu.h>
#include <iostream>

Block::Block(const sf::Vector3f &position, const sf::Vector3f &size, const sf::Color &color)
  : _position(position),
    _size(size),
    _color(color),
    _v(1, 0, 0)
{
}

Block::~Block()
{
}

void
Block::setColor(const sf::Color &c)
{
  _color = c;
}

void
Block::draw()
{
  glColor3f(_color.r, _color.g, _color.b);
  glVertex3d(_position.x, _position.y, 0);
  glVertex3d(_position.x + _size.x, _position.y, 0);
  glVertex3d(_position.x + _size.x, _position.y + _size.y, 0);
  glVertex3d(_position.x, _position.y + _size.y, 0);

  glColor3f(0,0,0);
  glVertex3d(_position.x, _position.y, 0);
  glColor3f(_color.r, _color.g, _color.b);
  glVertex3d(_position.x, _position.y, 1 + _position.z);
  glVertex3d(_position.x + _size.x, _position.y, 1 + _position.z);
  glColor3f(0,0,0);
  glVertex3d(_position.x + _size.x, _position.y, 0);

  glVertex3d(_position.x, _position.y, 0);
  glColor3f(_color.r, _color.g, _color.b);
  glVertex3d(_position.x, _position.y, 1 + _position.z);
  glVertex3d(_position.x, _position.y + _size.y, 1 + _position.z);
  glColor3f(0,0,0);
  glVertex3d(_position.x, _position.y + _size.y, 0);

  glColor3f(_color.r, _color.g, _color.b);
  glVertex3d(_position.x, _position.y, 1 + _position.z);
  glVertex3d(_position.x + _size.x, _position.y, 1 + _position.z);
  glVertex3d(_position.x + _size.x, _position.y + _size.y, 1 + _position.z);
  glVertex3d(_position.x, _position.y + _size.y, 1 + _position.z);

  glColor3f(0,0,0);
  glVertex3d(_position.x, _position.y + _size.y, 0);
  glColor3f(_color.r, _color.g, _color.b);
  glVertex3d(_position.x, _position.y + _size.y, 1 + _position.z);
  glVertex3d(_position.x + _size.x, _position.y + _size.y, 1 + _position.z);
  glColor3f(0,0,0);
  glVertex3d(_position.x + _size.x, _position.y + _size.y, 0);

  glVertex3d(_position.x + _size.x, _position.y, 0);
  glColor3f(_color.r, _color.g, _color.b);
  glVertex3d(_position.x + _size.x, _position.y, 1 + _position.z);
  glVertex3d(_position.x + _size.x, _position.y + _size.y, 1 + _position.z);
  glColor3f(0,0,0);
  glVertex3d(_position.x + _size.x, _position.y + _size.y, 0);
}

void
Block::setPosition(const sf::Vector3f &pos)
{
  _position = pos;
}
