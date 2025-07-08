#include <iostream>
#include <vector>
#include <algorithm>

class cont : public std::exception
{
    public :
        virtual const char *what() const throw();
};


template <typename T>
typename T::iterator easyfind(T &n, int x)
{
    if (n.empty())
        throw cont();
    typename T::iterator it = (std::find(n.begin(), n.end(), x));
    if (it != n.end())
        return it;
    else
        throw cont();
}
