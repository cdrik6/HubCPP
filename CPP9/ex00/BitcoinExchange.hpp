/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguillo <caguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 01:59:20 by caguillo          #+#    #+#             */
/*   Updated: 2024/12/30 01:21:07 by caguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <cerrno>
# include <cstdlib>
# include <fstream>
# include <iomanip>
# include <iostream>
# include <map>
# include <string>

# define OK 1
# define KO 0

std::map<std::string, float> load_data(void);
void	valuation(char *input, std::map<std::string, float> data);
int		is_header(std::string header);
int		check_format(std::string line);
int		check_date(std::string date);
int		is_leap(int year);
int		check_value(std::string value, float *pos);
float	get_rate(std::string date, std::map<std::string, float> data);
int		sup(std::string date1, std::string date2);

#endif