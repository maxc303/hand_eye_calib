#ifndef AXXB_SOLVER__UTILS_HPP_
#define AXXB_SOLVER__UTILS_HPP_
#include <iostream>
#include <eigen3/Eigen/Core>

Eigen::Matrix3d skew(Eigen::Vector3d vec);

Eigen::Vector3d vee(Eigen::Matrix3d mtx);

Eigen::Matrix4d inverse(Eigen::Matrix4d mtx);

#endif // AXXB_SOLVER__UTILS_HPP_