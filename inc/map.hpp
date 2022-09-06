#ifndef MAP_HPP
#define MAP_HPP

namespace ft {
    template<typename Key, typename T, typename Compare = std::less<Key>,
        typename Alloc = std::allocator<std::pair<const Key, T> >>
    class map {
    public:
        typedef Key                                                         key_type;
        typedef T                                                           mapped_type;
        typedef ft::pair<key_type, mapped_type>                             value_type;
        typedef Compare                                                     key_compare;
        typedef Alloc                                                       allocator_type;

        typedef typename allocator_type::reference                          reference;
        typedef typename allocator_type::const_reference                    const_reference;
        typedef typename allocator_type::pointer                            pointer;
        typedef typename allocator_type::const_pointer                      const_pointer;

        typedef typename ft::Binary_search_tree<value_type,
            key_type>::const_iterator                                       const_iterator;
        typedef typename ft::Binary_search_tree<value_type,
                key_type>::iterator                                         iterator;
        typedef typename ft::reverse_iterator<iterator>                     reverse_iterator;
        typedef typename ft::reverse_iterator<const_iterator>               const_reverse_iterator;
        typedef typename ft::iterator_traits<iterator>::difference_type     difference_type;
        typedef size_t                                                      size_type;
    private:

        allocator_type                              _alloc;
        key_compare                                 _comp;
        Binary_search_tree<value_type, key_type>    _bst;
        size_type                                   _size;

    public:
        // ------------------------------------ CONSTRUCTOR DESTRUCTOR -------------------------------------
        // Empty constructor
        explicit map (const key_compare& comp = key_compare(),
                      const allocator_type& alloc = allocator_type()) :
                _alloc(alloc), _comp(comp), _bst(), _size(0) {}


        /*
         * Destructors
         */
        ~map()
        { this->clear(); }


        map &operator=(const map &x)
        {
            if (this == &x)
                return (*this);
            this->clear();

            //TODO : use insert() as vector (cimer pour l'OP bro <3 et l'inspi)
            this->_alloc = x._alloc;
            this->_comp = x._comp;
            this->_bst = x._bst;
            this->_size = x._size;
            return (*this);
        }
        // ------------------------------------ ITERATOR METHODS -------------------------------------

        iterator begin() { return (_bst.begin()); }
        const_iterator begin() const {return ( _bst.begin()); }
        iterator end() { return (_bst.end()); }
        const_iterator end() const { return (_bst.end()); }
        // Reverse Iterator methods
        reverse_iterator rbegin() { return (reverse_iterator(this->end())); }
        const_reverse_iterator rbegin() const { return (const_reverse_iterator(this->end())); }
        reverse_iterator rend() { return (reverse_iterator(this->begin())); }
        const_reverse_iterator rend() const { return (const_reverse_iterator(this->begin())); }

        // ------------------------------------ CAPACITY METHODS -------------------------------------

        bool empty() const { return (_bst.isEmpty()); }
        size_type size() const { return (this->_size); }
        size_type max_size() const { return (_alloc.max_size()); }

        // ------------------------------------ MODIFIERS -------------------------------------

        //TODO: insert
        void swap(map &x)
        {
            if (this != &x)
            {
                allocator_type  tmp_alloc = x._alloc;
                key_compare     tmp_comp = x._comp;
                size_type       tmp_size = x._size;
                this->_comp = x._comp;
                this->_size = x._size;
                this->_alloc = x._alloc;
                x._comp = tmp_comp;
                x._alloc = tmp_alloc;
                x._size = tmp_size;
                _bst.swap(x);
            }
        }

        void clear()
        {
            this->_bst.makeEmpty();
            this->_size = 0;
        }

        void erase(iterator position) { _bst.remove(*position); }

        // Methods from CPP11 and later : insert_or_assign, emplace, emplace_hint, try_emplace, extract, merge

        // ------------------------------------ LOOKUP -------------------------------------

        //TODO: equal_range
        iterator lower_bound(const key_type& x) { return _bst.lower_bound(x); }
        const_iterator lower_bound(const key_type& x) const { return _bst.lower_bound(x); }
        iterator upper_bound(const key_type& x) { return _bst.upper_bound(x); }
        const_iterator upper_bound(const key_type& x) const { return _bst.upper_bound(x); }
        iterator find(const key_type &x) { return (_bst.find(x)); }
        // Count returns the number of elements containing the parameter (key x)
        size_type count(const key_type &x) const { return (_bst.containsKey(x)); }

        // Methods from CPP 11 and later : contains




        // ------------------------------------ OBSERVERS -------------------------------------

        //TODO: key_comp, value_comp



    };
    // ------------------------------------ NON MEMBER -------------------------------------

    //TODO: operator==, operator!=, operator<, operator<=, operator>, operator>=, swap

}
#endif // MAP_HPP
