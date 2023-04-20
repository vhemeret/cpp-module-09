/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahemere <vahemere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 15:43:16 by vahemere          #+#    #+#             */
/*   Updated: 2023/04/20 18:49:20 by vahemere         ###   ########.fr       */
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

int								openInput(std::string file, std::fstream &fd);
int								insertBdd(std::string data, std::map<std::string, double> &map);
void							run(std::fstream &input, std::map<std::string, double> &bdd);

#endif