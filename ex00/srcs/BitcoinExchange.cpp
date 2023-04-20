/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahemere <vahemere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 19:47:16 by vahemere          #+#    #+#             */
/*   Updated: 2023/04/20 18:47:53 by vahemere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/BitcoinExchange.hpp"

/*=========================== Manage Input ===================================*/

int		check_digits(const char *str)
{
	for (int i = 0; str[i]; i++)
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
	}
	return (1);
}

int		checkInput(std::string year, std::string month, std::string day, double val)
{
	bool	check = true;
	int		y;
	int		m;
	int		d;

	if (val > 1000)
	{
		std::cout << "\033[1;31mError:\033[0m too large a number." << std::endl;
		return (0);
	}
	if (val < 0)
	{
		std::cout << "\033[1;31mError:\033[0m not a positive number." << std::endl;
		return (0);
	}
	if (!check_digits(year.c_str()) || !check_digits(month.c_str()) || !check_digits(day.c_str()))
		check = false;
	if (year.length() != 4 || month.length() != 2 || day.length() != 2)
		check = false;
	y = atoi(year.c_str());
	m = atoi(month.c_str());
	d = atoi(day.c_str());
	if ((y < 1 || y > 2023)
		|| (m < 1 || m > 12)
		|| (d < 1 || d > 31))
		check = false;
	if (check == false)
	{
		std::cout << "\033[1;31mError:\033[0m bad input => " << year << "-" << month << "-" << day << std::endl;
		return (0);
	}
	return (1);
}

void	del_space(std::string &line)
{
	int	i = 0;
	while (line[i]){
		if (line[i] == ' ')
			line.erase(i, 1);
		else
			i++;
	}
}

std::pair<std::string, double> getInput(std::string &line){
	
	std::istringstream	stream(line);
	std::string			left;
	std::string			right;
	double				value;
	
	del_space(line);
	std::getline(stream, left, '|');
	std::getline(stream, right);
	value = strtod(right.c_str(), NULL);
	
	return std::make_pair(left, value);
}

int	openInput(std::string file, std::fstream &fd)
{
	fd.open(file.c_str(), std::ios::in);
	if (!fd.is_open())
	{
		std::cout << "\033[1;31mError:\033[0m could not open file." << std::endl;
		return (0);
	}
	return (1);
}

/*============================================================================*/


/*=========================== Manage Bdd =====================================*/

int	insertBdd(std::string data, std::map<std::string, double> &map)
{
	std::fstream	fd;
	std::string		line;

	fd.open(data.c_str(), std::ios::in);
	if (!fd.is_open())
	{
		std::cout << "Error: could not open file." << std::endl;
		return (0);
	}
	else
	{
		while (getline(fd, line))
		{
			std::stringstream	stream(line);
			std::string			date;
			std::string			strValue;
			double				value;

			getline(stream, date, ',');
			getline(stream, strValue);
			value = strtod(strValue.c_str(), NULL);
			map[date] = value;
		}
	}
	return (1);
}

/*============================================================================*/


/*=============================== Algo =======================================*/

void	run(std::fstream &input, std::map<std::string, double> &bdd)
{
	int										i;
	double									value;
	std::string								line;
	std::string								year;
	std::string								month;
	std::string								day;
	std::pair<std::string, double>			p;
	std::map<std::string, double>::iterator	it;

	i = 0;
	while (getline(input, line))
	{
		if (i == 0)
		{
			i++;
			continue;
		}
		
		p = getInput(line);
		del_space(p.first);
		std::stringstream	stream(p.first);
		getline(stream, year, '-');
		getline(stream, month, '-');
		getline(stream, day);
		if (!checkInput(year, month, day, p.second))
			continue;
		try
		{
			value = bdd.at(p.first);
			it = bdd.find(p.first);
		}
		catch(const std::exception& e)
		{
			bdd[p.first];
			
			it = bdd.find(p.first);
			std::map<std::string, double>::iterator itmp;
			itmp = it;
			if (it == bdd.begin())
			{
				bdd.erase(it);
				std::cout << "Error: Is lower than values in the database." << std::endl;
				continue ;
			}
			it--;
			value = bdd[it->first];
			bdd.erase(itmp);
		}
		std::cout << "\033[1;34m" << it->first << "\033[0m: " << "=> " << p.second << " = " << value * p.second << std::endl;
	}
}

/*============================================================================*/