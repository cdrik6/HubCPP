/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguillo <caguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 05:42:18 by caguillo          #+#    #+#             */
/*   Updated: 2024/12/31 00:40:14 by caguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

double evaluation(std::string expr) 
{
    std::stack<double> s;
    std::istringstream iss(expr);
    std::string token;
    double d;
    double d1;
    double d2;
    
    while (iss >> token)
    {
        // std::cout << "[" << token << "]" << std::endl;
        if (is_operand(token, &d))        
            s.push(d);        
        else if (is_operator(token) && s.size() >= 2)
        {            
            d2 = s.top();
            s.pop();
            d1 = s.top();
            s.pop();
            s.push(compute(d1, d2, token));            
        }
        else
            throw (InputException());        
    }
    if (s.size() == 1)
        return (s.top());        
    else
        throw (InputException());
}

int is_operand(std::string token, double *d)
{
    char *endtok;
    size_t pos = token.find('.');
    
    errno = 0;    
    *d = std::strtod(token.c_str(), &endtok);    
    if (token == std::string(endtok)) // conversion failed
        return (0);    
    if (errno == ERANGE) // overflow-underflow
        return (0);    
    if (endtok && endtok[0] != 0) // case 123abc --> don't take it
        return (0);
    if (pos != std::string::npos)    
        return (0);
    if (*d < -std::numeric_limits<double>::max() || *d > 9)    
        return (0);
    return (1);
}

int is_operator(std::string token)
{
    if (token == "+" || token == "-" || token == "*" || token == "/")
        return (1);
    return (0);   
}

double compute(double d1, double d2, std::string token)
{
    char ope = token.at(0);
    
    switch(ope)
    {
        case '+':
            return (check_add(d1, d2));
        case '-':
            return (check_sub(d1, d2));
        case '*':
            return (check_mul(d1, d2));
        case '/':
            return (check_div(d1, d2));
    }
    throw (std::exception());
}

double check_add(double d1, double d2)
{
    double result = d1 + d2;
    
    if (d1 == -d2)
        return (0);    
    if (std::isinf(result))
        throw std::overflow_error("Operation result is infinite (overflow)");    
    else if (result == 0.0) // zero, but neither operand is zero => underflow to zero          
        throw std::underflow_error("Operation result underflowed to zero");
    else if (std::fpclassify(result) == FP_SUBNORMAL) // subnormal => underflow occurred
        throw std::underflow_error("Operation result is subnormal (underflow).");    
    return (result); // No overflow or underflow detected   
}

double check_sub(double d1, double d2)
{
    double result = d1 - d2;
    
    if (d1 == d2)
        return (0);    
    if (std::isinf(result))
        throw std::overflow_error("Operation result is infinite (overflow)");    
    else if (result == 0.0) // zero, but neither operand is zero => underflow to zero          
        throw std::underflow_error("Operation result underflowed to zero");
    else if (std::fpclassify(result) == FP_SUBNORMAL) // subnormal => underflow occurred
        throw std::underflow_error("Operation result is subnormal (underflow).");    
    return (result); // No overflow or underflow detected   
}

double check_mul(double d1, double d2)
{
    double result = d1 * d2;
    
    if (d1 == 0.0 || d2 == 0.0)
        return (0);    
    if (std::isinf(result))
        throw std::overflow_error("Operation result is infinite (overflow)");    
    else if (result == 0.0) // zero, but neither operand is zero => underflow to zero          
        throw std::underflow_error("Operation result underflowed to zero");
    else if (std::fpclassify(result) == FP_SUBNORMAL) // subnormal => underflow occurred
        throw std::underflow_error("Operation result is subnormal (underflow).");    
    return (result); // No overflow or underflow detected   
}

double check_div(double d1, double d2)
{
    if (d2 == 0)
        throw (std::invalid_argument("Error: division by 0"));
    
    double result = d1 / d2;
    
    if (d1 == 0)
        return (0);    
    if (std::isinf(result))
        throw std::overflow_error("Operation result is infinite (overflow)");    
    else if (result == 0.0) // zero, but neither operand is zero => underflow to zero          
        throw std::underflow_error("Operation result underflowed to zero");
    else if (std::fpclassify(result) == FP_SUBNORMAL) // subnormal => underflow occurred
        throw std::underflow_error("Operation result is subnormal (underflow).");    
    return (result); // No overflow or underflow detected   
}

const char* InputException::what() const throw()
{
    return ("Error: wrong input");
}