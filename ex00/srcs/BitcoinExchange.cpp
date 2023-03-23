/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahemere <vahemere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 19:47:16 by vahemere          #+#    #+#             */
/*   Updated: 2023/03/23 18:02:52 by vahemere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/BitcoinExchange.hpp"

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