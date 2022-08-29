#ifndef VECTOR_HPP
# define VECTOR_HPP

// -------------------------------------------- Includes ----------------------------------------------------
# include "./random_access_iterator.hpp"
# include "./reverse_iterator.hpp"
# include <iostream>
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
                 }
             }


            ~vector ()
            {

            }
        };
}
// ----------------------------------------------------------------------------------------------------------
#endif // VECTOR_HPP