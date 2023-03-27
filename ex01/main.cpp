/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahemere <vahemere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 18:24:03 by vahemere          #+#    #+#             */
/*   Updated: 2023/03/27 17:50:50 by vahemere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "includes/RPN.hpp"

int main(int ac, char **av)
{
	std::string		input;
	
	if (ac != 2)
	{
		std::cout << "Error: bad numbers of arguments." << std::endl;
		return (0);
	}
	input = av[1];
	if (!checkInput(input))
	{
		std::cout << "Error: bad input." << std::endl;
		return (0);
	}
	else
		rpn(input);
	return (0);
}
