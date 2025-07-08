#include "Span.hpp"

Span::Span(unsigned int N) : limit(N)
{

}


void Span::addNumber(int nb)
{
    if (tab.size() == (long unsigned int)limit)
        throw Span::MaxCapacityException();
    tab.push_back(nb);
}

int Span::longestSpan()
{
    if (tab.size() <= 1)
        throw Span::contentTooLow();
    std::sort(tab.begin(), tab.end());
    return tab.back() - tab.front();
}

// int Span::shortestSpan()
// {
//     if (this->tab.size() <= 1)
//         throw Span::contentTooLow();
//     int rang = 2147483647;
//     for(std::vector<int>::iterator i = tab.begin(); i != tab.end(); i++)
//     {
//         for(std::vector<int>::iterator it = i; it != tab.end(); it++)
//         {
//             if (*i > *it)
//             {
//                 if (*i - *it < rang)
//                     rang = *i - *it;
//             }
//             else
//             {
//                 if (*it - *i < rang)
//                     rang = *it - *i;
//             }
//         }
//     }
//     return rang;
// }

int Span::shortestSpan()
{
    if (tab.size() <= 1)
        throw Span::contentTooLow();
    int range = 2147483647;
    std::sort(tab.begin(), tab.end());
    std::vector<int>::iterator it1 = tab.begin();
    std::vector<int>::iterator it2 = it1 + 1;
    while (it2 != tab.end())
    {
        int diff = *it2 - *it1;
        if (diff < range)
            range = diff;
        ++it1;
        ++it2;
    }
    return range;
}

const char *Span::contentTooLow::what() const throw()
{
    return "The number of elements in the vector must be greater than 1";
}

const char *Span::MaxCapacityException::what() const throw()
{
    return "The number of elements in the vector must be lower than X";
}
