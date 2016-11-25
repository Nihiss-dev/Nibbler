//
// main.cpp for nibbler in /home/buathi_q/rendu/cpp_nibbler
// 
// Made by BUATHIER Quentin
// Login   <buathi_q@epitech.net>
// 
// Started on  Tue Mar 31 17:29:12 2015 BUATHIER Quentin
// Last update Thu Apr  9 14:35:29 2015 BUATHIER Quentin
//

#include <dlfcn.h>
#include <iostream>
#include <unistd.h>
#include <cstdlib>
#include "IWindow.h"
#include "Map.h"

int		main(int ac, char **av)
{
  Map		*map;
  void		*dl;
  IWindow	*window;
  IWindow	*(*init)(int, int);
  void		(*destroy)(IWindow*);
  int		width;
  int		height;

  if (ac != 4)
    {
      std::cerr << "Usage: ./nibbler [WIDTH] [HEIGHT] [GRAPHICAL_LIB]" << std::endl;
      return (0);
    }
  if ((width = std::atoi(av[1])) < 20
      || (width = std::atoi(av[1])) > 50
      || (height = std::atoi(av[2])) < 20
      || (height = std::atoi(av[2])) > 50)
    {
      std::cerr << "Invalid width / height, minimum 20, maximum 50" << std::endl;
      return (1);
    }
  if ((dl = dlopen(av[3], RTLD_NOW)) == NULL)
    {
      std::cerr << "Can't open " << dlerror() << std::endl;
      return (1);
    }
  if ((init = (IWindow *(*)(int, int))dlsym(dl, "init")) == NULL)
    {
      std::cerr << "Can't load init function : " << dlerror() << std::endl;
      dlclose(dl);
      return (1);
    }
  if ((destroy = (void (*)(IWindow*))dlsym(dl, "destroy")) == NULL)
    {
      std::cerr << "Can't load destroy function : " << dlerror() << std::endl;
      dlclose(dl);
      return (1);
    }
  if ((window = init(width, height)) == NULL)
    {
      std::cerr << "Can't init window" << std::endl;
      dlclose(dl);
      return (1);
    }
  map = new Map(window, width, height);
  while (window->isOpen())
    {
      window->update(map->getSnake());
      map->update();
      window->clear();
      window->draw(*map);
      window->display();
      usleep(TIME_SLEEP);
    }
  destroy(window);
  dlclose(dl);
  std::cout << "Your score : " << map->getScore() << std::endl;
  delete map;
  return (0);
}
