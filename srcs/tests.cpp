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
    for (int u = 0; u < 25; u++)
        it_std_first++;
    for (int u = 0; u < 30; u++)
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
    for (int u = 0; u < 25; u++)
        it_ft_first++;
    for (int u = 0; u < 30; u++)
        it_ft_second++;
    // Call of erase within the range
    test_ft.erase(it_ft_first, it_ft_second);
    std::cout << std::endl << "---------FT VECTOR----------------------" << std::endl;
    for(ft::vector<int>::iterator it_ft = test_ft.begin(); it_ft != test_ft.end(); ++it_ft) {
        std::cout << i++ << ": *it_ft: " << *it_ft << std::endl;
    }
    i = 0;
    //---------------------------------------------------
    ft::vector<int> test_ft1;
    ft::vector<int> test_ft2;
    std::vector<int> test_std1;
    std::vector<int> test_std2;

    for (int i = 0; i < 50; i++)
        test_ft1.push_back(i);
    for (int i = 55; i > 0; i--)
        test_ft2.push_back(i);
    for (int i = 0; i < 50; i++)
        test_std1.push_back(i);
    for (int i = 55; i > 0; i--)
        test_std2.push_back(i);

    std::cout << "---------------------------Swap()---------------------------" << std::endl;
    std::cout << "------------------------FT_CONTAINER------------------------" << std::endl;
    std::cout << "Size 1 : " << test_ft1.size() << std::endl;
    std::cout << "Size 2 : " << test_ft2.size() << std::endl;

    std::cout << "Capacity 1 : " << test_ft1.capacity() << std::endl;
    std::cout << "Capacity 2 : " << test_ft2.capacity() << std::endl;

    std::cout << "Begin 1 : " << *(test_ft1.begin()) << std::endl;
    std::cout << "Begin 2 : " << *(test_ft2.begin()) << std::endl;

    std::cout << "##### Swap ........ ######" << std::endl;
    test_ft1.swap(test_ft2);

    std::cout << "Size 1 : " << test_ft1.size() << std::endl;
    std::cout << "Size 2 : " << test_ft2.size() << std::endl;

    std::cout << "Capacity 1 : " << test_ft1.capacity() << std::endl;
    std::cout << "Capacity 2 : " << test_ft2.capacity() << std::endl;

    std::cout << "Begin 1 : " << *(test_ft1.begin()) << std::endl;
    std::cout << "Begin 2 : " << *(test_ft2.begin()) << std::endl;


    std::cout << "------------------------STD_CONTAINER------------------------" << std::endl;
    std::cout << "Size 1 : " << test_std1.size() << std::endl;
    std::cout << "Size 2 : " << test_std2.size() << std::endl;

    std::cout << "Capacity 1 : " << test_std1.capacity() << std::endl;
    std::cout << "Capacity 2 : " << test_std2.capacity() << std::endl;

    std::cout << "Begin 1 : " << *(test_std1.begin()) << std::endl;
    std::cout << "Begin 2 : " << *(test_std2.begin()) << std::endl;

    std::cout << "##### Swap ........ ######" << std::endl;
    test_std1.swap(test_std2);

    std::cout << "Size 1 : " << test_std1.size() << std::endl;
    std::cout << "Size 2 : " << test_std2.size() << std::endl;

    std::cout << "Capacity 1 : " << test_std1.capacity() << std::endl;
    std::cout << "Capacity 2 : " << test_std2.capacity() << std::endl;

    std::cout << "Begin 1 : " << *(test_std1.begin()) << std::endl;
    std::cout << "Begin 2 : " << *(test_std2.begin()) << std::endl;

    //---------------------------------------------------

    std::cout << "---------------------------Shrink_to_fit()---------------------------" << std::endl;
    std::cout << "------------------------FT_CONTAINER------------------------" << std::endl;
    test_ft1.pop_back();
    test_ft1.pop_back();
    std::cout << "Size : " << test_ft1.size() << std::endl;
    std::cout << "Capacity : " << test_ft1.capacity() << std::endl;
    std::cout << "##### Shrink to fit ........ ######" << std::endl;
    test_ft1.shrink_to_fit();
    std::cout << "Size : " << test_ft1.size() << std::endl;
    std::cout << "Capacity : " << test_ft1.capacity() << std::endl;

    std::cout << "------------------------STD_CONTAINER------------------------" << std::endl;
    test_std1.pop_back();
    test_std1.pop_back();
    std::cout << "Size : " << test_std1.size() << std::endl;
    std::cout << "Capacity : " << test_std1.capacity() << std::endl;
    std::cout << "##### Shrink to fit ........ ######" << std::endl;
    test_std1.shrink_to_fit();
    std::cout << "Size : " << test_std1.size() << std::endl;
    std::cout << "Capacity : " << test_std1.capacity() << std::endl;

    //--------------------------------------------------------------------------
    std::cout << "---------------------------insert()---------------------------" << std::endl;
    std::vector<int> test_std3;
    std::vector<int>::iterator it_std_insert;
    for (int u = 0; u < 8; u++)
        test_std3.push_back(u);
    it_std_insert = test_std3.begin();
    for (int u = 0; u < 3; u++)
        it_std_insert++;
    std::cout << "Size : " << test_std3.size() << std::endl;
    std::cout << "Capacity : " << test_std3.capacity() << std::endl;
    std::cout << "##### insert ........ ######" << std::endl;
    test_std3.insert(it_std_insert, 15, 2000);
    std::cout << "Size : " << test_std3.size() << std::endl;
    std::cout << "Capacity : " << test_std3.capacity() << std::endl;
    i = 0;
    for(std::vector<int>::iterator it_std = test_std3.begin(); it_std != test_std3.end(); ++it_std) {
        std::cout << i++ << ": *it_std: " << *it_std << std::endl;
    }
    i = 0;

    std::cout << "---------------------------insert()---------------------------" << std::endl;
    ft::vector<int> test_ft3;
    ft::vector<int>::iterator it_ft_insert;
    ft::vector<int>::iterator it_ft_insert_first;
    ft::vector<int>::iterator it_ft_insert_last;
    ft::vector<int> test_ft_insert;

    for (int u = 0; u < 8; u++)
        test_ft3.push_back(u);
    test_ft3.reserve(100);
    for (int u = 26; u < 33; u++)
        test_ft_insert.push_back(u);
    it_ft_insert = test_ft3.begin();
    it_ft_insert_first = test_ft_insert.begin();
    it_ft_insert_last = test_ft_insert.begin();
    for (int u = 0; u < 3; u++)
        it_ft_insert++;
    for (int u = 0; u < 3; u++)
        it_ft_insert_first++;
    for (int u = 0; u < 6; u++)
        it_ft_insert_last++;

    std::cout << "Size : " << test_ft3.size() << std::endl;
    std::cout << "Capacity : " << test_ft3.capacity() << std::endl;
    std::cout << "##### insert ........ ######" << std::endl;
    test_ft3.insert(it_ft_insert, it_ft_insert_first, it_ft_insert_last);
    std::cout << "Size : " << test_ft3.size() << std::endl;
    std::cout << "Capacity : " << test_ft3.capacity() << std::endl;
    i = 0;
    for(ft::vector<int>::iterator it_ft44 = test_ft3.begin(); it_ft44 != test_ft3.end(); ++it_ft44) {
        std::cout << i++ << ": *it_ft: " << *it_ft44 << std::endl;
    }
    i = 0;
    return (0);
}