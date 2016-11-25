/*
** openglWindow.h for nibbler in /home/feldma_a/Documents/test/nibbler/src/opengl
** 
** Made by Alexis Feldmar
** Login   <feldma_a@epitech.net>
** 
** Started on  Tue Apr  7 13:39:06 2015 Alexis Feldmar
** Last update Wed Apr  8 17:02:56 2015 Alexis Feldmar
*/

#ifndef OPENGLWINDOW_H_
# define OPENGLWINDOW_H_

# include <SDL/SDL.h>
# include <GL/gl.h>
# include <GL/glu.h>
# include "IWindow.h"

# define BLOCK_SIZE	20

class		openglWindow : public IWindow
{
 public:
  openglWindow(int width, int height);
  ~openglWindow();

  bool		isOpen() const;
  void		close();

  void		update(Snake*);
  void		clear();
  void		draw(Map&);
  void		display();
 private:
  void		drawSquare(Map&, int, int type);
  bool		_open;
};

#endif
