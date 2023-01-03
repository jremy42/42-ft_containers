#include "vector.hpp"
#include <iostream>
#include <vector>
#include "utils.hpp"

#ifndef NAMESPACE
# define NAMESPACE ft
#endif
class A
{
public:
	A() {}
	~A() {}
	A(A const &a) { (void)a; }
	A &operator=(A const &a) { (void)a; return *this; }
    friend std::ostream &operator<<(std::ostream &out, A const &a)
    {
        (void)a;
        out << "A";
        return out;
    }
};

int main()
{
    std::cout << "vector element access test" << std::endl;

    NAMESPACE::vector<int> v(20, 42);

    // insert
    v.insert(v.begin(), 1);
    v.insert(v.begin(), 2);
    v.insert(v.begin(), 3);
    v.insert(v.begin(), 4);
    v.insert(v.begin(), 5);
    size_t size = v.size();
    for (size_t i = 0; i < size; i++)
        std::cout << v[i] << std::endl;
    std::cout << std::endl;
    for (size_t i = 0; i < size; i++)
        std::cout << v.at(i) << std::endl;
    std::cout << std::endl;
    for (size_t i = 0; i < size; i++)
        std::cout << v.front() << std::endl;
    std::cout << std::endl;
    for (size_t i = 0; i < size; i++)
        std::cout << v.back() << std::endl;
    std::cout << std::endl;
    // same with const vector
    const NAMESPACE::vector<int> v2(v.begin(), v.end());
    size = v2.size();
    for (size_t i = 0; i < size; i++)
        std::cout << v2[i] << std::endl;
    std::cout << std::endl;
    for (size_t i = 0; i < size; i++)
        std::cout << v2.at(i) << std::endl;
    std::cout << std::endl;
    for (size_t i = 0; i < size; i++)
        std::cout << v2.front() << std::endl;
    std::cout << std::endl;
    for (size_t i = 0; i < size; i++)
        std::cout << v2.back() << std::endl;
    std::cout << std::endl;
}