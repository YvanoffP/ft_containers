#ifndef BST_HPP
#define BST_HPP

# include "utils.hpp"

namespace ft {
    template <class T, class Compare = ft::less<T>, class Node = ft::BST_Node<T>,
            class Type_Alloc = std::allocator<T>, class Node_Alloc = std::allocator<Node> >
    class Binary_search_tree
    {

        /*
         * Small reminder of the members of node
         * value_type value;
         * BST_Node* parent;
         * BST_Node* left;
         * BST_Node* right;
         */
        private:

        public:
    };
}

#endif // BSTHPP