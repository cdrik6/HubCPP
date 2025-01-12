/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguillo <caguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 23:21:35 by caguillo          #+#    #+#             */
/*   Updated: 2024/10/27 05:09:32 by caguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie	*horde;
	int		N;	

	N = 5;
	horde = zombieHorde(N, "hordie");
	if (!horde)
		return (std::cerr << "Zzzz" << std::endl, 1);
	for (int i = 0; i < N; i++)	
		horde[i].announce();
	delete[] horde;
	return (0);
}
