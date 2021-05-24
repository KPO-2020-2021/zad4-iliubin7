#include "../include/vector2D.hpp"

template <>
/*inline*/ Vector<double,2> Vector<double, 2>::rotation(const double &angle) const
{
    Vector2D rotated;
    Matrix2D transformation;
    transformation.MatrixRotate(angle);
    rotated = transformation * *this;
    return rotated;
}
