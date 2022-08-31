#ifndef MAP_HPP
#define MAP_HPP

namespace ft {
    template<typename Key, typename _Tp, typename Compare = std::less<Key>,
        typename Alloc = std::allocator<std::pair<const Key, m_type> >>
    class map {
    public:
        typedef Key                                             key_type;
        typedef m_type                                          mapped_type;
        typedef std::pair<const Key, m_type>                    value_type;
        typedef Compare                                         key_compare;
        typedef Alloc                                           allocator_type;
        typedef typename _Base::reference                       reference;
        typedef typename _Base::const_reference                 const_reference;
        typedef typename allocator_type::reference              reference;
        typedef typename allocator_type::const_reference        const_reference;
        typedef typename allocator_type::pointer                pointer;
        typedef typename allocator_type::const_pointer          const_pointer;
// ??
        typedef ft::random_access_iterator<value_type>          iterator;
        typedef ft::random_access_iterator<const value_type>    const_iterator;
        typedef ft::reverse_iterator<iterator>                  reverse_iterator;
        typedef ft::reverse_iterator<const iterator>            const_reverse_iterator;
        typedef ft::iterator_traits<iterator>                   difference_type;
        typedef size_t                                          size_type;

    };


}
#endif // MAP_HPP
