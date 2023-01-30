#include "vector.hpp"
#include "iterator.hpp"
#include <iostream>
#include <vector>
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
};

int main()
{
    std::cout << "test reverse iterator base" << std::endl;
    NAMESPACE::vector<int> v;
    // test reverse iterator base
    NAMESPACE::vector<int>::reverse_iterator rit = v.rbegin();
    NAMESPACE::vector<int>::reverse_iterator rite = v.rend();
    std::cout << "rit == rite: " << (rit == rite) << std::endl;
    std::cout << "rit != rite: " << (rit != rite) << std::endl;
    std::cout << "rit < rite: " << (rit < rite) << std::endl;
    std::cout << "rit <= rite: " << (rit <= rite) << std::endl;
    std::cout << "rit > rite: " << (rit > rite) << std::endl;
    std::cout << "rit >= rite: " << (rit >= rite) << std::endl;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    rit = v.rbegin();
    rite = v.rend();
    std::cout << "rit == rite: " << (rit == rite) << std::endl;
    std::cout << "rit != rite: " << (rit != rite) << std::endl;
    std::cout << "rit < rite: " << (rit < rite) << std::endl;
    std::cout << "rit <= rite: " << (rit <= rite) << std::endl;
    std::cout << "rit > rite: " << (rit > rite) << std::endl;
    std::cout << "rit >= rite: " << (rit >= rite) << std::endl;

    // test const reverse iterator base
    NAMESPACE::vector<int>::const_reverse_iterator crit = v.rbegin();
    NAMESPACE::vector<int>::const_reverse_iterator crite = v.rend();
    std::cout << "crit == crite: " << (crit == crite) << std::endl;
    std::cout << "crit != crite: " << (crit != crite) << std::endl;
    std::cout << "crit < crite: " << (crit < crite) << std::endl;
    std::cout << "crit <= crite: " << (crit <= crite) << std::endl;
    std::cout << "crit > crite: " << (crit > crite) << std::endl;
    std::cout << "crit >= crite: " << (crit >= crite) << std::endl;

	// test const & non const
	std::cout << "crit == rit: " << (crit == rit) << std::endl;
	std::cout << "crit != rit: " << (crit != rit) << std::endl;
	std::cout << "crit < rit: " << (crit < rit) << std::endl;
	std::cout << "crit <= rit: " << (crit <= rit) << std::endl;
	std::cout << "crit > rit: " << (crit > rit) << std::endl;
	std::cout << "crit >= rit: " << (crit >= rit) << std::endl;

	std::cout << "rit == crit: " << (rit == crit) << std::endl;
	std::cout << "rit != crit: " << (rit != crit) << std::endl;
	std::cout << "rit < crit: " << (rit < crit) << std::endl;
	std::cout << "rit <= crit: " << (rit <= crit) << std::endl;
	std::cout << "rit > crit: " << (rit > crit) << std::endl;
	std::cout << "rit >= crit: " << (rit >= crit) << std::endl;
	

    return 0;
}