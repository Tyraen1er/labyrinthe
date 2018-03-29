#include "labyrinthe.hpp"

bool	get_map(s_map &data, const std::string &argv)
{
	std::ifstream	fd(argv);
	char			c = '\0';

	if (!fd)
	{
		std::cout << "erreur d'ouverture de la map"<< std::endl;
		return (false);
	}
	data.map.push_back(std::vector<int>);
	while (fd.get(c))
	{
		if (c == '\n')
			data.map.push_back(std::vector<int>);
		if ('0' <= c && c <= '9')
			data.map.back().push_back(c - '0');
	}
	for (unsigned int i = 0; i < data.map.size() - 1; ++i)
	{
		if (data.map[i].size() != data.map[i + 1].size())
			return (false);
	}
	return (true);
}

bool	other_carac()
{
	return (true);
}

s_map	loadfile(const std::string &argv, s_map &data)
{
	//carte délimitée par des 1
	//carte rectangle
	//1 seul 'X' présent
	//Pas d'autres caractère que '0' '1' 'X'
	if (!get_map(data, argv) || !other_carac())
		exit(3);
	return (data);
}
