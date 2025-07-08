#include "easyfind.hpp"
#include <iostream>
#include <list>
const char *cont::what() const throw()
{
    return "error in easyfind\n";
}

int main()
{
    {  
        int tab[] = {855, 858,6314,87,23, -12, 9};
        std::vector<int> v(tab, (tab + sizeof(tab) / sizeof (int)));
        try
        {
            std::vector<int>::iterator it = v.begin();
            it = easyfind(v, 8);
            if (it != v.end())
            std::cout << *it << "\n";
        }
        catch (const cont &e)
        {
            std::cout << e.what();
        }
    }
    {
        int tab[] = {855, 858,6314,87,23, -12, 9};
        std::list<int> v(tab, (tab + sizeof(tab) / sizeof (int)));
        try
        {
            std::list<int>::iterator it = v.begin();
            it = easyfind(v, 9);
            if (it != v.end())
            std::cout << *it << "\n";
        }
        catch (const cont &e)
        {
            std::cout << e.what();
        }
    }
}
