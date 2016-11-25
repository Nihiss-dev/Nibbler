/*
** IWindow.h for nibbler in /home/buathi_q/rendu/cpp_nibbler
** 
** Made by BUATHIER Quentin
** Login   <buathi_q@epitech.net>
** 
** Started on  Tue Mar 31 17:33:24 2015 BUATHIER Quentin
** Last update Tue Apr  7 12:21:18 2015 BUATHIER Quentin
*/

class			IWindow;

#ifndef IWINDOW_H_
# define IWINDOW_H_

# define		TIME_SLEEP      140000

# include "Map.h"
# include "Snake.h"

class			IWindow
{
 public:
  virtual ~IWindow() {};

  virtual bool		isOpen() const = 0;
  virtual void		close() = 0;

  virtual void		update(Snake*) = 0;
  virtual void		clear() = 0;
  virtual void		draw(Map &) = 0;
  virtual void		display() = 0;
};

#endif
