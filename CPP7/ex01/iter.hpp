/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguillo <caguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 11:05:53 by caguillo          #+#    #+#             */
/*   Updated: 2024/12/21 21:33:31 by caguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>
# include <string>

template<typename T>
void iter(const T *array, size_t length, void(*f)(const T&))
{
    for (size_t i = 0; i < length; i++)
        f(array[i]);
    // std::cout << "--> through the const T prototype" << std::endl;   
}

template<typename T>
void iter (T *array, size_t length, void(*f)(T&))
{
    for (size_t i = 0; i < length; i++)
        f(array[i]);
    // std::cout << "--> through the T prototype" << std::endl;       
}

template<typename T>
void printnl(T& a)
{
	std::cout << a << std::endl;	
}

template<typename T>
void size_of(T& a)
{
	std::cout << sizeof(a) << std::endl;	
}

#endif


// NB :

// void(*f)(T&) and NOT void(f)(T&)
// we need a pointer on f, *f,  to give f as a parameter to iter here
// if not, would need the definition of the function inside the parameter, not possible
// perso non verifie : en faisant *f on donne a f un caractere de variable
// f is not an argument, *f yes
// void(*f)(T&) --> f as argumentand
// void(f)(T&) --> declare a funcfion f

// (*f) or (&f)

// void (*f)(int) declares f as a pointer to a function.
// need the * to indicate that f is a pointer and parentheses to group it properly.
// A function's name automatically decays into a pointer when assigned or passed as an argument,
// so don’t need & explicitly.
// You can use either (*f)(...) or f(...) to call the function through the pointer.

// The (*f) syntax is used because:
// It explicitly declares f as a pointer to a function.
// The & is unnecessary when assigning or using the function pointer because function names automatically decay into pointers.
// (les noms de fonctions se transforment automatiquement en pointeurs.)
