#include <iostream> 
#include "include/eliminate_unset_bits.h" 
using namespace std; 

int main() 
{ 
    string binaryNumber; 
    cin >> binaryNumber; 
    cout << eliminate_unset_bits(binaryNumber) << endl; 

    return 0; 
}