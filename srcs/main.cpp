#include "vector.hpp"
#include <iostream>
#include <vector>
#include "utils.hpp"
#include <list>
#include <fstream>
#include <sstream>

#ifndef NAMESPACE
# define NAMESPACE ft
#endif
class A
{
public:
	A() { _a = new int;}
	~A() {delete _a;}
	A(A const &a) { (void)a; }
	A &operator=(A const &a) { (void)a; return *this; }
    friend std::ostream &operator<<(std::ostream &out, A const &a)
    {
        (void)a;
        out << "A";
        return out;
    }
	private:
		int* _a;
};

int main()
{
    std::cout << __LINE__ << "vector modifier test" << std::endl;
    NAMESPACE::vector<int> v;
    std::cout << __LINE__ << v << std::endl;
    v.push_back(1);
    v.push_back(2);
    for (int i = 0; i < 10; i++)
        v.push_back(i);
    for (int i = 0; i < 3; i++)
        v.insert(v.begin(), i);
    std::cout << __LINE__ << v << std::endl;
    //test assign
    NAMESPACE::vector<int> v2;
    v2.assign(5, 10);
    std::cout << __LINE__ << v2 << std::endl;
    v2.assign(v.begin(), v.end());
    std::cout << __LINE__ << v2 << std::endl;
    //test insert
    v2.insert(v2.begin(), 42);
    std::cout << __LINE__ << v2 << std::endl;
    v2.insert(v2.begin(), 2, 42);
    std::cout << __LINE__ << v2 << std::endl;
    v2.insert(v2.begin(), v.begin(), v.end());
    std::cout << __LINE__ << v2 << std::endl;
    //test erase
    v2.erase(v2.begin());
    std::cout << __LINE__ << v2 << std::endl;
    v2.erase(v2.begin(), v2.begin() + 5);
    std::cout << __LINE__ << v2 << std::endl;
    //test swap
    v2.swap(v);
    std::cout << __LINE__ << v2 << std::endl;
    std::cout << __LINE__ << v << std::endl;
    //test clear
    v2.clear();
    std::cout << __LINE__ << v2 << std::endl;
    //test pop_back
    v.pop_back();
    std::cout << __LINE__ << v << std::endl;
    // same but with const vector
    const NAMESPACE::vector<int> v3(v.begin(), v.end());
    std::cout << __LINE__ << v3 << std::endl;
    //test assign
    NAMESPACE::vector<int> v4;
    v4.assign(5, 10);
    std::cout << __LINE__ << v4 << std::endl;
    v4.assign(v3.begin(), v3.end());
    std::cout << __LINE__ << v4 << std::endl;
	std::vector<int> v5;
	v5.push_back(55);
	v5.push_back(60);

	NAMESPACE::vector<int> v6;
	v6.assign(v5.begin(), v5.end());

	std::cout << __LINE__ << v6 << std::endl;

	std::list<int> l;
	l.push_back(55);
	l.push_back(60);

	NAMESPACE::vector<int> v7;
	v7.assign(l.begin(), l.end());

	std::cout << __LINE__ << v7 << std::endl;

	std::stringstream ss;
	// create iterator from string stream
	// create eos frorm ss
	for (int i = 0; i < 10; i++)
		ss << i << " ";
	std::istream_iterator<int> it(ss);
	std::istream_iterator<int> eos;

	NAMESPACE::vector<int> v8;
	v8.assign(it, eos);
	std::cout << __LINE__ << v8 << std::endl;

	std::stringstream ss2;
	for (int i = 0; i < 10; i++)
		ss2 << i << " ";
	std::istream_iterator<int> it2(ss2);
	std::istream_iterator<int> eos2;

	NAMESPACE::vector<int> v9(it2, eos2);
	std::cout << __LINE__ << v9 << std::endl;

	// same but use insert
	NAMESPACE::vector<int> v10;
	std::stringstream ss3;
	for (int i = 0; i < 10; i++)
		ss3 << i << " ";
	std::istream_iterator<int> it3(ss3);
	std::istream_iterator<int> eos3;
	v10.insert(v10.begin(), it3, eos3);
	std::cout << __LINE__ << v10 << std::endl;

	NAMESPACE::vector<A> v11;
	v11.push_back(A());
	v11.push_back(A());
	v11.insert(v11.begin(), A());
	std::cout << __LINE__ << v11 << std::endl;
	v11.insert(v11.begin(), 10, A());
	v11.insert(v11.end(), 5, A());
	v11.insert(v11.begin() + 3, 2, A());
}