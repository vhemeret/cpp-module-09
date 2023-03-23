/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manageInput.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahemere <vahemere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 15:42:59 by vahemere          #+#    #+#             */
/*   Updated: 2023/03/23 18:06:20 by vahemere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/BitcoinExchange.hpp"

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
