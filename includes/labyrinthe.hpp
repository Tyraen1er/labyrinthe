#ifndef LABYRINTHE_H
# define LABYRINTHE_H

# ifdef __linux__
#  include <SDL2/SDL.h>
# elif __APPLE__
#
# endif

# include <iostream>
# include <vector>
# include <fstream>

# define WCTOR<int> std::vector<std::vector<int>>

struct		s_point
{
	float	x;
	float	y;
};

struct			s_map
{
	WCTOR<int>	map;
	int			limitx;
	int			limity;
	s_point		player;
	s_point		plane;
};

void	init_sdl();
s_map	loadfile(char *argv);

#endif
