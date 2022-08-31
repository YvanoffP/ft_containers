#ifndef UTILS_HPP
# define UTILS_HPP

#include <string>
#include <iostream>
#include <sstream>

namespace ft {
    template<class InputIterator>
        typename ft::iterator_traits<InputIterator>::difference_type
        distance (InputIterator first, InputIterator last)
        {
            typename ft::iterator_traits<InputIterator>::difference_type ret = 0;
            while (first != last)
            {
                first++;
                ret++;
            }
            return (ret);
        }

    template <typename T>
        std::string to_string(T n)
        {
            std::ostringstream stream;
            stream << n;
            return (stream.str());
        }
}

#endif // UTILS_HPP
