//
// Map.cpp for nibbler in /home/buathi_q/rendu/cpp_nibbler
// 
// Made by BUATHIER Quentin
// Login   <buathi_q@epitech.net>
// 
// Started on  Tue Apr  7 11:03:58 2015 BUATHIER Quentin
// Last update Tue Apr  7 17:03:04 2015 Sylvain GIROD
//

#include "Map.h"

Map::Map(IWindow *window, int width, int height)
{
  _width = width;
  _height = height;
  _window = window;
  _snake = new Snake(this, width / 2, height / 2);
  _score = 0;
}

Map::~Map()
{
  delete _snake;
}

Snake				*Map::getSnake() const
{
  return (_snake);
}

void				Map::update()
{
  if (_fruits.size() == 0)
    {
      _fruits.push_front(rand() % (_width * _height));
      _score += 8;
    }
  try
    {
      _snake->update();
    }
  catch(GameOver &e)
    {
      _window->close();
    }
}

int				Map::getWidth() const
{
  return (_width);
}

int				Map::getHeight() const
{
  return (_height);
}

std::list<int>			&Map::getFruits()
{
  return (_fruits);
}

unsigned int			Map::getScore() const
{
  return (_score > 8 ? _score - 8 : 0);
}
