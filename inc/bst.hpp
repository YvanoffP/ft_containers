#ifndef BST_HPP
#define BST_HPP

# include "utils.hpp"

namespace ft {
    template <class T, class P = ft::less<T>, class Node = ft::BST_Node<T>,
            class Type_Alloc = std::allocator<T>, class Node_Alloc = std::allocator<Node> >
    class Binary_search_tree
    {
        /*
         * BINARY SEARCH ITERATOR =========================================================
         */
        template <typename P>
        class BstIterator
                : public ft::iterator<ft::bidirectional_iterator_tag, P> {
            public:

                typedef typename P                                  value_type;
                typedef P&                                          reference;
                typedef P*                                          pointer;
                typedef typename BST_Node<value_type>               Node;
                typedef typename Binary_search_tree<value_type>     Tree;

                BstIterator();

                // comparison operators. just P node pointers
                bool operator== (const BstIterator& rhs) const;

                bool operator!= (const BstIterator& rhs) const;

                // dereference operator. return a reference to
                // the value pointed to by nodePtr
                const reference operator* () const;

                // preincrement. move forward to next larger value
                BstIterator& operator++ ();

                // postincrement
                BstIterator operator++ (int);

                // predecrement. move backward to largest value < current value
                BstIterator  operator-- ();

                // postdecrement
                BstIterator  operator-- (int);

            private:
                friend class Tree;

                // nodePtr is the current location in the tree. we can move
                // freely about the tree using left, right, and parent.
                // tree is the address of the BinarySearchTree object associated
                // with this iterator. it is used only to access the
                // root pointer, which is needed for ++ and --
                // when the iterator value is end()
                const Node *_nodePtr;
                const Tree *_tree_ptr;

                // used to construct an iterator return value from
                // a node pointer
                BstIterator (const Node *p,
                             const Node *t);
        };
        //====================================================================================

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