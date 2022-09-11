#ifndef PAIR_HPP
#define PAIR_HPP

namespace ft {

    template <class _T1, class _T2>
    struct pair
    {
        typedef _T1 first_type;
        typedef _T2 second_type;

        _T1 first;
        _T2 second;

        // Constructors
        pair() : first(), second() {}
        pair( const _T1 a, const _T2 b) : first(a), second(b) {}
        // Copy constructor

        template<class A, class B>
        pair(const pair<A, B> &p) : first(p.first), second(p.second) {}

        pair &operator=(const pair &x)
        {
            if (this == &x)
                return *this;
            this->first = x.first;
            this->second = x.second;
            return *this;
        }
    };

    template<class _T1, class _T2>
    bool operator==(const ft::pair<_T1, _T2> &lhs, const ft::pair<_T1, _T2> &rhs)
    { return lhs.first == rhs.first && lhs.second == rhs.second; }

    template<class _T1, class _T2>
    bool operator!=(const ft::pair<_T1, _T2> &lhs, const ft::pair<_T1, _T2> &rhs)
    { return !(lhs == rhs); }

    template<class _T1, class _T2>
    bool operator<=(const ft::pair<_T1, _T2> &lhs, const ft::pair<_T1, _T2> &rhs)
    { return !(rhs < lhs); }

    template<class _T1, class _T2>
    bool operator>=(const ft::pair<_T1, _T2> &lhs, const ft::pair<_T1, _T2> &rhs)
    { return !(lhs < rhs); }

    template<class _T1, class _T2>
    bool operator<(const ft::pair<_T1, _T2> &lhs, const ft::pair<_T1, _T2> &rhs)
    { return lhs.first < rhs.first || (lhs.first <= rhs.first && lhs.second < rhs.second); }

    template<class _T1, class _T2>
    bool operator>(const ft::pair<_T1, _T2> &lhs, const ft::pair<_T1, _T2> &rhs)
    { return !(lhs < rhs); }

    template<class _T1, class _T2>
    ft::pair<_T1, _T2> make_pair(_T1 lhs, _T2 rhs)
    { return ft::pair<_T1, _T2>(lhs, rhs); }
}

#endif // PAIR_HPP
