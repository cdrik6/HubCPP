/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguillo <caguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 23:21:35 by caguillo          #+#    #+#             */
/*   Updated: 2024/10/30 04:45:57 by caguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>
#include <string>

#define OK 0
#define KO 1


int	main(int argc, char **argv)
{
	// Parsing	
	if (argc != 4)
		return (std::cerr << "Usage: ./sed filename s1(string to be replaced by s2) s2" << std::endl, KO);		
	std::ifstream infile(argv[1], std::ios::binary);
	if (!infile)
		return (perror(argv[1]), KO);
	std::string outname = std::string(argv[1]) + ".replace";
	std::ofstream outfile(outname.c_str(), std::ios::binary);
	if (!outfile)
		return (perror(outname.c_str()), KO);
	std::string s1 = std::string(argv[2]);
	std::string s2 = std::string(argv[3]);
	int	len_s1 = s1.size();
	if (len_s1 == 0)	
		return(std::cerr << "Error: s1 can't be empty" << std::endl, KO);
	
	// Replace	
	char *buffer = new char[len_s1 + 1];
	buffer[len_s1] = 0; // to do correct str comparison
	int i = 0;
	while (infile.read(buffer, len_s1))	
	{
		if (s1.compare(buffer) == 0)
		{
			outfile << s2;
			i = i + len_s1;
		}
		else
		{
			outfile << buffer[0];			
			i++;
		}		
		infile.seekg(i, std::ios::beg);
	}
	for (int j = 0; j < infile.gcount(); j++)	
		outfile << buffer[j];	
	delete[] buffer;
	return (OK);
}

// N.B. string comparison
// soit strcmp(buffer, s1.c_str()) == 0 --> back to C
// soit s1 == buffer this way well defined by the overloaded operator of String
// soit s1.compare(buffer) == 0
// PAS buffer == s1: will compare only the pointers not the strings

// N.B. while loop
// If the read operation successfully reads len_s1 bytes, infile remains in a good state, and the loop continues.
// If the end of the file is reached before len_s1 bytes are read, 	or if an error occurs during reading,
// infile sets either the EOF (end-of-file) flag or the fail flag.
// When EOF or fail flags are set, infile is evaluated as false in the condition, which stops the loop.



// Debug tools
// std::cout << buffer << std::endl;
// echo -n bonjour < test.txt --> check
// chmod
// "" par s1 ou s2 chaine vide
// 	"bonjour \ntoto"
// echo "bon\0jour" < test.txt
// std::string line;
// while(std::getline(infile, line))
// {
// 	outfile << ft_replace(line, s1, s2);		
// }
// std::cout << infile.gcount() << std::endl;			
// std::cout << buffer << std::endl;
// check it s not infinite size (/dev/random)