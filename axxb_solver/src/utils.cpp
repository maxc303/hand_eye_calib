#include "utils.hpp"

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

Eigen::Matrix4d inverse(Eigen::Matrix4d mtx)
{
    Eigen::Matrix4d mtx_inv = Eigen::Matrix4d::Identity();
    mtx_inv.block<3, 3>(0, 0) = mtx.block<3, 3>(0, 0).transpose();
    mtx_inv.block<3, 1>(0, 3) = -mtx.block<3, 3>(0, 0).transpose() * mtx.block<3, 1>(0, 3);
    return mtx_inv;
}