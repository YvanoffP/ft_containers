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
            //this->clear();

            //TODO : use insert() as vector
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
    };


}
#endif // MAP_HPP
