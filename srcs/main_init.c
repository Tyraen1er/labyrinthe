#include "labyrinthe.h"

int		main(int argc, char **argv)
{
	t_all	data;

	data.map = (argc == 2) ? loadfile(argv[1]) : loadfile("creationsample");
	init_sdl(&data);
	return (0);
}

void	init_sdl()
{
}
