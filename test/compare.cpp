#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

std::string errorInLine(std::string line1, std::string line2)
{
    std::string::iterator it1 = line1.begin();
    std::string::iterator it2 = line2.begin();
    std::stringstream ret;

    for (;it1 != line1.end() && it2 != line2.end(); it2++, it1++)
    {
        if (*it1 != *it2)
        {
            ret << "\e[31m" << *it2 << "\e[0m";
        }
        else
        {
            ret << "\e[33m" << *it2 << "\e[0m";
        }
    }
    for (;it2 != line2.end(); it2++)
        ret << "\e[31m" << *it2 << "\e[0m";
    return (ret.str());
}


int main(int ac, char ** av)
{
    std::cout << av[1] << ": ";
    std::string line1;
    std::string line2;
    std::ifstream file1;
    std::ifstream file2;
    std::stringstream output;
     int i = 0;
     int ret = 0;


    file1.open(av[2]);
    file2.open(av[3]);

    while (getline(file1,line1) && getline(file2, line2))
    {
        if (line1 == line2)
        {
            std::cout << i << ":[" << "\e[32mOK\e[0m] ";
        }
        else
        {
            std::cout << i << ":[" << "\e[31mKO\e[0m] ";
            output << i << " : \e[33m {" << "ft : [" << line1 << "] != std : [" << errorInLine(line1, line2) << "] " << "}\e[0m" << std::endl;
            ret = 1;
        }
        i++;
    }
    std::cout << std::endl;
    std::cout << output.str() << std::endl;
    file1.close();
    file2.close();
    return  (ret);
};