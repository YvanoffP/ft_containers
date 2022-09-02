#ifndef BST_ITERATOR_HPP
#define BST_ITERATOR_HPP

namespace ft {
    template <typename T, class Compare>
    class BST_iterator : ft::iterator<ft::bidirectional_iterator_tag, T>
    {
        private:
            T*			_node;
            T*			_last_node;
            Compare     _comp;
        public:
            typedef typename T::value_type                                      value_type;
            typedef typename ft::iterator<ft::bidirectional_iterator_tag,
                    value_type>::iterator_category                              iterator_category;
            typedef typename ft::iterator<ft::bidirectional_iterator_tag,
                    value_type>::difference_type                                difference_type;
            typedef typename ft::iterator<ft::bidirectional_iterator_tag,
                    value_type>::pointer                                        pointer;
            typedef typename ft::iterator<ft::bidirectional_iterator_tag,
                    value_type>::reference                                      reference;

            /*
             * Constructors
             */
            BST_iterator(const Compare& comp = Compare()):
                    _node(),
                    _last_node(),
                    _comp(comp)
            {}
            // Constructor on a node
            BST_iterator(T * node_p, T * last_node,
                         const Compare& comp = Compare()):
                    _node(node_p),
                    _last_node(last_node),
                    _comp(comp)
            {}
            // Copy constructor
            // it recieves the binary tree
            BST_iterator(const BST_iterator& bst_it)
                    :
                    _node(bst_it._node),
                    _last_node(bst_it._last_node),
                    _comp()
            {}

            // Destructor
            virtual ~BST_iterator() { }

    };
}

#endif // BST_ITERATOR_HPP