#include "easyfind.hpp"
#include <iostream>

const char *cont::what() const throw()
{
    return "error in easyfind\n";
}

int main()
{
    int tab[] = {855, 858,6314,87,23, -12, 9};
    std::vector<int> v(tab, (tab + sizeof(tab) / sizeof (int)));
    try
    {
        for(std::vector<int>::iterator i = v.begin(); i != v.end(); i++)
        {
            std::cout << *i << std::endl;
        }
        std::vector<int>::iterator it = v.begin();
        it = easyfind(v, 6314);
        if (it != v.end())
        std::cout << *it << "\n";
    }
    catch (const cont &e)
    {
        std::cout << e.what() << "fllflf" << std::endl;
    }
}
