#include "tests_utils.hpp"

#define _fvec ft::vector
#define _svec std::vector

int main(void)
{
    // Constructors tests
    {
        // ========= STD DECLARATIONS =====================
        _svec<int> std_test_void;
        _svec<int> std_test(10);
        _svec<int>::const_iterator it_std = std_test.begin();
        _svec<int>::const_iterator ite_std = --(--std_test.end());
        _svec<int> std_test2(std_test);
        _svec<int> std_test3(100, 99);
        _svec<int> std_test4(it_std, ite_std);
        // ========= FT DECLARATIONS =====================
        _fvec<int> ft_test_void;
        _fvec<int> ft_test(10);
        _fvec<int>::const_iterator it_ft = ft_test.begin();
        _fvec<int>::const_iterator ite_ft = --(--ft_test.end());
        _fvec<int> ft_test2(ft_test);
        _fvec<int> ft_test3(100, 99);
        _fvec<int> ft_test4(it_ft, ite_ft);
        // ========= COMPARISONS =========================
        std::cout << FMAG("============== Constructors comparisons ==============") << std::endl;
        std::cout << FGRN("void constructor :") << std::endl;
        std::cout << "-----------ft----------- " << std::endl;
        printSize(ft_test_void, 0);
        std::cout << "-----------std-----------" << std::endl;
        printSize(std_test_void, 0);
        std::cout << std::endl << std::endl;

        std::cout << FGRN("value constructor :") << std::endl;
        std::cout << "-----------ft----------- " << std::endl;
        printSize(ft_test, 0);
        std::cout << "-----------std-----------" << std::endl;
        printSize(std_test, 0);
        std::cout << "-----------content-----------" << std::endl;
        controlContent(ft_test, std_test);
        std::cout << std::endl << std::endl;

        std::cout << FGRN("copy constructor :") << std::endl;
        std::cout << "-----------ft----------- " << std::endl;
        printSize(ft_test2, 0);
        std::cout << "-----------std-----------" << std::endl;
        printSize(std_test2, 0);
        std::cout << "-----------content-----------" << std::endl;
        controlContent(ft_test2, std_test2);
        std::cout << std::endl << std::endl;

        std::cout << FGRN("value and fill constructor :") << std::endl;
        std::cout << "-----------ft----------- " << std::endl;
        printSize(ft_test3, 0);
        std::cout << "-----------std-----------" << std::endl;
        printSize(std_test3, 0);
        std::cout << "-----------content-----------" << std::endl;
        controlContent(ft_test3, std_test3);
        std::cout << std::endl << std::endl;

        std::cout << FGRN("iterator range constructor :") << std::endl;
        std::cout << "-----------ft----------- " << std::endl;
        printSize(ft_test4, 0);
        std::cout << "-----------std-----------" << std::endl;
        printSize(std_test4, 0);
        std::cout << "-----------content-----------" << std::endl;
        controlContent(ft_test4, std_test4);
        std::cout << std::endl << std::endl;
    }

    {
        std::cout << FMAG("============== assign() ==============") << std::endl;
        // ========= STD DECLARATIONS =====================
        _svec<int> std_test(10);
        _svec<int>::const_iterator it_std = std_test.begin();
        _svec<int>::const_iterator ite_std = --(--std_test.end());
        // ========= FT DECLARATIONS =====================
        _fvec<int> ft_test(10);
        _fvec<int>::const_iterator it_ft = ft_test.begin();
        _fvec<int>::const_iterator ite_ft = --(--ft_test.end());
        // ========= COMPARISONS =========================
        std::cout << FGRN("Assign fill :") << std::endl;
        ft_test.assign(250, 100);
        std::cout << "-----------ft----------- " << std::endl;
        printSize(ft_test, 0);
        std_test.assign(250, 100);
        std::cout << "-----------std-----------" << std::endl;
        printSize(std_test, 0);
        std::cout << std::endl << std::endl;

        std::cout << FGRN("Assign range :") << std::endl;
        ft_test.assign(it_ft, ite_ft);
        std::cout << "-----------ft----------- " << std::endl;
        printSize(ft_test, 0);
        std_test.assign(it_std, ite_std);
        std::cout << "-----------std-----------" << std::endl;
        printSize(std_test, 0);
        std::cout << std::endl << std::endl;

    }

    {
        std::cout << FMAG("============== at() ==============") << std::endl;
        // ========= STD DECLARATIONS =====================
        _svec<int> std_test(200, 200);
        _svec<int>::iterator it_std = std_test.begin();
        for (int i = 0; i < 100; i++)
            it_std++;
        std_test.insert(it_std, 42);
        // ========= FT DECLARATIONS =====================
        _fvec<int> ft_test(200, 200);
        _fvec<int>::iterator it_ft = ft_test.begin();
        for (int i = 0; i < 100; i++)
            it_ft++;
        ft_test.insert(it_ft, 42);
        // ========= COMPARISONS =========================
        std::cout << FGRN("assign check :") << std::endl;
        std::cout << "-----------ft----------- " << std::endl;
        std::cout << "99: " << ft_test.at(99) << " | 100: " << ft_test.at(100)
        << " | 101: " << ft_test.at(101) << std::endl;
        std::cout << "-----------std----------- " << std::endl;
        std::cout << "99: " << std_test.at(99) << " | 100: " << std_test.at(100)
                  << " | 101: " << std_test.at(101) << std::endl;
        std::cout << "-----------content-----------" << std::endl;
        controlContent(ft_test, std_test);
        std::cout << std::endl << std::endl;

    }

}