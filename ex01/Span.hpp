#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <iterator>
#include <ctime>
#include <cstdlib>
#include <climits>

class Span
{
    private :
        Span();
        std::vector<int> tab;
        int limit;
    public :
        Span(unsigned int N);
        Span(const Span &copy);
        Span &operator=(const Span &src);
        void addNumber(int nb);
        template <typename Iterrator>
        void addNumbers(Iterrator a,Iterrator b)
        {
            if (this->tab.size() + std::distance(a, b) > (unsigned long)limit)
                throw Span::MaxCapacityException();
            std::copy(a, b, std::back_inserter(tab));
        } 
        int shortestSpan();
        int longestSpan();
        void printTab();
        class MaxCapacityException : public std::exception
        {
            public :
                virtual const char *what() const throw();
        };
        class contentTooLow : public std::exception
        {
            public :
                virtual const char *what() const throw();
        };
}; 
#endif