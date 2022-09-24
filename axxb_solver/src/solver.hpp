#ifndef AXXB_SOLVER__SOLVER_HPP_
#define AXXB_SOLVER__SOLVER_HPP_

#include <eigen3/Eigen/Core>
#include <unsupported/Eigen/MatrixFunctions>
#include <vector>
#include <iostream>
#include "utils.hpp"
Eigen::Matrix3d solve_r(const std::vector<Eigen::Matrix4d> &T_a, const std::vector<Eigen::Matrix4d> &T_b);

#endif // AXXB_SOLVER__SOLVER_HPP_