#include "../include/matrix2D.hpp"

template <>
inline void Matrix<double, 2>::MatrixRotate(const double &angle)
{
    double angle_radian = angle * M_PI / 180;
    double tmp[][2] = {{cos(angle_radian), -sin(angle_radian)}, {sin(angle_radian), cos(angle_radian)}};
    Matrix2D transformation(tmp);
    *this = transformation;
}