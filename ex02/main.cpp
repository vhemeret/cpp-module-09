/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahemere <vahemere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 22:01:48 by vahemere          #+#    #+#             */
/*   Updated: 2023/04/05 19:03:44 by vahemere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <vector>
#include <deque>

void	TempDisplay(std::vector<int> &main, std::vector<int> &temp)
{
	std::cout << "Main Array:" << std::endl;
	for (int i = 0; (unsigned long)i < main.size(); i++)
		std::cout << "|" << main[i] << "|" << " ";
	std::cout << std::endl << std::endl;
	if (temp.size())
	{
		std::cout << "Sub-Array" << std::endl;
		for (int i = 0; (unsigned long)i < temp.size(); i++)
			std::cout << "|" << temp[i] << "|" << " ";
		std::cout << std::endl << std::endl;
	}
}

void	MergeInsertionSort(std::vector<int> &arr)
{
	int					tmp;
	int					i;
	std::vector<int>	subarr;
	
	// formation de paire et trie des premiers elements (dans le meme vecteur).
	TempDisplay(arr, subarr);
	for (int n = 0; (unsigned long)n < arr.size(); n += 2)
	{
		if (arr[n + 1] && arr[n] > arr[n + 1])
		{
			tmp = arr[n];
			arr[n] = arr[n + 1];
			arr[n + 1] = tmp;
		}
	}
	TempDisplay(arr, subarr);
	std::cout << "-------------------" << std::endl;

	// trie par paire par rapport au second element
	// # 

	// separation des paires en deux listes.
	std::vector<int>::iterator	it;
	i = 0;
	for (it = arr.begin(); it != arr.end(); it++)
	{
		if (i % 2 != 0)
		{
			subarr.push_back(*it);
			arr.erase(it);
		}
		i++;
	}
	TempDisplay(arr, subarr);
}

int main(int ac, char **av)
{
	std::vector<int> arr;
	
	if (ac)
	{
		// init array
		for (int i = 1; av[i]; i++)
			arr.push_back(std::atoi(av[i]));
		
		// sort 
		MergeInsertionSort(arr);

		// display result
		// std::vector<int>::iterator it;
		// for (it = arr.begin(); it != arr.end(); it++)
		// 	std::cout << *it << " ";
		// std::cout << std::endl;
	}

	return (0);
}