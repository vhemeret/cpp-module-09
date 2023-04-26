/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahemere <vahemere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 18:24:06 by vahemere          #+#    #+#             */
/*   Updated: 2023/04/26 16:03:16 by vahemere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/RPN.hpp"

int	checkSpaceInput(std::string input)
{
	std::istringstream		stream(input);
	std::string				component;

	while (getline(stream, component, ' '))
	{
		if (component.empty())
			return (0);
	}
	return (1);
}

int	is_sign(const char c)
{
	if (c != '+' && c != '-' && c != '*' && c != '/')
		return (0);
	return (1);
}

int	checkInput(std::string input)
{
	size_t	i = -1;

	if (!is_sign(input[input.size() - 1]))
		return (0);
	while (input[++i])
	{
		if (!is_sign(input[i]) && !isdigit(input[i]) && input[i] != ' ')
			return (0);
		if (i == 0 && !isdigit(input[i]))
		{
			if (input[i] == '-' && input[i + 1])
			{
				if (isdigit(input[i + 1]))
					continue;
			}
			else
				return (0);
			
		}
		if (is_sign(input[i]) && input[i + 1])
		{
			if (input[i] != '-' && isdigit(input[i + 1]))
				return (0);
			if (input[i + 1] != ' ' && !isdigit(input[i + 1]))
				return (0);
		}
		if (!checkSpaceInput(input))
			return (0);
	}
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
	char					sign = 0;
	int						a;
	int						b;
	bool					isoper;

	while (getline(stream, tmp, ' '))
	{
		// know if str is operator or operand
		if (is_sign(tmp[0]))
		{
			if (tmp[1])
			{ 
				// maybe a +n or -n and not a sign
				if (isdigit(tmp[1]))
					isoper = false;
			}
			else
			{
				sign = tmp[0];
				isoper = true;
			}
		}
		else
			isoper = false;
		// action
		if (isoper)
		{
			if (mystack.size() <= 1)
			{
				std::cout << "Error: Bad input." << std::endl;
				return ;
			}
			a = mystack.top();
			mystack.pop();
			b = mystack.top();
			mystack.pop();
			if (sign == '/' && a == 0)
			{
				std::cout << "Error: division by zero" << std::endl;
				return ;
			}
			mystack.push(calculate(b, a, sign));
		}
		else
			mystack.push(std::atoi(tmp.c_str()));
	}
	std::cout << mystack.top() << std::endl;
}