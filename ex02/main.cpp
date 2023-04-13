/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahemere <vahemere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 22:01:48 by vahemere          #+#    #+#             */
/*   Updated: 2023/04/13 02:49:54 by vahemere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <vector>
#include <deque>


/*============================================ VECTOR PART ====================================================*/

// insertion des éléments de le pending chain dans la main chain par recherche binaire
void binaryInsert(std::vector<int> &main, std::vector<int> &pending) 
{
    int mainSize = main.size();
    int pendingSize = pending.size();
	
    for (int i = 0; i < pendingSize; i++)
	{
        int element = pending[i];
        int low = 0, high = mainSize - 1;
		
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


void	MergeInsertionSort(std::vector<int> &arr)
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
	std::vector<int> main;
	std::vector<int> pending;

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

/*=============================================================================================================*/


/*============================================ DEQUE PART =====================================================*/

/*=============================================================================================================*/

void	displayArr(std::vector<int> &arr)
{
	std::vector<int>::iterator it;
	
	for (it = arr.begin(); it != arr.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
}

int main(int ac, char **av)
{
	std::vector<int> arr;
	
	if (ac)
	{
		for (int i = 1; av[i]; i++)
			arr.push_back(std::atoi(av[i]));
		
		// need to parse
		
		std::cout << "Before:\t";
		displayArr(arr);
		MergeInsertionSort(arr);
		std::cout << "After\t";
		displayArr(arr);

	}

	return (0);
}