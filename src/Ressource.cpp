#include "Ressource.hh"
#include "Window.hpp"
#include "Game.hh"

Ressource::Ressource()
  : _block(0),
    _matier(0),
    _sec(0.0),
    _sec2(0.0)
{
  _font.loadFromFile("assets/font/Transformers Movie.ttf");
  _tBlock.setFont(_font);
  _tBlock.setCharacterSize(42);
  _tBlock.setPosition(50, 758);
  _tBlock.setColor(sf::Color(0, 255, 0));

  _tPow.setFont(_font);
  _tPow.setCharacterSize(42);
  _tPow.setPosition(50, 800);
  _tPow.setColor(sf::Color(255, 0, 0));

  _tMatier.setFont(_font);
  _tMatier.setCharacterSize(42);
  _tMatier.setPosition(50, 50);
  _tMatier.setColor(sf::Color(0, 255, 0));

  _tPower.setFont(_font);
  _tPower.setCharacterSize(42);
  _tPower.setPosition(50, 92);
  _tPower.setColor(sf::Color(255, 0, 0));

}

Ressource::~Ressource()
{
}

void
Ressource::setBlock(int set)
{
  _block = set;
  _tBlock.setString("Block = " + std::to_string(_block));
}

int
Ressource::getBlock() const
{
  return (_block);
}

void
Ressource::setMatier(int set)
{
  _matier = set;
  _tMatier.setString("Block = +" + std::to_string(_matier));
}

int
Ressource::getPower() const
{
  return (_power);
}

void
Ressource::setPower(int set)
{
  _power = set;
  _tPower.setString("Power = +" + std::to_string(_power));
}


int
Ressource::getPow() const
{
  return (_pow);
}

void
Ressource::setPow(int set)
{
  _pow = set;
  _tPow.setString("Power = " + std::to_string(_pow));
}

void
Ressource::update()
{
  _sec += Game::instance().getTick();
  _sec2 += Game::instance().getTick();
  if (_sec >= 1 / (double) _matier)
    {
      _sec = 0;
      _block += 1;
      _tBlock.setString("Block = " + std::to_string(_block));
    }
  if (_sec2 >= 1 / (double) _power)
    {
      _sec2 = 0;
      _pow += 1;
      _tPow.setString("Power = " + std::to_string(_pow));
    }
}

int
Ressource::getMatier() const
{
  return (_matier);
}

void
Ressource::draw()
{
  Window::instance().pushGLStates();
  Window::instance().draw(_tBlock);
  Window::instance().draw(_tMatier);
  Window::instance().draw(_tPower);
  Window::instance().draw(_tPow);
  Window::instance().popGLStates();
}
