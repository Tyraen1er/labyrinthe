#include "labyrinthe.hpp"

bool	get_map(s_map &data, ifstream fd)
{
	char	c = '\0';

	while (fd.get(c))
	{
		if (c == '\n')
			data->map.push_back(std::vector<int>);
		if ('0' <= c && c <= '9')
			data->map.back().push_back(c - '0');
	}
	for (int i = 0; i < data->map.size() - 1; ++i)
	{
		if (data->map[i].size() != data->map[i + 1].size())
	}
	return (true);
}

bool	other_carac()
{
	return (true);
}

s_map	loadfile(char *argv)
{
	//carte délimitée par des 1
	//carte rectangle
	//1 seul 'X' présent
	//Pas d'autres caractère que '0' '1' 'X'
	ifstream	fd(argv);
	s_map		*data;

	if (!fd)
		exit(3);
	data = new(s_map);
	if (!limit() || !other_carac())
		exit(3);
	return (data);
}
