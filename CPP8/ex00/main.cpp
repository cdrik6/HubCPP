/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguillo <caguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 05:21:49 by caguillo          #+#    #+#             */
/*   Updated: 2024/12/24 01:29:16 by caguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <list>
#include <deque>
#include <set>
#include "easyfind.hpp"

int main(void)
{
    std::cout << "--- Easyfind with container Vector ---" << std::endl;    
    // int arr[] = {4, 5, 6};    //std::vector<int> container = {4, 5, 6 } --> c++11
    // std::vector<int> container(arr, arr + sizeof(arr)/sizeof(arr[0]));    
    std::vector<int> containerV;
    containerV.push_back(4);
    containerV.push_back(5);
    containerV.push_back(6);    
    try
    {
        std::cout << ">> Search 5 in {4, 5, 6}" << std::endl;    
        std::cout << *easyfind(containerV, 5) << std::endl;
        std::cout << ">> Search 3 in {4, 5, 6}" << std::endl;    
        std::cout << *easyfind(containerV, 3) << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "--- Easyfind with container List ---" << std::endl;        
    std::list<int> containerL;
    containerL.push_back(4);
    containerL.push_back(5);
    containerL.push_back(6);
    try
    {
        std::cout << ">> Search 5 in {4, 5, 6}" << std::endl;    
        std::cout << *easyfind(containerL, 5) << std::endl;
        std::cout << ">> Search 3 in {4, 5, 6}" << std::endl;    
        std::cout << *easyfind(containerL, 3) << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout << std::endl;   

    std::cout << "--- Easyfind with container Deque ---" << std::endl;        
    std::deque<int> containerD;
    containerD.push_back(4);
    containerD.push_back(5);
    containerD.push_back(6);
    try
    {
        std::cout << ">> Search 5 in {4, 5, 6}" << std::endl;    
        std::cout << *easyfind(containerD, 5) << std::endl;
        std::cout << ">> Search 3 in {4, 5, 6}" << std::endl;    
        std::cout << *easyfind(containerD, 3) << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "--- Easyfind with container Set ---" << std::endl;        
    std::set<int> containerS;
    containerS.insert(4);
    containerS.insert(5);
    containerS.insert(6);
    try
    {
        std::cout << ">> Search 5 in {4, 5, 6}" << std::endl;    
        std::cout << *easyfind(containerS, 5) << std::endl;
        std::cout << ">> Search 3 in {4, 5, 6}" << std::endl;    
        std::cout << *easyfind(containerS, 3) << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout << std::endl;    
}

// containers that provide iterators:
// std::vector
// std::list
// std::deque
// std::set or std::unordered_set
// std::map or std::unordered_map --> issues with find
