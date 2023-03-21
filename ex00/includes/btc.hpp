/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btc.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahemere <vahemere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 15:43:16 by vahemere          #+#    #+#             */
/*   Updated: 2023/03/21 19:50:52 by vahemere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BTC_HPP
# define BTC_HPP

/*========= Lib ==========*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <map>

/*========= Fnct =========*/

void	del_space(std::string &line);
std::pair<std::string, double> getInput(std::string &line);

#endif