//
// main.cpp for nibbler in /home/feldma_a/Documents/test/nibbler/src
// 
// Made by Alexis Feldmar
// Login   <feldma_a@epitech.net>
// 
// Started on  Tue Apr  7 13:34:42 2015 Alexis Feldmar
// Last update Tue Apr  7 13:54:40 2015 Alexis Feldmar
//

#include "openglWindow.h"

extern "C" {
  IWindow			*init(int width, int height)
  {
    return (new openglWindow(width, height));
  }

  void				destroy(IWindow *window)
  {
    delete window;
  }
}
