#include <iostream>
#include <iomanip>
#include "Array.hpp"
#include <cstdlib>
#include <cmath>

#define MAX_VAL 750
int main(int, char**)
{
    std::cout << "--- provided main ---" << std::endl << std::endl;    
    
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//
    std::cout << std::endl;

    std::cout << "--- personnal tests ---" << std::endl;
    std::cout << std::endl;

    std::cout << ">> Empty array and wrong access:" << std::endl;
    Array<int> empty;
    try { std::cout << empty[0] << std::endl; }
    catch (const std::exception& e)
    {
        std::cerr << "empty[0] = "<< e.what() << " --> out of range"<< std::endl;
    }
    std::cout << std::endl;

    std::cout << ">> Array of size 12:" << std::endl;
    Array<char> helloworld(12);
    std::string hw = "hello world!";
    for (int i = 0; i < 12; i++)
        helloworld[i] = hw.at(i);
    for (int i = 0; i < 12; i++)    
        std::cout << helloworld[i];        
    std::cout << std::endl << std::endl;

    std::cout << ">> Constructor by assignment (titi = toto ?):" << std::endl;
    Array<double> toto(4);
    for (int i = 0; i < 4; i++)
        toto[i] = tan(i);
    Array<double> titi = toto;
    for (int i = 0; i < 4; i++)
    {
        std::cout << "toto[" << i << "] = " << toto[i] << std::endl;
        std::cout << "titi[" << i << "] = " << titi[i] << std::endl;
    }    
    std::cout << std::endl;

    std::cout << ">> Constructor by copy (tata = toto ?) and access with const array:" << std::endl;
    const Array<double> tata(toto);
    for (int i = 0; i < 4; i++)
    {
        std::cout << "toto[" << i << "] = " << toto[i] << std::endl;
        std::cout << "tata[" << i << "] = " << tata[i] << std::endl;
    }    
    std::cout << std::endl;

    return 0;
}
