/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguillo <caguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 02:43:28 by caguillo          #+#    #+#             */
/*   Updated: 2025/01/10 05:24:12 by caguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

// set for data.csv
std::map<std::string, float> load_data(void)
{
    std::map<std::string, float> data;
    std::string line;
    std::string date;    
    float rate;
    char *endfx = NULL; 
    size_t pos;   
    
    std::ifstream infile("data.csv", std::ios::binary);
	if (!infile)		
        throw (std::exception());
    getline (infile, line); // header
    while (getline (infile, line))
    {
        pos = line.find(','); // 10
        date = line.substr(0, pos); // 10
        rate = std::strtof(line.substr(pos + 1).c_str(), &endfx); // 11
        data.insert(std::pair<std::string, float>(date, rate));
    }
    return(data);
}

void valuation(char *input, std::map<std::string, float> data)
{
    std::string line;
    std::string date;
    std::string value;
    float pos;
    
    std::ifstream infile(input, std::ios::binary);
	if (!infile)		
        throw (std::exception());
    while (getline (infile, line))
    {
        if (check_format(line) == OK)
        {
            date = line.substr(0, 10);        
            value = line.substr(13);
            if (check_date(date) == OK && check_value(value, &pos) == OK)            
                std::cout << date << " => " << value << " = " << pos * get_rate(date, data) << std::endl;                        
        } // << std::fixed << std::setprecision(2)
        else if (is_header(line) == 0)
            std::cerr << "Error: bad input => " << line << std::endl;        
    }    
}

int is_header(std::string header)
{
    if (header == "date | value" )
        return (1);
    return (0);    
}

int check_format(std::string line)
{
    if (line.length() < 14)
        return (KO);
    if (line.substr(10, 3) != " | ")
        return (KO);
    if (line.at(4) != '-' || line.at(7) != '-')    
        return (KO);
    return (OK);
}

//xxxx-xx-xx to be checked
int check_date(std::string date)
{
    int year = std::atoi(date.substr(0,4).c_str());
    int month = std::atoi(date.substr(5,2).c_str());
    int day = std::atoi(date.substr(8,2).c_str());
     
    if (year <= 0)    		
        return (std::cerr << "Error: wrong date\n", KO);
    if (month <= 0 || month > 12)
        return (std::cerr << "Error: wrong date\n", KO);
    if (day <= 0 || day > 31)
        return (std::cerr << "Error: wrong date\n", KO);
    if (month == 4 || month == 6 || month == 9 || month == 11)    
        if (day > 30)
            return (std::cerr << "Error: wrong date\n", KO);
    if (month == 2 && is_leap(year) == 1)
        if (day > 29)
            return (std::cerr << "Error: wrong date\n", KO);
    if (month == 2 && is_leap(year) == 0)
        if (day > 28)
            return (std::cerr << "Error: wrong date\n", KO);
    return (OK);
}

int is_leap(int year)
{
    bool C1 = false;
    bool C2 = false;

    if (year % 4 == 0 && year % 100 != 0)
        C1 = true;
    if (year % 400 == 0)
        C2 = true;    
    if (C1 == false && C2 == false)
        return (0);
    return (1);    
}

int check_value(std::string value, float *pos)
{
    char *endval = NULL;
    
    errno = 0;
    *pos = std::strtof(value.c_str(), &endval);
    if (value == std::string(endval)) // conversion failed
        return (std::cerr << "Error: not a number\n", KO);
    if (errno == ERANGE) // overflow-underflow
        return (std::cerr << "Error: overflow-underflow\n", KO);
    // if (endval) // case 123abc --> don't take it
    //     return (std::cerr << "Error: not a number\n", KO);
    if (*pos < 0)
        return (std::cerr << "Error: not a positive number\n", KO);
    if (*pos > 1000)
        return (std::cerr << "Error: too large number\n", KO);
    return (OK);
}

float get_rate(std::string date, std::map<std::string, float> data)
{
    std::map<std::string, float>::iterator it;    
        
    for (it = data.begin(); it != data.end(); ++it)
    {
        if (sup(date, (*it).first) == 0)
        {
            if (it == data.begin())
                return (0); //return((*it).second);
            return (--it, (*it).second);
        }        
    }    
    return (--it, (*it).second);
}

// date 1 > date2 => 1 / date 1 = date2 => 1 / date 1 < date2 => 0
int sup(std::string date1, std::string date2)
{
    int year1 = std::atoi(date1.substr(0,4).c_str());
    int month1 = std::atoi(date1.substr(5,2).c_str());
    int day1 = std::atoi(date1.substr(8,2).c_str());
    int year2 = std::atoi(date2.substr(0,4).c_str());
    int month2 = std::atoi(date2.substr(5,2).c_str());
    int day2 = std::atoi(date2.substr(8,2).c_str()); 

    if (year2 > year1)
        return (0);
    if (year1 > year2)
        return (1);    
    // year1 = year2        
    if (month2 > month1)
        return (0);
    if (month1 > month2)
        return (1);
    // month1 = month2
    if (day2 > day1)
        return (0);
    if (day1 > day2)
        return (1);
    // day1 = day2
    return (1);
}