#pragma once

#include <iostream>
#include "vector3D.hpp"
#include "matrix3D.hpp"
#include "size.hpp"


/*!
 * \file Cuboid.hpp
 * \brief Plik zawiera definicje klasy reprezentujacej prostopadloscian.
 *
 */



/*!
 *  \brief Class Cuboid
 *
 *  Klas opisuje prostopadloscian i jego zachowanie
 *  w przestrzeni trojwymiarowej
 */
class Cuboid {
  
   Vector3D vc3[NUMBEROFVERTEX][SIZE2D];

  public:

   /*!
 *  \brief Konstruktor bezparametryczny klasy Cuboid.
 *          Powstaly prostopadloscian ma dwa prostokaty, z ktorych zostal stworzony:
 *          r1 = [0][0] = (0,0,0), [0][1] =  (1,0,0), [0][2] = (1,1,0), [0][3] = (0,1,0)      
 *          r2 = [1][0] = (0,0,1), [1][1] =  (1,0,1), [1][2] = (1,1,1), [1][3] = (0,1,1)                                            
 *  Argumenty:                                                                
 *      Brak argumentow.                                                      
 *  Zwraca:                                                                   
 *      Zwraca wszystkie wierzcholki prostopadloscianu.                                   
 */
 Cuboid();

   /*!
 *  \brief Konstruktor parametryczny klasy Cuboid.                                              
 *  Argumenty:                                                                
 *       ar- tablica o rozmiarze 2x4 typu Vector3D.                                                      
 *  Zwraca:                                                                   
 *       Zwraca wszystkie wierzcholki prostopadloscianu zadane przez program.                                  
 */
 Cuboid(Vector3D const (&ar)[SIZE2D][NUMBEROFVERTEX]);

  /*!
 *  \brief Konstruktor parametryczny klasy Cuboid.                                              
 *  Argumenty:                                                                
 *      ar3 - tablica o rozmiarze 2x4x3 typu double                                                     
 *  Zwraca:                                                                   
 *      Zwraca wszystkie wiercholki prostopadloscianu zadane przez program                                  
 */
 Cuboid(double (&ar3)[SIZE2D][NUMBEROFVERTEX][SIZE]);

  /*!
 *  \brief Metoda zwracajaca do tablicy 3x2 wektory reprezentujace
 *              przeciwne boki prostopadloscianu.                                           
 *  Argumenty:  
 *      vx - tablica 3x2 typu Vector3D do ktorej program zwraca boki                                                                                                                                  
 *  Zwraca:                                                                   
 *      Brak.                                 
 */
void new_vect(Vector3D (&vx)[SIZE][SIZE2D]) const;

/*!
 *  \brief Metoda sprawdzajaca czy dlugosci wektory tworzace przeciwne boki prostopadloscianu
 *          maja poprawne wartosci (nie sa rowne 0)                                          
 *  Argumenty:
 *       Brak.                                                                                                       
 *  Zwraca:                                                                   
 *     \retval true - maja poprawne wartosci
 *     \retval false - nie maja poprawnych wartosci                                  
 */
bool check_length_of_v() const;

/*!
 *  \brief Metoda zapisujaca do tablicy ar w kolejnosci:
 *          1.dluzsze przeciwlegle boki
 *          2.krotsze przeciwlegle boki
 *          3.poprzeczne przeciwlegle boki
 *         Wartosci dlugosci tych bokow                                      
 *  Argumenty:
 *       ar - tablica x3 do ktorej zapisza sie wartosci                                                                                                       
 *  Zwraca:    
 *       Brak.                                                                                              
 */
void write_to_ar(double (&ar)[SIZE][SIZE2D]) const;

/*!
 *  \brief Metoda sprawdzajaca czy wektory tworzace przeciwne boki prostopadloscianu
 *          sa rowne                                          
 *  Argumenty:
 *       Brak.                                                                                                      
 *  Zwraca:                                                                   
 *     \retval true - sa rowne
 *     \retval false - nie sa rowne                                  
 */
bool check_v() const;

/*!
 *  \brief Metoda zwracajaca do tablicy 2x3 wektory reprezentujace
 *          boki przy wierzcholkach [0][1] (do vecs[0])
 *          i [1][3] (do v[1]) prostopadloscianu                                         
 *  Argumenty:  
 *      v - tablica 2x3 typu Vector3D do ktorej
 *                        program zwraca boki                                                                                                                
 *  Zwraca:                                                                   
 *     Brak.                                
 */
void ret_vec(Vector3D (&v)[SIZE2D][SIZE]) const;

/*!
 *  \brief Metoda sprawdzajaca czy wektory tworzace niektore konkretne boki prostokata
            (glownie te przy wierzcholkach) sa prostopadle                                   
 *  Argumenty:        
 *         brak                                                                                                            
 *  Zwraca:                                                                   
 *     \retval true - sa prostopadle
 *     \retval false - nie sa prostopadle                                 
 */
bool check_vec_eq() const;

/*!
 *  \brief Metoda sprawdzajaca czy prostopadloscian jest poprawnie zbudowany                                            
 *  Argumenty:                                                                                                                    
 *  Zwraca:                                                                   
 *     \retval true - jest zgodny
 *     \retval false - nie jest zgodny                                   
 */
bool check_cube() const;

/*!
 *  \brief Przeciazenie operatora ==                                               
 *  Argumenty:                                                                
 *      cube - porownywany prostopadloscian                                            
 *  Zwraca:
 *      \retval true - sa rowne, 
 *      \retval false - nie sa rowne.                                                  
 */
bool operator == (const Cuboid &cube) const;

/*!
 *  \brief Metoda przesuwajaca prostopadloscian o zadany kat                                            
 *  Argumenty:                                                                
 *      tr - Vector3D                                                     
 *  Zwraca:                                                                   
 *     translated - prostopadloscian po operacji przesuniecia                                
 */
Cuboid translation(Vector3D const &tr) const;

/*!
 *  \brief Metoda obracajaca prostopadloscian o zadany kat                                            
 *  Argumenty:                                                                
 *      mat - macierz obrotu                                                     
 *  Zwraca:                                                                   
 *     rotated - prostopadloscian po operacji rotacji                               
 */
Cuboid rotation(Matrix3D const &mat) const;

/*!
 *  \brief Metoda zwracajaca wierzcholki prostopadloscianu do Vector3D                                              
 *  Argumenty:                                                                
 *      ar - tablica 2x4 typu Vector3D                                                     
 *  Zwraca:                                                                   
 *     zwraca osiem wiercholkow przechowywanych w klasie Cuboid i przypisuje je do podanej tablicy                                  
 */
void ret_cube1(Vector3D (&ar)[SIZE2D][NUMBEROFVERTEX]) const;

/*!
 *  \brief Metoda zwracajaca wierzcholki prostopadloscianu do tablicy                                             
 *  Argumenty:                                                                
 *      ar - tablica 2x4x3 typu double                                                   
 *  Zwraca:                                                                   
 *     zwraca osiem wiercholkow przechowywanych w klasie Cuboid i przypisuje je do podanej tablicy                                  
 */
void ret_cube2(double (&ar)[SIZE2D][NUMBEROFVERTEX][SIZE]) const;

/*!
 *  \brief Metoda wypisania odpowiednich wierzcholkow do pliku                                                
 *  Argumenty:                                                                
 *      out - strumien wyjsciowy,                                                                                                
 */

void print_cuboid1(std::ostream &out) const;

/*!
 *  \brief Metoda wypisania odpowiednich wierzcholkow do pliku
 *         zgodnie z zaproponowanym sposobem w zadaniu                              
 *  Argumenty:                                                                
 *        out - strumien wyjsciowy,                                                                                                
 */
void print_cuboid2(std::ostream &out) const;


};


/*!
 * \brief Przeciazenie operatora <<
 *
 *   Argumenty:
 *    Strm - strumien wyjsciowy,
 *    Pr - prostopadloscian.
 */
std::ostream& operator << ( std::ostream       &Strm, 
                            const Cuboid    &Pr
                          );