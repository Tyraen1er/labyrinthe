#include "labyrinthe.hpp"

int		main(int argc, char **argv)
{
	std::string map_file = (argc == 2) ? argv[1] : "creationsample";
	s_map	data;

	loadfile(map_file, data);
	delete(data);
	return (0);
}
