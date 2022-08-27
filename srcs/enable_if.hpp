#ifndef ENABLE_IF_HPP
#define ENABLE_IF_HPP

/*
 * In C++ metaprogramming, std::enable_if is an important
 * function to enable certain types for template specialization
 * via some predicates known at the compile time. Using types that are
 * not enabled by std::enable_if for template
 * specialization will result in compile-time error.
 */

namespace ft {
    public:
        template<bool Cond, class T = void>
        struct enable_if {};

        template<class T>
        struct enable_if<true, T> { typedef T type; };
}

//TODO : MORE comms

#endif // ENABLE_IF_HPP