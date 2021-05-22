#pragma once
#include "vector.hpp"
#include <iostream>
#include <cstdlib>
#include "vector3D.hpp"
/*!
* \file matrix.hpp
*
*/

/*! \class Matrix
*
*/
template <typename type, unsigned int SIZE>
class Matrix
{
    private:
/*!
* \brief Tablica wartosci macieryz
*/
  type value[SIZE][SIZE];

  public:
  /*!
  * \brief Konstruktor klasy Matrix.                                                 |
  * Argumenty:                                                                |
  *     Brak argumentow.                                                      |
  *  Zwraca:                                                                   |
  *     Macierz wypelnione wartoscia 0. 
  */
      Matrix();            // Konstruktor klasy
  /*!
  * \brief Konstruktor parametryczny klasy Matrix.                                              |
  * Argumenty:                                                                |
  *    tmp - dwuwymiarowa tablica z elementami typu double.                               |
  * Zwraca:                                                                   |
  *     Macierz wypelniona wartosciami podanymi w argumencie. 
  */
    Matrix(type [SIZE][SIZE]);             // Konstruktor klasy

    /*!
    * \brief Destruktor klasy Matrix.
    * Argumenty:
    *    Brak argumentow.
    * Zwraca:
    *   Usuwa klase.
    */
    Matrix::~Matrix(){}

    /*!
    * \brief Realizuje mnozenie macierzy przez wektor.  
    * Argumenty:                                                                |
    *   this - macierz, czyli pierwszy skladnik mnozenia,                     |
    *   v - wektor, czyli drugi skladnik mnozenia.                            |
    * Zwraca:                                                                   |
    *    Iloczyn dwoch skladnikow przekazanych jako wektor.                    |
    */
     Vector<type, SIZE> operator * (Vector<type, SIZE> tmp);
    /*!
    * \brief Przeciążenie dodawania macierzy                                                          |
   * Argumenty:                                                                |
   *    this - macierz, czyli pierwszy skladnik dodawania,                     |
   *    v - wektor, czyli drugi skladnik dodawania.                                               |
   * Zwraca:                                                                   |
   *     Macierz - suma dwóch podanych macierzy.                  |
   */
  Matrix operator + (Matrix tmp);

  /*!
  * \brief Funktor macierzy                                                          |
  * Argumenty:                                                                |
  *     row - numer wiersza.                                                  |
  *     column - numer kolumny.                                               |
  * Zwraca:                                                                   |
  *    Wartosc macierzy w danym miejscu tablicy.                             |
  */
   type  &operator () (unsigned int row, unsigned int column);

   /*!
   * \brief Funktor macierzy                                                          |
   * Argumenty:                                                                |
   *     row - numer wiersza.                                                  |
   *     column - numer kolumny.                                               |
   * Zwraca:                                                                   |
   *     Wartosc macierzy w danym miejscu tablicy jako stala.                  |
   */
   const type &operator () (unsigned int row, unsigned int column) const;
   
   /*!
   * \brief Przeciążenie == macierzy                                                         
   *  Argumenty:                                                               
   *      \param[in] this - macierz, ktora porownujemy                   
   *      \param[in] tmp - macierz, z ktora porownujemy                                                          
   *  Zwraca:                                                                  
   *      \retval true - jesli sa rowne
   *      \retval false - jesli nie sa                
   */
   bool operator == (const Matrix &tmp) const;

   /*!
   *  \brief Zwraca wynik mnozenia dwoch macierzy                                                      
   *  Argumenty:                                                               
   *      \param[in] this - macierz 1 (L)
   *      \param mat - macierz 2 (P)                                                             
   *  Zwraca:                                                                  
   *      \param[out] res - wynik mnozenia macierzy               
   */

   void MatrixRotate(const type & angle);   // metoda rotacji dla macierzy 2D
    
   Matrix MatrixRotate(const type & angle, const char &axis) const;  // metoda rotacji dla macierzy 3D

   Vector<type,SIZE> rotation_of_three(const Vector<type,SIZE> &rotation) const; // metoda obrotu wektora o zadane 3 katy wokol osi x,y,z w 3D

   Matrix multiply(Matrix const &mat) const;

   /*!
   *  \brief Zwraca macierz schodkowa utworzona przez eliminacje gaussa                                                        
   *  Argumenty:                                                               
   *      \param[in] this - macierz dla ktorej chcemy przeprowadzic operacje                                                           
   *  Zwraca:                                                                  
   *      \param[out] mat - macierz schodkowa              
   */
   Matrix gauss() const;

   /*!
   *  \brief Zwraca wyznacznik macierzy                                                       
   *  Argumenty:                                                               
   *      \param[in] this - macierz, ktorej wyznacznik liczymy                                                             
   *  Zwraca:                                                                  
   *      \param[out] det - wyznacznik               
   */
   type determinant() const;

   /*!
   *  \brief Przeciazenie operatora >>                                                 |
   * Argumenty:                                                                |
   *    in - strumien wyjsciowy,                                              |
   *    mat - macierz.                                                         |
   */
   std::istream &operator >> (std::istream &in, Matrix &mat);

   /*!
   *  \brief Przeciazenie operatora <<                                                 |
   * Argumenty:                                                                |
   *    out - strumien wejsciowy,                                             |
   *     mat - macierz.                                                        |
   */
   std::ostream &operator << (std::ostream &out, Matrix const &mat);
};  
