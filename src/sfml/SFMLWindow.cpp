//
// SFMLWindow.cpp for nibbler in /home/buathi_q/rendu/cpp_nibbler
// 
// Made by BUATHIER Quentin
// Login   <buathi_q@epitech.net>
// 
// Started on  Tue Mar 31 17:35:34 2015 BUATHIER Quentin
// Last update Tue Apr  7 16:47:20 2015 BUATHIER Quentin
//

#include "SFMLWindow.h"

SFMLWindow::SFMLWindow(int width, int height)
{
  _window = new sf::RenderWindow(sf::VideoMode(width * BLOCK_SIZE, height * BLOCK_SIZE), "Nibbler");
}

SFMLWindow::~SFMLWindow()
{
  delete _window;
}

bool			SFMLWindow::isOpen() const
{
  return (_window->IsOpened());
}

void			SFMLWindow::close()
{
  _window->Close();
}

void			SFMLWindow::update(Snake *s)
{
  sf::Event		event;

  while (_window->GetEvent(event))
    {
      if (event.Type == sf::Event::Closed)
	_window->Close();
      else if ((event.Type == sf::Event::KeyPressed) && (event.Key.Code == sf::Key::Escape))
	_window->Close();
      else if ((event.Type == sf::Event::KeyPressed) && (event.Key.Code == sf::Key::Left))
	s->left();
      else if ((event.Type == sf::Event::KeyPressed) && (event.Key.Code == sf::Key::Right))
	s->right();
    }
}

void			SFMLWindow::clear()
{
  _window->Clear();
}

void			SFMLWindow::draw(Map &m)
{
  std::list<int> const	*nodes;
  std::list<int>	*fruits;

  nodes = &m.getSnake()->getNodes();
  fruits = &m.getFruits();
  for(std::list<int>::const_iterator it = nodes->begin(); it != nodes->end(); it++)
    drawSquare(m, *it, sf::Color(255, 255, 255, 255));
  for(std::list<int>::iterator it = fruits->begin(); it != fruits->end(); it++)
    drawSquare(m, *it, sf::Color(255, 0, 0, 255));
}

void			SFMLWindow::display()
{
  _window->Display();
}

void			SFMLWindow::drawSquare(Map const &m, int pos, sf::Color color)
{
  sf::Shape		r;

  r = sf::Shape::Rectangle((pos % m.getWidth()) * BLOCK_SIZE, (pos / m.getWidth()) * BLOCK_SIZE,
			   (pos % m.getWidth() + 1) * BLOCK_SIZE, (pos / m.getWidth() + 1) * BLOCK_SIZE,
			   color);
  _window->Draw(r);
}
