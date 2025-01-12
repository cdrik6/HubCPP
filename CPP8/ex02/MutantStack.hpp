/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguillo <caguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 04:47:55 by caguillo          #+#    #+#             */
/*   Updated: 2024/12/26 04:36:24 by caguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <stack>
# include <deque>
# include <list>
# include <algorithm>
# include <vector>


template <typename T>
class MutantStack : public std::stack<T>
{
    public:
        MutantStack();
        MutantStack(const MutantStack& other);
        MutantStack& operator=(const MutantStack& other);
        ~MutantStack();
        // 
        typedef typename std::stack<T>::container_type::iterator iterator;
        iterator begin(void);
        iterator end(void);
        // Read-only access to the container, best practices: mimick the design of the standard container
        // Read-only iteration over a non-const stack
	    typedef typename std::stack<T>::container_type::const_iterator const_iterator;              
        const_iterator begin(void) const;
        const_iterator end(void) const;
};

# include "MutantStack.tpp"

#endif

// https://cplusplus.com/reference/stack/stack/
// https://en.cppreference.com/w/cpp/container/stack
// *c_it = 50; // This will cause a compilation error --> const, can't modify iterator