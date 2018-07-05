#include "loadfile.h"

int main()
{
	Loadfile	fichier("./coucou.txt");

	std::cout<<fichier.get();
	return 0;
}
