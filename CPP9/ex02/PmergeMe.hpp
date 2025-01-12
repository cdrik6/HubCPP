/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguillo <caguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 21:01:39 by caguillo          #+#    #+#             */
/*   Updated: 2025/01/10 03:39:05 by caguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

# include <string>
# include <iostream>
# include <sstream>
# include <vector>
# include <deque>
# include <cstdlib>
# include <cmath>
# include <ctime>

# define OK 0
# define KO 1
# define IEME_JACOB_NBR 13
// # define MAX_JACOB_IDX 5460

typedef struct timespec	t_nsec;

// extern int g_count;

// parsing
void v_check_str_input(std::string expr, std::vector<int> *v);
void v_check_int_input(int argc, char **argv, std::vector<int> *v);
void d_check_str_input(std::string expr, std::deque<int> *d);
void d_check_int_input(int argc, char **argv, std::deque<int> *d);
bool is_valid_int(std::string token, int *i);

// sort with a vector
std::vector<int> v_sort(std::vector<int> v);
std::vector<int> v_insert_pend(std::vector<int>& sorted, std::vector<int>& pend);
int v_get_insert_index(int start, int end, std::vector<int>& tab, int val);
void v_reindex_pend(std::vector<int>& sorted, std::vector<int>& main, std::vector<int> *pend);
int v_get_index(int val, std::vector<int>& main);
std::vector<int> v_merge(std::vector<int> sorted, std::vector<int>& main, std::vector<int>& pend);

// sort with a deqeu
std::deque<int> d_sort(std::deque<int> d);
std::deque<int> d_insert_pend(std::deque<int>& sorted, std::deque<int>& pend);
int d_get_insert_index(int start, int end, std::deque<int>& tab, int val);
void d_reindex_pend(std::deque<int>& sorted, std::deque<int>& main, std::deque<int> *pend);
int d_get_index(int val, std::deque<int>& main);
std::deque<int> d_merge(std::deque<int> sorted, std::deque<int>& main, std::deque<int>& pend);

// jacobsthal tool
int jacobsthal(int n);
std::vector<int> get_jacob_index_vector(int j, int pend_size);

// tools
float get_diff_micros(t_nsec nano, t_nsec t0);
void output(std::vector<int>& v, char b_or_a);
void output(std::deque<int>& d, char b_or_a);

class VInputException : public std::exception
{
    virtual const char* what() const throw();
};

class DInputException : public std::exception
{
    virtual const char* what() const throw();
};

// // ********************************************** tools --> to be commented ***************
// void aff_main(std::vector<int>& main);
// void aff_pend(std::vector<int>& pend); 
// void aff_tab(std::vector<int>& pend); 
// bool is_sorted(std::vector<int>& v);
// bool is_sorted(std::deque<int>& d);

#endif
