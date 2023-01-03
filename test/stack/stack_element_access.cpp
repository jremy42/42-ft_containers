
#include "stack.hpp"
#include <iostream>
#include <stack>
#include "utils.hpp"

#ifndef NAMESPACE
# define NAMESPACE ft
#endif

int main(void)
{
    std::cout << "stack element access " << std::endl;
    NAMESPACE::stack<int> s;
    NAMESPACE::stack<int> s2(s);

    for (int i = 0; i < 10; i++)
        s.push(i);
    for (int i = 10; i > 0; i--)
        s2.push(i);
    std::cout << s.top() << std::endl;
    std::cout << s2.top() << std::endl;
    s.pop();
    s2.pop();
    std::cout << s.top() << std::endl;
    std::cout << s2.top() << std::endl;

    // same with const
    const NAMESPACE::stack<int> s3(s);
    std::cout << s3.top() << std::endl;
  
    return 0;
}