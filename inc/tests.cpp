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
//#include "./map.hpp"

template <typename Ite_1, typename Ite_2>
void ft_eq_ope(const Ite_1 &first, const Ite_2 &second, const bool redo = 1)
{
    std::cout << (first < second) << std::endl;
    std::cout << (first <= second) << std::endl;
    std::cout << (first > second) << std::endl;
    std::cout << (first >= second) << std::endl;
    if (redo)
        ft_eq_ope(second, first, 0);
}

int main()
{

    {
        const int size = 5;
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
        ft_eq_ope(it_mid, cit_1 - 3);
    }

    return (0);
}


