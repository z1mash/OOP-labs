#include <gtest/gtest.h>
#include "../include/point.h"
#include "../include/triangle.h"
#include "../include/octagon.h"
#include "../include/square.h"
#include "../include/array.h"

// Тесты для класса Point
TEST(PointTest, Comparison) {
    Point<double> p1(1.0, 2.0);
    Point<double> p2(1.0, 2.0);
    Point<double> p3(2.0, 3.0);

    EXPECT_EQ(p1, p2);
    EXPECT_NE(p1, p3);
}

TEST(PointTest, Output) {
    Point<double> p(1.0, 2.0);
    std::ostringstream oss;
    oss << p;
    EXPECT_EQ(oss.str(), "(1, 2)");
}

TEST(PointTest, Input) {
    Point<double> p;
    std::istringstream iss("3.0 4.0");
    iss >> p;
    EXPECT_EQ(p, Point<double>(3.0, 4.0));
}

// Тесты для класса Triangle
TEST(TriangleTest, AreaCalculation) {
    Triangle<double> triangle(5.0);
    EXPECT_DOUBLE_EQ(triangle.f_square(), 10.825317547305483);
}

TEST(TriangleTest, CenterCalculation) {
    Triangle<double> triangle(5.0);
    auto center = triangle.center();
    EXPECT_DOUBLE_EQ(center.first, 2.5);
    EXPECT_DOUBLE_EQ(center.second, 1.4433756729740645);
}

TEST(TriangleTest, Comparison) {
    Triangle<double> t1(5.0);
    Triangle<double> t2(5.0);
    Triangle<double> t3(6.0);

    EXPECT_EQ(t1, t2);
    EXPECT_NE(t1, t3);
}

// Тесты для класса Square
TEST(SquareTest, AreaCalculation) {
    Square<double> square(4.0);
    EXPECT_DOUBLE_EQ(square.f_square(), 16.0);
}

TEST(SquareTest, CenterCalculation) {
    Square<double> square(4.0);
    auto center = square.center();
    EXPECT_DOUBLE_EQ(center.first, 2.0);
    EXPECT_DOUBLE_EQ(center.second, 2.0);
}

TEST(SquareTest, Comparison) {
    Square<double> s1(4.0);
    Square<double> s2(4.0);
    Square<double> s3(5.0);

    EXPECT_EQ(s1, s2);
    EXPECT_NE(s1, s3);
}

// Тесты для класса Array
TEST(ArrayTest, PushBackAndAccess) {
    Array<std::shared_ptr<Figure<double>>> arr;
    arr.push_back(std::make_shared<Square<double>>(4.0));
    arr.push_back(std::make_shared<Triangle<double>>(5.0));

    EXPECT_DOUBLE_EQ(static_cast<double>(*arr[0]), 16.0);
    EXPECT_DOUBLE_EQ(static_cast<double>(*arr[1]), 10.825317547305483);
}

TEST(ArrayTest, RemoveElement) {
    Array<std::shared_ptr<Figure<double>>> arr;
    arr.push_back(std::make_shared<Square<double>>(4.0));
    arr.push_back(std::make_shared<Triangle<double>>(5.0));

    arr.remove(1);

    EXPECT_DOUBLE_EQ(static_cast<double>(*arr[0]), 16.0);
    EXPECT_EQ(arr.get_size(), 1);
}

TEST(ArrayTest, TotalArea) {
    Array<std::shared_ptr<Figure<double>>> arr;
    arr.push_back(std::make_shared<Square<double>>(4.0));
    arr.push_back(std::make_shared<Triangle<double>>(5.0));

    EXPECT_DOUBLE_EQ(arr.totalArea(), 26.825317547305483);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}