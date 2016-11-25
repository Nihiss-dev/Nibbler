##
## Makefile for nibbler in /home/buathi_q/rendu/cpp_nibbler
## 
## Made by BUATHIER Quentin
## Login   <buathi_q@epitech.net>
## 
## Started on  Tue Mar 31 17:13:00 2015 BUATHIER Quentin
## Last update Wed Apr  8 17:04:40 2015 Alexis Feldmar
##

LD		= ld
CPP		= g++
RM		= rm -rf

CPPFLAGS	= -W -Wall -Wextra -Werror
LDFLAGS		= -ldl

NAME		= nibbler
NAME_SFML	= lib_nibbler_sfml.so
NAME_OPENGL	= lib_nibbler_opengl.so
NAME_NCURSES	= lib_nibbler_ncurses.so

SRCS		= $(shell find src/main -type f -name "*.cpp")
SRCS_SFML	= $(shell find src/sfml -type f -name "*.cpp")
SRCS_OPENGL	= $(shell find src/opengl -type f -name "*.cpp")
SRCS_NCURSES	= $(shell find src/ncurses -type f -name "*.cpp")

OBJS		= $(subst src/, obj/, $(SRCS:.cpp=.o))
OBJS_SFML	= $(subst src/, obj/, $(SRCS_SFML:.cpp=.o))
OBJS_OPENGL	= $(subst src/, obj/, $(SRCS_OPENGL:.cpp=.o))
OBJS_NCURSES	= $(subst src/, obj/, $(SRCS_NCURSES:.cpp=.o))

all: $(NAME) $(NAME_SFML) $(NAME_NCURSES) $(NAME_OPENGL)

$(NAME): $(OBJS)
	$(CPP) -o $@ $^ $(LDFLAGS) -L. -Wl,--rpath=. -rdynamic

$(NAME_SFML): $(OBJS_SFML)
	$(LD) -shared -o $@ $^ -lsfml-window -lsfml-graphics -lsfml-system

$(NAME_OPENGL): $(OBJS_OPENGL)
	$(LD) -shared -o $@ $^ -lGL -lGLU -lSDL

$(NAME_NCURSES): $(OBJS_NCURSES)
	$(CPP) -shared -o $@ $^ -lncurses -ltinfo

obj/sfml/%.o: src/sfml/%.cpp
	@mkdir -p $(dir $@)
	$(CPP) -fPIC -o $@ -c $< $(CPPFLAGS) -I include

obj/opengl/%.o: src/opengl/%.cpp
	@mkdir -p $(dir $@)
	$(CPP) -fPIC -o $@ -c $< $(CPPFLAGS) -I include

obj/ncurses/%.o: src/ncurses/%.cpp
	@mkdir -p $(dir $@)
	$(CPP) -fPIC -o $@ -c $< $(CPPFLAGS) -I include

obj/%.o: src/%.cpp
	@mkdir -p $(dir $@)
	$(CPP) -o $@ -c $< $(CPPFLAGS) -I include

clean:
	$(RM) $(OBJS)
	$(RM) $(OBJS_SFML)
	$(RM) $(OBJS_OPENGL)
	$(RM) $(OBJS_NCURSES)

fclean: clean
	$(RM) $(NAME)
	$(RM) $(NAME_SFML)
	$(RM) $(NAME_OPENGL)
	$(RM) $(NAME_NCURSES)

re: fclean all

.PHONY: all clean fclean re
