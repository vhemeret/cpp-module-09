/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahemere <vahemere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 22:01:48 by vahemere          #+#    #+#             */
/*   Updated: 2023/04/19 18:04:15 by vahemere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/PmergeMe.hpp"

int main(int ac, char **av)
{
	std::vector<int> vector_arr;
	std::deque<int>	deque_arr;
	
	if (ac <= 1)
	{
		std::cout << "Error: To few arguments." << std::endl;
		return (0);
	}
	else
	{
		if (parser(&av[1]))
		{
			clock_t	start = clock();
			clock_t	end = clock();
			double	time;

			for (int i = 1; av[i]; i++)
			{
				vector_arr.push_back(std::atoi(av[i]));
				deque_arr.push_back(std::atoi(av[i]));
			}

			// part vector
			std::cout << "Before:\t";
			displayArr(vector_arr);
			start = clock();
			MergeInsertionSort(vector_arr);
			end = clock();
			time = (end - start) / (double)(CLOCKS_PER_SEC / 1000);
			std::cout << "After\t";
			displayArr(vector_arr);
			std::cout << "Time to process a range of " << vector_arr.size() << " elements with std::vector : " << std::fixed << std::setprecision(3) << time << " ms" << std::endl;

			//part deque
			start = clock();
			MergeInsertionSort(deque_arr);
			end = clock();
			time = (end - start) / (double)(CLOCKS_PER_SEC / 1000);
			std::cout << "Time to process a range of " << deque_arr.size() << " elements with std::deque : " << std::fixed << std::setprecision(3) << time << " ms" << std::endl;
		}
		else
			return (0);
	}
	return (0);
}