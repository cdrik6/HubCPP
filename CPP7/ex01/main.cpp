/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguillo <caguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 11:04:48 by caguillo          #+#    #+#             */
/*   Updated: 2024/12/21 22:04:43 by caguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int	main(void)
{
	const int array[] = {0, 1, 2, 3};	
	std::cout << "Print elements of an array of const int:" << std::endl;
	iter(array, 4, printnl<const int>);
	std::cout << "Size of elements of an array of const int:" << std::endl;
	iter(array, 4, size_of<const int>);
	std::cout << std::endl;
	
	char charray[] = {48, 49, 50, 51};
	std::cout << "Print elements of an array of char:" << std::endl;
	iter(charray, 4, printnl<char>);
	std::cout << "Size of elements of an array of char:" << std::endl;
	iter(charray, 4, size_of<char>);
	std::cout << std::endl;

	std::string words[] = {"zero", "un", "deux", "trois"};	
	std::cout << "Print elements of an array of string:" << std::endl;
	iter(words, 4, printnl<std::string>);
	std::cout << "Size of elements of an array of string:" << std::endl;
	iter(words, 4, size_of<std::string>);
	std::cout << std::endl;

	double a = 1.2e+12;
	double b = 42e-42;
	double *dptr[] = {&a, &b};
	std::cout << "Print elements of an array of pointer on double:" << std::endl;
	iter(dptr, 2, printnl<double*>);
	std::cout << "Size of elements of an array of pointer on double:" << std::endl;
	iter(dptr, 2, size_of<double*>);
	std::cout << std::endl;	

	return (0);
}

// class Awesome
// {
//   public:
//     Awesome( void ) : _n( 42 ) { return; }
//     int get( void ) const { return this->_n; }
//   private:
//     int _n;
// };

// std::ostream & operator<<( std::ostream & o, Awesome const & rhs )
// {
//   o << rhs.get();
//   return o;
// }

// template< typename T >
// void print(T& x )
// {
//   std::cout << x << std::endl;
//   return;
// }

// int main() {
//   int tab[] = { 0, 1, 2, 3, 4 };
//   Awesome tab2[5];

//   iter( tab, 5, print<const int>);
//   iter( tab2, 5, print<Awesome>);

//   return 0;
// }

// NB :
// iter( tab2, 5, print<Awesome>); --> could pass inside the const T version,
// but in that case failed to pass through the T version of the function print 
// iter( tab, 5, print<const int>); --> pass through the const T version as int
// can be cast into const int (not the opposite), and all is consistent
