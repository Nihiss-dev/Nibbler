/*
** CWindow.h for CWindow in /home/girod_s/rendu/cpp_nibbler/include
** 
** Made by Sylvain GIROD
** Login   <girod_s@epitech.net>
** 
** Started on  Tue Apr  7 14:12:19 2015 Sylvain GIROD
** Last update Tue Apr  7 14:28:54 2015 Sylvain GIROD
*/

#ifndef CWINDOW_H_
# define CWINDOW_H_

#include <curses.h>
#include "IWindow.h"
#include "Map.h"
#include "Snake.h"

class		CWindow : public IWindow
{
 public:
  CWindow(int width, int height);
  ~CWindow();

  bool		isOpen() const;
  void		close();

  void		update(Snake*);
  void		clear();
  void		draw(Map&);
  void		display();

 private:
  bool		_isopened;
  WINDOW	*_window;
};

#endif
