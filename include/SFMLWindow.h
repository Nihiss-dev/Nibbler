/*
** SFMLWindow.h for nibbler in /home/buathi_q/rendu/cpp_nibbler
** 
** Made by BUATHIER Quentin
** Login   <buathi_q@epitech.net>
** 
** Started on  Tue Mar 31 17:35:53 2015 BUATHIER Quentin
** Last update Tue Apr  7 12:22:19 2015 BUATHIER Quentin
*/

#ifndef SFMLWINDOW_H_
# define SFMLWINDOW_H_

# include <SFML/Window/Input.hpp>
# include <SFML/Graphics.hpp>
# include "IWindow.h"
# include "Map.h"
# include "Snake.h"

# define		BLOCK_SIZE	20

class			SFMLWindow : public IWindow
{
 public:
  SFMLWindow(int width, int height);
  ~SFMLWindow();

  bool			isOpen() const;
  void			close();

  void			update(Snake*);
  void			clear();
  void			draw(Map&);
  void			display();

 private:
  sf::RenderWindow	*_window;

  void			drawSquare(Map const&, int, sf::Color);
};

#endif
