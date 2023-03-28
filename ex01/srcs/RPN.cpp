/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahemere <vahemere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 18:24:06 by vahemere          #+#    #+#             */
/*   Updated: 2023/03/28 21:47:11 by vahemere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/RPN.hpp"

int	checkComponentInput(std::string input)
{
	std::istringstream		stream(input);
	std::string				component;
	size_t					i = 0;

	while (getline(stream, component, ' '))
	{
		if (i == 0 && isdigit(component[0]))
			while (component[++i])
				if (!isdigit(component[i]))
					return (0);
		i = 0;
	}
	return (1);
}

int	checkInput(std::string input)
{
	std::string::iterator	it;
	std::string::iterator	ite;
	size_t 					i = 0;
	
	ite = input.begin() + (input.size() - 1);
	if (*ite != '+' && *ite != '-' && *ite != '/' && *ite != '*')
			return (0);
	for (it = input.begin(); it != input.end(); it++)
	{
		if (i == 0 && !isdigit(*it))
		{
			if (input.size() == 1)
				return (0);
			if ((*it == '-' || *it == '+') && !isdigit(*(it + 1)))
			{
				return (0);
			}
		}
		if (*it == ' ')
			continue ;
		if (*it != '+' && *it != '-' && *it != '/' && *it != '*' && !isdigit(*it))
			return (0);
		i++;
	}
	if (!checkComponentInput(input))
		return (0);
	return (1);
}

int		calculate(int a, int b, char sign)
{
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
	std::stack<int>			mystack;
	std::istringstream		stream(input);
	std::string				tmp;
	int						a;
	int						b;
	bool					isoper;

	while (getline(stream, tmp, ' '))
	{
		// know if str is operator or operand
		if (tmp[0] == '-' || tmp[0] == '+' || tmp[0] == '*' || tmp[0] == '/')
		{
			if (tmp[1])
			{
				if (isdigit(tmp[1]))
					isoper = false;
			}
			else
				isoper = true;
		}
		else
			isoper = false;
		// action
		if (isoper)
		{
			if (mystack.size() > 1)
			{
				a = mystack.top();
				mystack.pop();
				b = mystack.top();
				mystack.pop();
				mystack.push(calculate(b, a, tmp[0]));
			}
		}
		else
			mystack.push(std::atoi(tmp.c_str()));
	}
	std::cout << mystack.top() << std::endl;	
}