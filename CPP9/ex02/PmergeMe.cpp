/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguillo <caguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 21:04:57 by caguillo          #+#    #+#             */
/*   Updated: 2025/01/10 03:44:10 by caguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "PmergeMe.hpp"

/*********************************************************  sort with vector **************************************** */
/*********************************************************  sort with vector **************************************** */
/*********************************************************  sort with vector **************************************** */

std::vector<int> v_sort(std::vector<int> v)
{
    int oddy = -1;    
    std::vector<int> main;
    std::vector<int> pend;    

    if (v.size() <= 1)
        return (v) ;
    // put away the oddy
    if (v.size() % 2 != 0)
    {
        oddy = v.back();
        v.pop_back();
    }    
    // split by 2, main vs pend
    for (int i = 0; i < v.size(); i = i + 2)    
    {        
        if (v.at(i) < v.at(i+1))
        {
            main.push_back(v.at(i+1));
            pend.push_back(v.at(i));
        }            
        else
        {
            main.push_back(v.at(i));
            pend.push_back(v.at(i+1));
        }            
        // g_count++;
    }    
    if (oddy != -1)
        pend.push_back(oddy);
    // /********************/    
    // std::cout << "main = ";
    // for (int i = 0; i < main.size(); i++)
    //     std::cout << main.at(i) << " ";
    // std::cout << std::endl;
    // std::cout << "pend = ";
    // for (int i = 0; i < pend.size(); i++)
    //     std::cout << pend.at(i) << " ";
    // std::cout << std::endl;
    // /******************** */    
    // recur 
    if (main.size() != 1)
        return (v_merge(v_sort(main), main, pend));
    else
        return (v_merge(main, main, pend)); // sorted = main;               
}

std::vector<int> v_merge(std::vector<int> sorted, std::vector<int>& main, std::vector<int>& pend)
{
    v_reindex_pend(sorted, main, &pend);
    sorted = v_insert_pend(sorted, pend);
    // for (int i = 0; i < sorted.size(); i++)
    //     std::cout << sorted.at(i) << " ";
    // std::cout << std::endl;        
    return (sorted);
}

std::vector<int> v_insert_pend(std::vector<int>& sorted, std::vector<int>& pend)
{        
    std::vector<int> res = sorted;    
    std::vector<int> idx;
    int val_to_insert;
    int i = 0;
    int j = 0;
    int k = 0;
    bool out = false;        
    // aff_pend(pend);
    
    // insert the small of the biggest    
    res.insert(res.begin() + 0, pend.at(0));        
    // get Jacob --> index = 2 et 1 de pend    
    idx = get_jacob_index_vector(IEME_JACOB_NBR, pend.size());        
    for (int h = 1; h < pend.size(); h++)
    {           
        // if (h <= idx.size() - 1) // if (h <= MAX_JACOB_IDX)        
        // {            
            if (out == false)   
                j = idx.at(h);
            if (j >= pend.size() || out == true)
            {
                if (out == false)   
                {
                    j = pend.size() - 1;
                    out = true;
                }
                else 
                    j--;                         
            }
        // }            
        // else
        //     j = h;        
        val_to_insert = pend.at(j);
        // std::cout << j << " = val = " << pend.at(j) << std::endl;
        if (pend.size() != sorted.size() && j == pend.size() - 1)        
            k = v_get_insert_index(0, res.size() - 1, res, val_to_insert);        
        else 
        {   
            i = 0;
            while (res.at(i) < sorted.at(j))   
                i++;            
            k = v_get_insert_index(0, i - 1, res, val_to_insert);
        }        
        res.insert(res.begin() + k, val_to_insert);
        // std::cout << "#" << g_count << std::endl;
    }    
    return (res);
}

// start = index // end = index
int v_get_insert_index(int start, int end, std::vector<int>& tab, int val)
{    
    int s = end - start + 1; // size
    int k = start + s - s/2 - 1; // middle index + s/2
    
    // aff_tab(tab);
    // std::cout << "size = " << s << std::endl;        
    // std::cout << "k = " << k << std::endl;        
    // std::cout << "start = " << tab.at(start) << std::endl;        
    // std::cout << "end = " << tab.at(end) << std::endl;
    if (s == 1)
    {
        if (val < tab.at(k))
            return (k); // return (g_count++, k);
        else
            return (k + 1); // return (g_count++, k + 1);     
    }    
    if (val < tab.at(k))   
    {
        if (k == start)
            return (k); // return (g_count++, get_insert_index(start, k, tab, val));            
        return (v_get_insert_index(start, k - 1, tab, val));        
    }        
    else //if (val > tab.at(k))
    {
        if (k == end)
            return (k + 1); //return (g_count++, get_insert_index(k, end, tab, val));
        return (v_get_insert_index(k + 1, end, tab, val));
    }        
}

void v_reindex_pend(std::vector<int>& sorted, std::vector<int>& main, std::vector<int> *pend)
{
    std::vector<int> temp;
    
    for (int i = 0; i < main.size(); i++)            
        temp.push_back((*pend).at(v_get_index(sorted.at(i), main)));
    if ((*pend).size() != main.size())            
        temp.push_back((*pend).back());            
    (*pend).clear();
    (*pend) = temp;    
}

int v_get_index(int val, std::vector<int>& main)
{
    for (int i = 0; i < main.size(); i++)
    {
        if (val == main.at(i))
            return (i);
    }
    return (0);
}


/*********************************************************  sort with deque **************************************** */
/*********************************************************  sort with deque **************************************** */
/*********************************************************  sort with deque **************************************** */

std::deque<int> d_sort(std::deque<int> d)
{
    int oddy = -1;    
    std::deque<int> main;
    std::deque<int> pend;    

    if (d.size() <= 1)
        return (d) ;
    // put away the oddy
    if (d.size() % 2 != 0)
    {
        oddy = d.back();
        d.pop_back();
    }    
    // split by 2, main vs pend
    for (int i = 0; i < d.size(); i = i + 2)    
    {        
        if (d.at(i) < d.at(i+1))
        {
            main.push_back(d.at(i+1));
            pend.push_back(d.at(i));
        }            
        else
        {
            main.push_back(d.at(i));
            pend.push_back(d.at(i+1));
        }            
        // g_count++;
    }    
    if (oddy != -1)
        pend.push_back(oddy);
    // /********************/    
    // std::cout << "main = ";
    // for (int i = 0; i < main.size(); i++)
    //     std::cout << main.at(i) << " ";
    // std::cout << std::endl;
    // std::cout << "pend = ";
    // for (int i = 0; i < pend.size(); i++)
    //     std::cout << pend.at(i) << " ";
    // std::cout << std::endl;
    // /******************** */    
    // recur 
    if (main.size() != 1)
        return (d_merge(d_sort(main), main, pend));
    else
        return (d_merge(main, main, pend)); // sorted = main;               
}

std::deque<int> d_merge(std::deque<int> sorted, std::deque<int>& main, std::deque<int>& pend)
{
    d_reindex_pend(sorted, main, &pend);
    sorted = d_insert_pend(sorted, pend);
    // for (int i = 0; i < sorted.size(); i++)
    //     std::cout << sorted.at(i) << " ";
    // std::cout << std::endl;        
    return (sorted);
}

std::deque<int> d_insert_pend(std::deque<int>& sorted, std::deque<int>& pend)
{        
    std::deque<int> res = sorted;    
    std::vector<int> idx;
    int val_to_insert;
    int i = 0;
    int j = 0;
    int k = 0;
    bool out = false;        
    // aff_pend(pend);
    
    // insert the small of the biggest    
    res.insert(res.begin() + 0, pend.at(0));        
    // get Jacob --> index = 2 et 1 de pend    
    idx = get_jacob_index_vector(IEME_JACOB_NBR, pend.size());        
    for (int h = 1; h < pend.size(); h++)
    {           
        if (out == false)   
            j = idx.at(h);
        if (j >= pend.size() || out == true)
        {
            if (out == false)   
            {
                j = pend.size() - 1;
                out = true;
            }
            else 
                j--;                         
        }        
        //  j = h;        
        val_to_insert = pend.at(j);
        // std::cout << j << " = val = " << pend.at(j) << std::endl;
        if (pend.size() != sorted.size() && j == pend.size() - 1)        
            k = d_get_insert_index(0, res.size() - 1, res, val_to_insert);
        else
        {   
            i = 0;
            while (res.at(i) < sorted.at(j))   
                i++;            
            k = d_get_insert_index(0, i - 1, res, val_to_insert);
        }        
        res.insert(res.begin() + k, val_to_insert);
        // std::cout << "#" << g_count << std::endl;
    }    
    return (res);
}

// start = index // end = index
int d_get_insert_index(int start, int end, std::deque<int>& tab, int val)
{    
    int s = end - start + 1; // size
    int k = start + s - s/2 - 1; // middle index + s/2
    
    // aff_tab(tab);
    // std::cout << "size = " << s << std::endl;        
    // std::cout << "k = " << k << std::endl;        
    // std::cout << "start = " << tab.at(start) << std::endl;        
    // std::cout << "end = " << tab.at(end) << std::endl;
    if (s == 1)
    {
        if (val < tab.at(k))
            return (k);
        else
            return (k + 1);     
    }    
    if (val < tab.at(k))   
    {
        if (k == start)
            return (k); // return (g_count++, get_insert_index(start, k, tab, val));            
        return (d_get_insert_index(start, k - 1, tab, val));        
    }        
    else //if (val > tab.at(k))
    {
        if (k == end)
            return (k + 1); //return (g_count++, get_insert_index(k, end, tab, val));
        return (d_get_insert_index(k + 1, end, tab, val));
    }        
}

void d_reindex_pend(std::deque<int>& sorted, std::deque<int>& main, std::deque<int> *pend)
{
    std::deque<int> temp;
    
    for (int i = 0; i < main.size(); i++)            
        temp.push_back((*pend).at(d_get_index(sorted.at(i), main)));
    if ((*pend).size() != main.size())            
        temp.push_back((*pend).back());            
    (*pend).clear();
    (*pend) = temp;    
}

int d_get_index(int val, std::deque<int>& main)
{
    for (int i = 0; i < main.size(); i++)
    {
        if (val == main.at(i))
            return (i);
    }
    return (0);
}


/*********************************************************  Jacobsthal tools **************************************** */
/*********************************************************  Jacobsthal tools **************************************** */
/*********************************************************  Jacobsthal tools **************************************** */

int jacobsthal(int n)
{
    return((pow(2, n) - pow(-1, n)) / 3);
}

// i-eme jacobsthal number i = 15 => [10923 j(15) - 21844]
// i-eme jacobsthal number i = 14 => [5461 j(14) - 10922]
// i-eme jacobsthal number i = 13 => [2731 j(13) - 5460]
std::vector<int> get_jacob_index_vector(int j, int pend_size)
{
    std::vector<int> idx;    
    int start = 0;
    int end = 0;    
    
    idx.push_back(0);    
    for (int i = 1; i < j; i++)  // i-eme jacobsthal number
    {               
        start = 2*jacobsthal(i) + start;        
        end  = start - 2*jacobsthal(i) + 1;        
        for (int k = start; k >= end; k--)                       
            idx.push_back(k);                
    }    
    while (idx.size() < pend_size)
    {        
        j++;
        idx = get_jacob_index_vector(j, pend_size);
    }    
    return (idx);
}
// std::cout << "****" << idx.size() << std::endl;
// std::cout << "////" << idx.size() << std::endl;


/*********************************************************  time tools **************************************** */
/*********************************************************  time tools **************************************** */
/*********************************************************  time tools **************************************** */

// int clock_gettime(clockid_t clk_id, struct timespec *tp);
// struct timespec {
//     time_t tv_sec;  /* seconds */
//     long   tv_nsec; /* nanoseconds */ 1 000 000 000
// };
float   get_diff_micros(t_nsec nano, t_nsec t0)
{
	float	us;

	us = (static_cast<float>(nano.tv_nsec - t0.tv_nsec)) / 1000;
	us = (static_cast<float>(nano.tv_sec - t0.tv_sec)) * 1000000 + us;
	return (us);
}


/*********************************************************  Exception **************************************** */
/*********************************************************  Exception **************************************** */
/*********************************************************  Exception **************************************** */

const char* DInputException::what() const throw()
{
    return ("Deque: Error: wrong input");
}

const char* VInputException::what() const throw()
{
    return ("Vector: Error: wrong input");
}
