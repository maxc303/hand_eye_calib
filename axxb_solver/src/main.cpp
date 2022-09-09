
#include <iostream>
#include <eigen3/Eigen/Core>

int main()
{
    Eigen::Vector4f mtx;
    mtx << 1.0f, 2.0f, 3.0f, 4.0f;
    std::cout << "Test main" << mtx << std::endl;
}