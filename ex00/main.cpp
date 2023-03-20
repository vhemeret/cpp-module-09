/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahemere <vahemere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 16:43:02 by vahemere          #+#    #+#             */
/*   Updated: 2023/03/20 16:40:02 by vahemere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>
#include <map>
#include <vector>
#include <sstream>
#include <algorithm>

template <typename T>
std::string to_string(const T src) {
  std::ostringstream s;
  std::string tmp;

  s << src;
  tmp = s.str();
  return tmp;
}

void	erase_spaces(std::string &s) {

	size_t i = 0;
	while (i < s.size()) {
		if (s[i] == ' ')
			s.erase(s.begin() + i);
		else
			i++;
	}
}

int main(int ac, char **av)
{
	std::fstream	input;
	std::fstream	bdd;
	std::string		line;
	bool			error = false;
	std::map<std::string, std::vector<double> > values;
	std::map<std::string, std::vector<double> > bdh;
	
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
			int i = 0;
			while (getline(input, line))
			{
				if (i == 0) {
					i++;
					continue;
				}
				erase_spaces(line);
				std::istringstream stream(line);
				std::string tmp1;
				std::string tmp2;
				std::getline(stream, tmp1, '|');
				std::getline(stream, tmp2);
				//std::cout << tmp1 << " \033[1;31m" << tmp2 << "\033[0m" << std::endl;
				double dtmp = strtod(tmp2.c_str(), NULL);
				if (dtmp < 1 || dtmp > 999) {
					error = true;
					if (dtmp < 1)
						std::cout << dtmp << " : Not positive" << std::endl;
					else
						std::cout << dtmp << " : Number too large" << std::endl;
				}
				values[tmp1].push_back(dtmp);
				std::cout << "\033[1;33m" << tmp1 << "\033[0m " << tmp2 << std::endl;
				
			}
			i = 0;
			while (getline(bdd, line))
			{
				if (i == 0) {
					i++;
					continue;
				}
				std::istringstream stream(line);
				std::string tmp1;
				std::string tmp2;
				std::getline(stream, tmp1, ',');
				std::getline(stream, tmp2);
				//std::cout << tmp1 << " \033[1;31m" << tmp2 << "\033[0m" << std::endl;
				double dtmp = strtod(tmp2.c_str(), NULL);
				//if (tmp2.isdigit() != true)
				//	error = true;
				bdh[tmp1].push_back(dtmp);
				std::cout << "\033[1;35m" << tmp1 << "\033[0m " << tmp2 << std::endl;
				
			}
			input.close();
			bdd.close();
		}
	}
	if (error)
		std::cout << "\033[1;31mERROR END\033[0m" << std::endl;

	std::vector<double> vect = values[to_string("2011-01-07")];
	std::cout << std::boolalpha << vect.empty() << std::endl;
	//if empty == true
		std::map<std::string, std::vector<double> >::iterator it;
		std::map<std::string, std::vector<double> >::iterator itminus;

		it = values.find(to_string("2011-01-07"));
		itminus = it;
		itminus--;
		std::cout << itminus->first << std::endl;
		values.erase(it->first);
	//std::cout << values[to_string("2011-01-07")] << std::endl;
	
	return (0);
}