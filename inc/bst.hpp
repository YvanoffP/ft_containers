#ifndef BST_HPP
#define BST_HPP

# include "utils.hpp"

namespace ft {
    template < class T, class Compare = std::less<T>, class Node = ft::BST_Node<T>,
            class Alloc = std::allocator<T>, class Node_Alloc = std::allocator<Node> >
    class Binary_search_tree
    {
        public:
            typedef T                               value_type;
            typedef Node                            node;
            typedef Alloc                           allocator_type;
            typedef Node_Alloc                      node_alloc;


        private:
            node_alloc  _alloc;
            node        *_root;
        /*
         * BINARY SEARCH ITERATOR =========================================================
         */
        template <typename P>
        class BstIterator
                : public ft::iterator<ft::bidirectional_iterator_tag, P> {
            public:

                typedef typename P::value_type             value_type;
                typedef BST_Node<value_type>               node;

                BstIterator();
                BstIterator(const node *n, const Binary_search_tree *t): _node_ptr(n), _tree_ptr(t){}
                BstIterator(const BstIterator &rhs) : _node_ptr(rhs._node_ptr), _tree_ptr(rhs._tree_ptr) {}
                ~BstIterator() {}

                // comparison operators. just P node pointers
                bool operator== (const BstIterator& rhs) const
                {
                    return (this->_node_ptr = rhs._node_ptr);
                }

                bool operator!= (const BstIterator& rhs) const
                {
                    return (this->_node_ptr != rhs._node_ptr);
                }



                // preincrement. move forward to next larger value
                BstIterator& operator++ ()
                {
                    node *p;

                    if (_node_ptr == NULL)
                    {
                        // ++ from end(). get the _root of the tree
                        _node_ptr = _tree_ptr->__root;
                        // error! ++ requested for an empty tree
                        if (_node_ptr == NULL)
                            throw std::exception {};
                        // move to the smallest value in the tree,
                        // which is the first node inorder
                        while (_node_ptr->left != NULL) {
                            _node_ptr = _node_ptr->left;
                        }
                    }
                    else {
                        if (_node_ptr->right != NULL) {
                            // successor is the farthest left node of
                            // right subtree
                            _node_ptr = _node_ptr->right;

                            while (_node_ptr->left != NULL) {
                                _node_ptr = _node_ptr->left;
                            }
                        } else {
                            // have already processed the left subtree, and
                            // there is no right subtree. move up the tree,
                            // looking for a parent for which _node_ptr is a left child,
                            // stopping if the parent becomes NULL. a non-NULL parent
                            // is the successor. if parent is NULL, the original node
                            // was the last node inorder, and its successor
                            // is the end of the list
                            p = _node_ptr->parent;
                            while (p != NULL && _node_ptr == p->right) {
                                _node_ptr = p;
                                p = p->parent;
                            }
                            // if we were previously at the right-most node in
                            // the tree, _node_ptr = NULL, and the iterator specifies
                            // the end of the list
                            _node_ptr = p;
                        }
                    }

                    return *this;
                }

                // postincrement
                BstIterator operator++ (int)
                {
                    BstIterator tmp;
                    ++(*this);
                    return (tmp);
                }

                // predecrement. move backward to largest value < current value
                BstIterator  operator-- ()
                {
                    node *p;
                    if (_node_ptr == NULL)
                    {
                        _node_ptr = _tree_ptr->__root;
                        if (_node_ptr == NULL)
                            throw std::exception{};
                        while (_node_ptr->right != NULL) {
                            _node_ptr = _node_ptr->right;
                        }
                    }
                    else {
                        if (_node_ptr->right != NULL) {
                            _node_ptr = _node_ptr->left;
                            while (_node_ptr->right != NULL) {
                                _node_ptr = _node_ptr->right;
                            }
                        } else {
                            p = _node_ptr->parent;
                            while (p != NULL && _node_ptr == p->left) {
                                _node_ptr = p;
                                p = p->parent;
                            }
                            _node_ptr = p;
                        }
                    }
                    return *this;
                }

                // postdecrement
                BstIterator  operator-- (int)
                {
                    BstIterator tmp;
                    --(*this);
                    return (tmp);
                }

            private:
                friend class Tree;

                // _node_ptr is the current location in the tree. we can move
                // freely about the tree using left, right, and parent.
                // tree is the address of the BinarySearchTree object associated
                // with this iterator. it is used only to access the
                // _root pointer, which is needed for ++ and --
                // when the iterator value is end()
                const node *_node_ptr;
                const Binary_search_tree *_tree_ptr;

                // used to construct an iterator return value from
                // a node pointer
                BstIterator (const node *p,
                             const node *t);
        };
        //====================================================================================

        /*
         * Small reminder of the members of node
         * value_type value;
         * BST_Node* parent;
         * BST_Node* left;
         * BST_Node* right;
         */
        public:
            typedef BstIterator<value_type>         iterator;
            typedef BstIterator<const value_type>   const_iterator;

            Binary_search_tree( ) : _root{ NULL }
            {
            }

            /**
             * Copy constructor
             */
            Binary_search_tree( const Binary_search_tree & rhs ) : _root{ NULL }
            {
                _root = clone( rhs._root );
            }
            /**
            * Destructor for the tree
            */
            ~Binary_search_tree( )
            {
                makeEmpty( _root );
            }
            /**
             * @return bool True if root is NULL so tree is empty
             */
            bool isEmpty( ) const
            {
                return _root == NULL;
            }
            /**
             * Returns the min value in the tree
             * We just go to the furthest left element in the tree
             */
            node * findMin( node *t ) const
            {
                node *tmp;
                if( isEmpty( _root ) )
                    return NULL;
                tmp = t;
                while (tmp->left != NULL)
                    tmp = tmp->left;
                return (tmp);
            }

            /**
             * Returns the max value in the tree
             * We just go to the furthest right element in the tree
             */
            node * findMax( node *t ) const
            {
                node *tmp;
                if( isEmpty( _root ) )
                    return NULL;
                tmp = t;
                while (tmp->right != NULL)
                    tmp = tmp->right;
                return (tmp);
            }

            /**
             * @param x
             * @param node
             * @return True if the key exists, false if not
             */
            bool contains_key( const value_type & x, node *node) const
            {
                if( node == NULL )
                    return false;
                else if( x->value.first < node->value.first )
                    return contains_key( x, node->left );
                else if( node->value.first < node->value.first )
                    return contains_key( x, node->right );
                else
                    return true;    // Match
            }

            iterator insert(const value_type& x, int& isNew) {
                node* temp = insert(_root, NULL, x, isNew);
                setParent(_root);
                return iterator(temp, this);
            }

            /**
             * Re sets the parents of all the nodes present
             * in the tree
             * @param r
             */
            void setParent(node *current) {
                if (current)
                {
                    if (current->left != NULL) {
                        current->left->parent = current;
                        setParent(current->left);
                    }
                    if (current->right != NULL) {
                        current->right->parent = current;
                        setParent(current->right);
                    }
                }
            }

            void remove( const value_type & x, node * & t )
            {
                if( t == NULL )
                    return;   // Item not found; do nothing
                if( Compare(x.first, t->element.first) )
                    remove( x, t->left );
                else if( Compare()(t->element.first, x.first ))
                    remove( x, t->right );
                else if( t->left.first != NULL && t->right.first != NULL ) // Two children
                {
                    node * tmp = findMin( t->right );
                    t->value = tmp->value;
                    remove( t->value, t->right );
                }
                else
                {
                    node *oldNode = t;
                    t = ( t->left != NULL ) ? t->left : t->right;
                    _alloc.destroy(oldNode);
                    _alloc.deallocate(oldNode, 1);
                    setParent(_root);
                }
            }

            void makeEmpty( node * & t )
            {
                if( t != NULL )
                {
                    makeEmpty( t->left );
                    makeEmpty( t->right );
                    _alloc.destroy(t);
                    _alloc.deallocate(t, 1);
                }
                t = NULL;
            }

        private:
            node *insert(node *start, node *parent, const value_type &val)
            {
                if (start == NULL)
                {
                    start = _alloc.allocate(1);
                    _alloc.construct(start, node(val, parent));
                    return (start);
                }
                else if (Compare()(val.first, start->value.first)) // val.first < start->value.first : left
                    return (insert(start->left, start, val));
                else if (Compare()(start->value.first, val.first)) // val.first > start->value.first : left
                    return (insert(start->right, start, val));
                return (start);
            }


    };
}

#endif // BSTHPP