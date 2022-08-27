#ifndef PAIR_HPP
#define PAIR_HPP

namespace ft {

    struct pair
    {
        typedef _T1 first_type;
        typedef _T2 second_type;

        _T1 first;
        _T2 second;

        // Constructors
        pair() : first(), second() {}
        pair( const _T1 &a, const _T2 &b) : first(a), second(b) {}
        // Copy constructor

        template<class A, class B>
        pair(const pair<A, B> &p) : first(p.first), second(p.second) {}
    };
    template<class _T1, class _T2>
    bool &operator==(const std::pair<_T1, _T2> &lhs, const std::pair<_T1, _T2> &rhs)
    { return lhs.first == rhs.first && lhs.second == rhs.second; }

    template<class _T1, class _T2>
    bool &operator!=(const std::pair<_T1, _T2> &lhs, const std::pair<_T1, _T2> &rhs)
    { return !(lhs == rhs); }

    template<class _T1, class _T2>
    bool &operator<=(const std::pair<_T1, _T2> &lhs, const std::pair<_T1, _T2> &rhs)
    { return lhs <= rhs; }

    template<class _T1, class _T2>
    bool &operator>=(const std::pair<_T1, _T2> &lhs, const std::pair<_T1, _T2> &rhs)
    { return lhs >= rhs; }

    template<class _T1, class _T2>
    bool &operator<(const std::pair<_T1, _T2> &lhs, const std::pair<_T1, _T2> &rhs)
    { return lhs.first < rhs.first || lhs.first < rhs.second && lhs.second < rhs.second; }

    template<class _T1, class _T2>
    bool &operator>(const std::pair<_T1, _T2> &lhs, const std::pair<_T1, _T2> &rhs)
    { return lhs.first > rhs.first || lhs.first > rhs.second && lhs.second > rhs.second; }
}

#endif // PAIR_HPP