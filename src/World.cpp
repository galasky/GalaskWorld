#include <GL/gl.h>
#include <GL/glu.h>
#include "World.hh"
#include <iostream>
#include "Window.hpp"
#include "Event.hpp"
#include <math.h>

#define X       10
#define Y       17

int random(int a, int b)
{
  return rand()%(b-a) +a;
}

World::World()
  : _player(sf::Vector3f((float) SIZE_MAP / 2, (float) SIZE_MAP / 2, 1), &_cam),
    _cam(sf::Vector3f((float) SIZE_MAP / 2, (float) SIZE_MAP / 2, 10))
{
}

void
World::init()
{
  srand(time(NULL));
  _mouse.x = 400;
  _mouse.y = 300;
  sf::Mouse::setPosition(_mouse, Window::instance());
  _texture.loadFromFile("assets/texture/floor.jpg");
  sf::Texture::bind(&_texture);
  image.loadFromFile("assets/texture/floor.jpg");
  glGenTextures(1, &texture);
  glBindTexture(GL_TEXTURE_2D, texture);
}

void
World::load()
{
  _map.resize(SIZE_MAP);
  for (int y = 0; y < SIZE_MAP; y++)
    {
      _map[y].resize(SIZE_MAP);
      for (int x = 0; x < SIZE_MAP; x++)
	{
	  if (x == 0 || x == SIZE_MAP - 1 || y == 0 || y == SIZE_MAP - 1)
	    _map[y][x] = new Block(sf::Vector3f(x, y, 0), sf::Vector3f(1, 1, 1), sf::Color(255, 255, 255));
	  else
	    {
	      int r = random(0, SIZE_MAP * 10);
	      if (r == 1)
		_map[y][x] = new Block(sf::Vector3f(x, y, 0), sf::Vector3f(1, 1, 1), sf::Color(0, 255, 0));
	      else if (r == 2)
		_map[y][x] = new Block(sf::Vector3f(x, y, 0), sf::Vector3f(1, 1, 1), sf::Color(255, 0, 0));
	      else
		_map[y][x] = NULL;
	    }
	}
    }
  std::cout << "Map Finish Load" << std::endl;
}

World::~World()
{
}

void
World::testZone()
{
  
}

void
World::space()
{
  sf::Vector3f	p = _player.getPos();

  if (_map[(int) p.y][(int) p.x] != NULL)
    _map[(int) p.y][(int) p.x]->setColor(_player.getColor());
  else
    {
      if (_player.space())
	_map[(int) p.y][(int) p.x] = new Block(sf::Vector3f((int) p.x, (int) p.y, 0), sf::Vector3f(1, 1, 1), _player.getColor());
    }
}

void
World::update()
{
  while (Window::instance().pollEvent(Event::instance()))
    {
      _key["Left"] = sf::Keyboard::isKeyPressed(sf::Keyboard::Left);
      _key["Right"] = sf::Keyboard::isKeyPressed(sf::Keyboard::Right);
      _key["Up"] = sf::Keyboard::isKeyPressed(sf::Keyboard::Up);
      _key["Down"] = sf::Keyboard::isKeyPressed(sf::Keyboard::Down);
      _key["E"] = sf::Keyboard::isKeyPressed(sf::Keyboard::E);
      _key["A"] = sf::Keyboard::isKeyPressed(sf::Keyboard::A);
      _key["Z"] = sf::Keyboard::isKeyPressed(sf::Keyboard::Z);
      _key["Q"] = sf::Keyboard::isKeyPressed(sf::Keyboard::Q);
      _key["S"] = sf::Keyboard::isKeyPressed(sf::Keyboard::S);
      _key["D"] = sf::Keyboard::isKeyPressed(sf::Keyboard::D);
      _key["Space"] = sf::Keyboard::isKeyPressed(sf::Keyboard::Space);
      _key["Shift"] = sf::Keyboard::isKeyPressed(sf::Keyboard::LShift);

      if (Event::instance().type == sf::Event::Closed)
	Window::instance().close();
      else if (Event::instance().type == sf::Event::MouseMoved)
	{
	}
    }
  _cam.update();
  _player.update();
  if (_key["Left"])
    _cam.left();
  if (_key["Right"])
    _cam.right();
  if (_key["Up"])
    _cam.up();
  if (_key["Down"])
    _cam.down();
  if (_key["E"])
    _cam.scroll(-1);
  if (_key["A"])
    _cam.scroll(1);
  if (_key["S"])
    _player.down();
  if (_key["Z"])
    _player.up();
  if (_key["Q"])
    _player.left();
  if (_key["D"])
    _player.right();
  if (_key["Space"])
    this->space();
  if (_key["Shift"])
    _player.run();
}

void
World::draw()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  gluLookAt(_cam.pos.x, _cam.pos.y, _cam.pos.z, _player.getPos().x + .5, _player.getPos().y + .5 - 0.000001, 0, 0, 0, 1);


  gluBuild2DMipmaps(GL_TEXTURE_2D, GL_RGBA, image.getSize().x, image.getSize().y, GL_RGBA, GL_UNSIGNED_BYTE, image.getPixelsPtr());
  //glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
  //glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
  //glDisableClientState(GL_NORMAL_ARRAY);
  //glDisableClientState(GL_COLOR_ARRAY);

  glBindTexture(GL_TEXTURE_2D, texture);
  glBegin(GL_QUADS);
  //  glColor3f(255, 255, 255);
  glTexCoord2d(0,0);			glVertex3d(0,0,0);
  glTexCoord2d(SIZE_MAP,0);		glVertex3d(SIZE_MAP,0,0);
  glTexCoord2d(SIZE_MAP,SIZE_MAP);	glVertex3d(SIZE_MAP,SIZE_MAP,0);
  glTexCoord2d(0,SIZE_MAP);		glVertex3d(0,SIZE_MAP,0);

  glEnd();
  
  glBegin(GL_QUADS);
  
  for (int y = 0; y < SIZE_MAP; y++)
    {
      for (int x = 0; x < SIZE_MAP; x++)
	{
	  if (_map[y][x] != NULL)
	    _map[y][x]->draw();
	}      
    }
  _player.draw();
  glEnd();
  glFlush();
  _player.getRessource().draw();
}
