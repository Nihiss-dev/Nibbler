//
// main.cpp for nibbler in /home/buathi_q/rendu/cpp_nibbler
// 
// Made by BUATHIER Quentin
// Login   <buathi_q@epitech.net>
// 
// Started on  Tue Mar 31 18:05:11 2015 BUATHIER Quentin
// Last update Tue Apr  7 16:10:48 2015 Sylvain GIROD
//

#include "CWindow.h"

extern "C" {
  IWindow			*init(int width, int height)
  {
    return (new CWindow(width, height));
  }

  void				destroy(IWindow *window)
  {
    delete window;
  }
}
