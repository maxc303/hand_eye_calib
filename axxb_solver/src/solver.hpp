#include <eigen3/Eigen/Core>
#include <unsupported/Eigen/MatrixFunctions>
#include <vector>
#include <iostream>
#include "utils.hpp"
Eigen::Matrix3d solve_r(const std::vector<Eigen::Matrix4d> &T_a, const std::vector<Eigen::Matrix4d> &T_b)
{

    if (T_a.size() != T_b.size())
    {
        return Eigen::Matrix3d::Identity();
    }

    Eigen::MatrixXd S(T_a.size() * 3, 3);
    Eigen::VectorXd v(T_a.size() * 3);

    for (int i = 0; i < T_a.size(); i++)
    {
        Eigen::Matrix3d r_a = T_a[i].block<3, 3>(0, 0);
        Eigen::Matrix3d r_b = T_b[i].block<3, 3>(0, 0);

        Eigen::Vector3d k_r_a = vee(r_a.log());
        Eigen::Vector3d k_r_b = vee(r_b.log());

        k_r_a = k_r_a / k_r_a.norm();
        k_r_b = k_r_b / k_r_b.norm();

        S.block<3, 3>(3 * i, 0) = skew(k_r_a + k_r_b);
        v.block<3, 1>(3 * i, 0) = k_r_a - k_r_b;
    }

    std::cout << S << std::endl;
    std::cout << v << std::endl;

    Eigen::Vector3d k_r_prime = S.bdcSvd(Eigen::ComputeThinU | Eigen::ComputeThinV).solve(v);

    double theta = 2 * std::atan(k_r_prime.norm());

    Eigen::Vector3d k_r_axis = k_r_prime / k_r_prime.norm();
    // std::cout << (Eigen::Matrix3d::Identity() * std::cos(theta) + std::sin(theta) * skew(k_r_axis) + (1 - std::cos(theta)) * k_r_axis * k_r_axis.transpose()).transpose() << std::endl;
    return (skew(k_r_axis) * theta).exp().transpose();
}