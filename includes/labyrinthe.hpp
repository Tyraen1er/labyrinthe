#ifndef LABYRINTHE_H
# define LABYRINTHE_H

# ifdef __linux__
#  include <SDL2/SDL.h>
# elif __APPLE__
#  include <SDL.h>
# endif

# include <iostream>
# include <vector>
# include <fstream>

struct		s_point
{
	float	x;
	float	y;
};

struct			s_map
{
	std::vector<std::vector<int>>	map;
	int			limitx;
	int			limity;
	s_point		player;
	s_point		plane;
};

s_map	loadfile(std::string argv, s_map &data)

#endif
