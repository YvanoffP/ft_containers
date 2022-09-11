#include <iostream>
#include <string>
#include <deque>
#include <map>
#include <vector>
#include "map.hpp"
#include "vector.hpp"
#include <stdlib.h>
//#include "colors.hpp"
#include <chrono>
using namespace std::chrono;

#include <cstdio>
#include <ctime>
#include <time.h>
#include <math.h>


void	ft_banner();
void	ft_vector();
void	ft_map();
float   ft_round(double var);

int main()
{
    ft_banner();
    ft_vector();
    ft_map();
}

void	ft_vector()
{
    ft::vector<std::string>		ft_vector_string;
    std::vector<std::string>	std_vector_string;
    ft::vector<int>		ft_vector_int;
    std::vector<int>	std_vector_int;

    // Tests Vector

    std::cout << "\n\nVector" << std::endl << std::endl;

    // Test push_back

    std::clock_t ft_push_back = std::clock();
    for (int i = 0; i < 1000; i++)
    {
        ft_vector_int.push_back(i);
    }
    double ft_push_back_diff = ( std::clock() - ft_push_back ) / (double) CLOCKS_PER_SEC;

    std::clock_t std_push_back = std::clock();
    for (int i = 0; i < 1000; i++)
    {
        std_vector_int.push_back(i);
    }
    double std_push_back_diff = ( std::clock() - std_push_back ) / (double) CLOCKS_PER_SEC;

    int i = 0;
    int result = 0;
    while (i < 1000)
    {
        if (ft_vector_int[i] != std_vector_int[i])
            result = 1;
        i++;
    }

    std::cout << "push_back = ";
    if (result == 1)
        std::cout << "KO\n";
    else
        std::cout << "OK\n";
    std::cout << " | Duration : FT =  " << ft_round(ft_push_back_diff) << " | STD = " << ft_round(std_push_back_diff) << " | Diff =  " << (int)(ft_push_back_diff / std_push_back_diff) << " | ";
    if (ft_push_back_diff / std_push_back_diff <= 20)
        std::cout << "OK\n";
    else
        std::cout << "KO\n";


    // Test erase()
    std::clock_t ft_erase = std::clock();
    for (int i = 0; i != 100; i++)
    {
        ft_vector_int.erase(ft_vector_int.begin());
    }
    double ft_erase_diff = ( std::clock() - ft_erase ) / (double) CLOCKS_PER_SEC;

    std::clock_t std_erase = std::clock();
    for (int i = 0; i != 100; i++)
    {
        std_vector_int.erase(std_vector_int.begin());
    }
    double std_erase_diff = ( std::clock() - std_erase ) / (double) CLOCKS_PER_SEC;

    std::cout << "erase     = ";
    int	erase_result = 0;
    int	erase_i = 0;
    while (erase_i < 1000)
    {
        if (ft_vector_int[erase_i] != std_vector_int[erase_i])
            erase_result = 1;
        erase_i++;
    }
    if (ft_vector_int.size() != std_vector_int.size() || erase_result != 0)
        std::cout << "KO\n";
    else
        std::cout << "OK\n";
    std::cout << " | Duration : FT = " << ft_round(ft_erase_diff) << " | STD = " << ft_round(std_erase_diff) + 1 << " | Diff = " << (int)(ft_erase_diff / std_erase_diff) << " | ";

    if (std_erase_diff == 0 && ft_erase_diff <= 20)
        std::cout << "OK\n";
    else if (ft_erase_diff / std_erase_diff <= 20)
        std::cout << "OK\n";
    else
        std::cout << "KO\n";

    // Test insert()
    std::clock_t ft_insert = std::clock();
    for (int i = 0; i != 50; i++)
    {
        ft_vector_int.insert(ft_vector_int.begin(), 42);
    }
    double ft_insert_diff = ( std::clock() - ft_insert ) / (double) CLOCKS_PER_SEC;

    std::clock_t std_insert = std::clock();
    for (int i = 0; i != 50; i++)
    {
        std_vector_int.insert(std_vector_int.begin(), 42);
    }
    double std_insert_diff = ( std::clock() - std_insert ) / (double) CLOCKS_PER_SEC;

    std::cout << "insert    = ";
    int	insert_result = 0;
    int	insert_i = 0;
    while (insert_i < 1050)
    {
        if (ft_vector_int[insert_i] != std_vector_int[insert_i])
            insert_result = 1;
        insert_i++;
    }
    if (ft_vector_int.size() != std_vector_int.size())
        std::cout << "KO\n";
    else
        std::cout << "OK\n";
    std::cout << " | Duration : FT = " << ft_round(ft_insert_diff) << " | STD = " << ft_round(std_insert_diff) + 1 << " | Diff = " << (int)(ft_round(ft_insert_diff / (std_insert_diff + 1))) << " | ";

    if (((int)std_insert_diff == 0 || (int)std_insert_diff == 1) && ft_insert_diff <= 20)
        std::cout << "OK\n";
    else if (ft_insert_diff / std_insert_diff <= 20)
        std::cout << "OK\n";
    else
        std::cout << "KO\n";


    // Test resize()
    std::clock_t ft_resize = std::clock();
    ft_vector_int.resize(2000);
    double ft_resize_diff = ( std::clock() - ft_resize ) / (double) CLOCKS_PER_SEC;

    std::clock_t std_resize = std::clock();
    std_vector_int.resize(2000);
    double std_resize_diff = ( std::clock() - std_resize ) / (double) CLOCKS_PER_SEC;

    std::cout << "resize    = ";
    if (ft_vector_int.size() != std_vector_int.size())
        std::cout << "KO\n";
    else
        std::cout << "OK\n";
    std::cout << " | Duration : FT =  " << ft_round(ft_resize_diff) << " | STD = " << ft_round(std_resize_diff) << " | Diff =  " << (int)(ft_resize_diff / std_resize_diff) << " | ";

    if (std_resize_diff == 0 && ft_resize_diff <= 20)
        std::cout << "OK\n";
    else if (ft_resize_diff / std_resize_diff <= 20)
        std::cout << "OK\n";
    else
        std::cout << "KO\n";



    // Test pop_back()
    std::clock_t ft_pop_back = std::clock();
    int pop_back = 0;
    while (pop_back < 1000)
    {
        ft_vector_int.pop_back();
        pop_back++;
    }
    double ft_pop_back_diff = ( std::clock() - ft_pop_back ) / (double) CLOCKS_PER_SEC;

    std::clock_t std_pop_back = std::clock();
    pop_back = 0;
    while (pop_back < 1000)
    {
        std_vector_int.pop_back();
        pop_back++;
    }
    double std_pop_back_diff = ( std::clock() - std_pop_back ) / (double) CLOCKS_PER_SEC;

    std::cout << "pop_back  = ";
    if (ft_vector_int.size() != std_vector_int.size())
        std::cout << "KO\n";
    else
        std::cout << "OK\n";
    std::cout << " | Duration : FT =  " << ft_round(ft_pop_back_diff) << " | STD = " << ft_round(std_pop_back_diff) << " | Diff =  " << (int)(ft_pop_back_diff / std_pop_back_diff) << " | ";

    if (std_pop_back_diff == 0 && ft_pop_back_diff <= 20)
        std::cout << "OK\n";
    else if (ft_pop_back_diff / std_pop_back_diff <= 20)
        std::cout << "OK\n";
    else
        std::cout << "KO\n";

    // Test swap()
    ft::vector<int>		ft_vector_swap(ft_vector_int);
    std::vector<int>	std_vector_swap(std_vector_int);

    ft_vector_swap.resize(500);
    std_vector_swap.resize(500);
    ft_vector_swap.insert(ft_vector_swap.begin(), 666);
    std_vector_swap.insert(std_vector_swap.begin(), 666);

    std::clock_t ft_swap = std::clock();
    ft_vector_int.swap(ft_vector_swap);
    double ft_swap_diff = ( std::clock() - ft_swap ) / (double) CLOCKS_PER_SEC;

    std::clock_t std_swap = std::clock();
    std_vector_int.swap(std_vector_swap);
    double std_swap_diff = ( std::clock() - std_swap ) / (double) CLOCKS_PER_SEC;

    int swap_i = 0;
    int swap_result = 0;
    while (swap_i < 666)
    {
        if (ft_vector_int[swap_i] != std_vector_int[swap_i])
            swap_result = 1;
        swap_i++;
    }
    std::cout << "swap      = ";
    if (swap_result != 0)
        std::cout << "KO\n";
    else
        std::cout << "OK\n";
    std::cout << " | Duration : FT =  " << ft_round(ft_swap_diff) << " | STD = " << ft_round(std_swap_diff) << " | Diff =  ";
    if ((int)(ft_swap_diff / std_swap_diff) <= 0)
        std::cout << "0" << " | ";
    else
        std::cout << (int)(ft_swap_diff / std_swap_diff) << " | ";
    if (std_swap_diff == 0 && ft_swap_diff <= 20)
        std::cout << "OK\n";
    else if (ft_swap_diff / std_swap_diff <= 20)
        std::cout << "OK\n";
    else
        std::cout << "KO\n";

    ft_vector_int.swap(ft_vector_swap);
    std_vector_int.swap(std_vector_swap);

    // Test clear()
    std::clock_t ft_clear = std::clock();
    ft_vector_int.clear();
    double ft_clear_diff = ( std::clock() - ft_clear ) / (double) CLOCKS_PER_SEC;

    std::clock_t std_clear = std::clock();
    std_vector_int.clear();
    double std_clear_diff = ( std::clock() - std_clear ) / (double) CLOCKS_PER_SEC;

    std::cout << "clear     = ";
    if (ft_vector_int.size() != std_vector_int.size())
        std::cout << "KO\n";
    else
        std::cout << "OK\n";
    std::cout << " | Duration : FT =  " << ft_round(ft_clear_diff) << " | STD = " << ft_round(std_clear_diff) << " | Diff =  " << (int)(ft_clear_diff / std_clear_diff) << " | ";

    if (std_clear_diff == 0 && ft_clear_diff <= 20)
        std::cout << "OK\n";
    else if (ft_clear_diff / std_clear_diff <= 20)
        std::cout << "OK\n";
    else
        std::cout << "KO\n";

    // Test operators

    int operator_result = 0;
    if ((ft_vector_int[0] == ft_vector_int[1]) != (std_vector_int[0] == std_vector_int[1]))
        operator_result = 1;
    if ((ft_vector_int[0] != ft_vector_int[1]) != (std_vector_int[0] != std_vector_int[1]))
        operator_result = 1;
    if ((ft_vector_int[0] < ft_vector_int[1]) != (std_vector_int[0] < std_vector_int[1]))
        operator_result = 1;
    if ((ft_vector_int[0] <= ft_vector_int[1]) != (std_vector_int[0] <= std_vector_int[1]))
        operator_result = 1;
    if ((ft_vector_int[0] > ft_vector_int[1]) != (std_vector_int[0] > std_vector_int[1]))
        operator_result = 1;
    if ((ft_vector_int[0] >= ft_vector_int[1]) != (std_vector_int[0] >= std_vector_int[1]))
        operator_result = 1;

    std::cout << "operators = ";
    if (operator_result == 0)
        std::cout << "OK\n";
    else
        std::cout << "KO\n";
    std::cout << " | == : ";
    if ((ft_vector_int[0] == ft_vector_int[1]) != (std_vector_int[0] == std_vector_int[1]))
        std::cout << "KO\n";
    else
        std::cout << "OK\n";
    std::cout << " | != : ";
    if ((ft_vector_int[0] != ft_vector_int[1]) != (std_vector_int[0] != std_vector_int[1]))
        std::cout << "KO\n";
    else
        std::cout << "OK\n";
    std::cout << " | < : ";
    if ((ft_vector_int[0] < ft_vector_int[1]) != (std_vector_int[0] < std_vector_int[1]))
        std::cout << "KO\n";
    else
        std::cout << "OK\n";
    std::cout << " | <= : ";
    if ((ft_vector_int[0] <= ft_vector_int[1]) != (std_vector_int[0] <= std_vector_int[1]))
        std::cout << "KO\n";
    else
        std::cout << "OK\n";
    std::cout << " | > : ";
    if ((ft_vector_int[0] > ft_vector_int[1]) != (std_vector_int[0] > std_vector_int[1]))
        std::cout << "KO\n";
    else
        std::cout << "OK\n";
    std::cout << " | >= : ";
    if ((ft_vector_int[0] >= ft_vector_int[1]) != (std_vector_int[0] >= std_vector_int[1]))
        std::cout << "KO\n";
    else
        std::cout << "OK\n";

    // Test capacity
    int capacity_result = 0;
    if (ft_vector_int.empty() != std_vector_int.empty())
        capacity_result = 1;
    if (ft_vector_int.size() != std_vector_int.size())
        capacity_result = 1;
    if (ft_vector_int.max_size() != std_vector_int.max_size())
        capacity_result = 1;
    if (ft_vector_int.capacity() != std_vector_int.capacity())
        capacity_result = 1;

    std::cout << "capacity  = ";
    if (capacity_result == 0)
        std::cout << "OK\n";
    else
        std::cout << "KO\n";
    std::cout << " | empty = ";
    if (ft_vector_int.empty() == std_vector_int.empty())
        std::cout << "OK\n";
    else
        std::cout << "KO\n";
    std::cout << " | size = ";
    if (ft_vector_int.size() == std_vector_int.size())
        std::cout << "OK\n";
    else
        std::cout << "KO\n";
    std::cout << " | max_size = ";
    if (ft_vector_int.max_size() == std_vector_int.max_size())
        std::cout << "OK\n";
    else
        std::cout << "KO\n";
    std::cout << " | capacity = ";
    if (ft_vector_int.capacity() == std_vector_int.capacity())
        std::cout << "OK\n";
    else
        std::cout << "KO\n";
    std::cout << " | reserve = ";
    ft_vector_int.reserve(ft_vector_int.capacity() + 1);
    std_vector_int.reserve(std_vector_int.capacity() + 1);
    if (ft_vector_int.size() == std_vector_int.size())
        std::cout << "OK\n";
    else
        std::cout << "KO\n";
}


void	ft_map()
{
    ft::map<int, std::string>	ft_map;
    std::map<int, std::string>	std_map;

    // Tests Map

    std::cout << "\nMap" << std::endl << std::endl;

    // Test  insert
    std::clock_t ft_insert_map = std::clock();
    ft_map.insert(ft::pair<int, std::string>(1, "one"));
    ft_map.insert(ft::pair<int, std::string>(2, "two"));
    ft_map.insert(ft::pair<int, std::string>(3, "three"));
    ft_map.insert(ft::pair<int, std::string>(4, "four"));
    ft_map.insert(ft::pair<int, std::string>(5, "five"));
    double ft_insert_map_diff = ( std::clock() - ft_insert_map ) / (double) CLOCKS_PER_SEC;

    std::clock_t std_insert_map = std::clock();
    std_map.insert(std::pair<int, std::string>(1, "one"));
    std_map.insert(std::pair<int, std::string>(2, "two"));
    std_map.insert(std::pair<int, std::string>(3, "three"));
    std_map.insert(std::pair<int, std::string>(4, "four"));
    std_map.insert(std::pair<int, std::string>(5, "five"));
    double std_insert_map_diff = ( std::clock() - std_insert_map ) / (double) CLOCKS_PER_SEC;

    ft::map<int, std::string>::const_iterator ft_it = ft_map.begin();

    int insert_result_map = 0;
    for (std::map<int, std::string>::const_iterator std_it = std_map.begin(); std_it != std_map.end(); std_it++)
    {
        if (std_it->first != ft_it->first || std_it->second != ft_it->second)
            insert_result_map = 1;
        ft_it++;
    }
    std::cout << "insert    = ";
    if (insert_result_map != 0)
        std::cout << "KO\n";
    else
        std::cout << "OK\n";

    std::cout << " | Duration : FT = " << ft_round(ft_insert_map_diff) << " | STD = " << ft_round(std_insert_map_diff) << " | Diff = " << (int)(ft_insert_map_diff / std_insert_map_diff) << " | ";

    if (std_insert_map_diff == 0 && ft_insert_map_diff <= 20)
        std::cout << "OK\n";
    else if (ft_insert_map_diff / std_insert_map_diff <= 20)
        std::cout << "OK\n";
    else
        std::cout << "KO\n";

    // Test erase()
    std::clock_t ft_erase_map = std::clock();
    for (int i = 0; i != 2; i++)
    {
        ft_map.erase(ft_map.begin());
    }
    double ft_erase_map_diff = ( std::clock() - ft_erase_map ) / (double) CLOCKS_PER_SEC;

    std::clock_t std_erase_map = std::clock();
    for (int i = 0; i != 2; i++)
    {
        std_map.erase(std_map.begin());
    }
    double std_erase_map_diff = ( std::clock() - std_erase_map ) / (double) CLOCKS_PER_SEC;

    std::cout << "erase     = ";
    int	erase_map_result = 0;
    int	erase_map_i = 0;
    while (erase_map_i < 1000)
    {
        if (ft_map[erase_map_i] != std_map[erase_map_i])
            erase_map_result = 1;
        erase_map_i++;
    }
    if (ft_map.size() != std_map.size() || erase_map_result != 0)
        std::cout << "KO\n";
    else
        std::cout << "OK\n";
    std::cout << " | Duration : FT = " << ft_round(ft_erase_map_diff) << " | STD = " << ft_round(std_erase_map_diff) << " | Diff = " << (int)(ft_erase_map_diff / std_erase_map_diff) << " | ";

    if (std_erase_map_diff == 0 && ft_erase_map_diff <= 20)
        std::cout << "OK\n";
    else if (ft_erase_map_diff / std_erase_map_diff <= 20)
        std::cout << "OK\n";
    else
        std::cout << "KO\n";

    // Test swap()
    ft::map<int, std::string>	ft_map_swap;
    std::map<int, std::string>	std_map_swap;

    ft_map_swap.insert(ft::pair<int, std::string>(42, "forthy-two"));
    ft_map_swap.insert(ft::pair<int, std::string>(21, "twenty-one"));
    std_map_swap.insert(std::pair<int, std::string>(42, "forthy-two"));
    std_map_swap.insert(std::pair<int, std::string>(21, "twenty-one"));

    std::clock_t ft_swap_map = std::clock();
    ft_map.swap(ft_map_swap);
    double ft_swap_map_diff = ( std::clock() - ft_swap_map ) / (double) CLOCKS_PER_SEC;

    std::clock_t std_swap_map = std::clock();
    std_map.swap(std_map_swap);
    double std_swap_map_diff = ( std::clock() - std_swap_map ) / (double) CLOCKS_PER_SEC;

    int swap_map_i = 0;
    int swap_map_result = 0;
    while (swap_map_i < 666)
    {
        if (ft_map[swap_map_i] != std_map[swap_map_i])
            swap_map_result = 1;
        swap_map_i++;
    }
    std::cout << "swap      = ";
    if (swap_map_result != 0)
        std::cout << "KO\n";
    else
        std::cout << "OK\n";
    std::cout << " | Duration : FT = " << ft_round(ft_swap_map_diff) << " | STD = " << ft_round(std_swap_map_diff) << " | Diff = ";
    if ((int)(ft_swap_map_diff / std_swap_map_diff) <= 0 || !isfinite((int)(ft_swap_map_diff / std_swap_map_diff)))
        std::cout << "0" << " | ";
    else
        std::cout << ft_swap_map_diff / std_swap_map_diff << " | ";
    if (std_swap_map_diff == 0 && ft_swap_map_diff <= 20)
        std::cout << "OK\n";
    else if (ft_swap_map_diff / std_swap_map_diff <= 20)
        std::cout << "OK\n";
    else
        std::cout << "KO\n";

    ft_map.swap(ft_map_swap);
    std_map.swap(std_map_swap);

    // Test count()
    std::clock_t ft_count_map = std::clock();
    int	ft_return = ft_map.count(1);
    double ft_count_map_diff = ( std::clock() - ft_count_map ) / (double) CLOCKS_PER_SEC;

    std::clock_t std_count_map = std::clock();
    int	std_return = std_map.count(1);
    double std_count_map_diff = ( std::clock() - std_count_map ) / (double) CLOCKS_PER_SEC;

    std::cout << "count     = ";
    if (ft_return != std_return)
        std::cout << "KO\n";
    else
        std::cout << "OK\n";
    std::cout << " | Duration : FT = " << ft_round(ft_count_map_diff) << " | STD = " << ft_round(std_count_map_diff) << " | Diff = ";
    if (isnan((int)(ft_count_map_diff / std_count_map_diff)) || isinf((int)(ft_count_map_diff / std_count_map_diff)) || (int)(ft_count_map_diff / std_count_map_diff) == -2147483648)
        std::cout << "0" << " | ";
    else
        std::cout << (int)(ft_count_map_diff / std_count_map_diff) << " | ";

    if (std_count_map_diff == 0 && ft_count_map_diff <= 20)
        std::cout << "OK\n";
    else if (ft_count_map_diff / std_count_map_diff <= 20)
        std::cout << "OK\n";
    else
        std::cout << "KO\n";


    // Test find()
    std::clock_t ft_find_map = std::clock();
    ft::map<int, std::string>::iterator	ft_find_iterator = ft_map.find(1);
    double ft_find_map_diff = ( std::clock() - ft_find_map ) / (double) CLOCKS_PER_SEC;

    std::clock_t std_find_map = std::clock();
    std::map<int, std::string>::iterator	std_find_iterator = std_map.find(1);
    double std_find_map_diff = ( std::clock() - std_find_map ) / (double) CLOCKS_PER_SEC;

    std::cout << "find      = ";
    if (ft_find_iterator->second != std_find_iterator->second)
        std::cout << "KO\n";
    else
        std::cout << "OK\n";
    std::cout << " | Duration : FT = " << ft_round(ft_find_map_diff) << " | STD = " << ft_round(std_find_map_diff) << " | Diff = ";
    if (isnan((int)(ft_find_map_diff / std_find_map_diff)) || (int)(ft_find_map_diff / std_find_map_diff)== -2147483648)
        std::cout << "0" << " | ";
    else
        std::cout << (int)(ft_find_map_diff / std_find_map_diff) << " | ";

    if (std_find_map_diff == 0 && ft_find_map_diff <= 20)
        std::cout << "OK\n";
    else if (ft_find_map_diff / std_find_map_diff <= 20)
        std::cout << "OK\n";
    else
        std::cout << "KO\n";

    // Test operators

    int operator_result = 0;
    ft::map<int, std::string>::iterator	ft_operator_i = ft_map.begin();
    ft::map<int, std::string>::iterator	ft_operator_i2 = ft_map.begin();
    ft_operator_i2++;
    std::map<int, std::string>::iterator	std_operator_i = std_map.begin();
    std::map<int, std::string>::iterator	std_operator_i2 = std_map.begin();
    std_operator_i2++;
    if ((ft_operator_i->second == ft_operator_i2->second) != (std_operator_i->second == std_operator_i2->second))
        operator_result = 1;
    if ((ft_operator_i->second != ft_operator_i2->second) != (std_operator_i->second != std_operator_i2->second))
        operator_result = 1;
    if ((ft_operator_i->second < ft_operator_i2->second) != (std_operator_i->second < std_operator_i2->second))
        operator_result = 1;
    if ((ft_operator_i->second <= ft_operator_i2->second) != (std_operator_i->second <= std_operator_i2->second))
        operator_result = 1;
    if ((ft_operator_i->second > ft_operator_i2->second) != (std_operator_i->second > std_operator_i2->second))
        operator_result = 1;
    if ((ft_operator_i->second >= ft_operator_i2->second) != (std_operator_i->second >= std_operator_i2->second))
        operator_result = 1;

    std::cout << "operators = ";
    if (operator_result == 0)
        std::cout << "OK\n";
    else
        std::cout << "KO\n";
    std::cout << " | == : ";
    if ((ft_operator_i->second == ft_operator_i2->second) != (std_operator_i->second == std_operator_i2->second))
        std::cout << "KO\n";
    else
        std::cout << "OK\n";
    std::cout << " | != : ";
    if ((ft_operator_i->second != ft_operator_i2->second) != (std_operator_i->second != std_operator_i2->second))
        std::cout << "KO\n";
    else
        std::cout << "OK\n";
    std::cout << " | < : ";
    if ((ft_operator_i->second < ft_operator_i2->second) != (std_operator_i->second < std_operator_i2->second))
        std::cout << "KO\n";
    else
        std::cout << "OK\n";
    std::cout << " | <= : ";
    if ((ft_operator_i->second <= ft_operator_i2->second) != (std_operator_i->second <= std_operator_i2->second))
        std::cout << "KO\n";
    else
        std::cout << "OK\n";
    std::cout << " | > : ";
    if ((ft_operator_i->second > ft_operator_i2->second) != (std_operator_i->second > std_operator_i2->second))
        std::cout << "KO\n";
    else
        std::cout << "OK\n";
    std::cout << " | >= : ";
    if ((ft_operator_i->second >= ft_operator_i2->second) != (std_operator_i->second >= std_operator_i2->second))
        std::cout << "KO\n";
    else
        std::cout << "OK\n";
    std::cout << std::endl << std::endl;
}

float	ft_round(double var)
{
    float value = (int)(var * 100000 + .5);
    return((float)value);
}

void	ft_banner()
{
    std::cout << "tkt frero met 100" <<std::endl;
    std::cout << "##################################################################################################\n";
    std::cout << "#  ____ ___     ____ ____ _  _ ___ ____ _ _  _ ____ ____ ____     ___ ____ ____ ___ ____ ____    #\n";
    std::cout << "#  |___  |      |    |  | |\\ |  |  |__| | |\\ | |___ |__/ [__       |  |___ [__   |  |___ |__/    #\n";
    std::cout << "#  |     |  ___ |___ |__| | \\|  |  |  | | | \\| |___ |  \\ ___] ___  |  |___ ___]  |  |___ |  \\    #\n";
    std::cout << "#                                                                                                #\n";
    std::cout << "#  ___  _   _    ____ _  _ _  _ ___  ____ ____                                                   #\n";
    std::cout << "#  |__]  \\_/     |__| |__| |  | |__] |___ |__/                                                   #\n";
    std::cout << "#  |__]   |      |  | |  | |__| |__] |___ |  \\                                                   #\n";
    std::cout << "#                                                                                                #\n";
    std::cout << "##################################################################################################\n";
}
