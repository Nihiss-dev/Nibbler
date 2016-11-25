//
// main.cpp for nibbler in /home/buathi_q/rendu/cpp_nibbler
// 
// Made by BUATHIER Quentin
// Login   <buathi_q@epitech.net>
// 
// Started on  Tue Mar 31 18:05:11 2015 BUATHIER Quentin
// Last update Tue Mar 31 18:13:24 2015 BUATHIER Quentin
//

#include "SFMLWindow.h"

extern "C" {
  IWindow			*init(int width, int height)
  {
    return (new SFMLWindow(width, height));
  }

  void				destroy(IWindow *window)
  {
    delete window;
  }
}
