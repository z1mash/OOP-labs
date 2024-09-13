#include "../include/eliminate_unset_bits.h" 
#include <cmath>
using namespace std; 

long eliminate_unset_bits(string binaryNumber) 
{ 
    string filteredBinaryNumber = ""; 
    for (int i = 0; i < binaryNumber.size(); ++i) 
    { 
        if (binaryNumber[i] == '1') filteredBinaryNumber += binaryNumber[i]; 
    } 

    if (filteredBinaryNumber.size() == 0) 
        return 0; 
    else 
    { 
        long decimalNumber; 
        decimalNumber = pow(2, filteredBinaryNumber.size()) - 1; 
        return decimalNumber; 
    } 
}