#pragma once
#include <iostream>
#include <cmath>
#include "figure.h"

template <Scalar T>
class Octagon : public Figure<T> 
{
private:
    using Figure<T>::points;

public:
    Octagon() noexcept
    {
        points.resize(8);
        for (auto& point : points) {
            point = std::make_unique<Point<T>>();
        }
    }

    Octagon(const double& len)
    {
        points.resize(8);
        double angle = 0;
        for (size_t i = 0; i < 8; ++i) {
            points[i] = std::make_unique<Point<T>>(len * std::cos(angle), len * std::sin(angle));
            angle += M_PI / 4;
        }
    }

    Octagon(const Octagon<T>& other)
    {
        points.resize(8);
        for (size_t i = 0; i < 8; ++i) {
            points[i] = std::make_unique<Point<T>>(other.points[i]->x, other.points[i]->y);
        }
    }

    ~Octagon() = default;

    std::pair<T, T> center() const override
    {
        T sumX = 0, sumY = 0;
        for (const auto& point : points) {
            sumX += point->x;
            sumY += point->y;
        }
        return {sumX / 8, sumY / 8};
    }

    double f_square() const override
    {
        // Исправленная формула для вычисления площади восьмиугольника
        double side = points[1]->x;
        return 2 * std::pow(side, 2) * (1 + std::sqrt(2));
    }

    operator double() const override
    {
        return f_square();
    }

    friend std::istream& operator >> (std::istream& cin, Octagon<T>& other)
    {
        T length;
        cin >> length;
        other = Octagon<T>(length);
        return cin;
    }

    using Figure<T>::operator == ;

    Octagon<T>& operator = (const Octagon<T>& other) noexcept
    {
        if (this != &other) {
            for (size_t i = 0; i < 8; ++i) {
                points[i] = std::make_unique<Point<T>>(other.points[i]->x, other.points[i]->y);
            }
        }
        return *this;
    }

    Octagon<T>& operator = (Octagon<T>&& other) noexcept
    {
        if (this != &other) {
            points = std::move(other.points);
        }
        return *this;
    }
};