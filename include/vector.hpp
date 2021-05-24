#pragma once
#include <iostream>
#include <cmath>
#include <iomanip>
#define MIN_DIFF 0.000001

/*!
* \file vector.hpp
*
*/


/*! \class Vector
* \brief opisuje wektor o SIZE-wierszach
*/

template < typename type, unsigned int SIZE>
class Vector {
    private:
    /*!
    * \brief Tablica wektora
    */
   type size[SIZE];
   public:
    /*! 
   * \brief Konstruktor klasy Vector

   * Argumenty:
   *     Brak argumentow. 
   * Zwraca:
   *      Tablice wypelniona wartoscia 0.
   */
    Vector();

   /*! 
   * \brief Konstruktor klasy Vector

   * Argumenty:
   *     tmp - Jednowymiarowa tablica. 
   * Zwraca:
   *      Tablice wypelniona wartosciami podanymi w argumencie.
   */
    Vector(type [SIZE]);

    /*! 
   * \brief Destruktor klasy Vector

   * Argumenty:
   *     Brak argumentow.  
   * Zwraca:
   *      Usuwa wektor.
   */
  ~Vector();

   /*! 
   * \brief Realizuje dodawanie dwoch wektorow. 

   * Argumenty:
   *     this - pierwszy skladnik dodawania,                                   |
 |       v - drugi skladnik dodawania. 
   * Zwraca:
   *      Sume dwoch skladnikow przekazanych jako wskaznik                      |
 |        na parametr. 
   */
   Vector operator + (const Vector &v) const;

   /*! 
   * \brief Realizuje odejmowanie dwoch wektorow. 

   * Argumenty:
   *    this - pierwszy skladnik odejmowania,                                 |
 |      v - drugi skladnik odejmowania.  
   * Zwraca:
   *      Roznice dwoch skladnikow przekazanych jako wskaznik                   |
 |        na parametr.  
   */
   Vector operator - (const Vector &v) const;
   
   /*! 
   * \brief Realizuje mnozenie wektora przez liczbe zmiennoprzecinkowa. 

   * Argumenty:
   *   this - pierwszy skladnik mnozenia (wektor),                           |
 |      v - drugi skladnik mnozenia (liczba typu type). 
   * Zwraca:
   *      Iloczyn dwoch skladnikow przekazanych jako wskaznik                   |
 |        na parametr.   
   */
   Vector operator * (const type &tmp) const;

   /*! 
   * \brief Realizuje dzielenie dwoch wektorow. 

   * Argumenty:
   *   this - licznik dzielenia,                           |
 |      v - mianownik dzielenia. 
   * Zwraca:
   *      Iloraz dwoch skladnikow przekazanych jako wskaznik
   *      na parametr. 
   */
   Vector operator / (const type &tmp) const;

   Vector rotation(const type &angle) const;  // metoda rotacji wektora 2D

    /*! 
   * \brief Metoda do znajdowania kwadrata dlugosci wektora  

   * Argumenty:
   *   Brak argumentow. 
   * Zwraca:
   *      Kwadrat dlugosci wektora.
   */
    type mudul2() const;

    /*! 
   * \brief Metoda do znajdowania dlugosci wektora  

   * Argumenty:
   *   Brak argumentow. 
   * Zwraca:
   *      Dlugosc wektora.
   */
    type get_length() const;
   
   /*! 
   * \brief Metoda zwracajaca wektor do tablicy o rozmiarze SIZE 

   * Argumenty:
   *   tab - tablica do ktorej wypisywany jest wektor 
   * Zwraca:
   *      tablice o zmienionej zawartosci
   */
    void vector_zmien(type (&tab)[SIZE]) const;
    
    /*! 
   * \brief Przeciazenie operatora == (sprawdza czy wektory sa rowne) 

   * Argumenty:
   *   this - pierwszy wektor                           |
 |      v - drugi wektor
   * Zwraca:
   *      wartosc 1 gdy wektory sa rowne,
          a w przypadku przeciwnym zwraca wartosc 0  
   */
   bool operator == (const Vector &v) const;

   /*!
 *  \brief Metoda do obliczania iloczynu skalarnego wektorow                                                        
 *  Argumenty:                                                               
 *      v2 - drugi wektor do porownania                                              
 *  Zwraca:                                                                  
 *      result - wynik iloczynu skalarnego                           
 */
    type v_scalar(Vector const &v2) const;

    /*! 
   * \brief Funktor wektora. 

   * Argumenty:
   *   index - index wektora.
   * Zwraca:
   *      Wartosc wektora w danym miejscu tablicy jako stala.
   */
   const type &operator [] (unsigned int index) const;

   /*! 
   * \brief Funktor wektora. 

   * Argumenty:
   *   index - index wektora.
   * Zwraca:
   *      Wartosc wektora w danym miejscu tablicy.
   */
  type &operator [] (unsigned int index);
   }; 
   /*! 
   * \brief Przeciazenie operatora << 

   * Argumenty:
   *   out - strumien wejsciowy,                                             |
 |     tmp - wektor.
   */
  template <typename type, unsigned int SIZE>
  std::ostream &operator << (std::ostream &out, Vector<type,SIZE> const &tmp);

  /*! 
   * \brief Przeciazenie operatora >> 

   * Argumenty:
   *   out - strumien wyjsciowy,                                             |
 |     tmp - wektor.
   */
  template <typename type, unsigned int SIZE>
  std::istream &operator >> (std::istream &in, Vector<type,SIZE> &tmp);

#include "../src/vector.ipp"