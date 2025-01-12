/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguillo <caguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 01:57:29 by caguillo          #+#    #+#             */
/*   Updated: 2024/12/30 01:25:12 by caguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
        return(std::cerr << "Error: could not open file" << std::endl, OK);
    std::ifstream infile(argv[1], std::ios::binary);
	if (!infile)
		return (perror(argv[1]), KO);
    try
    {
        valuation(argv[1], load_data());
    }
    catch(std::exception& e)
    {
        std::cerr << e.what() << ": could not open data file" << std::endl;
    }
    return (OK);
}