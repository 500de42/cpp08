#include "Span.hpp"

Span::Span(unsigned int N) : limit(N)
{

}

Span::Span(const Span &copy) : limit(copy.limit)
{
    std::copy(copy.tab.begin(), copy.tab.end(), this->tab.begin());
}

Span &Span::operator=(const Span &src)
{
    std::copy(src.tab.begin(), src.tab.end(), this->tab.begin());
    this->limit = src.limit;
    return *this;
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

void Span::printTab()
{
    for (std::vector<int>::iterator i = tab.begin(); i != tab.end(); i++)
    {
        std::cout << *i << std::endl;
    }
    std::cout << std::distance(tab.begin(), tab.end()) << std::endl;
}

const char *Span::contentTooLow::what() const throw()
{
    return "The number of elements in the vector must be greater than 1";
}

const char *Span::MaxCapacityException::what() const throw()
{
    return "The number of elements in the vector must be lower than X";
}
