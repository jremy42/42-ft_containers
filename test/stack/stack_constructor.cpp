
#include "stack.hpp"
#include <iostream>
#include <stack>
#include "utils.hpp"

#ifndef NAMESPACE
# define NAMESPACE ft
#endif

int main(void)
{
    std::cout << "stack constructor test" << std::endl;
    NAMESPACE::stack<int> s;
    std::cout << s.size() << std::endl;
    std::cout << s.empty() << std::endl;
    s.push(1);
    std::cout << s.size() << std::endl;
    std::cout << s.empty() << std::endl;

    NAMESPACE::stack<int> s2(s);
    std::cout << s2.size() << std::endl;
    std::cout << s2.empty() << std::endl;
    s2.push(2);
    std::cout << s2.size() << std::endl;
    std::cout << s2.empty() << std::endl;

    return 0;
}