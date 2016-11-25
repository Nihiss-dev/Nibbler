//
// openglWindow.cpp for nibbler in /home/feldma_a/Documents/test/nibbler/src/opengl
// 
// Made by Alexis Feldmar
// Login   <feldma_a@epitech.net>
// 
// Started on  Tue Apr  7 13:37:42 2015 Alexis Feldmar
// Last update Wed Apr  8 17:12:25 2015 BUATHIER Quentin
//

#include "openglWindow.h"

openglWindow::openglWindow(int width, int height)
{
  const SDL_VideoInfo	*info = NULL;

  SDL_Init(SDL_INIT_VIDEO);
  info = SDL_GetVideoInfo();
  SDL_SetVideoMode(width * BLOCK_SIZE, height * BLOCK_SIZE, info->vfmt->BitsPerPixel, SDL_OPENGL);
  glClearColor(0, 0, 0, 0);
  gluOrtho2D(0, width, 0, height);
  _open = true;
}

openglWindow::~openglWindow()
{
  SDL_Quit();
}

bool		openglWindow::isOpen() const
{
  return (_open);
}

void		openglWindow::close()
{
  _open = false;
}

void		openglWindow::update(Snake *s)
{
  SDL_Event	event;

  while (SDL_PollEvent(&event))
    if (event.type == SDL_QUIT)
      this->close();
    else if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_RIGHT)
      s->left();
    else if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_LEFT)
      s->right();
    else if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE)
      this->close();
}

void		openglWindow::clear()
{
  glClear(GL_COLOR_BUFFER_BIT);
}

void		openglWindow::draw(Map &m)
{
  std::list<int> const	*nodes;
  std::list<int>	*fruits;

  nodes = &m.getSnake()->getNodes();
  fruits = &m.getFruits();
  for (std::list<int>::const_iterator it = nodes->begin(); it != nodes->end(); it++)
    drawSquare(m, *it, 0);
  for (std::list<int>::iterator it = fruits->begin(); it != fruits->end(); it++)
    drawSquare(m, *it, 1);
}

void		openglWindow::display()
{
  glFlush();
  SDL_GL_SwapBuffers();
}

void		openglWindow::drawSquare(Map &m, int pos, int type)
{
  glBegin(GL_QUADS);
  if (type == 0)
    glColor3ub(255, 255, 255);
  if (type == 1)
    glColor3ub(255, 0, 0);

  glVertex2d(pos % m.getWidth(), pos / m.getWidth());
  glVertex2d(pos % m.getWidth() + 1, pos / m.getWidth());
  glVertex2d(pos % m.getWidth() + 1, pos / m.getWidth() + 1);
  glVertex2d(pos % m.getWidth(), pos / m.getWidth() + 1);

  glEnd();
}
