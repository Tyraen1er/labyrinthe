#include "labyrinthe.hpp"

bool	check_map(Loadfile map, Player &play)
{
	std::vector<std::vector<int> >	index;
	index = map.getInt();

	//rectangulaire
	for (unsigned int i = 0; i < index.size() - 1; ++i)
	{
		if (index[i].size() != index[i + 1].size())
		{
			std::cout<<"Votre carte n'est pas rectangulaire.";
			return false;
		}
	}
	//haut et bas
	for (unsigned int i = 0; i < index[0].size(); ++i)
	{
		if (index[0][i] != 1 || index[index.size() - 1][i] != 1)
		{
			std::cout<<"Votre carte n'est pas cernée de 1.";
			return false;
		}
	}
	//gauche et droite
	for (unsigned int i = 1; i < index.size(); ++i)
	{
		if (index[i][0] != 1 || index[i][index.size() - 1] != 1)
		{
			std::cout<<"Votre carte n'est pas cernée de 1.";
			return false;
		}
	}
	//init player et trouver 2
	bool verif = false;
	for (unsigned int i = 0; i < index.size(); ++i)
	{
		for (unsigned int it = 0; it < index[i].size(); ++it)
		{
			if (index[i][it] == 2)
			{
				if (verif)
				{
					std::cout<<"Il y a plusieurs '2' dans votre carte"<<
						std::endl;
					return false;
				}
				play.setPlayer(i, it);
				verif = true;
			}
		}
	}
	return true;
}

