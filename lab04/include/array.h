#pragma once
#include <iostream>
#include <memory>

template <class T>
class Array 
{
private:
    std::shared_ptr<T[]> arr;
    size_t _size;
    size_t _capacity;

public:
    Array() 
    {
        _capacity = 1;
        arr = std::shared_ptr<T[]>(new T[_capacity]);
        _size = 0;
    }

    Array(size_t len) 
    {
        _capacity = len;
        arr = std::shared_ptr<T[]>(new T[_capacity]);
        _size = 0;
    }

    ~Array() 
    {
        _size = 0;
        _capacity = 0;
    }

    void push_back(T elem) 
    {
        if (_size == _capacity) {
            resize(_capacity * 2);
        }
        arr[_size++] = std::move(elem);
    }

    void pop_back() 
    {
        if (_size > 0) {
            --_size;
        }
    }

    T& operator[](size_t ind) const
    {
        if (ind >= _size) throw std::invalid_argument("Attempt to process a non-exist object.");
        return arr[ind];
    }

    size_t get_size() const 
    {
        return _size;
    }

    void resize(size_t new_capacity) 
    {
        std::shared_ptr<T[]> new_arr(new T[new_capacity]);
        for (size_t i = 0; i < _size; ++i) {
            new_arr[i] = std::move(arr[i]);
        }
        arr = std::move(new_arr);
        _capacity = new_capacity;
    }

    void remove(size_t index) 
    {
        if (index >= _size) throw std::invalid_argument("Index out of range.");
        for (size_t i = index; i < _size - 1; ++i) {
            arr[i] = std::move(arr[i + 1]);
        }
        --_size;
    }

    double totalArea() const 
    {
        double total = 0.0;
        for (size_t i = 0; i < _size; ++i) {
            total += static_cast<double>(*arr[i]);
        }
        return total;
    }
};