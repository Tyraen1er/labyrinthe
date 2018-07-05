#ifndef LOADFILE_H
# define LOADFILE_H

# include <fstream>
# include <iostream>
# include <string>
# include <vector>

class	Loadfile
{
	private:
	std::vector<std::string>	m_content;

	public:
	Loadfile(const std::string path);
	Loadfile(const std::string path, std::string &file);
	std::string	get() const;
};

#endif
