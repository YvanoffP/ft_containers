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
#include <memory>
#include "bst.hpp"
#include <map>
#include "./map.hpp"
#include <utility>
#include <list>
#include <string>


/*class B {
public:
    char *l;
    int i;
    B():l(NULL), i(1) {};
    B(const int &ex) {
        this->i = ex;
        this->l = new char('a');
    };
    virtual ~B() {
        delete this->l;
        this->l = NULL;
    };
};

class A : public B {
public:
    A():B(){};
    A(const B* ex){
        this->l = new char(*(ex->l));
        this->i = ex->i;
        if (ex->i == -1) throw "n";
    }
    ~A() {
        delete this->l;
        this->l = NULL;
    };
};*/

/*template <typename Ite_1, typename Ite_2>
void ft_eq_ope(const Ite_1 &first, const Ite_2 &second, const bool redo = 1)
{
    std::cout << (first < second) << std::endl;
    std::cout << (first <= second) << std::endl;
    std::cout << (first > second) << std::endl;
    std::cout << (first >= second) << std::endl;
    if (redo)
        ft_eq_ope(second, first, 0);
}*/
#define T1 int
#define T2 int
typedef ft::pair<const T1, T2> T3;

template <class MAP>
void	cmp(const MAP &lhs, const MAP &rhs)
{
    static int i = 0;

    std::cout << "############### [" << i++ << "] ###############"  << std::endl;
    std::cout << "eq: " << (lhs == rhs) << " | ne: " << (lhs != rhs) << std::endl;
    std::cout << "lt: " << (lhs <  rhs) << " | le: " << (lhs <= rhs) << std::endl;
    std::cout << "gt: " << (lhs >  rhs) << " | ge: " << (lhs >= rhs) << std::endl;
}

/*

template <typename T>
std::string    printPair(const T &iterator, bool nl = true, std::ostream &o = std::cout)
{
    o << "key: " << iterator->first << " | value: " << iterator->second;
    if (nl)
        o << std::endl;
    return ("");
}

template <typename T_MAP>
void    printSize(T_MAP const &mp, bool print_content = 1)
{
    std::cout << "size: " << mp.size() << std::endl;
    std::cout << "max_size: " << mp.max_size() << std::endl;
    if (print_content)
    {
        typename T_MAP::const_iterator it = mp.begin(), ite = mp.end();
        std::cout << std::endl << "Content is:" << std::endl;
        for (; it != ite; ++it)
            std::cout << "- " << printPair(it, false) << std::endl;
    }
    std::cout << "###############################################" << std::endl;
}*/
int main()
{
    ft::map<T1, T2> mp1;
    ft::map<T1, T2> mp2;

    mp1['a'] = 2; mp1['b'] = 3; mp1['c'] = 4; mp1['d'] = 5;
    mp2['a'] = 2; mp2['b'] = 3; mp2['c'] = 4; mp2['d'] = 5;

    cmp(mp1, mp1); // 0
    cmp(mp1, mp2); // 1

    mp2['e'] = 6; mp2['f'] = 7; mp2['h'] = 8; mp2['h'] = 9;

    cmp(mp1, mp2); // 2
    cmp(mp2, mp1); // 3

    (++(++mp1.begin()))->second = 42;

    cmp(mp1, mp2); // 4
    cmp(mp2, mp1); // 5

    swap(mp1, mp2);

    cmp(mp1, mp2); // 6
    cmp(mp2, mp1); // 7

    return (0);
/*        std::list<T3> lst;
        unsigned int lst_size = 7;
        for (unsigned int i = 0; i < lst_size; ++i)
            lst.push_back(T3(lst_size - i, i));

        ft::map<T1, T2> mp(lst.begin(), lst.end());
        std::cout << "First print : " << std::endl;
        printSize(mp);

        ft::map<T1, T2>::iterator it = mp.begin(), ite = mp.end();
        --(--ite);
    --(--ite);


    std::cout << "End first : " << ite->first << std::endl;

        for (int i = 0; it != ite; ++it)
            it->second = ++i * 5;

        std::cout << "Second print : " << std::endl;
        printSize(mp);

        it = mp.begin(); ite = --(--mp.end());

        std::cout << "End first : " << ite->first << std::endl;

        for (int i = 0; it != ite; ++it)
            it->second = ++i * 7;

        std::cout << "Third print : " << std::endl;
        printSize(mp);
        return (0);*/
    /*{
        ft::map<int, int> test;
        ft::pair<int, int> kk1(1, 26);
        ft::pair<int, int> kk2(2, 262);
        ft::pair<int, int> kk3(3, 333);
        ft::pair<int, int> kk4(4, 212316);
        ft::pair<int, int> kk5(5, 2123);
        ft::map<int, int> test2;
        int i = 12;
        int u = 25;
        ft::pair<int, int> test_pair = ft::make_pair(i, u);
        i = u + i;
        u += 199;
        ft::pair<int, int> test_pair2 = ft::make_pair(i, u);
        i = u + i;
        u += 199;
        ft::pair<int, int> test_pair3 = ft::make_pair(i, u);
        i = 1;
        u = 2;
        ft::pair<int, int> test_pair4 = ft::make_pair(i, u);
        i = 199;
        u = 2000;
        ft::pair<int, int> test_pair5 = ft::make_pair(i, u);
        test.insert(kk5);
        test.insert(kk4);
        test.insert(kk3);
        test.insert(kk1);
        test.insert(kk2);
        test.print();

        test2.insert(test_pair);
        test2.insert(test_pair2);
        test2.insert(test_pair3);
        test2.insert(test_pair4);
        test2.insert(test_pair5);
        std::cout << "Lower bound of 38 is :" << test2.lower_bound(38)->first << std::endl;
        std::cout << "Upper bound of 38 is :" << test2.upper_bound(38)->first << std::endl;
        test2.print();

        *//*test2.erase(test2.begin());
        ft::map<int, int>::const_iterator it = test2.begin(), ite = test2.end();
        std::cout << std::endl << "Content is:" << std::endl;
        for (; it != ite; ++it)
            std::cout << "- " << "cc" << std::endl;*//*
    }*/
    {
       /* std::list<std::pair<const int, std::string> > lst;
        unsigned int lst_size = 10;
        for (unsigned int i = 0; i < lst_size; ++i)
            lst.push_back(std::pair<const int, std::string>(i, std::string((lst_size - i), i + 65)));
        ft::map<int, std::string> mp(lst.begin(), lst.end());*/
        /*printSize(mp);

        ft_erase(mp, ++mp.begin());

        ft_erase(mp, mp.begin());
        ft_erase(mp, --mp.end());

        ft_erase(mp, mp.begin(), ++(++(++mp.begin())));
        ft_erase(mp, --(--(--mp.end())), --mp.end());

        mp[10] = "Hello";
        mp[11] = "Hi there";
        printSize(mp);*/
        //ft_erase(mp, --(--(--mp.end())), mp.end());

        /*mp[12] = "ONE";
        mp[13] = "TWO";
        mp[14] = "THREE";
        mp[15] = "FOUR";*/
        /*printSize(mp);
        ft_erase(mp, mp.begin(), mp.end());*/
    }
    /*{

        ft::Binary_search_tree<ft::pair<int, int>, int> test;
        int i = 12;
        int u = 25;
        ft::pair<int, int> test_pair = ft::make_pair(i, u);
        i = u + i;
        u += 199;
        ft::pair<int, int> test_pair2 = ft::make_pair(i, u);
        i = u + i;
        u += 199;
        ft::pair<int, int> test_pair3 = ft::make_pair(i, u);
        i = 1;
        u = 2;
        ft::pair<int, int> test_pair4 = ft::make_pair(i, u);
        i = 199;
        u = 2000;
        ft::pair<int, int> test_pair5 = ft::make_pair(i, u);

        std::cout << "Is test tree empty ? " << test.isEmpty() << std::endl;
        std::cout << "test pair 1: " << test_pair.first << " " << test_pair.second << std::endl;
        std::cout << "test pair 2: " << test_pair2.first << " " << test_pair2.second << std::endl;
        std::cout << "test pair 3: " << test_pair3.first << " " << test_pair3.second << std::endl;
        std::cout << "test pair 4: " << test_pair4.first << " " << test_pair4.second << std::endl;
        std::cout << "test pair 5: " << test_pair5.first << " " << test_pair5.second << std::endl;
        test.insert(test_pair);
        test.insert(test_pair2);
        test.insert(test_pair3);
        test.insert(test_pair4);
        test.insert(test_pair5);


        std::cout << "Is test tree empty ? " << test.isEmpty() << std::endl;
        std::cout << "Root : " << test.getRoot()->value.first << std::endl;
        std::cout << "Does Tree have 37 as a key ? " << test.containsKey(test_pair2, test.getRoot() ) << std::endl;
        std::cout << "Max value in the tree is : " << test.findMax(test.getRoot())->value.first << std::endl;
        std::cout << "Min value in the tree is : " << test.findMin(test.getRoot())->value.first << std::endl;
        test.printBT();
        std::cout << "Lower bound of 38 is :" << test.lower_bound(38)->first << std::endl;
        std::cout << "Upper bound of 38 is :" << test.upper_bound(38)->first << std::endl;
        test.remove(test_pair);
        test.remove(test_pair3);

        std::cout << "Find Pair 1 | 2 : " << test.find(test_pair4)->value.first << " | "
            << test.find(test_pair4)->value.second << " His parent is : " <<
            test.find(test_pair4)->parent->value.first <<
            " | " << test.find(test_pair4)->parent->value.second << std::endl;
        test.printBT();
        test.makeEmpty();
        std::cout << "Is test tree empty ? " << test.isEmpty() << std::endl;
        test.printBT();

    }*/
    /*{

        std::map<int, int> test;
        int i = 12;
        int u = 25;
        std::pair<int, int> test_pair = std::make_pair(i, u);
        i = u + i;
        u += 199;
        std::pair<int, int> test_pair2 = std::make_pair(i, u);
        i = u + i;
        u += 199;
        std::pair<int, int> test_pair3 = std::make_pair(i, u);
        i = 1;
        u = 2;
        std::pair<int, int> test_pair4 = std::make_pair(i, u);
        i = 199;
        u = 2000;
        std::pair<int, int> test_pair5 = std::make_pair(i, u);

        std::cout << "test pair 1: " << test_pair.first << " " << test_pair.second << std::endl;
        std::cout << "test pair 2: " << test_pair2.first << " " << test_pair2.second << std::endl;
        std::cout << "test pair 3: " << test_pair3.first << " " << test_pair3.second << std::endl;
        std::cout << "test pair 4: " << test_pair4.first << " " << test_pair4.second << std::endl;
        std::cout << "test pair 5: " << test_pair5.first << " " << test_pair5.second << std::endl;
        test.insert(test_pair);
        test.insert(test_pair2);
        test.insert(test_pair3);
        test.insert(test_pair4);
        test.insert(test_pair5);
        std::cout << "Lower bound of 38 is :" << test.lower_bound(38)->first << std::endl;
        std::cout << "Upper bound of 38 is :" << test.upper_bound(38)->first << std::endl;

    }*/
    /*int i = 0;
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
    std::cout << "MAIN DE LA DARONNE DE MES 2" << std::endl;
    std::vector<int> v;
    ft::vector<int> tmp;
    ft::vector<int> vector;
    tmp.assign(260, 1);
    vector.assign(420, 1);

    vector.insert(vector.end() - 100, tmp.begin(), tmp.end());

    v.push_back(vector[3]);

    v.push_back(vector.size());

    v.push_back(vector.capacity());

    std::unique_ptr<B> k2(new B(3));
    std::unique_ptr<B> k3(new B(4));
    std::unique_ptr<B> k4(new B(-1));
    ft::vector<A> vv;
    ft::vector<B*> v1;

    v1.push_back(&(*k2));
    v1.push_back(&(*k3));
    v1.push_back(&(*k4));

    for (ft::vector<B*>::iterator it = v1.begin(); it != v1.end(); it ++) {
        std::cout << *it << std::endl;
    }

    try { vv.insert(vv.begin(), v1.begin(), v1.end()); }
    catch (...) {
        ft::vector<A>::iterator it = vv.begin();
        std::cout << vv.size() << " " << vv.capacity() << std::endl;
        std::cout << v1.size() << " " << v1.capacity() << std::endl;
        //std::cout << *it << std::endl;
        v.push_back(vv.size());
        v.push_back(vv.capacity());
        //std::cout << "allo" << std::cout;
    }*/
    //--------------------------------------------------------------------------
    /*std::cout << "---------------------------insert()---------------------------" << std::endl;
    std::vector<int> test_std3;
    std::vector<int>::iterator it_std_insert;
    std::vector<int>::iterator it_std_insert_first;
    std::vector<int>::iterator it_std_insert_last;
    std::vector<int> test_std_insert;

    for (int u = 0; u < 8; u++)
        test_std3.push_back(u);
    for (int u = 20; u < 33; u++)
        test_std_insert.push_back(u);
    it_std_insert = test_std3.begin();
    it_std_insert_first = test_std_insert.begin();
    it_std_insert_last = test_std_insert.begin();
    for (int u = 0; u < 3; u++)
        it_std_insert++;
    for (int u = 0; u < 3; u++)
        it_std_insert_first++;
    for (int u = 0; u < 6; u++)
        it_std_insert_last++;

    std::cout << "Size : " << test_std3.size() << std::endl;
    std::cout << "Capacity : " << test_std3.capacity() << std::endl;
    std::cout << "##### insert ........ ######" << std::endl;
    test_std3.insert(it_std_insert, test_std_insert.begin(), test_std_insert.end());
    i = 0;
    for(std::vector<int>::iterator it_std44 = test_std3.begin(); it_std44 != test_std3.end(); ++it_std44) {
        std::cout << i++ << ": *it_std: " << *it_std44 << std::endl;
    }*/
    //i = 0;

   /* std::cout << "---------------------------insert()---------------------------" << std::endl;
    ft::vector<int> test_ft3;
    ft::vector<int>::iterator it_ft_insert;
    ft::vector<int>::iterator it_ft_insert_first;
    ft::vector<int>::iterator it_ft_insert_last;
    ft::vector<int> test_ft_insert;

    for (int u = 0; u < 4200000; u++)
        test_ft3.push_back(u);
    for (int u = 0; u < 100; u++)
        test_ft_insert.push_back(u);
    //it_ft_insert = test_ft3.begin();
    it_ft_insert_first = test_ft_insert.begin();
    it_ft_insert_last = test_ft_insert.end();
    //for (int u = 0; u < 3; u++)
        //it_ft_insert++;
    //for (int u = 0; u < 3; u++)
        //it_ft_insert_first++;
    //for (int u = 0; u < 6; u++)
        //it_ft_insert_last++;

    std::cout << "Size : " << test_ft3.size() << std::endl;
    std::cout << "Capacity : " << test_ft3.capacity() << std::endl;
    std::cout << "##### insert ........ ######" << std::endl;
    test_ft3.insert(test_ft3.end(), it_ft_insert_first, it_ft_insert_last);
    std::cout << "Size : " << test_ft3.size() << std::endl;
    std::cout << "Capacity : " << test_ft3.capacity() << std::endl;
    i = 0;
    //for(ft::vector<int>::iterator it_ft44 = test_ft3.begin(); it_ft44 != test_ft3.end(); ++it_ft44) {
    //    std::cout << i++ << ": *it_ft: " << *it_ft44 << std::endl;
    //}
    i = 0;
    test_ft3.insert(test_ft3.begin(), 2, 21);
    std::cout << "Size : " << test_ft3.size() << std::endl;
    std::cout << "Capacity : " << test_ft3.capacity() << std::endl;
    std::cout << "##### insert ........ ######" << std::endl;
    test_ft3.insert(test_ft3.end() - 2, 30);
    std::cout << "Size : " << test_ft3.size() << std::endl;
    std::cout << "Capacity : " << test_ft3.capacity() << std::endl;
    i = 0;
    for(ft::vector<int>::iterator it_ft44 = test_ft3.begin(); it_ft44 != test_ft3.end(); ++it_ft44) {
        std::cout << i++ << ": *it_ft: " << *it_ft44 << std::endl;
    }
    i = 0;

    std::cout << "Size : " << test_ft3.size() << std::endl;
    std::cout << "Capacity : " << test_ft3.capacity() << std::endl;
    std::cout << "##### insert ........ ######" << std::endl;
    test_ft3.insert(test_ft3.end(), 2, 30);
    std::cout << "Size : " << test_ft3.size() << std::endl;
    std::cout << "Capacity : " << test_ft3.capacity() << std::endl;
    i = 0;
    for(ft::vector<int>::iterator it_ft44 = test_ft3.begin(); it_ft44 != test_ft3.end(); ++it_ft44) {
        std::cout << i++ << ": *it_ft: " << *it_ft44 << std::endl;
    }
    i = 0;*/

    // --------------------------------------------------------------------------------------------------------------

    {
        /*const int size = 5;
        ft::vector<int> vct(size);
        ft::vector<int>::reverse_iterator it = vct.rbegin();
        ft::vector<int>::const_reverse_iterator ite = vct.rbegin();

        for (int i = 0; i < size; ++i)
            it[i] = (size - i) * 5;

        it = it + 5;
        it = 1 + it;
        it = it - 4;
        std::cout << *(it += 2) << std::endl;
        std::cout << *(it -= 1) << std::endl;

        *(it -= 2) = 42;
        *(it += 2) = 21;

        std::cout << "const_ite +=/-=: " << *(ite += 2) << " | " << *(ite -= 2) << std::endl;

        std::cout << "(it == const_it): " << (ite == it) << std::endl;
        std::cout << "(const_ite - it): " << (ite - it) << std::endl;
        std::cout << "(ite + 3 == it): " << (ite + 3 == it) << std::endl;*/
    }
    {
        /*const int size = 5;
        ft::vector<int> vct(size);
        ft::vector<int>::reverse_iterator it(vct.rbegin());
        ft::vector<int>::const_reverse_iterator ite(vct.rend());

        for (int i = 1; it != ite; ++i)
            *it++ = (i * 7);

        it = vct.rbegin();
        ite = vct.rbegin();

        std::cout << *(++ite) << std::endl;
        std::cout << *(ite++) << std::endl;
        std::cout << *ite++ << std::endl;
        std::cout << *++ite << std::endl;

        it->m();
        ite->m();

        std::cout << *(++it) << std::endl;
        std::cout << *(it++) << std::endl;
        std::cout << *it++ << std::endl;
        std::cout << *++it << std::endl;

        std::cout << *(--ite) << std::endl;
        std::cout << *(ite--) << std::endl;
        std::cout << *--ite << std::endl;
        std::cout << *ite-- << std::endl;

        (*it).m();
        (*ite).m();

        std::cout << *(--it) << std::endl;
        std::cout << *(it--) << std::endl;
        std::cout << *it-- << std::endl;
        std::cout << *--it << std::endl;*/
    }
    {
        /*const int size = 5;
        ft::vector<int> vct(size);
        ft::vector<int>::reverse_iterator it_0(vct.rbegin());
        ft::vector<int>::reverse_iterator it_1(vct.rend());
        ft::vector<int>::reverse_iterator it_mid;

        ft::vector<int>::const_reverse_iterator cit_0 = vct.rbegin();
        ft::vector<int>::const_reverse_iterator cit_1;
        ft::vector<int>::const_reverse_iterator cit_mid;

        std::cout << "cc" << std::endl;

        for (int i = size; it_0 != it_1; --i)
            *it_0++ = i;

        it_0 = vct.rbegin();
        cit_1 = vct.rend();
        it_mid = it_0 + 3;

        cit_mid = it_0 + 3; cit_mid = cit_0 + 3; cit_mid = it_mid;

        std::cout << std::boolalpha;

        std::cout << ((it_0 + 3 == cit_0 + 3) && (cit_0 + 3 == it_mid)) << std::endl;

        std::cout << "\t\tft_eq_ope:" << std::endl;
        // regular it

        ft_eq_ope(it_0 + 3, it_mid);
        ft_eq_ope(it_0, it_1);
        ft_eq_ope(it_1 - 3, it_mid);
        // const it

        ft_eq_ope(cit_0 + 3, cit_mid);
        ft_eq_ope(cit_0, cit_1);
        ft_eq_ope(cit_1 - 3, cit_mid);
        // both it

        ft_eq_ope(it_0 + 3, cit_mid);
        ft_eq_ope(it_mid, cit_0 + 3);
        ft_eq_ope(it_0, cit_1);
        ft_eq_ope(it_1, cit_0);
        ft_eq_ope(it_1 - 3, cit_mid);
        ft_eq_ope(it_mid, cit_1 - 3);*/
    }


    return (0);
}


