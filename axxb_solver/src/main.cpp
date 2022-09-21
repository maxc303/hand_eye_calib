
#include <iostream>
#include <eigen3/Eigen/Core>
#include "solver.hpp"
int main()
{
    Eigen::Vector4f mtx;
    mtx << 1.0f, 2.0f, 3.0f, 4.0f;
    std::cout << "Test main" << mtx << std::endl;

    std::vector<Eigen::Matrix4d> T_a, T_b;

    Eigen::Matrix4d A_last;
    A_last << 1, 0, 0, 0,
        0, 1, 0, 0,
        0, 0, 1, 0,
        0, 0, 0, 1;

    // Ground truth
    Eigen::Matrix4d T_a_b;
    // T_a_b << 1 / sqrt(2), -1 / sqrt(2), 0, 1,
    //     1 / sqrt(2), 1 / sqrt(2), 0, 1,
    //     0, 0, 1, 1,
    //     0, 0, 0, 1;

    T_a_b << 0.7071068, -0.7071068, 0.0000000, 1,
        0.7044160, 0.7044160, -0.0871557, 1,
        0.0616284, 0.0616284, 0.9961947, 1,
        0, 0, 0, 1;

    Eigen::Matrix4d B_last = A_last * T_a_b;
    for (int i = 0; i < 10; i++)
    {
        Eigen::Matrix4d T_a_i = Eigen::Matrix4d::Zero();
        T_a_i.block<3, 3>(0, 0) = Eigen::AngleAxisd((i + 1) / 30.0 * M_PI, Eigen::Vector3d::UnitZ()).matrix() * Eigen::AngleAxisd((i + 1) / 20.0 * M_PI, Eigen::Vector3d::UnitY()).matrix();

        T_a_i(0, 3) = 1;
        T_a_i(1, 3) = 1;
        T_a_i(2, 3) = 1;
        T_a_i(3, 3) = 1;

        Eigen::Matrix4d A_i = A_last * T_a_i;
        Eigen::Matrix4d B_i = A_i * T_a_b;

        // std::cout << "T_a_i " << std::endl
        //           << T_a_i << std::endl;
        // std::cout << "T_b_i " << std::endl
        //           << inverse(B_last) * B_i << std::endl;

        T_a.push_back(T_a_i);
        T_b.push_back(inverse(B_last) * B_i);

        A_last = A_i;
        B_last = B_i;
    }
    std::cout << solve_r(T_a, T_b) << std::endl;
}