#include <iostream>
#include <eigen3/Eigen/Core>

Eigen::Matrix3d skew(Eigen::Vector3d vec)
{
    Eigen::Matrix3d mtx;
    mtx << 0, -vec(2, 0), vec(1, 0), //
        vec(2, 0), 0, -vec(0, 0),    //
        -vec(1, 0), vec(0, 0), 0;
    return mtx;
}

Eigen::Vector3d vee(Eigen::Matrix3d mtx)
{
    Eigen::Vector3d vec;
    vec << mtx(2, 1), mtx(0, 2), mtx(1, 0);
    return vec;
}