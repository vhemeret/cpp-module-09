/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahemere <vahemere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 16:43:02 by vahemere          #+#    #+#             */
/*   Updated: 2023/04/20 18:41:00 by vahemere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "includes/BitcoinExchange.hpp"

int main(int ac, char **av)
{
	std::map<std::string, double>		bdd;
	std::fstream						input;
	
	if (ac != 2)
	{
		std::cout << "Error: To few arguments." << std::endl;
		return (0);
	}
	else
	{
		if (!openInput(av[1], input))
			return (0);
		else
		{	
			insertBdd("data.csv", bdd);
			run(input, bdd);
		}
	}
	return (0);
}
