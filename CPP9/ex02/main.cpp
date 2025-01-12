/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguillo <caguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 01:57:29 by caguillo          #+#    #+#             */
/*   Updated: 2025/01/10 03:47:24 by caguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

// int g_count;

int main(int argc, char **argv)
{   
    std::vector<int> v; 
    std::deque<int> d;
    t_nsec	t0, t1, t2, t3;    

    if (argc < 2)
        return(std::cout << "Usage: ./PmergeMe `shuf -i 1-20 -n 12 | tr \"\\n\" \" \"`" << std::endl, OK);

    std::cout << std::endl;
    // sorting with vector    
    std::cout << "--- Sorting with std::vector ---" << std::endl;
    clock_gettime(CLOCK_MONOTONIC, &t0);
    // g_count = 0;
    if (argc == 2)
    {
        try { v_check_str_input(std::string(argv[1]), &v); }
        catch(const std::exception& e) { std::cerr << e.what() << std::endl; }        
    }
    else
    {        
        try { v_check_int_input(argc, argv, &v); }
        catch(const std::exception& e) { std::cerr << e.what() << std::endl; }
    }
    clock_gettime(CLOCK_MONOTONIC, &t1);
    if (!v.empty())
    {        
        output(v, 'b');        
        clock_gettime(CLOCK_MONOTONIC, &t2);
        v = v_sort(v);
        clock_gettime(CLOCK_MONOTONIC, &t3);        
        output(v, 'a');
        std::cout << "Duration for parsing " << v.size() << " integers with std::vector : ";
        std::cout << std::fixed << get_diff_micros(t1, t0) << " us" << std::endl;
        std::cout << "Duration for sorting " << v.size() << " integers with std::vector : ";
        std::cout << std::fixed << get_diff_micros(t3, t2) << " us" << std::endl;        
        // if (is_sorted(v))    
        //     std::cout << "v sorted" << std::endl;
        // std::cout << g_count << std::endl;
    }
    else
        std::cout << "Vector empty" << std::endl;

    std::cout << std::endl;
    // sorting with deque
    std::cout << "--- Sorting with std::deque ---" << std::endl;
    clock_gettime(CLOCK_MONOTONIC, &t0);
    // g_count = 0;
    if (argc == 2)
    {
        try { d_check_str_input(std::string(argv[1]), &d); }
        catch(const std::exception& e) { std::cerr << e.what() << std::endl; }        
    }
    else
    {        
        try { d_check_int_input(argc, argv, &d); }
        catch(const std::exception& e) { std::cerr << e.what() << std::endl; }
    }
    clock_gettime(CLOCK_MONOTONIC, &t1);    
    if (!d.empty())
    {   
        output(d, 'b');
        clock_gettime(CLOCK_MONOTONIC, &t2);
        d = d_sort(d);
        clock_gettime(CLOCK_MONOTONIC, &t3);
        output(d, 'a');        
        std::cout << "Duration for parsing " << v.size() << " integers with std::deque : ";
        std::cout << std::fixed << get_diff_micros(t1, t0) << " us" << std::endl;
        std::cout << "Duration for sorting " << v.size() << " integers with std::deque : ";
        std::cout << std::fixed << get_diff_micros(t3, t2) << " us" << std::endl;        
        // if (is_sorted(d))    
        //     std::cout << "d sorted" << std::endl;    
        // std::cout << g_count << std::endl;
    }
    else
        std::cout << "Deque empty" << std::endl;    
    std::cout << std::endl;    
    return (OK);
}


/*********************************************************  data management **************************************** */
/*********************************************************  data management **************************************** */
/*********************************************************  data management **************************************** */

bool is_valid_int(std::string token, int *i)
{
    std::istringstream iss(token);        
    iss >> *i;     
    return (iss.eof() && !iss.fail()); //123abc not ok // 2.4 not ok 
    //return (!iss.fail());   //123abc-->123 // 2.4-->2
}

void v_check_str_input(std::string expr, std::vector<int> *v)
{
    std::istringstream iss(expr);
    std::string token;
    int i;
    
    while (iss >> token)
    {
        // std::cout << "[" << token << "]" << std::endl;
        if (is_valid_int(token, &i) && (i > 0))        
            (*v).push_back(i);
        else
            throw (VInputException());        
    }    
}

void d_check_str_input(std::string expr, std::deque<int> *d)
{
    std::istringstream iss(expr);
    std::string token;
    int i;
    
    while (iss >> token)
    {
        
        if (is_valid_int(token, &i) && (i > 0))
            (*d).push_back(i);
        else
            throw (DInputException());        
    }    
}

void v_check_int_input(int argc, char **argv, std::vector<int> *v)
{
    int i;
    
    for (int j = 1; j < argc; j++)
    {
        if (is_valid_int(std::string(argv[j]), &i) && (i > 0))
            (*v).push_back(i);        
        else
            throw (VInputException());        
    }    
}

void d_check_int_input(int argc, char **argv, std::deque<int> *d)
{
    int i;
    
    for (int j = 1; j < argc; j++)
    {
        if (is_valid_int(std::string(argv[j]), &i) && (i > 0))        
            (*d).push_back(i);        
        else
            throw (DInputException());        
    }    
}

void output(std::vector<int>& v, char b_or_a)
{
    if (b_or_a == 'b')
    {
        std::cout << "Before: ";
        if (v.size() <= 12)
        {           
            for (int j = 0; j < v.size(); j++)
                std::cout << v.at(j) << " ";
        }
        else
        {
            for (int j = 0; j < 6; j++)
                std::cout << v.at(j) << " ";
            std::cout << "... ";        
            for (int j = v.size() - 6; j < v.size(); j++)
                std::cout << v.at(j) << " ";    
        }
    }
    if (b_or_a == 'a')
    {
        std::cout << "After : ";
        if (v.size() <= 12)
        {           
            for (int j = 0; j < v.size(); j++)
                std::cout << v.at(j) << " ";
        }
        else
        {
            for (int j = 0; j < 6; j++)
                std::cout << v.at(j) << " ";
            std::cout << "... ";        
            for (int j = v.size() - 6; j < v.size(); j++)
                std::cout << v.at(j) << " ";    
        }
    }    
    std::cout << std::endl;
}

void output(std::deque<int>& d, char b_or_a)
{
    if (b_or_a == 'b')
    {
        std::cout << "Before: ";
        if (d.size() <= 12)
        {           
            for (int j = 0; j < d.size(); j++)
                std::cout << d.at(j) << " ";
        }
        else
        {
            for (int j = 0; j < 6; j++)
                std::cout << d.at(j) << " ";
            std::cout << "... ";        
            for (int j = d.size() - 6; j < d.size(); j++)
                std::cout << d.at(j) << " ";    
        }
    }
    if (b_or_a == 'a')
    {
        std::cout << "After : ";
        if (d.size() <= 12)
        {           
            for (int j = 0; j < d.size(); j++)
                std::cout << d.at(j) << " ";
        }
        else
        {
            for (int j = 0; j < 6; j++)
                std::cout << d.at(j) << " ";
            std::cout << "... ";        
            for (int j = d.size() - 6; j < d.size(); j++)
                std::cout << d.at(j) << " ";    
        }
    }    
    std::cout << std::endl;
}

// // ****************************************  tools --> to be commented
// bool is_sorted(std::vector<int>& v)
// {
//     if (!v.empty())
//     {
//         int temp = v.at(0);
//         for (int i = 1; i < v.size(); i++)
//         {
//             if (v.at(i) < temp)
//                 return (false);
//             temp = v.at(i);     
//         }        
//     }    
//     return (true);
// }

// bool is_sorted(std::deque<int>& d)
// {
//     if (!d.empty())
//     {
//         int temp = d.at(0);
//         for (int i = 1; i < d.size(); i++)
//         {
//             if (d.at(i) < temp)
//                 return (false);
//             temp = d.at(i);     
//         }        
//     }    
//     return (true);
// }

// void aff_main(std::vector<int>& main)
// {
//     std::cout << "affiche main = ";
//     for (int i = 0; i < main.size(); i++)
//         std::cout << main.at(i) << " ";
//     std::cout << std::endl;    
// }

// void aff_pend(std::vector<int>& pend) 
// {
//     std::cout << "affiche re-pend = ";        
//     for (int i = 0; i < pend.size(); i++)
//         std::cout << pend.at(i) << " ";
//     std::cout << std::endl;
// }

// void aff_tab(std::vector<int>& pend) 
// {
//     std::cout << "affiche tab = ";        
//     for (int i = 0; i < pend.size(); i++)
//         std::cout << pend.at(i) << " ";
//     std::cout << std::endl;
// }
