#include"../include/matrix3D.hpp"

template<>
inline Matrix<double, 3> Matrix<double, 3>::MatrixRotate(const double &angle, const char &axis) const
{
    double angle_radian = angle * M_PI/180;    
    switch(axis){
        case 'x' :
        {
            double t[3][3] = {{1, 0, 0},{0, cos(angle_radian), -sin(angle_radian)},{0, sin(angle_radian), cos(angle_radian)}};
            Matrix3D rotate(t);
            return rotate;
            break;
        }
        case 'y' :
        {
            double t[3][3] = {{cos(angle_radian), 0, sin(angle_radian)},{0, 1, 0},{-sin(angle_radian),0, cos(angle_radian)}};
            Matrix3D rotate(t);
            return rotate;
            break;
        }
        case 'z' :
        {
            double t[3][3] = {{cos(angle_radian), -sin(angle_radian), 0},{sin(angle_radian), cos(angle_radian), 0},{0,0, 1}};
            Matrix3D rotate(t);
            return rotate;
            break;
        }
        default:
        {
            Matrix3D rotation;
            return rotation;
            break;
        }
    }
}

template <>
inline Vector<double, 3> Matrix<double, 3>::rotation_of_three(const Vector<double,3> &vect_rot) const
{
    Matrix3D m = *this;
    Vector3D tmp;

    tmp = m * vect_rot;
    return tmp;
}