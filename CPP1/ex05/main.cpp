/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguillo <caguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 23:21:35 by caguillo          #+#    #+#             */
/*   Updated: 2024/10/31 02:26:54 by caguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(void)
{
	Harl toto;

	toto.complain("DEBUG");
	toto.complain("INFO");
	toto.complain("WARNING");
	toto.complain("ERROR");
	toto.complain("TOTO");

	return (0);
}
