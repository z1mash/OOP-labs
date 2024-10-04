#include "../include/seven.h"
#include <iostream>
 
// Resize

void Seven::resize_arr(const size_t size) 
{
    unsigned char* new_s_array = new unsigned char[size];
    std::memcpy(new_s_array, s_array, size * sizeof(unsigned char));
    s_size = size;
    delete [] s_array;
    s_array = new_s_array;
}

// Constructors
 
Seven::Seven() 
{
    s_array = new unsigned char;
    *s_array = {'0'};
    s_size = 1;
}
 
Seven::Seven(const size_t & n, unsigned char t = '0')
{
    if ((t > 54) || (t < 48)) throw std::invalid_argument("Character not from the working alphabet has been entered");
    s_array = new unsigned char [n];
    s_size = n;
    for (int i = 0; i < s_size; ++i) s_array[i] = t;
}
 
Seven::Seven(const std::initializer_list<unsigned char> &t)
{
    s_array = new unsigned char[t.size()];
    s_size = t.size();
    int i = t.size() - 1;
 
    for (unsigned char elem : t)
    {
        if ((elem > 54) || (elem < 48)) throw std::invalid_argument("Character not from the working alphabet has been entered");
 
        s_array[i--] = elem;
    }
}
 
Seven::Seven(const std::string &t)
{
    s_array = new unsigned char[t.size()];
    s_size = t.size();
    int i = t.size() - 1;

    for (unsigned char elem : t)
    {
        if ((elem < 48) || (elem > 54)) throw std::invalid_argument("Character not from the working alphabet has been entered");
 
        s_array[i--] = elem;
    }
}
 
Seven::Seven(const Seven& other)
{
    s_array = new unsigned char[other.s_size];
    std::memcpy(s_array, other.s_array, other.s_size);
    s_size = other.s_size;
}
 
Seven::Seven(Seven&& other) noexcept
{
    s_array = other.s_array;
    s_size = other.s_size;
}
 
Seven::~Seven() noexcept 
{

}
 
// Operations
 
Seven Seven::operator + (const Seven& other)
{
    size_t size_f, size_s;
    
    if (s_size < other.s_size) 
    {
        size_f = other.s_size;
        size_s = s_size;
    }
    else
    {
        size_f = s_size;
        size_s = other.s_size;
    }
 
    Seven result = Seven(size_f, '0');
    int i_val = 0; 
    int i_position = 0, remnant = 0;
    for (int i = 0; i < size_s; ++i)
    {
        i_val = ((s_array)[i] - 48) + ((other.s_array)[i] - 48) + remnant;
        remnant = i_val / 7;
        i_position = i_val % 7;
        result.s_array[i] = i_position + 48;
    }
    
    for (int i = size_s; i < size_f; ++i)
    {
        i_val = (((s_size < other.s_size) ? other.s_array : s_array)[i] - 48) + remnant;
        remnant = i_val / 7;
        i_position = i_val % 7;
        result.s_array[i] = i_position + 48;
    }
    
    if (remnant > 0)
    {
        result.resize_arr(size_f + 1);
        result.s_array[result.s_size - 1] = remnant + 48;
    }
 
    return result;
}
 
Seven Seven::operator - (const Seven& other)
{
    Seven result = *this;
 
    if (result < other) throw std::underflow_error("A negative value will be received");
 
    int remnant = 0;
    int i_val = 0;

    for (int i = 0; i < other.s_size; ++i)
    {
        i_val = (s_array[i] - 48) - (other.s_array[i] - 48) - remnant;
        result.s_array[i] = ((i_val % 7 + 7) % 7) + 48;
        remnant = i_val < 0 ? 1 : 0;
    }

    size_t j = other.s_size;
    while (remnant == 1)
    {
        i_val = (s_array[j] - 48) - remnant;
        result.s_array[j] = ((i_val % 7 + 7) % 7) + 48;
        remnant = i_val < 0 ? 1 : 0;
        j++;
    }
    
    int pop_back = 0;

    for (int i = result.s_size - 1; i > 0; --i)
    {
        if (result.s_array[i] == '0') 
            ++pop_back;
        else
            break;
    }

    result.resize_arr(result.s_size - pop_back);
    return result;
}
 
Seven Seven::operator = (const Seven& other)
{
    resize_arr(other.s_size);
    for (int i = 0; i < s_size; ++i)
        s_array[i] = other.s_array[i];
        
    return *this;
}
 
bool Seven::operator < (const Seven& other)
{
    if (s_size < other.s_size)  return true;
 
    if (s_size > other.s_size)  return false;
 
    for (int i = s_size - 1; i >= 0; --i) 
    {
        if (s_array[i] < other.s_array[i])  return true;
 
        if (s_array[i] > other.s_array[i])  return false;
    }
 
    return false;
}
 
bool Seven::operator > (const Seven& other)
{
    if (s_size > other.s_size)  return true;
 
    if (s_size < other.s_size)  return false;
 
    for (int i = s_size - 1; i >= 0; --i) 
    {
        if (s_array[i] > other.s_array[i])  return true;
 
        if (s_array[i] < other.s_array[i])  return false;
    }
 
    return false;
}
 
bool Seven::operator == (const Seven& other)
{
    if (s_size != other.s_size) return false;
 
    for (int i = s_size - 1; i >= 0; --i) 
    {
        if (s_array[i] != other.s_array[i]) return false;
    }
 
    return true;
}
 
// To string

std::string Seven::to_string() const
{
    std::string result;
    for (int i = s_size - 1; i >= 0; --i)
        result += s_array[i];

    return result;
}