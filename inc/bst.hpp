#ifndef BST_HPP
#define BST_HPP

# include "utils.hpp"
# include "pair.hpp"
# include "iterator_traits.hpp"

namespace ft {
    template < class T, class Key, class Compare = std::less<Key>, class Node = ft::BST_Node<T>,
            class Alloc = std::allocator<T>, class Node_Alloc = std::allocator<Node> >
    class Binary_search_tree
    {
        public:
            typedef T                               value_type;
            typedef Node                            node;
            typedef Alloc                           allocator_type;
            typedef Node_Alloc                      node_alloc;
            typedef Key                             key_type;
            typedef size_t                          size_type;

        private:
            node_alloc  _alloc;
            node        *_root;

        public:
        /*
         * BINARY SEARCH ITERATOR =========================================================
         */
        template <typename P, class Comp>
        class BstIterator {
            public:

                typedef BST_Node<value_type>                                    node;
                typedef P                                                       value_type;
                typedef typename ft::iterator<ft::bidirectional_iterator_tag,
                        value_type>::difference_type                            difference_type;
                typedef P*                                                      pointer;
                typedef P&                                                      reference;
                typedef typename ft::iterator<ft::bidirectional_iterator_tag,
                        value_type>::iterator_category                          iterator_category;

            private:
                friend class Binary_search_tree;

                // _node_ptr is the current location in the tree. we can move
                // freely about the tree using left, right, and parent.
                // tree is the address of the BinarySearchTree object associated
                // with this iterator. it is used only to access the
                // _root pointer, which is needed for ++ and --
                // when the iterator value is end()
                node                        *_node_ptr;
                const Binary_search_tree    *_tree_ptr;

            public:
                // ------------------------------------ CONSTRUCTOR DESTRUCTOR -------------------------------------
                BstIterator() : _node_ptr(NULL), _tree_ptr(NULL) {};
                BstIterator(node *n, const Binary_search_tree *t): _node_ptr(n), _tree_ptr(t){}
                BstIterator(const BstIterator &rhs) : _node_ptr(rhs._node_ptr), _tree_ptr(rhs._tree_ptr) {}
                virtual ~BstIterator() { }

                // ------------------------------------ OPERATOR OVERLOAD -------------------------------------

                BstIterator &operator=(const BstIterator &rhs)
                {
                    if (this == &rhs)
                        return *this;
                    this->_node_ptr = rhs._node_ptr;
                    this->_tree_ptr = rhs._tree_ptr;
                    return *this;
                }

                operator BstIterator<const P, Comp>() const
                {
                    return (BstIterator<const P, Comp>(this->_node_ptr, this->_tree_ptr));
                }

                // comparison operators. just P node pointers
                bool operator== (const BstIterator& rhs) const
                {
                    return (this->_node_ptr == rhs._node_ptr);
                }

                bool operator!= (const BstIterator& rhs) const
                {
                    return (this->_node_ptr != rhs._node_ptr);
                }

                pointer operator->() const {
                    if (_node_ptr == NULL)
                        throw std::exception();
                    return &(_node_ptr->value);
                }

                reference operator*() const {
                    if (_node_ptr == NULL)
                        throw std::exception();
                    return _node_ptr->value;
                }

                // preincrement. move forward to next larger value
                BstIterator& operator++ ()
                {
                    node *p;

                    if (_node_ptr == NULL)
                    {
                        // ++ from end(). get the _root of the tree
                        _node_ptr = _tree_ptr->_root;
                        // error! ++ requested for an empty tree
                        if (_node_ptr == NULL)
                            throw std::exception();
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
                    BstIterator tmp = *this;
                    ++(*this);
                    return (tmp);
                }

                // predecrement. move backward to largest value < current value
                BstIterator &operator-- ()
                {
                    node *p;
                    if (_node_ptr == NULL)
                    {
                        _node_ptr = _tree_ptr->_root;
                        if (_node_ptr == NULL)
                            throw std::exception();
                        while (_node_ptr->right != NULL) {
                            _node_ptr = _node_ptr->right;
                        }
                    }
                    else {
                        if (_node_ptr->left != NULL) {
                            this->_node_ptr = this->_node_ptr->left;
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
                    BstIterator tmp = *this;
                    --(*this);
                    return (tmp);
                }

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
            typedef BstIterator<value_type, Compare>         iterator;
            typedef BstIterator<const value_type, Compare>   const_iterator;
            // ------------------------------------ CONSTRUCTOR DESTRUCTOR -------------------------------------

            Binary_search_tree( ) : _root( NULL ) { }

            /**
             * Copy constructor
             */
            Binary_search_tree( const Binary_search_tree & rhs ) : _root( NULL )
            { _root = clone( rhs._root ); }

            /**
            * Destructor for the tree
            */
            ~Binary_search_tree( )
            {
                makeEmpty( );
            }
            // ------------------------------------ MEMBERS METHOD -------------------------------------
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
            node *findMin( node *t ) const
            {
                node *tmp = t;
                if( isEmpty( ) || tmp == NULL)
                    return NULL;
                while (tmp->left != NULL)
                    tmp = tmp->left;
                return (tmp);
            }

            /**
             * Returns the max value in the tree
             * We just go to the furthest right element in the tree
             */
            node *findMax( node *t ) const
            {
                node *tmp = t;
                if( isEmpty( ) || tmp == NULL)
                    return NULL;
                while (tmp->right != NULL)
                    tmp = tmp->right;
                return (tmp);
            }

            node *getRoot()
            {
                return (this->_root);
            }

            iterator insert(const value_type &x, bool &is_added) {
                node* temp = insert(_root, NULL, x, is_added);
                if (isEmpty())
                    this->_root = temp;
                return iterator(temp, this);
            }

            void remove(const value_type &x, bool &is_removed)
            {
                remove(x, this->_root, is_removed);
            }

            void remove(const key_type &x, bool &is_removed)
            {
                remove(x, this->_root, is_removed);
            }

            void makeEmpty( )
            {
                makeEmpty( _root );
            }

            // ------------------------------------ BST UTILS -------------------------------------

            void printBT()
            {
                printBT("", _root, false);
            }

            // ------------------------------------ MAP RELATED METHODS -------------------------------------

            void swap(Binary_search_tree &x)
            {
                if (this != &x) {
                    node_alloc tmp_alloc = this->_alloc;
                    node *tmp_root = this->_root;

                    this->_alloc = x._alloc;
                    this->_root = x._root;
                    x._alloc = tmp_alloc;
                    x._root = tmp_root;
                }
            }

            iterator lower_bound(const Key& val_key)
            {
                node* tmp = _root;

                while (tmp != NULL)
                {
                    if (tmp->value.first == val_key)
                        return (iterator(tmp, this));
                    else if (Compare()(val_key, tmp->value.first)) // XXX < XXX
                        return (iterator(tmp, this));
                    else
                        tmp = tmp->right;
                }
                return end();
            }

            const_iterator lower_bound(const Key& val_key) const
            {
                node* tmp = _root;

                while (tmp != NULL)
                {
                    if (tmp->value.first == val_key)
                        return (const_iterator(tmp, this));
                    else if (Compare()(val_key, tmp->value.first)) // XXX < XXX
                        return (const_iterator(tmp, this));
                    else
                        tmp = tmp->right;
                }
                return end();
            }

            iterator upper_bound(const Key& val_key)
            {
                node* tmp = _root;

                while (tmp != NULL)
                {
                    if (Compare()(val_key, tmp->value.first)) // XXX < XXX
                        return iterator(tmp, this);
                    else
                        tmp = tmp->right;
                }
                return end();
            }

            const_iterator upper_bound(const Key& val_key) const
            {
                node* tmp = _root;

                while (tmp != NULL)
                {
                    if (Compare()(val_key, tmp->value.first)) // XXX < XXX
                        return const_iterator(tmp, this);
                    else
                        tmp = tmp->right;
                }
                return end();
            }

            iterator end() { return (iterator(NULL, this)); }
            const_iterator end() const { return (const_iterator(NULL, this)); }
            iterator begin() { return (iterator(findMin(this->_root), this)); }
            const_iterator begin() const { return (const_iterator(findMin(this->_root), this)); }

            bool contains(const value_type &x, node *node) const
            {
                if (node == NULL)
                    return (false);
                else if (Compare()(x.first, node->value->first))
                    return contains(x, node->left);
                else if (Compare()(node->value->first, x.first))
                    return contains(x. node->value->right);
                else
                    return (true);
            }
            /**
             * @param x
             * @param node
             * @return True if the key exists, false if not
             */
            size_type containsKey( const key_type &x) const
            {
                node *tmp = this->_root;

                if( tmp == NULL )
                    return 0;
                while ( tmp != NULL ) {
                    if (Compare()(x, tmp->value.first))
                        tmp = tmp->left;
                    else if (Compare()(tmp->value.first, x))
                        tmp = tmp->right;
                    else
                        return (1); // Match
                }
                return (0);
            }

           /* void reorganize_tree(node *checker, node *root)
            {
                if (checker->left != NULL) {
                    if (checker->left->right != NULL)
                        relocate_node_left(checker->left->right, root);
                    reorganize_tree(checker->left, root);
                }
                if (checker->right != NULL) {
                    if (checker->right->left != NULL)
                        relocate_node_right(checker->right->left, root);
                    reorganize_tree(checker->right, root);
                }
            }

            void relocate_node_right(node *to_relocate, node *root)
            {
                node *tmp = root;
                node *back_up = NULL;

                while (tmp != NULL) {
                    if (Compare()(tmp->value.first, to_relocate->value.first) && Compare()(to_relocate->value.first, tmp->right->value.first)) // <
                    {
                        back_up = tmp->right;
                        tmp->right = to_relocate;
                        to_relocate->parent = tmp;
                        to_relocate->right = back_up;
                        back_up->parent = to_relocate;
                        back_up->left = NULL;
                    }
                    else
                        tmp = tmp->right;
                }
            }

            void relocate_node_left(node *to_relocate, node *root)
            {
                node *tmp = root;
                node *back_up = NULL;

                while (tmp != NULL) {
                    if (Compare()(to_relocate->value.first, tmp->value.first) && Compare()(tmp->left->value.first, to_relocate->value.first)) // <
                    {
                        back_up = tmp->left;
                        tmp->left = to_relocate;
                        to_relocate->parent = tmp;
                        to_relocate->left = back_up;
                        back_up->parent = to_relocate;
                        back_up->right = NULL;
                    }
                    else
                        tmp = tmp->left;
                }
            }*/

            node *clone( node *root )
            {
                if (root == NULL)
                    return NULL;
                else
                {
                    node *tmp = _alloc.allocate(1);
                    _alloc.construct(tmp, node(root->value, clone(root->left), clone(root->right), root->parent));
                    return (tmp);
                }
            }

            iterator find( const value_type & x )
            {
                node *tmp = this->_root;

                if( tmp == NULL )
                    return end();
                while (tmp != NULL && tmp->value.first != x.first)
                    tmp = (Compare()(x.first, tmp->value.first) ? tmp->left : tmp->right);
                return (iterator(tmp, this));
            }

            const_iterator find( const value_type & x ) const
            {
                node *tmp = this->_root;

                if( tmp == NULL )
                    return end();
                while (tmp != NULL && tmp->value.first != x.first)
                    tmp = (Compare()(x.first, tmp->value.first) ? tmp->left : tmp->right);
                return (const_iterator(tmp, this));
            }

            iterator find( const key_type & x )
            {
                node *tmp = this->_root;

                if( tmp == NULL )
                    return end();
                while (tmp != NULL && tmp->value.first != x)
                    tmp = (Compare()(x, tmp->value.first) ? tmp->left : tmp->right);
                return (iterator(tmp, this));
            }

            const_iterator find( const key_type & x ) const
            {
                node *tmp = this->_root;

                if( tmp == NULL )
                    return end();
                while (tmp != NULL && tmp->value.first != x)
                    tmp = (Compare()(x, tmp->value.first) ? tmp->left : tmp->right);
                return (const_iterator(tmp, this));
            }

        private:
            node *insert(node *&start, node *parent, const value_type &val,  bool &is_added)
            {
                if (start == NULL)
                {
                    start = _alloc.allocate(1);
                    _alloc.construct(start, node(val, NULL, NULL, parent));
                    is_added = true;
                    return (start);
                }
                else if (Compare()(val.first, start->value.first)) // val.first < start->value.first : left
                    return (insert(start->left, start, val, is_added));
                else if (Compare()(start->value.first, val.first)) // val.first > start->value.first : right
                    return (insert(start->right, start, val, is_added));
                else
                    return (start);
            }

            void swap_val_node(node *&lhs, node *&rhs)
            {
                node tmp;

                tmp.value.first = lhs->value.first;
                tmp.value.second = lhs->value.second;

                lhs->value.first = rhs->value.first;
                lhs->value.second = rhs->value.second;

                rhs->value.first = tmp.value.first;
                rhs->value.second = tmp.value.second;

            }

            void printBT(const std::string& prefix, const Node* node, bool isLeft)
            {
                if( node != NULL )
                {
                    std::cout << prefix;

                    std::cout << (isLeft ? "├──" : "└──" );

                    // print the value of the node
                    std::cout << node->value.first << std::endl;

                    // enter the next tree level - left and right branch
                    printBT( prefix + (isLeft ? "│   " : "    "), node->left, true);
                    printBT( prefix + (isLeft ? "│   " : "    "), node->right, false);
                }
            }

            void remove( const value_type & x, Node * & t, bool &is_removed)
            {
                if( t == NULL ) {
                    is_removed = false;
                    return;   // Item not found; do nothing
                }
                if( Compare()(x.first, t->value.first) )
                    remove( x, t->left, is_removed );
                else if( Compare()(t->value.first, x.first ))
                    remove( x, t->right, is_removed );
                else if( t->left != NULL && t->right != NULL ) // Two children
                {
                    Node * tmp = findMin( t->right );
                    t->value = tmp->value;
                    remove( t->value, t->right, is_removed );
                }
                else
                {
                    node *oldNode = t;
                    t = ( t->left != NULL ) ? t->left : t->right;
                    if (t)
                        t->parent = oldNode->parent;
                    _alloc.destroy(oldNode);
                    _alloc.deallocate(oldNode, 1);
                    is_removed = true;
                }
            }

            void remove( const key_type & x, Node * & t, bool &is_removed)
            {
                if( t == NULL ) {
                    is_removed = false;
                    return;   // Item not found; do nothing
                }
                if( Compare()(x, t->value.first) )
                    remove( x, t->left, is_removed );
                else if( Compare()(t->value.first, x ))
                    remove( x, t->right, is_removed );
                else if( t->left != NULL && t->right != NULL ) // Two children
                {
                    Node * tmp = findMin( t->right );
                    t->value = tmp->value;
                    remove( t->value, t->right, is_removed );
                }
                else
                {
                    node *oldNode = t;
                    t = ( t->left != NULL ) ? t->left : t->right;
                    if (t)
                        t->parent = oldNode->parent;
                    _alloc.destroy(oldNode);
                    _alloc.deallocate(oldNode, 1);
                    is_removed = true;
                }
            }

            void makeEmpty( node *&t )
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

    };
}

#endif // BSTHPP
