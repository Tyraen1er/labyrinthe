#include "loadfile.h"

Loadfile::Loadfile(std::string path)
{
	std::ifstream	fd(path);
	std::string	buffer;

	nb_line = -1;
	if (!fd)
	{
		std::cout << ("Error for opening file") << std::endl;
		return ;
	}
	while (getline(fd, buffer))
	{
		m_content += buffer + '\n';
		m_line.push_back(buffer);
		m_int.push_back(std::vector<int>{});
		for (unsigned int a = 0; a < buffer.size(); ++a) 
		{
			if ('0' <= buffer[a] && buffer[a] <= '9')
			{
				m_int.back().push_back(std::stoi(&buffer[a]));
				while ('0' <= buffer[a] && buffer[a] <= '9')
					++a;
			}
		}
	}
	fd.close();
}

Loadfile::Loadfile(const std::string path, std::string &file)
{
	std::ifstream	fd(path);
	std::string	buffer;

	file.clear();
	nb_line = -1;
	if (!fd)
	{
		std::cout << ("Error for opening file") << std::endl;
	}
	while (getline(fd, buffer))
	{
		file += buffer + '\n';
		m_line.push_back(buffer);
		m_int.push_back(std::vector<int>{});
		for (unsigned int a = 0; a < buffer.size(); ++a) 
		{
			if ('0' <= buffer[a] && buffer[a] <= '9')
			{
				m_int.back().push_back(std::stoi(&buffer[a]));
				while ('0' <= buffer[a] && buffer[a] <= '9')
					++a;
			}
		}
	}
	fd.close();
}

Loadfile::~Loadfile()
{
	m_line.clear();
	delete(&m_line);
}

bool		Loadfile::isReady()
{
	if (nb_line == -1)
		return false;
	return true;
}

std::string	Loadfile::get() const
{
	return m_content;
}

std::vector<std::vector<int> >	Loadfile::getInt() const
{
	return m_int;
}

size_t		Loadfile::nb_lines() const
{
	return m_line.size();
}
