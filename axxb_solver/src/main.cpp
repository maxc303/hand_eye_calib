
#include <iostream>
#include <eigen3/Eigen/Core>
#include "solver.hpp"
int main()
{
    Eigen::Vector4f mtx;
    mtx << 1.0f, 2.0f, 3.0f, 4.0f;
    std::cout << "Test main" << mtx << std::endl;

    std::vector<Eigen::Matrix4d> T_a, T_b;
    Eigen::Matrix4d M_a;
    M_a << 1 / sqrt(2), -1 / sqrt(2), 0, 0,
        1 / sqrt(2), 1 / sqrt(2), 0, 0,
        0, 0, 1, 0,
        0, 0, 1, 1;
        
    Eigen::Matrix4d M_b = M_a;
    T_a.push_back(M_a);
    T_a.push_back(M_a);

    T_b.push_back(M_b);
    T_b.push_back(M_b);

    solve_r(T_a, T_b);
}