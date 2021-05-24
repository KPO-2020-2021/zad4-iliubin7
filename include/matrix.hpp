#pragma once
#include "vector.hpp"
#include <iostream>
#include <cstdlib>

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
    ~Matrix();

    /*!
    * \brief Realizuje mnozenie macierzy przez wektor.  
    * Argumenty:                                                                |
    *   this - macierz, czyli pierwszy skladnik mnozenia,                     |
    *   v - wektor, czyli drugi skladnik mnozenia.                            |
    * Zwraca:                                                                   |
    *    Iloczyn dwoch skladnikow przekazanych jako wektor.                    |
    */
     Vector<type,SIZE> operator * (Vector<type,SIZE> const  &tmp) const;
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
 *  \brief Zwraca wynik mnozenia dwoch macierzy                                                      
 *  Argumenty:                                                               
 *      this - macierz 1 
 *      mat - macierz 2                                                              
 *  Zwraca:                                                                  
 *      result - wynik mnozenia macierzy               
 */
    Matrix operator * (Matrix const &mat) const;

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
};
 /*!
   *  \brief Przeciazenie operatora >>                                                 |
   * Argumenty:                                                                |
   *    in - strumien wyjsciowy,                                              |
   *    mat - macierz.                                                         |
   */
   template<typename type, unsigned int SIZE>
   std::istream &operator >> (std::istream &in, Matrix<type,SIZE> &mat);

   /*!
   *  \brief Przeciazenie operatora <<                                                 |
   * Argumenty:                                                                |
   *    out - strumien wejsciowy,                                             |
   *     mat - macierz.                                                        |
   */
   template<typename type, unsigned int SIZE>
   std::ostream &operator << (std::ostream &out, Matrix<type,SIZE> const &mat); 
#include "../src/matrix.ipp"
