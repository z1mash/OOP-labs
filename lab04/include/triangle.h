#pragma once
#include <iostream>
#include <cmath>
#include "figure.h"

template <Scalar T>
class Triangle : public Figure<T> 
{
private:
    using Figure<T>::points;

public:
    Triangle() noexcept
    {
        points.resize(3);
        for (auto& point : points) {
            point = std::make_unique<Point<T>>();
        }
    }

    Triangle(const double& len)
    {
        points.resize(3);
        points[0] = std::make_unique<Point<T>>(0, 0);
        points[1] = std::make_unique<Point<T>>(len, 0);
        points[2] = std::make_unique<Point<T>>(len / 2, len * std::sqrt(3) / 2);
    }

    Triangle(const Triangle<T>& other)
    {
        points.resize(3);
        for (size_t i = 0; i < 3; ++i) {
            points[i] = std::make_unique<Point<T>>(other.points[i]->x, other.points[i]->y);
        }
    }

    ~Triangle() = default;

    std::pair<T, T> center() const override
    {
        T sumX = 0, sumY = 0;
        for (const auto& point : points) {
            sumX += point->x;
            sumY += point->y;
        }
        return {sumX / 3, sumY / 3};
    }

    double f_square() const override
    {
        T a = points[1]->x - points[0]->x;
        T h = points[2]->y;
        return a * h / 2;
    }

    operator double() const override
    {
        return f_square();
    }

    friend std::istream& operator >> (std::istream& cin, Triangle<T>& other)
    {
        T length;
        cin >> length;
        other = Triangle<T>(length);
        return cin;
    }

    using Figure<T>::operator == ;

    Triangle<T>& operator = (const Triangle<T>& other) noexcept
    {
        if (this != &other) {
            for (size_t i = 0; i < 3; ++i) {
                points[i] = std::make_unique<Point<T>>(other.points[i]->x, other.points[i]->y);
            }
        }
        return *this;
    }

    Triangle<T>& operator = (Triangle<T>&& other) noexcept
    {
        if (this != &other) {
            points = std::move(other.points);
        }
        return *this;
    }
};