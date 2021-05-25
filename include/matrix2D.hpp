#pragma once
#include "matrix.hpp"

typedef Matrix<double, 2> Matrix2D;

/*!
 * Tworzenie macierzy obrotu dla obrotu w 2D
 * Argumenty:
 *      angle_radian - kat obrotu w stopniach
 * Zwraca:
 *       this.
 */
 template <>
 inline void Matrix <double, 2>::MatrixRotate(const double &angle);

 #include "../src/matrix2D.cpp"