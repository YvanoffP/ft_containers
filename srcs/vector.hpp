#ifndef VECTOR_HPP
# define VECTOR_HPP

// -------------------------------------------- Includes ----------------------------------------------------
# include <memory>
# include <algorithm>
# include <cstddef>
# include <tgmath.h>
# include "./random_access_iterator.hpp"
// ----------------------------------------------------------------------------------------------------------

// -------------------------------------------- Class -------------------------------------------------------

namespace ft {
    template<typename T, typename Alloc = std::allocator<T> >
    class vector
    {
        public:
            typedef T				        value_type;
            typedef	Alloc			        allocator_type;
            typedef value_type&		        reference;
            typedef const value_type&       const_reference;
            typedef value_type*		        pointer;
            typedef const value_type*       const_pointer;
            typedef std::ptrdiff_t		        difference_type;
            typedef size_t			        size_type;

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


             /*
              * Constructor / Destructor -------------------------------------------------------------------------------
              */

             //TODO

             /*
             * Iterator Returns ----------------------------------------------------------------------------------------
             */
            iterator begin (void)
            {
                return (iterator(_start));
            }

            const_iterator cbegin (void) const
            {
                return (const_iterator(_start));
            }

            iterator end (void)
            {
                if (this->empty())
                    return (this->begin());
                return (_end);
            }

            const_iterator cend (void) const
            {
                if (this->empty())
                    return (this->begin());
                return (_end);
            }
            /*
             * Reverse Iterator Returns --------------------------------------------------------------------------------
             */
            reverse_iterator rbegin (void)
            {

            }

            const_reverse_iterator crbegin (void) const
            {

            }

            reverse_iterator rend (void)
            {

            }

            const_reverse_iterator crend (void) const
            {

            }

            /*
             * Capacity ------------------------------------------------------------------------------------------------
             */
            /*
             * Returns the number of elements in the vector
             */
            size_type   size(void) const { return (this->_end - this->_start); }

            /*
             * Returns the maximum number of elements the vector can hold.
             * std::alocator : https://en.cppreference.com/w/cpp/memory/allocator/max_size
             */
            size_type   max_size(void) const { return allocator_type().max_size(); }

            /*
             * Returns the size of the storage space currently allocated to the vector.
             * The value is expressed as number of elements.
             */
            size_type   capacity (void) const { return (this->_max_capacity - this->_start); }

            /*
             * resizes the container so it contains n elements.
             * if the value targeted is greater than _max_capacity, it just respects the allocation calcul.
             * if the resize is smaller than the size, it destroys until it reaches the size wanted
             */
            void        resize (size_type n, value_type val = value_type())
            {
                if (n > this->max_size())
                    throw (std::length_error("vector::resize"));
                else if (n < this->size())
                {
                    while (this->size() > n)
                    {
                        --_end;
                        _alloc.destroy(_end);
                    }
                }
                else
                    this->insert(this->end(), n - this->size(), val);
            }

            /*
             * Returns whether the container is empty or not
             */
            bool        empty (void) const { return (size() == 0 ? true : false); }

            /*
             * This function checks if vector can allocate n elements in the current vector
             * if not, it sets the _max_capacity to n
             */
            void        reserve (size_type n)
            {
                if (n > this->max_size())
                    throw (std::length_error("vector::reserve"));
                //TODO
            }

            /*
             * Element access ------------------------------------------------------------------------------------------
             */
            /*
             * Returns a reference to the element at position n in the vector
             */
            reference operator[] (size_type n) { return (*(_start + n)); }

            /*
             * Returns a reference to the element at position n in the vector
             */
            const_reference operator[] (size_type n) const { return (*(_start + n)); }

            /*
             * Reduces the capacity of the container to fit it's size and destroys all elements beyond it's capacity
             */
            void    shrink_to_fit ()
            {
                while (this->_max_capacity > this->size())
                {
                    _alloc.destroy(--_max_capacity);
                }
            }

            /*
             * It is used to get a reference to the element present at the position given as the parameter to
             * the function
             * non-const and const version below
             */
            reference at (size_type n)
            {

            }

            const_reference at (size_type n) const
            {

            }

            /*
             * Returns a reference to the first element in the vector
             * Unlike begin, which returns an iterator to the first element
             * non-const and const version :
             */
            reference front () { return (*_start); }
            const_reference front () const { return (*_start); }

            /*
             * Returns a reference to the last element in the vector
             * Unlike end, which returns an iterator to the last element
             * non-const and const version :
             */
            reference back () { return (*_end); }
            const_reference back () const { return (*_end); }

            /*
             * Small function to empty the vector and destroy it
             */
            void clear()
            {
                size_type save_size = this->size();
                for (size_type i = 0; i < save_size; i++)
                {
                    _end--;
                    _alloc.destroy(_end);
                }
            }

        private:
            allocator_type  _alloc;
            pointer         _start;
            pointer         _end;
            pointer         _max_capacity;
        };

}
// ----------------------------------------------------------------------------------------------------------
#endif // VECTOR_HPP