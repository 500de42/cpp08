#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>

class Span
{
    private :
        Span();
        std::vector<int> tab;
        int limit;
    public :
        Span(unsigned int N);
        void addNumber(int nb);
        int shortestSpan();
        int longestSpan();
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