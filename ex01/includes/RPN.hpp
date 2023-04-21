/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahemere <vahemere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 18:24:09 by vahemere          #+#    #+#             */
/*   Updated: 2023/04/21 18:02:20 by vahemere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

	/*===== Includes ======*/

# include <iostream>
# include <stack>
# include <cstdlib>
# include <sstream>
# include <string>

	/*===== Proto ======*/

int		checkInput(std::string input);
void	rpn(std::string input);


#endif