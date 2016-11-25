/*
** Snake.h for nibbler in /home/buathi_q/rendu/cpp_nibbler
** 
** Made by BUATHIER Quentin
** Login   <buathi_q@epitech.net>
** 
** Started on  Tue Apr  7 10:39:05 2015 BUATHIER Quentin
** Last update Tue Apr  7 12:03:00 2015 BUATHIER Quentin
*/

class		Snake;

#ifndef SNAKE_H_
# define SNAKE_H_

# include <map>
# include <list>
# include <algorithm>
# include "Map.h"

class			Snake
{
 public:
  Snake(Map*, int, int);
  ~Snake();

  void			update();
  void			left();
  void			right();

  std::list<int> const	&getNodes() const;

  enum direction
  {
    LEFT = 0,
    DOWN = 1,
    RIGHT = 2,
    UP = 3
  };

 private:
  Map			*_map;
  std::list<int>	_nodes;
  direction		_direction;
};

#endif
