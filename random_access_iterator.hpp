#ifndef RANDOM_ACCESS_ITERATOR_HPP
#define RANDOM_ACCESS_ITERATOR_HPP

namespace ft
{
    template <typename T>
    class random_access_iterator : ft::iterator<ft::random_access_iterator_tag, T> {

    public:
        typedef typename ft::iterator<ft::random_access_iterator_tag, T>::iterator_category iterator_category;
        typedef typename ft::iterator<ft::random_access_iterator_tag, T>::value_type        value_type;
        typedef typename ft::iterator<ft::random_access_iterator_tag, T>::difference_type   difference_type;
        typedef T*  pointer;
        typedef T&  reference;
    private:
        pointer _ptr;

    public:
        // ------------------------------------ CONSTRUCTOR DESTRUCTOR -------------------------------------
        /* Default constructor, pointer is NULL */
        random_access_iterator() : _ptr(NULL) {}

        /* Constructor from pointer, _ptr point on the element passed as parameter */
        random_access_iterator(pointer ptr) : _ptr(ptr) {}

        /* Copy constructor : construct iterator and copy the pointer */
        random_access_iterator(const random_access_iterator &cpy) : _ptr(cpy._ptr) {}

        /* Destructor */
        virtual ~random_access_iterator() {}
        // --------------------------------------- OPERATOR OVERLOAD ---------------------------------------
        /*
         * Operator-> : Returns a pointer to the element pointed by the iterator
         */
        pointer operator->() const
        {
            return (&(this->operator*()));
        }

        /*
         * Operator [] allows to access an element at n position
         * from the element pointed by the iterator
         */
        reference operator[](difference_type n)
        {
            return (*(operator+(n)));
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
        random_access_iterator &operator--()
        {
            _ptr--;
            return (*this);
        }

        /*
         * --Operator / Postdecrement : decrement iterator to points to the previous element
         * Return : iterator decremented
         */
        random_access_iterator operator--(int) {
            random_access_iterator tmp = *this;
            --(*this);
            return (tmp);
        }

        /*
         * Operator++ / Preincrement : increments the base iterator kept by the object, iterator point to the next element
         * Return : reference
         */
        random_access_iterator &operator++()
        {
            _ptr++;
            return (*this);
        }

        /*
         * Postincrement : increment iterator to points to the next element
         * Return : iterator incremented
         */
        random_access_iterator operator++(int) {
            random_access_iterator tmp = *this;
            ++(*this);
            return (tmp);
        }

        /*
         * Operator- : give an iterator where element is pointed at "- n" elements
         * Return : iterator pointing to the element located n positions before the element the iterator
         * points to.
         */
        random_access_iterator operator-(difference_type n) const
        {
            return (this->_ptr - n);
        }

        /*
         * Operator+ : give an iterator where element is pointed at "+ n" elements
         * Return : iterator pointing to the element located n positions after the element the iterator
         * points to.
         */
        random_access_iterator operator+(difference_type n) const
        {
            return (this->_ptr + n);
        }

        /*
         * Operator-= : take the element pointed by iterator "- n"
         * Return : reference to iterator
         */
        random_access_iterator &operator-=(difference_type n) const
        {
            this->_ptr -= n;
            return (*this);
        }

        /*
         * Operator+= : take the element pointed by iterator "+ n"
         * Return : reference to iterator
         */
        random_access_iterator &operator+=(difference_type n) const
        {
            this->_ptr += n;
            return (*this);
        }

        /*
         * Operator- : subtract n
         * Give iterator where element is "this - n" in memory
         */
        random_access_iterator operator-(difference_type n)
        {
            (this->_ptr - n);
        }

        /*
         * Operator+ : add n
         * Give iterator where element is "this + n" in memory
         */
        random_access_iterator operator+(difference_type n)
        {
            (this->_ptr + n);
        }

        /*
         * Transform iterator to const iterator
         */
        operator random_access_iterator<const T> () const
        {
            return (random_access_iterator<const T>(this->_ptr));
        }
}

#endif // RANDOM_ACCESS_ITERATOR_HPP
