#ifndef EQUAL_HPP
#define EQUAL_HPP

namespace ft {
    /*
     * Simply iterating to check if the elements are equal
     * within the range given.
     * False if there is no equality
     * True if there is equality
     */
    template <class InputIterator1, class InputIterator2>
    bool equal ( InputIterator1 first1, InputIterator1 last1,
                 InputIterator2 first2 )
    {
        while (first1 != last1) {
            if (!(*first1 == *first2))
                return false;
            ++first1;
            ++first2;
        }
        return true;
    }

    /*
     * Adding BinaryPredicate
     * A Binary Predicate is a Binary Function whose result represents
     * the truth or falsehood of some condition. A Binary Predicate might,
     * for example, be a function that takes two arguments and tests whether
     * they are equal.
     */
    template <class InputIterator1, class InputIterator2, class BinaryPredicate>
    bool equal ( InputIterator1 first1, InputIterator1 last1,
                 InputIterator2 first2, BinaryPredicate pred )
    {
        while (first1 != last1) {
            if (!pred(*first1, *first2))
                return false;
            ++first1;
            ++first2;
        }
        return true;
    }

    template <class InputIterator1>
    bool equal ( InputIterator1 first1, InputIterator1 last1,
                 InputIterator1 first2 )
    {
        while (first1 != last1) {
            if (!(*first1 == *first2))
                return false;
            ++first1;
            ++first2;
        }
        return true;
    }
}

#endif // EQUAL_HPP
