#include "loadfile.h"

Loadfile::Loadfile(std::string path)
{
	std::ifstream	fd(path);
	std::string	buffer;

	if (!fd)
	{
		std::cout << ("Error for opening file") << std::endl;
	}
	while (getline(fd, buffer))
		m_content += buffer;
	fd.close();
}

Loadfile::Loadfile(const std::string path, std::string &file)
{
	std::ifstream	fd(path);
	std::string	buffer;

	file.clear();
	if (!fd)
	{
		std::cout << ("Error for opening file") << std::endl;
	}
	while (getline(fd, buffer))
		file += buffer;
	fd.close();
}

std::string	Loadfile::get()
{
	return m_content;
}
