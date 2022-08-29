#ifndef VECTOR_HPP
# define VECTOR_HPP

// -------------------------------------------- Includes ----------------------------------------------------
# include "./random_access_iterator.hpp"
# include "./reverse_iterator.hpp"
# include <iostream>
# include "./utils.hpp"
// ----------------------------------------------------------------------------------------------------------

// -------------------------------------------- Class -------------------------------------------------------

namespace ft {
    template< typename T, typename Alloc = std::allocator<T> >
    class vector
    {
        public:
            typedef Alloc                                           allocator_type;
            typedef T                                               value_type;
            typedef typename allocator_type::reference              reference;
            typedef typename allocator_type::const_reference        const_reference;
            typedef typename allocator_type::pointer                pointer;
            typedef typename allocator_type::const_pointer          const_pointer;
            typedef ft::random_access_iterator<value_type>          iterator;
            typedef ft::random_access_iterator<const value_type>    const_iterator;
            typedef ft::reverse_iterator<iterator>                  reverse_iterator;
            typedef ft::reverse_iterator<const iterator>            const_reverse_iterator;
            typedef size_t                                          size_type;
            typedef ft::iterator_traits<iterator>                   difference_type;

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
            size_t _size;
            size_t _capacity;
            pointer _vector;
            allocator_type _alloc;


        public:
             /*
              * Constructor / Destructor -------------------------------------------------------------------------------
              */

             explicit vector (const allocator_type &alloc = allocator_type()) :
             _size(0), _capacity(0), _vector(nullptr), _alloc(alloc) {  }

             explicit vector (size_type n, const value_type& val = value_type(),
                              const allocator_type &alloc = allocator_type() ) :
             _size(0), _capacity(n), _vector(nullptr), _alloc(alloc)
             {
                 _vector = _alloc.allocate(n);
                 for (size_t j = 0; j < n; j++) {
                     _alloc.construct((_vector + j), val);
                     _size++;
                 }
             }

             //TODO: Copy constructor with insert

            template <class InputIterator>
            vector (InputIterator first, InputIterator last,
                    const allocator_type& alloc = allocator_type(),
                    typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = nullptr)
                    : _alloc(alloc), _size(0)
            {
                difference_type n = ft::distance(first, last);
                _alloc.allocate(n);
                for (size_t j = 0; n > 0; n--)
                {
                    _alloc.construct((_vector + j++), *first++);
                    _size++;
                }
            }

            ~vector ()
            {
                this->clear();
                _alloc.deallocate(_vector, _capacity);
            }

            /*
            * Iterator Returns ----------------------------------------------------------------------------------------
            */
            iterator begin (void) { return _vector; }

            const_iterator begin (void) const { return _vector; }

            iterator end (void) { return (_vector + _size); }

            const_iterator end (void) const { return (_vector + _size); }
            /*
             * Reverse Iterator Returns --------------------------------------------------------------------------------
             */
            reverse_iterator rbegin (void) { return (reverse_iterator(this->end())); }

            const_reverse_iterator rbegin (void) const { return (reverse_iterator(this->end())); }

            reverse_iterator rend (void) { return (reverse_iterator(this->begin())); }

            const_reverse_iterator rend (void) const { return (reverse_iterator(this->begin())); }

            /*
             * Operator ------------------------------------------------------------------------------------------------
             */
            vector &operator=(const vector &rhs)
            {
                if (rhs == *this)
                    return (*this);
                this->clear();
                //this->insert(this->end(), rhs.begin(), rhs.end());
                return (*this);
            }

            /*
            * Capacity ------------------------------------------------------------------------------------------------
            */
            /*
             * Returns the number of elements in the vector
             */
            size_type   size(void) const { return _size; }

            /*
             * Returns the maximum number of elements the vector can hold.
             * std::allocator : https://en.cppreference.com/w/cpp/memory/allocator/max_size
             */
            size_type   max_size(void) const { return allocator_type().max_size(); }

            /*
             * Returns the size of the storage space currently allocated to the vector.
             * The value is expressed as number of elements.
             */
            size_type   capacity (void) const { return _capacity; }

            /*
             * resizes the container so it contains n elements.
             * if the value targeted is greater than _max_capacity, it just respects the allocation calcul.
             * if the resize is smaller than the size, it destroys until it reaches the size wanted
             */
            //TODO : void        resize ( ) { }

            /*
             * Returns whether the container is empty or not
             */
            bool        empty (void) const { return (size() == 0 ? true : false); }

            /*
            * Element access ------------------------------------------------------------------------------------------
            */
            /*
             * Returns a reference to the element at position n in the vector
             */
            reference operator[] (size_type n) { return (*(_vector + n)); }

            /*
             * Returns a reference to the element at position n in the vector
             */
            const_reference operator[] (size_type n) const { return (*(_vector + n)); }

            /*
             * Reduces the capacity of the container to fit it's size and destroys all elements beyond it's capacity
             */
            // TODO : void    shrink_to_fit () { }
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
            void checkRange(const size_type& n) const
            {
                if (n >= this->size())
                    throw (std::out_of_range("vector::checkRange: n (which is "
                                             + ft::to_string(n) + ") >= this->size() (which is "
                                             + ft::to_string(this->size()) + ")"));
            }
            reference at (size_type n)
            {
                checkRange(n);
                return ((*this)[n]);
            }
            const_reference at (size_type n) const
            {
                checkRange(n);
                return ((*this)[n]);
            }

            /*
             * Returns a reference to the first element in the vector
             * Unlike begin, which returns an iterator to the first element
             * non-const and const version :
             */
            reference front () { return (*_vector); }
            const_reference front () const { return (*_vector); }

            /*
             * Returns a reference to the last element in the vector
             * Unlike end, which returns an iterator to the last element
             * non-const and const version :
             */
            reference back () { return (*(_vector + _size)); }
            const_reference back () const { return (*(_vector + _size)); }
            /*
             * MODIFIERS ---------------------------------------------------------------
             */
            /*
             * Reserve n space for future usage
             * n is allocated in a new pointer and the content
             * of old pointer is copied and clear/destroyed
             */
            void reserve (size_type n)
            {
                if (n > this->max_size())
                    throw::std::length_error("The requested size is too high");
                if (n > this->_capacity)
                {
                    pointer tmp = _alloc.allocate(n);
                    if (_vector != nullptr)
                    {
                        for (size_t j = 0; j < this->size(); j++)
                            _alloc.construct(tmp + j, *(_vector + j));
                        for (size_t j = 0; j < this->size(); j++)
                            _alloc.destroy(_vector + j);
                        _alloc.deallocate(_vector, _capacity);
                    }
                    _capacity = n;
                    _vector = tmp;
                }
            }

            /*
             * Add val after the last position in the vector size
             * if size > capacity, a resize is done
             */
            void push_back ( const value_type &val )
            {
                _size++;
                if (_size > _capacity)
                {
                    if (_capacity == 0) {
                        _capacity = 1;
                        _vector = _alloc.allocate(1);
                        this->reserve(1); // TODO : TERNAIRE MOI CA MON GRAND
                    }
                    else
                        this->reserve(_capacity * 2);
                }
                _alloc.construct(_vector + _size - 1, val);
            }

            template <class InputIterator>
            /*
             * Assign by range
             * It is important to call clear() here
             * it has no impact on standard types but .destroy() calls destructor for specified object
             */
            void assign (typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type first,
                         InputIterator last)
            {
                size_type n = distance(first, last);
                this->clear();
                if (n > _capacity)
                {
                    _alloc.deallocate(_vector, _capacity);
                    _vector = _alloc.allocate(n);
                    _capacity = n;
                }
                for (size_t j = 0; j < n; j++) {
                    _alloc.construct(_vector + j, first++);
                }
                _size = n;

            }
            /*
             * Assign by fill
             * It is important to call clear() here
             * it has no impact on standard types but .destroy() calls destructor for specified object
             */
            void assign (size_type n, const value_type &val)
            {
                this->clear();
                if (n > _capacity)
                {
                    _alloc.deallocate(_vector, _capacity);
                    _vector = _alloc.allocate(n);
                    _capacity = n;
                }
                for (size_t j = 0; j < n; j++) {
                    _alloc.construct(_vector + j, val);
                }
                _size = n;
            }

            /*
             * Clear destroy all elements
             * destroy calls the destructor of the element
             * Then set the size to 0
             */
            void clear ( void )
            {
                for (size_t j = 0; j != _size; j++)
                    _alloc.destroy(_vector + j);
                _size = 0;
            }

            /*
             * Removes the last element of the container
             */
            void pop_back(void)
            {
                _alloc.destroy(*this->back());
                _size--;
            }

            // TODO: insert / swap / erase
            iterator erase(iterator position)
            {
                _size--;
                _alloc.destroy(&(*position));
                for (iterator it = position; it != this->end(); it++) {
                    *it = *(it + 1);
                }
                return (position);
            }

            iterator erase(iterator first, iterator last)
            {
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



    };
}
#endif // VECTOR_HPP