/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manageInput.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahemere <vahemere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 15:42:59 by vahemere          #+#    #+#             */
/*   Updated: 2023/03/21 15:54:21 by vahemere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/btc.hpp"

void	del_space(std::string &line)
{
	int	i = -1;
	while (line[++i]){
		if (line[i] == ' ')
			line.erase(i, 1);
	}
}

std::pair<std::string, double> getInput(std::string line){
	
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