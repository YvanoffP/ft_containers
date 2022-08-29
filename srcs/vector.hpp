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

            template <class InputIterator>
            vector (InputIterator first, InputIterator last,
                    const allocator_type& alloc = allocator_type(),
                    typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = nullptr)
                    : _alloc(alloc)
            {
                difference_type n = ft::distance(first, last);
                _alloc.allocate(n);
                for (size_t j = 0; n > 0; n--)
                {
                    _alloc.construct((_vector + j++), *first++);
                }
            }

            ~vector ()
            {

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
             * This function checks if vector can allocate n elements in the current vector
             * if not, it sets the _max_capacity to n
             */
            //TODO: void        reserve (size_type n) { }

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
            reference back () { return (*(_vector + _size - 1)); }
            const_reference back () const { return (*(_vector + _size - 1)); }
            /*
            * Small function to empty the vector and destroy it
            */
            // TODO : void clear() { }

    };
}
#endif // VECTOR_HPP