#pragma once

#include "matrix.hpp"
#include "vector3D.hpp"


typedef Matrix<double, 3> Matrix3D;

/*!
 * Tworzenie macierzy obrotu dla obrotu w 3D
 * Argumenty:
 *          angle - kat obrotu (podany w stopniach)
 *          axis - os obrotu wybrana przez uzytkownika (x, y lub z)
 * Zwraca:
 *          rotated - macierz obrotu 
 */
  template <>
  /*inline*/ Matrix<double,3> Matrix<double, 3>::MatrixRotate(const double &angle, const char &axis) const;

  /*!
 * \brief Obrot wektora o zadane 3 katy wokol osi x,y,z w 3D             
 * Argumenty:                                                                
 *      vect_rot - Vector3D ktory chcemy obrocic                               
 * Zwraca:                                                                   
 *      rotated - obrocony wektor                                                      
 */
  template <>
  /*inline*/ Vector<double, 3> Matrix<double, 3>::rotation_of_three(const Vector<double,3> &vect_rot) const;

  
  
