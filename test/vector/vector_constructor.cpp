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
	std::cout << "vector constructor test" << std::endl;
    // create test all constructor vector
    NAMESPACE::vector<int> v1;
    NAMESPACE::vector<int> v2(5);
    NAMESPACE::vector<int> v3(5, 10);
    NAMESPACE::vector<int> v4(v3);
    NAMESPACE::vector<int> v5(v3.begin(), v3.end());
    NAMESPACE::vector<int> v6(v3.rbegin(), v3.rend());
    std::cout << "v1: " << v1 << std::endl;
    std::cout << "v2: " << v2 << std::endl;
    std::cout << "v3: " << v3 << std::endl;
    std::cout << "v4: " << v4 << std::endl;
    std::cout << "v5: " << v5 << std::endl;
    std::cout << "v6: " << v6 << std::endl;
    // create test all constructor vector with class A
    NAMESPACE::vector<A> v7;
    NAMESPACE::vector<A> v8(5);
    NAMESPACE::vector<A> v9(5, A());
    NAMESPACE::vector<A> v10(v9);
    NAMESPACE::vector<A> v11(v9.begin(), v9.end());
    NAMESPACE::vector<A> v12(v9.rbegin(), v9.rend());
    std::cout << "v7: " << v7 << std::endl;
    std::cout << "v8: " << v8 << std::endl;
    std::cout << "v9: " << v9 << std::endl;
    std::cout << "v10: " << v10 << std::endl;
    std::cout << "v11: " << v11 << std::endl;
    
    //same test but with new
    NAMESPACE::vector<int> *v13 = new NAMESPACE::vector<int>();
    NAMESPACE::vector<int> *v14 = new NAMESPACE::vector<int>(5);
    NAMESPACE::vector<int> *v15 = new NAMESPACE::vector<int>(5, 10);
    NAMESPACE::vector<int> *v16 = new NAMESPACE::vector<int>(*v15);
    NAMESPACE::vector<int> *v17 = new NAMESPACE::vector<int>(v15->begin(), v15->end());
    NAMESPACE::vector<int> *v18 = new NAMESPACE::vector<int>(v15->rbegin(), v15->rend());
    std::cout << "v13: " << *v13 << std::endl;
    std::cout << "v14: " << *v14 << std::endl;
    std::cout << "v15: " << *v15 << std::endl;
    std::cout << "v16: " << *v16 << std::endl;
    std::cout << "v17: " << *v17 << std::endl;
    std::cout << "v18: " << *v18 << std::endl;
    // create test all constructor vector with class A
    NAMESPACE::vector<A> *v19 = new NAMESPACE::vector<A>();
    NAMESPACE::vector<A> *v20 = new NAMESPACE::vector<A>(5);
    NAMESPACE::vector<A> *v21 = new NAMESPACE::vector<A>(5, A());
    NAMESPACE::vector<A> *v22 = new NAMESPACE::vector<A>(*v21);
    NAMESPACE::vector<A> *v23 = new NAMESPACE::vector<A>(v21->begin(), v21->end());
    NAMESPACE::vector<A> *v24 = new NAMESPACE::vector<A>(v21->rbegin(), v21->rend());
    std::cout << "v19: " << *v19 << std::endl;
    std::cout << "v20: " << *v20 << std::endl;
    std::cout << "v21: " << *v21 << std::endl;
    std::cout << "v22: " << *v22 << std::endl;
    std::cout << "v23: " << *v23 << std::endl;
    std::cout << "v24: " << *v24 << std::endl;
    delete v13;
    delete v14;
    delete v15;
    delete v16;
    delete v17;
    delete v18;
    delete v19;
    delete v20;
    delete v21;
    delete v22;
    delete v23;
    delete v24;
	return 0;
}