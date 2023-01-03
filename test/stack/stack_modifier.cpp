
#include "stack.hpp"
#include <iostream>
#include <stack>
#include "utils.hpp"

#ifndef NAMESPACE
# define NAMESPACE ft
#endif

int main(void)
{
    std::cout << "stack modifier test" << std::endl;
    NAMESPACE::stack<int> s;
    for (int i = 0; i < 10; i++)
    {
        s.push(i);
        std::cout << s << std::endl;
    }

    for (int i = 0; i < 10; i++)
    {
        s.pop();
        std::cout << s << std::endl;
    }
    return 0;
}