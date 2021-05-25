#pragma once

#include "vector.hpp"
#include "matrix2D.hpp"


typedef Vector<double, 2> Vector2D;

/*!
* \brief Metoda rotacji wektora wokol srodka ukladu wspolrzednych
* Argmunety:
*  angle - kat obrotu (podany w stopniach)
* Zwraca:
*      rotated - obrocony wektor
*/
template < >
inline Vector<double, 2> Vector<double, 2>::rotation(const double &angle) const;

#include "../src/vector2D.cpp"