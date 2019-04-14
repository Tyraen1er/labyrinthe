#include "labyrinthe.hpp"

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

	if (!map.isReady() || check_map(map, play) == false)
		return 0;
	init_sdl(play);
	return 0;
}
