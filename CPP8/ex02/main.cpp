/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguillo <caguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 23:18:54 by caguillo          #+#    #+#             */
/*   Updated: 2024/12/26 04:58:51 by caguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"


int	main(void)
{
	std::cout << "--- Test from subject ---" << std::endl;
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);	
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> st(mstack);
	std::cout << std::endl;
	//
	std::cout << "--- Other test 'requested' by subject (should output the same) ---" << std::endl;
	std::list<int> lst;
	lst.push_back(5);
	lst.push_back(17);
	std::cout << lst.back() << std::endl;
	lst.pop_back();
	std::cout << lst.size() << std::endl;
	lst.push_back(3);
	lst.push_back(5);
	lst.push_back(737);	
	lst.push_back(0);
	std::list<int>::iterator it_lst = lst.begin();
	std::list<int>::iterator ite_lst = lst.end();
	++it_lst;
	--it_lst;
	while (it_lst != ite_lst)
	{
		std::cout << *it_lst << std::endl;
		++it_lst;
	}
	std::list<int> list(lst);
	std::cout << std::endl;
	//		
    std::cout << "--- Kind of iteration with a stack:" << std::endl;
    std::stack<int> s;
    s.push(0);
    s.push(1);
    s.push(2);
    s.push(3);       
    for (std::stack<int> tmp = s; !tmp.empty(); tmp.pop())
        std::cout << tmp.top() << " ";
    std::cout << " --> reverse due to LIFO charateristic of a stack" << std::endl << std::endl;    

	std::cout << "--- Parallel iteration Vector / MutantStack ---" << std::endl;
	std::vector<int> vec;
	MutantStack<int> mut;
	for (int i = 0; i < 4; i++)	
	{		
		vec.push_back(i);
		mut.push(i);
	}	
	std::vector<int>::iterator v_it;
	std::cout << "Vector: ";
	for (v_it = vec.begin(); v_it != vec.end(); ++v_it)	
    	std::cout << *v_it << " ";
	std::cout << std::endl;
	MutantStack<int>::iterator m_it;
	std::cout << "MutantStack: ";
	for (m_it = mut.begin(); m_it != mut.end(); ++m_it)	
    	std::cout << *m_it << " "; 
	std::cout << std::endl;
    std::cout << "--> same iteration process" << std::endl << std::endl;    
	// m_it = mut.begin();
	// for (v_it = vec.begin(); v_it != vec.end(); ++v_it)	
	// {
	// 	std::cout << *v_it << " ";
	// 	std::cout << *m_it << " "; 	
	// 	++m_it;
	// }	
		
	return (0);
}