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
    std::cout << "test iterator base" << std::endl;
    NAMESPACE::vector<int> v;
    // test iterator
    NAMESPACE::vector<int>::iterator it = v.begin();
    NAMESPACE::vector<int>::iterator ite = v.end();
    std::cout << "it == ite: " << (it == ite) << std::endl;
    std::cout << "it != ite: " << (it != ite) << std::endl;
    std::cout << "it < ite: " << (it < ite) << std::endl;
    std::cout << "it <= ite: " << (it <= ite) << std::endl;
    std::cout << "it > ite: " << (it > ite) << std::endl;
    std::cout << "it >= ite: " << (it >= ite) << std::endl;
    // test const_iterator
    NAMESPACE::vector<int>::const_iterator cit = v.begin();
    NAMESPACE::vector<int>::const_iterator cite = v.end();
    std::cout << "cit == cite: " << (cit == cite) << std::endl;
    std::cout << "cit != cite: " << (cit != cite) << std::endl;
    std::cout << "cit < cite: " << (cit < cite) << std::endl;
    std::cout << "cit <= cite: " << (cit <= cite) << std::endl;
    std::cout << "cit > cite: " << (cit > cite) << std::endl;
    std::cout << "cit >= cite: " << (cit >= cite) << std::endl;
    
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    // test iterator
    it = v.begin();
    ite = v.end();
    std::cout << "it == ite: " << (it == ite) << std::endl;
    std::cout << "it != ite: " << (it != ite) << std::endl;
    std::cout << "it < ite: " << (it < ite) << std::endl;
    std::cout << "it <= ite: " << (it <= ite) << std::endl;
    std::cout << "it > ite: " << (it > ite) << std::endl;
    std::cout << "it >= ite: " << (it >= ite) << std::endl;
    //test const_iterator
    cit = v.begin();
    cite = v.end();
    std::cout << "cit == cite: " << (cit == cite) << std::endl;
    std::cout << "cit != cite: " << (cit != cite) << std::endl;
    std::cout << "cit < cite: " << (cit < cite) << std::endl;
    std::cout << "cit <= cite: " << (cit <= cite) << std::endl;
    std::cout << "cit > cite: " << (cit > cite) << std::endl;
    std::cout << "cit >= cite: " << (cit >= cite) << std::endl;

    NAMESPACE::vector<char> v2;
    //test iterator
    NAMESPACE::vector<char>::iterator it2 = v2.begin();
    NAMESPACE::vector<char>::iterator ite2 = v2.end();
    std::cout << "it2 == ite2: " << (it2 == ite2) << std::endl;
    std::cout << "it2 != ite2: " << (it2 != ite2) << std::endl;
    std::cout << "it2 < ite2: " << (it2 < ite2) << std::endl;
    std::cout << "it2 <= ite2: " << (it2 <= ite2) << std::endl;
    std::cout << "it2 > ite2: " << (it2 > ite2) << std::endl;
    std::cout << "it2 >= ite2: " << (it2 >= ite2) << std::endl;
    //test const_iterator
    NAMESPACE::vector<char>::const_iterator cit2 = v2.begin();
    NAMESPACE::vector<char>::const_iterator cite2 = v2.end();
    std::cout << "cit2 == cite2: " << (cit2 == cite2) << std::endl;
    std::cout << "cit2 != cite2: " << (cit2 != cite2) << std::endl;
    std::cout << "cit2 < cite2: " << (cit2 < cite2) << std::endl;
    std::cout << "cit2 <= cite2: " << (cit2 <= cite2) << std::endl;
    std::cout << "cit2 > cite2: " << (cit2 > cite2) << std::endl;
    std::cout << "cit2 >= cite2: " << (cit2 >= cite2) << std::endl;
    
    v2.push_back('a');
    v2.push_back('b');
    v2.push_back('c');
    //test iterator
    it2 = v2.begin();
    ite2 = v2.end();
    std::cout << "it2 == ite2: " << (it2 == ite2) << std::endl;
    std::cout << "it2 != ite2: " << (it2 != ite2) << std::endl;
    std::cout << "it2 < ite2: " << (it2 < ite2) << std::endl;
    std::cout << "it2 <= ite2: " << (it2 <= ite2) << std::endl;
    std::cout << "it2 > ite2: " << (it2 > ite2) << std::endl;
    std::cout << "it2 >= ite2: " << (it2 >= ite2) << std::endl;
    //test const_iterator
    cit2 = v2.begin();
    cite2 = v2.end();
    std::cout << "cit2 == cite2: " << (cit2 == cite2) << std::endl;
    std::cout << "cit2 != cite2: " << (cit2 != cite2) << std::endl;
    std::cout << "cit2 < cite2: " << (cit2 < cite2) << std::endl;
    std::cout << "cit2 <= cite2: " << (cit2 <= cite2) << std::endl;
    std::cout << "cit2 > cite2: " << (cit2 > cite2) << std::endl;
    std::cout << "cit2 >= cite2: " << (cit2 >= cite2) << std::endl;

    NAMESPACE::vector<std::string> v3;
    //test iterator
    NAMESPACE::vector<std::string>::iterator it3 = v3.begin();
    NAMESPACE::vector<std::string>::iterator ite3 = v3.end();
    std::cout << "it3 == ite3: " << (it3 == ite3) << std::endl;
    std::cout << "it3 != ite3: " << (it3 != ite3) << std::endl;
    std::cout << "it3 < ite3: " << (it3 < ite3) << std::endl;
    std::cout << "it3 <= ite3: " << (it3 <= ite3) << std::endl;
    std::cout << "it3 > ite3: " << (it3 > ite3) << std::endl;
    std::cout << "it3 >= ite3: " << (it3 >= ite3) << std::endl;
    //test const_iterator
    NAMESPACE::vector<std::string>::const_iterator cit3 = v3.begin();
    NAMESPACE::vector<std::string>::const_iterator cite3 = v3.end();
    std::cout << "cit3 == cite3: " << (cit3 == cite3) << std::endl;
    std::cout << "cit3 != cite3: " << (cit3 != cite3) << std::endl;
    std::cout << "cit3 < cite3: " << (cit3 < cite3) << std::endl;
    std::cout << "cit3 <= cite3: " << (cit3 <= cite3) << std::endl;
    std::cout << "cit3 > cite3: " << (cit3 > cite3) << std::endl;
    std::cout << "cit3 >= cite3: " << (cit3 >= cite3) << std::endl;

    v3.push_back("a");
    v3.push_back("b");
    v3.push_back("c");
    //test iterator
    it3 = v3.begin();
    ite3 = v3.end();
    std::cout << "it3 == ite3: " << (it3 == ite3) << std::endl;
    std::cout << "it3 != ite3: " << (it3 != ite3) << std::endl;
    std::cout << "it3 < ite3: " << (it3 < ite3) << std::endl;
    std::cout << "it3 <= ite3: " << (it3 <= ite3) << std::endl;
    std::cout << "it3 > ite3: " << (it3 > ite3) << std::endl;
    std::cout << "it3 >= ite3: " << (it3 >= ite3) << std::endl;
    //test const_iterator
    cit3 = v3.begin();
    cite3 = v3.end();
    std::cout << "cit3 == cite3: " << (cit3 == cite3) << std::endl;
    std::cout << "cit3 != cite3: " << (cit3 != cite3) << std::endl;
    std::cout << "cit3 < cite3: " << (cit3 < cite3) << std::endl;
    std::cout << "cit3 <= cite3: " << (cit3 <= cite3) << std::endl;
    std::cout << "cit3 > cite3: " << (cit3 > cite3) << std::endl;
    std::cout << "cit3 >= cite3: " << (cit3 >= cite3) << std::endl;
    std::cout << "it3++" << *(it3++) << std::endl;
    std::cout << "it3--" << *(it3--) << std::endl;
    std::cout << "it3" << *(it3) << std::endl;
    std::cout << "it3 + 1" << *(it3 + 1) << std::endl;
    std::cout << "it3 - 1" << *(it3 - 1) << std::endl;
    std::cout << "it3 += 1" << *(it3 += 1) << std::endl;
    std::cout << "it3 -= 1" << *(it3 -= 1) << std::endl;
	std::cout << " 1 + it3" << *(1 + it3) << std::endl;
    std::cout << "it3[1]" << (it3[1]) << std::endl;
    std::cout << "it3[1] = 1" << (it3[1] = 1) << std::endl;
    std::cout << "it3[1]" << (it3[1]) << std::endl;

	// test const_iterator assign iterator
	cit3 = it3;

    return 0;
}