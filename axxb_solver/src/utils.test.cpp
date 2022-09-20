#define CATCH_CONFIG_MAIN
#include <catch2/catch_all.hpp>
#include "utils.hpp"

TEST_CASE("Skew vector", "[unit]")
{
    SECTION("Zero value") { CHECK(skew(Eigen::Vector3d::Zero()) == Eigen::Matrix3d::Zero()); }
    SECTION("Random values")
    {
        Eigen::Vector3d vec;
        vec << 1.0, 2.0, 3.0;
        Eigen::Matrix3d m_expect;
        m_expect << 0.0, -3.0, 2.0, //
            3.0, 0.0, -1.0,         //
            -2.0, 1.0, 0.0;
        CHECK(skew(vec) == m_expect);
    }
}

TEST_CASE("Inverse skew ", "[unit]")
{
    SECTION("Zero value") { CHECK(vee(skew(Eigen::Vector3d::Zero())) == Eigen::Vector3d::Zero()); }
    SECTION("Random values")
    {
        Eigen::Vector3d vec;
        vec << 1.0, 2.0, 3.0;
        CHECK(vec == vee(skew(vec)));
    }
}