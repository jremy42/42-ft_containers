//programme qui genere des nombres aleatoires

#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
{
	srand(time(NULL));
	for (int i = 0; i < 100; i++)
		std::cout << rand() % 1000 << std::endl;
	return 0;
}