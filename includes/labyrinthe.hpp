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
# include "libma.h"

#define WIDTH 800
#define HEIGHT 600

struct	Point
{
	double	x;
	double	y;
};

class			Player
{
	private:
		Point		pos;
		Point		dir;

	public:
		Player()
		{
			dir.x = 0;
			dir.y = -1;
		}
		void	setPlayer(int y, int x)
		{
			pos.x = x;
			pos.y = y;
			dir.x = 0;
			dir.y = -1;
		}
};

bool	checkmap(Loadfile map, Player play);

#endif
