#include "labyrinthe.hpp"

int		main(int argc, char **argv)
{
	s_map	*data;

	data = loadfile((argc == 2) ? argv[1] : "creationsample");
	delete (data->map);
	delete(data);
	return (0);
}
