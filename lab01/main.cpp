#include <iostream> 
#include "include/eliminate_unset_bits.h" 
using namespace std; 

int main() 
{ 
    string BinNumber; 
    cin >> BinNumber; 
    cout << eliminate_unset_bits(BinNumber) << endl; 

    return 0; 
}