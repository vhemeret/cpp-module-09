/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahemere <vahemere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 16:43:02 by vahemere          #+#    #+#             */
/*   Updated: 2023/03/15 18:37:36 by vahemere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>
#include <map>

int main(int ac, char **av)
{
	std::fstream	input;
	std::fstream	bdd;
	std::string		line;
	
	if (ac != 2){
		std::cout << "Error: could not open file." << std::endl;
		return (0);
	}
	else{
		input.open(av[1], std::ios::in);
		if (!input.is_open()){	
			std::cout << "Error: could not open file." << std::endl;
			return (0);
		}
		else
		{
			bdd.open("data.csv", std::ios::in);
			while (getline(input, line))
			{
				//
			}
			input.close();
		}
	}
	
	return (0);
}