#include "Game.hh"
#include <iostream>
#include <unistd.h>
#include "Window.hpp"

Game::Game()
{
  Window::instance().create(sf::VideoMode(1600, 900), "GalaskWorld",  sf::Style::Default, sf::ContextSettings(32));
  Window::instance().setVerticalSyncEnabled(true); 
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(70, (double) 1600 / 900, 0.01, 10000);
  glEnable(GL_DEPTH_TEST);
  glEnable(GL_TEXTURE_2D);
  std::cout << "window create\n";
  Window::instance().setActive();
  Window::instance().setFramerateLimit(60);
  Window::instance().setVerticalSyncEnabled(true);
  Window::instance().setJoystickThreshold(100);
  _sec = 0;
  _elapsedTime = 0;
  _world.init();
}

Game::~Game()
{

}

Game
&Game::instance()
{
  static Game i;

  return (i);
}

double
Game::getTick() const
{
  return (_elapsedTime);
}

void
Game::run()
{
  sf::Clock     clock;

  _world.load();
  while (Window::instance().isOpen())
    {
      clock.restart();
      //this->update();
      _world.update();
      _world.draw();
      Window::instance().display();
      _elapsedTime = clock.getElapsedTime().asSeconds();
      _sec += _elapsedTime;
      /*      if (_sec >= 0.1)
	{
	  sf::Mouse::setPosition(sf::Vector2i(400, 300), Window::instance());
	  _sec = 0;
	  }*/
      usleep(100);
    }  
}
