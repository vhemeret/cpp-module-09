/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manageBdd.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahemere <vahemere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 19:10:55 by vahemere          #+#    #+#             */
/*   Updated: 2023/03/22 21:22:55 by vahemere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/BitcoinExchange.hpp"

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