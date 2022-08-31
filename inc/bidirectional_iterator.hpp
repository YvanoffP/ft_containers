#ifndef BIDIRECTIONAL_ITERATOR_HPP
# define BIDIRECTIONAL_ITERATOR_HPP


# include "./iterator.hpp"

namespace ft
{
    template <typename T>
    class bidirectional_iterator : ft::iterator<ft::bidirectional_iterator_tag, T> {

    public:
        typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::iterator_category iterator_category;
        typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::value_type        value_type;
        typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::difference_type   difference_type;
        typedef T*  pointer;
        typedef T&  reference;
    private:
        pointer _ptr;

    public:
        // ------------------------------------ CONSTRUCTOR DESTRUCTOR -------------------------------------
        /* Default constructor, pointer is NULL */
        bidirectional_iterator() : _ptr(NULL) {}

        /* Constructor from pointer, _ptr point on the element passed as parameter */
        bidirectional_iterator(pointer ptr) : _ptr(ptr) {}

        /* Copy constructor : construct iterator and copy the pointer */
        bidirectional_iterator(const bidirectional_iterator &cpy) : _ptr(cpy._ptr) {}

        /* Destructor */
        virtual ~bidirectional_iterator() {}

        /* Base : Give pointer where iterator point, return iterator */
        pointer base() const
        {
            return (this->_ptr);
        }

        // --------------------------------------- OPERATOR OVERLOAD ---------------------------------------
        /*
         * Operator-> : Returns a pointer to the element pointed by the iterator
         */
        pointer operator->() const
        {
            return (&(this->operator*()));
        }

        /*
         * Operator* : dereference -> give reference to value of element where iterator point
         */
        reference operator*() const
        {
            return (*_ptr);
        }

        /*
        * Operator-- / Predecrement : decrements the base iterator kept by the object,
        * iterator point to the previous element
        * Return : reference
        */
        bidirectional_iterator &operator--()
        {
            _ptr--;
            return (*this);
        }

        /*
         * --Operator / Postdecrement : decrement iterator to points to the previous element
         * Return : iterator decremented
         */
        bidirectional_iterator operator--(int) {
            bidirectional_iterator tmp = *this;
            --(*this);
            return (tmp);
        }

        /*
         * Operator++ / Preincrement : increments the base iterator kept by the object,
         * iterator point to the next element
         * Return : reference
         */
        bidirectional_iterator &operator++()
        {
            _ptr++;
            return (*this);
        }

        /*
         * Postincrement : increment iterator to points to the next element
         * Return : iterator incremented
         */
        bidirectional_iterator operator++(int) {
            bidirectional_iterator tmp = *this;
            ++(*this);
            return (tmp);
        }
        
        /*
         * Transform iterator to const iterator
         */
        operator bidirectional_iterator<const T> () const
        {
            return (bidirectional_iterator<const T>(this->_ptr));
        }
        // ------------------------------------------------------------------------------------------------
    };
}

#endif // BIDIRECTIONAL_ITERATOR_HPP