#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

#include "iterator.hpp"
#include "iterator_traits.hpp"

namespace ft
{
    template <class Iterator>
    class reverse_iterator {
    public:
        typedef Iterator iterator_type;
        typedef typename ft::iterator_traits<Iterator>::iterator_category   iterator_category;
        typedef typename ft::iterator_traits<Iterator>::value_type          value_type;
        typedef typename ft::iterator_traits<Iterator>::difference_type     difference_type;
        typedef typename ft::iterator_traits<Iterator>::pointer             pointer;
        typedef typename ft::iterator_traits<Iterator>::reference           reference;
    private:
        iterator_type _it;

    public:
        // ------------------------------------ CONSTRUCTOR DESTRUCTOR -------------------------------------
        /* Default constructor, pointer is NULL */
        reverse_iterator() : _it() {}

        // constructing from an iterator type
        explicit reverse_iterator(iterator_type it) : _it(it) {}

        // Copy construction
        template <class Iter>
        reverse_iterator (const reverse_iterator<Iter> &rev_it) : _it(rev_it.base()) {}

        template <class Iter>
        reverse_iterator &operator=(const reverse_iterator<Iter> &rev_it) {
            if (this == &rev_it)
                return (*this);
            this->_it = rev_it.base();
            return (*this);
        }

        /* Destructor */
        virtual ~reverse_iterator() {}

        // --------------------------------------- OPERATOR OVERLOAD ---------------------------------------
        /*
         * Operator-> : Returns a pointer to the element pointed by the iterator
         */
        pointer operator->() const
        {
            return (&(this->operator*()));
        }

        /* Base : Give pointer where iterator point, return iterator */
        pointer base() const
        {
            return (_it);
        }

        /*
         * Operator [] allows to access an element at n position
         * from the element pointed by the iterator
         * In this case it is a rev it so we -n -1
         */
        reference operator[](difference_type n)
        {
            return (this->base()[-n - 1]);
        }

        /*
         * Operator* : dereference -> give reference to value of element where iterator point
         */
        reference operator*() const
        {
            iterator_type temp = _it;
            return (*(--temp));
        }

        /*
        * Operator-- / Predecrement : decrements the base iterator kept by the object,
        * iterator point to the previous element
        * Return : reference
        */
        reverse_iterator &operator--()
        {
            ++_it;
            return (*this);
        }

        /*
         * --Operator / Postdecrement : decrement iterator to points to the previous element
         * Return : iterator decremented
         */
        reverse_iterator operator--(int)
        {
            reverse_iterator tmp = *this;
            ++(*this);
            return (tmp);
        }

        /*
         * Operator++ / Preincrement : increments the base iterator kept by the object,
         * iterator point to the next element
         * Return : reference
         */
        reverse_iterator &operator++()
        {
            _it--;
            return (*this);
        }

        /*
         * Postincrement : increment iterator to points to the next element
         * Return : iterator incremented
         */
        reverse_iterator operator++(int) {
            reverse_iterator tmp = *this;
            --(*this);
            return (tmp);
        }

        /*
         * Operator- : give an iterator where element is pointed at "- n" elements
         * Return : iterator pointing to the element located n positions before the element the iterator
         * points to.
         */
        reverse_iterator operator-(difference_type n) const
        {
            return (reverse_iterator(_it + n));
        }

        /*
         * Operator+ : give an iterator where element is pointed at "+ n" elements
         * Return : iterator pointing to the element located n positions after the element the iterator
         * points to.
         */
        reverse_iterator operator+(difference_type n) const
        {
            return (reverse_iterator(_it - n));
        }

        /*
         * Operator-= : take the element pointed by iterator "- n"
         * Return : reference to iterator
         */
        reverse_iterator &operator-=(difference_type n) const
        {
            this->_ptr += n;
            return (*this);
        }

        /*
         * Operator+= : take the element pointed by iterator "+ n"
         * Return : reference to iterator
         */
        reverse_iterator &operator+=(difference_type n) const
        {
            this->_ptr -= n;
            return (*this);
        }

        /*
         * Operator- : subtract n
         * Give iterator where element is "this - n" in memory
         */
        reverse_iterator operator-(difference_type n)
        {
            (this->_ptr - n);
        }

        /*
         * Operator+ : add n
         * Give iterator where element is "this + n" in memory
         */
        reverse_iterator operator+(difference_type n)
        {
            (this->_ptr + n);
        }

        /*
         * Transform iterator to const iterator
         */
        operator reverse_iterator<const Iterator> () const
        {
            return (reverse_iterator<const Iterator>(this->_it));
        }
        // ------------------------------------------------------------------------------------------------
    };
    /*
     * Operator== : comparison between two iterators
     * Return : true if equal
     *
     * (1) : both of them are same type (const or not)
     * (2) : in case of const - not const
     */
    /* (1) */
    template<typename Iterator>
    bool operator==(
            const ft::reverse_iterator<Iterator> &lhs,
            const ft::reverse_iterator<Iterator> &rhs)
    {
        return (lhs.base() == rhs.base());
    }
    /* (2) */
    template<typename T1, typename T2>
    bool operator==(
            const ft::reverse_iterator<T1> &lhs,
            const ft::reverse_iterator<T2> &rhs)
    {
        return (lhs.base() == rhs.base());
    }

    /*
     * Operator!= : comparison between two iterators
     * Return : true if lhs != rhs
     */
    /* (1) */
    template<typename Iterator>
    bool operator!=(
            const ft::reverse_iterator<Iterator> &lhs,
            const ft::reverse_iterator<Iterator> &rhs)
    {
        return (lhs.base() != rhs.base());
    }
    /* (2) */
    template<typename T1, typename T2>
    bool operator!=(
            const ft::reverse_iterator<T1> &lhs,
            const ft::reverse_iterator<T2> &rhs)
    {
        return (lhs.base() != rhs.base());
    }

    /*
     * Operator>= : comparison between two iterators
     * Return : true if lhs >= rhs
     */
    /* (1) */
    template<typename Iterator>
    bool operator>=(
            const ft::reverse_iterator<Iterator> &lhs,
            const ft::reverse_iterator<Iterator> &rhs)
    {
        return (lhs.base() >= rhs.base());
    }
    /* (2) */
    template<typename T1, typename T2>
    bool operator>=(
            const ft::reverse_iterator<T1> &lhs,
            const ft::reverse_iterator<T2> &rhs)
    {
        return (lhs.base() >= rhs.base());
    }

    /*
    * Operator>= : comparison between two iterators
    * Return : true if lhs >= rhs
    */
    /* (1) */
    template<typename Iterator>
    bool operator<=(
            const ft::reverse_iterator<Iterator> &lhs,
            const ft::reverse_iterator<Iterator> &rhs)
    {
        return (lhs.base() <= rhs.base());
    }
    /* (2) */
    template<typename T1, typename T2>
    bool operator<=(
            const ft::reverse_iterator<T1> &lhs,
            const ft::reverse_iterator<T2> &rhs)
    {
        return (lhs.base() <= rhs.base());
    }

    /*
     * Operator> : comparison between two iterators
     * Return : true if lhs > rhs
     */
    /* (1) */
    template<typename Iterator>
    bool operator>(
            const ft::reverse_iterator<Iterator> &lhs,
            const ft::reverse_iterator<Iterator> &rhs)
    {
        return (lhs.base() > rhs.base());
    }
    /* (2) */
    template<typename T1, typename T2>
    bool operator>(
            const ft::reverse_iterator<T1> &lhs,
            const ft::reverse_iterator<T2> &rhs)
    {
        return (lhs.base() > rhs.base());
    }

    /*
     * Operator< : comparison between two iterators
     * Return : true if lhs < rhs
     */
    /* (1) */
    template<typename Iterator>
    bool operator<(
            const ft::reverse_iterator<Iterator> &lhs,
            const ft::reverse_iterator<Iterator> &rhs)
    {
        return (lhs.base() < rhs.base());
    }
    /* (2) */
    template<typename T1, typename T2>
    bool operator<(
            const ft::reverse_iterator<T1> &lhs,
            const ft::reverse_iterator<T2> &rhs)
    {
        return (lhs.base() < rhs.base());
    }


    /*
     * Operator- : Difference between two iterators
     * Return : difference_type
     */
    /* (1) */
    template<typename T>
    typename ft::reverse_iterator<T>::difference_type operator-(
            const ft::reverse_iterator<T> lhs,
            const ft::reverse_iterator<T> rhs)
    {
        return (lhs.base() - rhs.base());
    }
    /* (2) */
    template<typename T1, typename T2>
    typename ft::reverse_iterator<T1>::difference_type operator-(
            const ft::reverse_iterator<T1> lhs,
            const ft::reverse_iterator<T2> rhs)
    {
        return (lhs.base() - rhs.base());
    }

    /*
     * Operator+ : return an iterator pointing to "current + n"
     * Return : iterator
     */
    template<typename T>
    typename ft::reverse_iterator<T> operator+ (
            typename ft::reverse_iterator<T>::difference_type n,
            typename ft::reverse_iterator<T> &current)
    {
        return (&(*current) + n);
    }
    //TODO: const addition ?
}



#endif // reverse_iterator_HPP
