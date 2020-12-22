#include <gtest/gtest.h>
#include <Quaternion.hpp>
#include <Vector3.hpp>
#include <math.h>

using Vector3 = Vector3Impl<double>;
using Quaterniond = Quaternion<double>;

TEST(QuaternionTest, EulerAnglesToQuaternionAndBack){
    const Vector3 eulerAngles(10, 20, 30);
    Quaterniond quaternion(eulerAngles);
    const Vector3 result = quaternion.toEulerAngles();

    EXPECT_NEAR(result.x, eulerAngles.x, 1e-6);
    EXPECT_NEAR(result.y, eulerAngles.y, 1e-6);
    EXPECT_NEAR(result.z, eulerAngles.z, 1e-6);
}

TEST(QuaternionTest, EulerAnglesToQuaternionAndBackZeroAngle){
    const Vector3 eulerAngles;
    Quaterniond quaternion(eulerAngles);
    const Vector3 result = quaternion.toEulerAngles();

    EXPECT_NEAR(result.x, eulerAngles.x, 1e-6);
    EXPECT_NEAR(result.y, eulerAngles.y, 1e-6);
    EXPECT_NEAR(result.z, eulerAngles.z, 1e-6);
}

TEST(QuaternionTest, EulerAnglesToQuaternionAndBackRollAlmost90Degrees){
    const Vector3 eulerAngles(89.9, 35, -12);
    Quaterniond quaternion(eulerAngles);
    const Vector3 result = quaternion.toEulerAngles();

    EXPECT_NEAR(result.x, eulerAngles.x, 1e-6);
    EXPECT_NEAR(result.y, eulerAngles.y, 1e-6);
    EXPECT_NEAR(result.z, eulerAngles.z, 1e-6);
}

TEST(QuaternionTest, EulerAnglesToQuaternionAndBackPitchAlmost90Degrees){
    const Vector3 eulerAngles(35, 89.9, -12);
    Quaterniond quaternion(eulerAngles);
    const Vector3 result = quaternion.toEulerAngles();

    EXPECT_NEAR(result.x, eulerAngles.x, 1e-6);
    EXPECT_NEAR(result.y, eulerAngles.y, 1e-6);
    EXPECT_NEAR(result.z, eulerAngles.z, 1e-6);
}

TEST(QuaternionTest, EulerAnglesToQuaternionAndBackYawAlmost90Degrees){
    const Vector3 eulerAngles(35, -12, 89.9);
    Quaterniond quaternion(eulerAngles);
    const Vector3 result = quaternion.toEulerAngles();

    EXPECT_NEAR(result.x, eulerAngles.x, 1e-6);
    EXPECT_NEAR(result.y, eulerAngles.y, 1e-6);
    EXPECT_NEAR(result.z, eulerAngles.z, 1e-6);
}

TEST(QuaternionTest, EulerAnglesToQuaternionAndBackAllAnglesAlmost90Degrees){
    const Vector3 eulerAngles(89.9, 89.9, 89.9);
    Quaterniond quaternion(eulerAngles);
    const Vector3 result = quaternion.toEulerAngles();

    EXPECT_NEAR(result.x, eulerAngles.x, 1e-6);
    EXPECT_NEAR(result.y, eulerAngles.y, 1e-6);
    EXPECT_NEAR(result.z, eulerAngles.z, 1e-6);
}
