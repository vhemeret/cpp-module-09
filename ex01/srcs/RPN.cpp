/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahemere <vahemere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 18:24:06 by vahemere          #+#    #+#             */
/*   Updated: 2023/03/27 20:02:12 by vahemere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/RPN.hpp"

int	checkInput(std::string input)
{
	std::string::iterator it;
	std::string::iterator ite;
	size_t i = 0;
	
	ite = input.begin() + (input.size() - 1);
	if (*ite != '+' && *ite != '-' && *ite != '/' && *ite != '*')
			return (0);
	for (it = input.begin(); it != input.end(); it++)
	{
		if (i == 0 && !isdigit(*it)) {
			if (input.size() == 1)
				return (0);
			if ((*it == '-' || *it == '+') && !isdigit(*(it + 1))) {
				std::cout << std::boolalpha << *(it + 1) << std::endl;
				return (0);
			}
		}
		if (*it == ' ')
			continue ;
		std::cout << "|" << *it << "|" << std::endl;
		if (*it != '+' && *it != '-' && *it != '/' && *it != '*' && !isdigit(*it))
			return (0);
		i++;
	}
	return (1);
}

int		calculate(int a, int b, char sign) {

	std::cout << a << " " << sign << " " << b << std::endl;
	if (sign == '+')
		return (a + b);
	if (sign == '-')
		return (a - b);
	if (sign == '*')
		return (a * b);
	return (a / b);
}

void	rpn(std::string input)
{
	std::stack<int> mystack;
	std::string::iterator sign;
	char c = 0;
	std::string::iterator index;
	std::istringstream stream(input);
	std::string tmp;
	int i = 0;
	
	for (size_t i = 0; i < input.size(); i++) {
		
		if ((input[i] == '-' || input[i] == '+' || input[i] == '*' || input[i] == '/'))
		{
			if (i < input.size() && !isdigit(input[i + 1])) {
				c = input[i];
				break ;
			}
		}
	}
	std::cout << "SIGN = " << c << std::endl;
	while (std::getline(stream, tmp, ' ')) {
		if (tmp.size() == 1 && !isdigit(tmp[0]) && tmp[0] != ' ') {
			c = tmp[0];
		}
		else {
			if (mystack.size() < 1)
				mystack.push(std::atoi(tmp.c_str()));
			else {
				if (i % 2 == 0) {
					int value = calculate(mystack.top(), std::atoi(tmp.c_str()), c);
					mystack.pop();
					mystack.push(value);
				}
				i++;
			}	
		}
	}
	std::cout << mystack.top() << std::endl;	
}