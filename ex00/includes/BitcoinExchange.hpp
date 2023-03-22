/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahemere <vahemere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 15:43:16 by vahemere          #+#    #+#             */
/*   Updated: 2023/03/22 20:58:01 by vahemere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

	/*========= Lib ==========*/

# include <iostream>
# include <fstream>
# include <sstream>
# include <algorithm>
# include <map>

	/*========= Fnct =========*/


/* manageInput.cpp */

int								openInput(std::string file, std::fstream &fd);
std::pair<std::string, double>	getInput(std::string &line);
void							del_space(std::string &line);
int								checkInput(std::string year, std::string month, std::string day, double val);


/* manageBdd.cpp */

int								insertBdd(std::string data, std::map<std::string, double> &map);


/* BitcoinExchange.cpp */

void							run(std::fstream &input, std::map<std::string, double> &bdd);

#endif