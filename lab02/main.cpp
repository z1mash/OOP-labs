#include <iostream>
#include "include/seven.h"
 
int main()
{
    try
    {
        std::string value1, value2;
        char op;
        std::cout << "Enter an expression like: <value operator value> (separated by a space)" << std::endl;
        std::cin >> value1 >> op >> value2; 
        Seven number1 = Seven(value1), number2 = Seven(value2);
        switch (op)
        {
            case '+':
                std::cout << (number1 + number2).to_string() << std::endl;
                break;
            case '-':
                std::cout << (number1 - number2).to_string() << std::endl;
                break; 
            case '>':
                std::cout << (number1 > number2) << std::endl;
                break;
            case '<':
                std::cout << (number1 < number2) << std::endl;
                break;
            case '=':
                std::cout << (number1 == number2) << std::endl;
                break;
            default:
                std::cout << "Incorrect expression" << std::endl;
                break;
        }
    }
    catch (const std::invalid_argument& error) // what() - вывод ошибки в виде строки
    {
        std::cout << "Invalid argument: " << error.what() << std::endl;
    }
    catch(const std::underflow_error& error)
    {
        std::cout << "Underflow error: " << error.what() << std::endl;
    }
 
    return 0;
}