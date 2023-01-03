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
    std::cout << "vector modifier test" << std::endl;
    NAMESPACE::vector<int> v;
    std::cout << v << std::endl;
    v.push_back(1);
    v.push_back(2);
    for (int i = 0; i < 10; i++)
        v.push_back(i);
    for (int i = 0; i < 3; i++)
        v.insert(v.begin(), i);
    std::cout << v << std::endl;
    //test assign
    NAMESPACE::vector<int> v2;
    v2.assign(5, 10);
    std::cout << v2 << std::endl;
    v2.assign(v.begin(), v.end());
    std::cout << v2 << std::endl;
    //test insert
    v2.insert(v2.begin(), 42);
    std::cout << v2 << std::endl;
    v2.insert(v2.begin(), 2, 42);
    std::cout << v2 << std::endl;
    v2.insert(v2.begin(), v.begin(), v.end());
    std::cout << v2 << std::endl;
    //test erase
    v2.erase(v2.begin());
    std::cout << v2 << std::endl;
    v2.erase(v2.begin(), v2.begin() + 5);
    std::cout << v2 << std::endl;
	std::cout << "break" << std::endl;
    //test swap
    v2.swap(v);
    std::cout << v2 << std::endl;
    std::cout << v << std::endl;
    //test clear
    v2.clear();
    std::cout << v2 << std::endl;
    //test pop_back
	std::cout << "ici" << std::endl;
    v.pop_back();
    std::cout << v << std::endl;
    // same but with const vector
    const NAMESPACE::vector<int> v3(v.begin(), v.end());
    std::cout << v3 << std::endl;
    //test assign
    NAMESPACE::vector<int> v4;
    v4.assign(5, 10);
    std::cout << v4 << std::endl;
    v4.assign(v3.begin(), v3.end());
    std::cout << v4 << std::endl;
	std::cout << "coucou" << std::endl;
}