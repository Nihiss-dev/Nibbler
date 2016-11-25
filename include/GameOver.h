/*
** GameOver.h for nibbler in /home/buathi_q/rendu/cpp_nibbler
** 
** Made by BUATHIER Quentin
** Login   <buathi_q@epitech.net>
** 
** Started on  Tue Apr  7 11:00:12 2015 BUATHIER Quentin
** Last update Tue Apr  7 11:01:05 2015 BUATHIER Quentin
*/

#ifndef GAMEOVER_H_
# define GAMEOVER_H_

# include <exception>

class			GameOver : public std::exception
{
 public:
  GameOver() {};
  ~GameOver() throw() {};
};

#endif
