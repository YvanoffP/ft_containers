#ifndef VECTOR_HPP
# define VECTOR_HPP

// -------------------------------------------- Includes ----------------------------------------------------
# include "./random_access_iterator.hpp"
# include "./reverse_iterator.hpp"
# include "./utils.hpp"
# include "./enable_if.hpp"
# include "./is_integral.hpp"
# include <iostream>
// ----------------------------------------------------------------------------------------------------------

// -------------------------------------------- Class -------------------------------------------------------

namespace ft {
    template< typename T, typename Alloc = std::allocator<T> >
    class vector {
    public:
        typedef Alloc allocator_type;
        typedef T value_type;
        typedef typename allocator_type::reference              reference;
        typedef typename allocator_type::const_reference        const_reference;
        typedef typename allocator_type::pointer                pointer;
        typedef typename allocator_type::const_pointer          const_pointer;
        typedef ft::random_access_iterator<value_type>          iterator;
        typedef ft::random_access_iterator<const value_type>    const_iterator;
        typedef ft::reverse_iterator<iterator>                  reverse_iterator;
        typedef ft::reverse_iterator<const iterator>            const_reverse_iterator;
        typedef ft::iterator_traits<iterator>                   difference_type;
        typedef size_t                                          size_type;

        /*
         * value_type       : type of the element(s) the vector will hold
         * allocator_type   : allocator type the vector will use
         * reference        : the reference to an element stored in the vector
         * const reference  : the const reference to an element stored in the vector
         * pointer          : gives a pointer to an element stored
         * const_pointer    : gives a const pointer to an element stored
         * difference_type  : can be described as te number of element between two pointers.
         * size_type        : an unsigned integral type that can represent any non-neg. value
         */

    private:
        size_type _size;
        size_type _capacity;
        pointer _vec;
        allocator_type _alloc;


    public:
        /*
         * Constructor / Destructor -------------------------------------------------------------------------------
         */

        //TODO: copy contructor ptetre ? naaaaan

        explicit vector(const allocator_type &alloc = allocator_type()) :
                _size(0), _capacity(0), _vec(nullptr), _alloc(alloc) {}

        explicit vector(size_type n, const value_type &val = value_type(),
                        const allocator_type &alloc = allocator_type()) :
                _size(0), _capacity(n), _vec(nullptr), _alloc(alloc) {
            _vec = _alloc.allocate(n);
            for (size_type j = 0; j < n; j++) {
                _alloc.construct((_vec + j), val);
                _size++;
            }
        }

        template<class InputIterator>
        vector(typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type first, InputIterator last,
               const allocator_type &alloc = allocator_type())
                : _alloc(alloc), _size(0), _capacity(0) {
            size_type n = ft::distance(first, last);
            _vec = _alloc.allocate(n);
            _size = n;
            _capacity = n;
            for (size_type j = 0; n > 0; n--) {
                _alloc.construct((_vec + j++), *first++);
            }
        }

        ~vector() {
            this->clear();
            _alloc.deallocate(_vec, _capacity);
        }

        /*
        * Iterator Returns ----------------------------------------------------------------------------------------
        */
        iterator begin(void) { return iterator(_vec); }

        const_iterator begin(void) const { return const_iterator(_vec); }

        iterator end(void) { return iterator(_vec + _size); }

        const_iterator end(void) const { return const_iterator(_vec + _size); }

        /*
         * Reverse Iterator Returns --------------------------------------------------------------------------------
         */
        reverse_iterator rbegin(void) { return reverse_iterator(iterator(this->end())); }

        const_reverse_iterator rbegin(void) const { return const_reverse_iterator(const_iterator(this->end())); }

        reverse_iterator rend(void) { return (reverse_iterator(this->begin())); }

        const_reverse_iterator rend(void) const { return (reverse_iterator(this->begin())); }

        /*
         * Operator ------------------------------------------------------------------------------------------------
         */
        vector &operator=(const vector &rhs) {
            if (rhs == *this)
                return (*this);
            this->clear();
            this->insert(this->end(), rhs.begin(), rhs.end());
            return (*this);
        }

        /*
        * Capacity ------------------------------------------------------------------------------------------------
        */
        /*
         * Returns the number of elements in the vector
         */
        size_type size(void) const { return _size; }

        /*
         * Returns the maximum number of elements the vector can hold.
         * std::allocator : https://en.cppreference.com/w/cpp/memory/allocator/max_size
         */
        size_type max_size(void) const { return allocator_type().max_size(); }

        /*
         * Returns the size of the storage space currently allocated to the vector.
         * The value is expressed as number of elements.
         */
        size_type capacity(void) const { return _capacity; }

        /*
         * resizes the container so it contains n elements.
         * if the value targeted is greater than _max_capacity, it just respects the allocation calcul.
         * if the resize is smaller than the size, it destroys until it reaches the size wanted
         */
        void resize (size_type n, value_type val = value_type())
        {
            if (n > this->max_size())
                throw (std::length_error("The requested size is too high"));
            else if (n <= this->_size)
            {
                for (size_type i = n; i < this->_size; i++) {
                    _alloc.destroy(_vec + i);
                }
            }
            else if (n > this->_size)
            {
                pointer tmp = _alloc.allocate(n);

                for (size_type i = 0; i < this->_size; i++) {
                    _alloc.construct(tmp + i, *(_vec + i));
                }

                for (size_type i = this->_size; i < n; i++) {
                    _alloc.construct(tmp + i, val);
                }

                this->clear();
                _alloc.deallocate(this->_vec, this->_capacity);
                this->_vec = tmp;

                /* Adapt capacity if n > capacity
                 * Otherwise we keep capacity */
                if (n > this->_capacity * 2)
                    this->_capacity = n;
                else if (n > this->_capacity)
                    this->_capacity *= 2;
            }
            this->_size = n;
        }

        /*
         * Returns whether the container is empty or not
         */
        bool empty(void) const { return (size() == 0 ? true : false); }

        /*
        * Element access ------------------------------------------------------------------------------------------
        */
        value_type *data(void) { return (this->_vec); }

        const value_type *data(void) const { return (this->_vec); }

        /*
         * Returns a reference to the element at position n in the vector
         */
        reference operator[](size_type n) { return (*(_vec + n)); }

        /*
         * Returns a reference to the element at position n in the vector
         */
        const_reference operator[](size_type n) const { return (*(_vec + n)); }

        /*
         * Reduces the capacity of the container to fit it's size and destroys all elements beyond it's capacity
         */
        void shrink_to_fit(void) {
            if (this->_size < this->_capacity) {
                pointer tmp = _alloc.allocate(this->_size);
                for (size_type j = 0; j < this->size(); j++)
                    _alloc.construct(tmp + j, *(_vec + j));
                for (size_type j = 0; j < this->size(); j++)
                    _alloc.destroy(_vec + j);
                _alloc.deallocate(_vec, _capacity);
                this->_capacity = this->_size;
                this->_vec = tmp;
            }
        }

        /*
         * It is used to get a reference to the element present at the position given as the parameter to
         * the function
         * non-const and const version below
         *
         * checkRange checks if "n" is in the range of the container.
         * if not it throws a std::out_of_range exception
         * Source code : https://gcc.gnu.org/onlinedocs/gcc-4.6.3/libstdc++/api/a01069_source.html#l00716
         * line 716
         */
        void checkRange(const size_type &n) const {
            if (n >= this->size())
                throw (std::out_of_range("vector::checkRange: n (which is "
                                         + ft::to_string(n) + ") >= this->size() (which is "
                                         + ft::to_string(this->size()) + ")"));
        }

        reference at(size_type n) {
            checkRange(n);
            return ((*this)[n]);
        }

        const_reference at(size_type n) const {
            checkRange(n);
            return ((*this)[n]);
        }

        /*
         * Returns a reference to the first element in the vector
         * Unlike begin, which returns an iterator to the first element
         * non-const and const version :
         */
        reference front() { return (*_vec); }

        const_reference front() const { return (*_vec); }

        /*
         * Returns a reference to the last element in the vector
         * Unlike end, which returns an iterator to the last element
         * non-const and const version :
         */
        reference back() { return (_vec[_size - 1]); }

        const_reference back() const { return (_vec[_size - 1]); }
        /*
         * MODIFIERS ---------------------------------------------------------------
         */
        /*
         * Reserve n space for future usage
         * n is allocated in a new pointer and the content
         * of old pointer is copied and clear/destroyed
         */
        void reserve(size_type n) {
            if (n > this->max_size())
                throw ::std::length_error("The requested size is too high");
            if (n > this->_capacity) {
                pointer tmp = _alloc.allocate(n);
                if (_vec != nullptr) {
                    for (size_type j = 0; j < this->size(); j++)
                        _alloc.construct(tmp + j, *(_vec + j));
                    for (size_type j = 0; j < this->size(); j++)
                        _alloc.destroy(_vec + j);
                    _alloc.deallocate(_vec, _capacity);
                }
                _capacity = n;
                _vec = tmp;
            }
        }

        /*
         * Add val after the last position in the vector size
         * if size > capacity, a resize is done
         */
         void push_back (const value_type& val)
         {
             // TODO : Ternaire ici non ??
             if (this->_capacity == 0)
             {
                 this->_capacity = 1;
                 this->reserve(this->capacity());
             }
             else if (this->_size + 1 > this->capacity())
                 this->reserve(this->capacity() * 2);
             _alloc.construct((this->_vec + this->size()), val);
             this->_size += 1;
         }

        template<class InputIterator>
        /*
         * Assign by range
         * It is important to call clear() here
         * it has no impact on standard types but .destroy() calls destructor for specified object
         */
        void assign(typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type first,
                    InputIterator last) {
            size_type n = ft::distance(first, last);
            this->clear();
            if (n > _capacity) {
                _alloc.deallocate(_vec, _capacity);
                _vec = _alloc.allocate(n);
                _capacity = n;
            }
            for (size_type j = 0; j < n; j++) {
                _alloc.construct(_vec + j, first++);
            }
            _size = n;

        }

        /*
         * Assign by fill
         * It is important to call clear() here
         * it has no impact on standard types but .destroy() calls destructor for specified object
         */
        void assign(size_type n, const value_type &val) {
            this->clear();
            if (n > _capacity) {
                _alloc.deallocate(_vec, _capacity);
                _vec = _alloc.allocate(n);
                _capacity = n;
            }
            for (size_type j = 0; j < n; j++) {
                _alloc.construct(_vec + j, val);
            }
            _size = n;
        }

        /*
         * Clear destroy all elements
         * destroy calls the destructor of the element
         * Then set the size to 0
         */
        void clear(void) {
            for (size_type j = 0; j != _size; j++)
                _alloc.destroy(_vec + j);
            _size = 0;
        }

        /*
         * Removes the last element of the container
         */
        void pop_back(void) {
            _alloc.destroy(&this->back());
            _size--;
        }

        /*
         * Erase remove an element from the vector.
         * It resized the container after removing the element.
         * Calling destroy is important to make sure we call the destructor of the element
         *
         * The second version deletes elements within a range of iterators
         */
        iterator erase(iterator position) {
            _size--;
            _alloc.destroy(&(*position));
            for (iterator it = position; it != this->end(); it++) {
                *it = *(it + 1);
            }
            return (position);
        }

        iterator erase(iterator first, iterator last) {
            size_type erase = 0;

            for (iterator it = first; it != last; it++) {
                _alloc.destroy(&(*it));
                erase++;
            }
            for (iterator it = first; last != this->end(); last++) {
                *it = *(last);
                it++;
            }
            this->_size -= erase;
            return (first);
        }

        iterator insert(iterator position, const value_type &val)
        {
            if (this->size() + 1 > this->capacity()) {
                size_type i = 0;
                iterator it_tmp = this->begin();
                size_type ret = position - this->begin();
                pointer tmp = _alloc.allocate(this->capacity() * 2);
                _size += 1;
                for (size_type j = 0; j < this->size(); j++) {
                    if (it_tmp == position)
                        _alloc.construct(tmp + i++, val);
                    _alloc.construct(tmp + i++, *(_vec + j));
                    it_tmp++;
                }
                for (size_type j = 0; j < this->size(); j++)
                    _alloc.destroy(_vec + j);
                _alloc.deallocate(_vec, _capacity);
                _capacity *= 2;
                _vec = tmp;
                return iterator(_vec + ret);
            } else {
                _size += 1;
                for (iterator it = this->end(); it != position; it--) {
                    *it = *(it - 1);
                }
                *position = val;
            }
            return (position);
        }

        void insert(iterator position, size_type n, const value_type &val)
        {
            if (this->size() + n > this->capacity()) {
                size_type i = 0;
                iterator it_tmp = this->begin();
                if (this->size() + n > this->capacity() * 2)
                    this->_capacity = n + this->size();
                else if (this->size() + n > this->capacity())
                    this->_capacity *= 2;
                pointer tmp = _alloc.allocate(this->capacity());
                _size += n;
                for (size_type j = 0; j < this->size(); j++) {
                    if (it_tmp == position)
                        for (size_type j = 0; j < n; j++)
                            _alloc.construct(tmp + i++, val);
                    _alloc.construct(tmp + i++, *(_vec + j));
                    it_tmp++;
                }
                for (size_type j = 0; j < this->size(); j++)
                    _alloc.destroy(_vec + j);
                _alloc.deallocate(_vec, _capacity);
                _vec = tmp;
            } else {
                iterator old_end = this->end();
                _size += n;
                for (iterator new_end = this->end(); old_end != position - 1; new_end--) {
                    *new_end = *old_end;
                    old_end--;
                }
                for (size_type i = 0; i < n; i++) {
                    *position++ = val;
                }
            }
        }

        template <class InputIterator>
        void insert (iterator position,
                     typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type first,
                     InputIterator last)
        {
            size_type n = ft::distance(first, last);
            size_type distance = ft::distance(this->begin(), position);
            if (_size + n > _capacity)
            {
                if (this->size() + n > this->capacity() * 2)
                    this->_capacity = n + this->size();
                else if (this->size() + n > this->capacity())
                    this->_capacity *= 2;
                pointer tmp = _alloc.allocate(this->capacity());
                for (size_type i = 0; i < distance; i++)
                    _alloc.construct(tmp + i, *(_vec + i));
                for (size_type i = 0; i < n; i++)
                    _alloc.construct(tmp + i + distance, *first++);
                for (size_type i = 0; i < this->size(); i++)
                    _alloc.construct(tmp + distance + n + i, *(_vec + distance + i));
                _size = this->size() + n;
                for (size_type j = 0; j < this->size(); j++)
                    _alloc.destroy(_vec + j);
                _alloc.deallocate(_vec, _capacity);
                _vec = tmp;
            }
            else
            {
                size_type new_end = _size + n;
                for (iterator end_scope = this->end(); end_scope != position; end_scope--)
                {
                    _alloc.construct(_vec + new_end--, *end_scope);
                }
                _alloc.construct(_vec + new_end, *position);
                for (size_type i = 0;i < n; i++)
                {
                    *(position + i) = *first++;
                }
                _size += n;
            }

        }

            /*
             * Swap the elements of the vector passed in the parameter with the
             * vector calling the method
             */
            void swap (vector& x)
            {
                //todo decomment when op == is done
                //if (x == *this)
                    //return;

                size_type tmp_size = x._size;
                size_type tmp_capacity = x._capacity;
                pointer tmp_vec = x._vec;
                allocator_type tmp_alloc = x._alloc;

                x._size = this->_size;
                x._vec = this->_vec;
                x._capacity = this->_capacity;
                x._alloc = this->_alloc;

                this->_size = tmp_size;
                this->_vec = tmp_vec;
                this->_capacity = tmp_capacity;
                this->_alloc = tmp_alloc;
            }

    };

    /*
     * Overload of ==
     */
    template <class T, class Alloc>
    bool operator== (const vector<T,Alloc> &lhs, const vector<T,Alloc> &rhs)
    {
        if (lhs.size() != rhs.size())
            return (false);
        typename vector<T>::iterator begin_right = rhs.begin();
        for (typename vector<T>::iterator it = lhs.begin(); it != lhs.end(); it++) {
            if (*it != *begin_right)
                return (false);
            begin_right++;
        }
        return (true);
    }

    /*
     * Operator !=
     */
    template <class T, class Alloc>
    bool operator!= (const vector<T,Alloc> &lhs, const vector<T,Alloc> &rhs)
    {
        return (!(lhs == rhs));
    }

    /*
     * Operator <
     */
    template <class T, class Alloc>
    bool operator<(const vector<T,Alloc> &lhs, const vector<T,Alloc> &rhs)
    {
        typename vector<T>::iterator beg_right = rhs.begin();

        for (typename vector<T>::iterator it = lhs.begin(); it != lhs.end(); it++) {
            if (*it >= *beg_right)
                return (false);
            beg_right++;
        }
        return (true);
    }

    /*
     * Overload of operator >
     */
    template <class T, class Alloc>
        bool operator>(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs)
        {
            return (rhs < lhs);
        }

    /*
     * Operator <=
     */
    template <class T, class Alloc>
        bool operator<= (const vector<T,Alloc> &lhs, const vector<T,Alloc> &rhs)
        {
            return (!(rhs < lhs));
        }

    /*
     * Overload of operator >=
     * if "lhs" elements are lexicographicalement superior or equal than "rhs".
     * true if "lhs" is lexicographicalement superior or equal, false otherwise.
     */
    template <class T, class Alloc>
        bool operator>=(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs)
        {
            return (!(lhs < rhs));
        }

    /*
     * overload of swap vect.
     */
    template <class T, class Alloc>
        void swap(vector<T,Alloc>& x, vector<T,Alloc>&y)
        {
            x.swap(y);
        }
}
#endif // VECTOR_HPP
