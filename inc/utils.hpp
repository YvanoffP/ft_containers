#ifndef UTILS_HPP
# define UTILS_HPP

#include <string>
#include <iostream>
#include <sstream>
#include "iterator_traits.hpp"

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

    template <typename T>
    struct BST_Node
    {
    public :

        /* First template argument, the type of stocked value */
        typedef T   value_type;

        value_type  value;
        BST_Node*   parent;
        BST_Node*   left;
        BST_Node*   right;

        BST_Node (const value_type& val, BST_Node* left,
                  BST_Node* right, BST_Node* parent):
                parent(parent),
                left(left),
                right(right) {value = val;}

        /*
         * Assignation op
         */
        BST_Node &operator=(const BST_Node& rhs)
        {
            if (rhs == *this)
                return (*this);

            this->value = rhs.value;
            this->parent = rhs.parent;
            this->left = rhs.left;
            this->right = rhs.right;

            return (*this);
        }

        /*
         * Comparison operator
         */
        bool operator==(const BST_Node& nd)
        {
            if (value == nd.value)
                return (true);
            return (false);
        }

    };
}

#endif // UTILS_HPP
