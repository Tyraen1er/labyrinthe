#include "labyrinthe.h"

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

void	sdl_loop()
{
	bool	continuer = true;
	SDL_Event evenements = {0};

	while (continuer)
	{
		if(evenements.type == SDL_QUIT)
			continuer = false;
	}
}

void init_sdl(Player &play)
{
	SDL_Window *fenetre(0);

	(void)play;
	if(SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		std::cout << "Erreur lors de l'initialisation de la SDL : " <<
			SDL_GetError() << std::endl;
		SDL_Quit();

		return ;
	}
	if (!(fenetre = SDL_CreateWindow("Labyrinthe", SDL_WINDOWPOS_CENTERED,
					SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN)))
	{
		std::cout << "Erreur lors de la creation de la fenetre : " <<
			SDL_GetError() << std::endl;
		SDL_Quit();
		return ;
	}
	sdl_loop();
	SDL_DestroyWindow(fenetre);
	SDL_Quit();
}

int		main(int argc, char **argv)
{
	Player		play;
	Loadfile	map((argc == 2) ? argv[1] : "creationsample");

	if (check_map(map, play) == false)
		return 0;
	init_sdl(play);
	return 0;
}
