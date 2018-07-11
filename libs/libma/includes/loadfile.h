#ifndef LOADFILE_H
# define LOADFILE_H

# include <fstream>
# include <iostream>
# include <string>
# include <vector>

class	Loadfile
{
	private:
	int				nb_line;
	std::string		m_content;
	std::vector<std::string>			m_line;
	std::vector<std::vector<int> >		m_int;

	public:
	Loadfile(const std::string path);
	Loadfile(const std::string path, std::string &file);
	~Loadfile();
	bool		isReady();
	size_t		nb_lines() const;		// number of line of the input file, even empty
	std::string	get() const;			// return the content in a simple string
	std::vector<std::vector<int> >	getInt() const;	// return all int by line
};

#endif
