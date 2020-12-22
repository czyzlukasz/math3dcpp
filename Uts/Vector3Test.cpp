#include <gtest/gtest.h>
#include <Vector3.hpp>
#include <Configuration.hpp>
#include <cmath>


TEST(Vector3Test, ZeroLength){
    const Vector3d zeroVector;
    EXPECT_EQ(zeroVector.length(), 0.);
}

TEST(Vector3Test, NonZeroLength){
    const Vector3d vector3d(3., 4., 5.);
    EXPECT_DOUBLE_EQ(vector3d.length(), std::sqrt(50));
}

TEST(Vector3Test, NormalizeZeroVector){
    const Vector3d zeroVector;
    EXPECT_EQ(zeroVector.normalized(), std::nullopt);
}

TEST(Vector3Test, NormalizeNonZeroVector){
    const Vector3d vector3d(3., 1., -2.);
    const auto result = vector3d.normalized();
    ASSERT_NE(result, std::nullopt);

    const double denominator = std::sqrt(14.);
    EXPECT_DOUBLE_EQ(result->x, vector3d.x / denominator);
    EXPECT_DOUBLE_EQ(result->y, vector3d.y / denominator);
    EXPECT_DOUBLE_EQ(result->z, vector3d.z / denominator);
}

TEST(Vector3Test, AddTwoVectors){
    const Vector3d first(3., 1., -2.);
    const Vector3d second(0.5, 0, 5.);
    const Vector3d result1 = first + second;
    const Vector3d result2 = second + first;

    EXPECT_EQ(result1, result2);

    EXPECT_DOUBLE_EQ(result1.x, 3.5);
    EXPECT_DOUBLE_EQ(result1.y, 1.);
    EXPECT_DOUBLE_EQ(result1.z, 3.);
}

TEST(Vector3Test, SubTwoVectors){
    const Vector3d first(3., 1., -2.);
    const Vector3d second(0.5, 0, 5.);
    const Vector3d result1 = first - second;
    const Vector3d result2 =  -second + first;

    EXPECT_EQ(result1, result2);

    EXPECT_DOUBLE_EQ(result1.x, 2.5);
    EXPECT_DOUBLE_EQ(result1.y, 1.);
    EXPECT_DOUBLE_EQ(result1.z, -7.);
}

TEST(Vector3Test, MultiplyByScalar){
    const Vector3d vector3d(3., 1., -2.);
    const Vector3d result = vector3d * 0.75;

    EXPECT_DOUBLE_EQ(result.x, 2.25);
    EXPECT_DOUBLE_EQ(result.y, 0.75);
    EXPECT_DOUBLE_EQ(result.z, -1.5);
}
