#ifndef TESTS_UTILS_HPP
#define TESTS_UTILS_HPP

// INCLUDE YOUR FILES HERE
#include "inc/map.hpp"
#include "inc/vector.hpp"
// ------------------------
#include <map>
#include <vector>
#include <chrono>
#include <ctime>
#include <iostream>
#include "colors.hpp"

#include <sys/time.h>

#define T1 int
#define T2 int

#define _pair ft::pair
#define _fmap ft::map
#define _smap std::map
#define _fvec ft::vector
#define _svec std::vector

template <typename T_VECT>
void    printSize(T_VECT const &vect, bool print_content = 1)
{
    std::cout << "size: " << vect.size() << " // capacity: " << vect.capacity() << std::endl;
    //std::cout << "max_size: " << vect.max_size() << std::endl;
    if (print_content)
    {
        typename T_VECT::const_iterator it = vect.begin(), ite = vect.end();
        std::cout << "Content is:" << std::endl;
        for (; it != ite; ++it)
            std::cout << "- " << *it << std::endl;
    }
    //std::cout << "###############################################" << std::endl;
}

template <typename FT_VECT, typename STD_VECT>
void controlSize (FT_VECT my_vec, STD_VECT std_vec)
{
    std::string toPrint;

    toPrint = (my_vec.size() != std_vec.size() ? "Size : KO" : "Size : OK");
    std::cout << toPrint << std::endl;

    toPrint = (my_vec.capacity() != std_vec.capacity() ? "Capacity : KO" : "Capacity : OK");
    std::cout << toPrint << std::endl;
}

template <typename FT_VECT, typename STD_VECT>
void controlContent (FT_VECT my_vec, STD_VECT std_vec)
{
    std::string toPrint = "Vectors content: ";

    typename STD_VECT::const_iterator it = std_vec.begin(), ite = std_vec.end();
    typename FT_VECT::const_iterator it_ft = my_vec.begin();
    typename FT_VECT::const_iterator it2 = my_vec.begin(), ite2 = my_vec.end();
    typename STD_VECT::const_iterator it_std = std_vec.begin();
    for (; it != ite; ++it){
        if (*it != *it_ft++) {
            toPrint += "❌";
            std::cout << toPrint << std::endl;
            return;
        }
    }
    for (; it2 != ite2; ++it2){
        if (*it2 != *it_std++) {
            toPrint += "❌";
            std::cout << toPrint << std::endl;
            return;
        }
    }
    toPrint += "✅";
    std::cout << toPrint << std::endl;
}

template <class T, class Alloc>
void    cmp(const ft::vector<T, Alloc> &lhs, const ft::vector<T, Alloc> &rhs)
{
    static int i = 0;

    std::cout << "############### [" << i++ << "] ###############"  << std::endl;
    std::cout << "eq: " << (lhs == rhs) << " | ne: " << (lhs != rhs) << std::endl;
    std::cout << "lt: " << (lhs <  rhs) << " | le: " << (lhs <= rhs) << std::endl;
    std::cout << "gt: " << (lhs >  rhs) << " | ge: " << (lhs >= rhs) << std::endl;
}

float	ft_round(double var)
{
    float value = (int)(var * 100000 + .5);
    return((float)value);
}

#endif // TESTS_UTILS_HPP