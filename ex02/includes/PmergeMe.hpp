/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahemere <vahemere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 18:41:33 by vahemere          #+#    #+#             */
/*   Updated: 2023/04/21 17:47:03 by vahemere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP


	/*========= Lib ==========*/

#include <iostream>
#include <cstdlib>
#include <vector>
#include <deque>
#include <ctime>
#include <sstream>
#include <iomanip>

	/*========= Fnct =========*/

int	parser(char **tab);
	
	/*====== Templates =======*/

// insertion des éléments de le pending chain dans la main chain par recherche binaire
template<typename T>
void binaryInsert(T &main, T &pending) 
{
    int mainSize = main.size();
    int pendingSize = pending.size();
	
    for (int i = 0; i < pendingSize; i++)
	{
        int element = pending[i];
        int low = 0;
		int	high = mainSize - 1;
		
        while (low <= high)
		{
            int mid = (low + high) / 2;
			
            if (element < main[mid])
                high = mid - 1;
            else
                low = mid + 1;
        }
		
        main.insert(main.begin() + low, element);
        mainSize++;
    }
}

template<typename T>
void	MergeInsertionSort(T &arr)
{
	int					tmp;
	int					tmp2;
	
	// formation de paire et trie des premiers elements (premier element < au deuxieme)
	for (int n = 0; (unsigned long)n < arr.size(); n += 2)
	{
		if (arr[n + 1] && arr[n] > arr[n + 1])
		{
			tmp = arr[n];
			arr[n] = arr[n + 1];
			arr[n + 1] = tmp;
		}
	}

	// trie des paires dans l'ordre croissant (par rapport au second element)
	for (int i = 1; (unsigned long)i < arr.size(); i += 2)
	{
		for (int j = i + 2; (unsigned long)j < arr.size(); j += 2)
		{
			if (arr[j] < arr[i])
			{
				tmp = arr[j];
				tmp2 = arr[j - 1];
				arr[j] = arr[i];
				arr[j - 1] = arr[i - 1];
				arr[i] = tmp;
				arr[i - 1] = tmp2;
			}
		}
	}
	
	// separation des paires en deux listes (si paire -> main chain | si impoaire -> pending chain)
	T main;
	T pending;

	for (int i = 0; (unsigned long)i < arr.size(); i++)
	{
		if (i % 2 == 0)
			pending.push_back(arr[i]);
		else
			main.push_back(arr[i]);
	}
	arr.clear();
	binaryInsert(main, pending);
	arr = main;
}

template<typename T>
void	displayArr(T &arr)
{
	typename T::iterator it;

	for (it = arr.begin(); it != arr.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
}

#endif