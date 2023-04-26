/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahemere <vahemere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 18:24:03 by vahemere          #+#    #+#             */
/*   Updated: 2023/04/26 16:06:01 by vahemere         ###   ########.fr       */
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
	if (input.size() == 1 && isdigit(input[0]))
	{
		std::cout << input << std::endl;
		return (0);
	}
	if (!checkInput(input))
	{
		std::cout << "Error: bad input." << std::endl;
		return (0);
	}
	else
		rpn(input);
	return (0);
}
