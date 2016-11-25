/*
** Map.h for nibbler in /home/buathi_q/rendu/cpp_nibbler
** 
** Made by BUATHIER Quentin
** Login   <buathi_q@epitech.net>
** 
** Started on  Tue Apr  7 10:32:32 2015 BUATHIER Quentin
** Last update Tue Apr  7 17:00:17 2015 Sylvain GIROD
*/

class		Map;

#ifndef MAP_H_
# define MAP_H_

# include <list>
# include "IWindow.h"
# include "GameOver.h"
# include "Snake.h"

class			Map
{
 public:
  Map(IWindow *window, int width, int height);
  ~Map();

  Snake			*getSnake() const;
  void			update();

  int			getWidth() const;
  int			getHeight() const;
  unsigned int		getScore() const;

  std::list<int>	&getFruits();

 private:
  Snake			*_snake;
  int			_width;
  int			_height;
  IWindow		*_window;
  std::list<int>	_fruits;
  unsigned int		_score;
};

#endif
