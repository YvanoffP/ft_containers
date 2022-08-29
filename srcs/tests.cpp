#include <iostream>
#include "./random_access_iterator.hpp"
#include "./bidirectional_iterator.hpp"
#include "./reverse_iterator.hpp"
#include "./pair.hpp"
#include "./enable_if.hpp"
#include "./equal.hpp"
#include "./is_integral.hpp"
#include "./vector.hpp"
#include <vector>

int main()
{
    int i = 0;
    ft::vector<int> test_ft;
    std::vector<int> test_std;
    for (int k = 0; k < 50; k++)
    {
        test_ft.push_back(k);
        test_std.push_back(k);
    }
    // Testing iteration -----------------------------
    std::cout << "---------FT VECTOR----------------------" << std::endl;
    for(ft::vector<int>::iterator it_ft2 = test_ft.begin(); it_ft2 != test_ft.end(); ++it_ft2) {
        std::cout << i++ << ": *it_ft: " << *it_ft2 << std::endl;
    }
    i = 0;
    std::cout << std::endl << "---------STD VECTOR----------------------" << std::endl;
    for(std::vector<int>::iterator it_std = test_std.begin(); it_std != test_std.end(); ++it_std) {
        std::cout << i++ << ": *it_std: " << *it_std << std::endl;
    }
    i = 0;
    // --------------------------------------------------
    std::cout << std::endl << "---------------Empty()--------------------------------" << std::endl;
    std::cout << "Is ft vector empty ? - " << test_ft.empty() << std::endl;
    std::cout << "Is std vector empty ? - " << test_std.empty() << std::endl;
    //---------------------------------------------------
    std::cout << std::endl << "---------------Capacity()--------------------------------" << std::endl;
    std::cout << "ft vector capacity : " << test_ft.capacity() << std::endl;
    std::cout << "std vector capacity : " << test_std.capacity() << std::endl;
    //---------------------------------------------------
    std::cout << std::endl << "---------------Max_size()--------------------------------" << std::endl;
    std::cout << "ft vector max_size : " << test_ft.max_size() << std::endl;
    std::cout << "std vector max_size : " << test_std.max_size() << std::endl;
    //---------------------------------------------------
    std::cout << std::endl << "---------------Size()--------------------------------" << std::endl;
    std::cout << "ft vector size : " << test_ft.size() << std::endl;
    std::cout << "std vector size : " << test_std.size() << std::endl;
    //---------------------------------------------------
    std::cout << std::endl << "---------------operator[]--------------------------------" << std::endl;
    std::cout << "ft vector @ [2] : " << test_ft[2] << std::endl;
    std::cout << "std vector @ [2] : " << test_std[2] << std::endl;
    //---------------------------------------------------
    std::cout << std::endl << "---------------at()--------------------------------" << std::endl;
    std::cout << "ft vector at 4 : " << test_ft.at(4) << std::endl;
    std::cout << "std vector at 4 : " << test_std.at(4) << std::endl;
    // DE COMMENT THESE ONE BY ONE TO CHECK THROW
    //test_ft.at(22);
    //test_std.at(22);
    //---------------------------------------------------
    std::cout << std::endl << "---------------front()--------------------------------" << std::endl;
    std::cout << "ft vector front : " << test_ft.front() << std::endl;
    std::cout << "std vector front : " << test_std.front() << std::endl;
    //---------------------------------------------------
    std::cout << std::endl << "---------------back()--------------------------------" << std::endl;
    std::cout << "ft vector back : " << test_ft.back() << std::endl;
    std::cout << "std vector back : " << test_std.back() << std::endl;
    //---------------------------------------------------
    std::cout << std::endl << "---------------erase()--------------------------------" << std::endl;
    std::vector<int>::iterator it_std_first;
    std::vector<int>::iterator it_std_second;
    it_std_first = test_std.begin();
    it_std_second = test_std.begin();
    // Move iterators to 25 for first and 30 for second
    for (int i; i < 25; i++)
        it_std_first++;
    for (int i; i < 30; i++)
        it_std_second++;
    // Call of erase within the range
    test_std.erase(it_std_first, it_std_second);
    std::cout << std::endl << "---------std VECTOR----------------------" << std::endl;
    for(std::vector<int>::iterator it_std = test_std.begin(); it_std != test_std.end(); ++it_std) {
        std::cout << i++ << ": *it_std: " << *it_std << std::endl;
    }
    i = 0;

    ft::vector<int>::iterator it_ft_first;
    ft::vector<int>::iterator it_ft_second;
    it_ft_first = test_ft.begin();
    it_ft_second = test_ft.begin();
    // Move iterators to 25 for first and 30 for second
    for (int i; i < 25; i++)
        it_ft_first++;
    for (int i; i < 30; i++)
        it_ft_second++;
    // Call of erase within the range
    test_ft.erase(it_ft_first, it_ft_second);
    std::cout << std::endl << "---------FT VECTOR----------------------" << std::endl;
    for(ft::vector<int>::iterator it_ft = test_ft.begin(); it_ft != test_ft.end(); ++it_ft) {
        std::cout << i++ << ": *it_ft: " << *it_ft << std::endl;
    }
    i = 0;




    return (0);
}