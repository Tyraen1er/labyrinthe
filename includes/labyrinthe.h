#ifndef LABYRINTHE_H
# define LABYRINTHE_H

# ifdef __linux__
#  include <SDL2/SDL.h>
# elif __APPLE__
#
# endif
# include "libft.h"

typedef struct	s_map
{
	int			limitx;
	int			limity;
	double		**map;
	t_point		player;
	t_point		plane;
}				t_map;

typedef struct	s_sdl
{

}				t_sdl;

typedef struct	s_all
{
	t_sdl		sdl;
	t_map		map;
}				t_all;

void	init_sdl();
t_map	loadfile(char *argv);

#endif
