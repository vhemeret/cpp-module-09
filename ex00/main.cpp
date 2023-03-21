/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahemere <vahemere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 16:43:02 by vahemere          #+#    #+#             */
/*   Updated: 2023/03/21 19:04:29 by vahemere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/btc.hpp"

int main(int ac, char **av)
{
	std::fstream						input_file;
	std::fstream						bdd_file;
	std::string							line;
	std::map<std::string, double>		bdd;
	int									i = 0;
	
	if (ac != 2){
		std::cout << "Error: could not open file." << std::endl;
		return (0);
	}
	
	else{
		
		input_file.open(av[1], std::ios::in);
		if (!input_file.is_open()){	
			std::cout << "Error: could not open file." << std::endl;
			return (0);
		}
		
		else
		{	
			//manage data.csv
			bdd_file.open("data.csv", std::ios::in);
			while (getline(bdd_file, line))
			{
				if (i == 0){
					i++;
					continue;
				}

				std::stringstream	stream(line);
				std::string			date;
				std::string			strVal;
				std::getline(stream, date, ',');
				std::getline(stream, strVal);
				double	value = strtod(strVal.c_str(), NULL);
				bdd.insert(std::pair<std::string, double>(date, value));
			}
			
			std::map<std::string, double>::iterator it;
			for (it = bdd.begin(); it != bdd.end(); it++){
				std::cout << it->first << " \033[1;31m" << it->second << "\033[0m" << std::endl;
			}

			//manage input
			i = 0;
			while (getline(input_file, line))
			{
				if (i == 0) {
					i++;
					continue;
				}
			}
		}
	}

	return (0);
}