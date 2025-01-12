/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguillo <caguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 05:21:49 by caguillo          #+#    #+#             */
/*   Updated: 2024/12/25 03:37:15 by caguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main(void)
{
    std::cout << "--- Provided main (addNumber) ---"<< std::endl;    
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
    std::cout << std::endl;

    std::cout << "--- Own tests --- " << std::endl;
    // std::cout << std::endl;
    //
    std::cout << ">> Exception tests:"<< std::endl;
    std::cout << "Full:" << std::endl;
    std::cout << "Add one more number: ";
    try { sp.addNumber(0); }
    catch (std::exception& e) { std::cerr << e.what() << std::endl;	}
    std::cout << std::endl;
    //
    std::cout << "No span:"<< std::endl;
    Span no = Span(5);
    // no.addNumber(0);    
    try { std::cout << "Shortest: " << no.shortestSpan() << std::endl; }
    catch (std::exception& e) { std::cerr << e.what() << std::endl;	}
    try { std::cout << "Longest: " << no.longestSpan() << std::endl; }
    catch (std::exception& e) { std::cerr << e.what() << std::endl;	}
    std::cout << std::endl;
    //
    std::cout << "Too many numbers:"<< std::endl;
    std::vector<int> src;
    for (int i = 0; i < 4; i++)
        src.push_back(i);
    Span small = Span(3);
    try { small.addNumber(src.begin(), src.end()); }    
    catch (std::exception& e) { std::cerr << e.what() << std::endl;	}
    std::cout << std::endl;
    //
    std::srand(time(NULL));    
    std::cout << ">> Add 100000 numbers:"<< std::endl;
    Span tt = Span(100000);
    std::vector<int> big;
    for (int i = 0; i < 100000; i++)
        big.push_back(std::rand() % 100000);
    tt.addNumber(big.begin(), big.end());
    std::cout << "Longest: " << tt.longestSpan() << std::endl;    
    std::cout << "Shortest: " << tt.shortestSpan() << std::endl;    
    std::cout << std::endl;
    
    return 0;
}

