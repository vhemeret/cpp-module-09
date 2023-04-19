/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahemere <vahemere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 18:27:53 by vahemere          #+#    #+#             */
/*   Updated: 2023/04/19 16:55:03 by vahemere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PmergeMe.hpp"

int	parser(char **tab)
{
	int	i = -1;
	int	j;
	
	while (tab[++i])
	{
		j = -1;
		while (tab[i][++j])
		{
			if (tab[i][j] == '-')
			{
				std::cout << "Error: Bad input, only positive number." << std::endl;
				return (0);
			}
			else if (!isdigit(tab[i][j]))
			{
				std::cout << "Error: Bad input." << std::endl;
				return (0);
			}
		}
	}
	return (1);
}
