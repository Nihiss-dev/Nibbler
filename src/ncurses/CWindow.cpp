//
// CWindow.cpp for CWindow in /home/girod_s/rendu/cpp_nibbler/src/ncurses
// 
// Made by Sylvain GIROD
// Login   <girod_s@epitech.net>
// 
// Started on  Tue Apr  7 14:16:00 2015 Sylvain GIROD
// Last update Tue Apr  7 16:39:18 2015 Sylvain GIROD
//

#include "CWindow.h"

CWindow::CWindow(int width, int height)
{
  initscr();
  cbreak();
  keypad(stdscr, TRUE);
  refresh();
  timeout(0);
  _window = newwin(height + 2, width + 2, 0, 0);
  curs_set(0);
  _isopened = true;
}

CWindow::~CWindow()
{
  delwin(_window);
  endwin();
}

bool		CWindow::isOpen() const
{
  return (_isopened);
}

void		CWindow::close()
{
  _isopened = false;
}

void		CWindow::update(Snake *s)
{
  int ch;

  ch = getch();
  if (ch == KEY_LEFT)
    s->left();
  else if (ch == KEY_RIGHT)
    s->right();
  else if (ch == 27)
    this->close();
}

void		CWindow::clear()
{
  wclear(_window);
}

void		CWindow::draw(Map &m)
{
  std::list<int> const	*nodes;
  std::list<int>	*fruits;

  box(_window, 0, 0);
  nodes = &m.getSnake()->getNodes();
  fruits = &m.getFruits();
  for(std::list<int>::const_iterator it = nodes->begin(); it != nodes->end(); it++)
    mvwaddch(_window, *it / m.getWidth() + 1, *it % m.getWidth() + 1, '#');
  for(std::list<int>::iterator it = fruits->begin(); it != fruits->end(); it++)
    mvwaddch(_window, *it / m.getWidth() + 1, *it % m.getWidth() + 1, '@');
  wrefresh(_window);
}

void		CWindow::display()
{

}
