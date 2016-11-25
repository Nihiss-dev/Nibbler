//
// Snake.cpp for nibbler in /home/buathi_q/rendu/cpp_nibbler
// 
// Made by BUATHIER Quentin
// Login   <buathi_q@epitech.net>
// 
// Started on  Tue Apr  7 10:45:06 2015 BUATHIER Quentin
// Last update Tue Apr  7 12:03:43 2015 BUATHIER Quentin
//

#include "Snake.h"

Snake::Snake(Map *map, int x, int y)
{
  _map = map;
  _direction = LEFT;
  _nodes.push_back(y * _map->getWidth() + x - 2);
  _nodes.push_back(y * _map->getWidth() + x - 1);
  _nodes.push_back(y * _map->getWidth() + x);
  _nodes.push_back(y * _map->getWidth() + x + 1);
}

Snake::~Snake()
{

}

void					Snake::update()
{
  std::list<int>::iterator		iter;
  std::map<direction, int>		map;

  map[UP] = -_map->getWidth();
  map[DOWN] = _map->getWidth();
  map[LEFT] = -1;
  map[RIGHT] = 1;
  if ((_direction == LEFT && _nodes.front() % _map->getWidth() == 0)
      || (_direction == RIGHT && _nodes.front() % _map->getWidth() == _map->getWidth() - 1))
    throw GameOver();
  _nodes.push_front(_nodes.front() + map[_direction]);
  if (_nodes.front() < 0 || _nodes.front() >= _map->getWidth() * _map->getHeight()
      || std::find(++_nodes.begin(), _nodes.end(), _nodes.front()) != _nodes.end())
    throw GameOver();
  iter = std::find(_map->getFruits().begin(), _map->getFruits().end(), _nodes.front());
  if (iter != _map->getFruits().end())
    _map->getFruits().erase(iter);
  else
    _nodes.pop_back();
}

void					Snake::left()
{
  std::map<direction, direction>	map;

  map[UP] = LEFT;
  map[LEFT] = DOWN;
  map[DOWN] = RIGHT;
  map[RIGHT] = UP;
  _direction = map[_direction];
}

void					Snake::right()
{
  std::map<direction, direction>	map;

  map[UP] = RIGHT;
  map[RIGHT] = DOWN;
  map[DOWN] = LEFT;
  map[LEFT] = UP;
  _direction = map[_direction];
}

std::list<int> const			&Snake::getNodes() const
{
  return (_nodes);
}
