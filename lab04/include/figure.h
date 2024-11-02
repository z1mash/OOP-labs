#pragma once
#include <iostream>
#include <vector>
#include <concepts>
#include <memory>
#include "point.h"

template <Scalar T>
class Figure 
{
protected:
    std::vector<std::unique_ptr<Point<T>>> points;

public:
    Figure() noexcept = default;
    virtual ~Figure() = default;

    virtual std::pair<T, T> center() const = 0;
    virtual double f_square() const = 0;
    virtual operator double() const = 0;

    friend std::ostream& operator << (std::ostream& out, const Figure<T>& other)
    {
        for (const auto& point : other.points) 
        {
            out << *point << std::endl;
        }
        return out;
    }

    virtual bool operator == (const Figure<T>& other) const
    {
        if (points.size() != other.points.size()) return false;
        for (size_t i = 0; i < points.size(); ++i) {
            if (*points[i] != *other.points[i]) {
                return false;
            }
        }
        return true;
    }
};