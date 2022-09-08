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

        // ------------------------------------ VALUE COMPARE (CPP98) -------------------------------------
        class value_compare : public std::binary_function<value_type, value_type, bool>
        {
            friend class map<key_type, mapped_type, key_compare, allocator_type>;

            protected:
                Compare comp;
                value_compare (Compare c) : comp(c) {}  // constructed with map's comparison object

            public:
                bool operator() (const value_type &x, const value_type &y) const {
                    return comp(x.first, y.first);
                }
        };

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
        ft::pair<iterator, bool> insert(const value_type &x)
        {
            bool is_added = false;

            iterator ret = _bst.insert(x, is_added);
            if (is_added == true)
            {
                this->_size +=1;
                //this->reorganize();
            }
            return (ft::make_pair(ret, is_added));
        }

        iterator insert(iterator position, const value_type &x)
        {
            bool is_added = false;

            (void)position;
            iterator ret = _bst.insert(x, is_added);
            if (is_added == true) {
                this->_size += 1;
                //this->reorganize();
            }
            return (ret);
        }

        /*void reorganize ()
        {
            this->_bst.reorganize_tree(_bst.getRoot(), _bst.getRoot());
        }*/

        template<class InputIterator>
        void insert(InputIterator first, InputIterator last)
        {
            bool is_added = false;

            while (first != last)
            {
                _bst.insert(*first++, is_added);
                if (is_added == true)
                {
                    this->_size += 1;
                    //this->reorganize();
                    is_added = false;
                }
            }
        }

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
        iterator lower_bound(const key_type& x)
        {
            iterator it = begin();

            while (it != end())
            {
                if (_comp((*it).first, x) == false)
                    return (it);
                it++;
            }
            return (it);
        }
        const_iterator lower_bound(const key_type& x) const { return (const_iterator(lower_bound(x))); }
        iterator upper_bound(const key_type& x)
        {
            iterator it = begin();

            while (it != end())
            {
                if (_comp(x, (*it).first))
                    return (it);
                it++;
            }
            return (it);
        }
        const_iterator upper_bound(const key_type& x) const { return (const_iterator(upper_bound(x))); }
        iterator find(const key_type &x) { return (_bst.find(x)); }
        // Count returns the number of elements containing the parameter (key x)
        size_type count(const key_type &x) const { return (_bst.containsKey(x)); }

        // Methods from CPP 11 and later : contains

        // ------------------------------------ Printer -------------------------------------

        void print( void )
        {
            this->_bst.printBT();
        }


        // ------------------------------------ OBSERVERS -------------------------------------

        key_compare key_comp() const { return (key_compare()); }
        value_compare value_comp() const { return (value_compare(key_compare())); }



    };
    // ------------------------------------ NON MEMBER -------------------------------------

    //TODO: operator==, operator!=, operator<, operator<=, operator>, operator>=, swap

}
#endif // MAP_HPP
