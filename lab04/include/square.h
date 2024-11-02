#pragma once
#include <iostream>
#include <cmath>
#include "figure.h"

template <Scalar T>
class Square : public Figure<T> 
{
private:
    using Figure<T>::points;

public:
    Square() noexcept
    {
        points.resize(4);
        for (auto& point : points) {
            point = std::make_unique<Point<T>>();
        }
    }

    Square(const T& len)
    {
        points.resize(4);
        points[0] = std::make_unique<Point<T>>(0, 0);
        points[1] = std::make_unique<Point<T>>(len, 0);
        points[2] = std::make_unique<Point<T>>(len, len);
        points[3] = std::make_unique<Point<T>>(0, len);
    }

    Square(const Square<T>& other)
    {
        points.resize(4);
        for (size_t i = 0; i < 4; ++i) {
            points[i] = std::make_unique<Point<T>>(other.points[i]->x, other.points[i]->y);
        }
    }

    ~Square() = default;

    std::pair<T, T> center() const override
    {
        return {points[1]->x / 2, points[1]->x / 2};
    }

    double f_square() const override
    {
        return points[1]->x * points[1]->x;
    }

    operator double() const override
    {
        return f_square();
    }

    friend std::istream& operator >> (std::istream& cin, Square<T>& other)
    {
        T length;
        cin >> length;
        other = Square<T>(length);
        return cin;
    }

    using Figure<T>::operator == ;

    Square<T>& operator = (const Square<T>& other) noexcept
    {
        if (this != &other) {
            for (size_t i = 0; i < 4; ++i) {
                points[i] = std::make_unique<Point<T>>(other.points[i]->x, other.points[i]->y);
            }
        }
        return *this;
    }

    Square<T>& operator = (Square<T>&& other) noexcept
    {
        if (this != &other) {
            points = std::move(other.points);
        }
        return *this;
    }
};