#include <iostream> 
#include "include/eliminate_unset_bits.h" 

int main() 
{ 
    std::string binaryNumber; 
    std::cin >> binaryNumber; 
    std::cout << eliminate_unset_bits(binaryNumber) << std::endl; 

    return 0; 
}