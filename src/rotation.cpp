#include "rotation.h"

void rotation_x(double a, sf::Vector3f &f)
{
  sf::Vector3f  tempo;

  tempo = f;
  f.x *= 1;
  f.y = cos(a) * tempo.y - sin(a) * tempo.z;
  f.z = sin(a) * tempo.y + cos(a) * tempo.z;
}

void rotation_y(double a, sf::Vector3f &f)
{
  sf::Vector3f  tempo;

  tempo = f;
  f.x = cos(a) * tempo.x + sin(a) * tempo.z;
  f.y *= 1;
  f.z = -sin(a) * tempo.x + cos(a) * tempo.z;
}

void rotation_z(double a, sf::Vector3f &f)
{
  sf::Vector3f  tempo;

  tempo = f;
  f.x = cos(a) * tempo.x - sin(a) * tempo.y;
  f.y = sin(a) * tempo.x + cos(a) * tempo.y;
  f.z *= 1;
}
