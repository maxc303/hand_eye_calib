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

        v.block<3, 1>(3 * i, 0) = k_r_a - k_r_b;
        S.block<3, 3>(3 * i, 0) = skew(k_r_a + k_r_b);
        // std::cout << r_a << std::endl;
        // std::cout << r_a.log() << std::endl;
        // std::cout << vee(r_a.log()) << std::endl;
    }

    std::cout << S << std::endl;
    std::cout << v << std::endl;

    Eigen::Vector3d k_r_prime = S.bdcSvd(Eigen::ComputeThinU | Eigen::ComputeThinV).solve(v);
    std::cout << k_r_prime << std::endl;
    std::cout << skew(k_r_prime).exp() << std::endl;
    return Eigen::Matrix3d::Identity();
}