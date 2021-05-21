#pragma once 

#include "vector2D.hpp"
#include "matrix.hpp"
#include "size.hpp"
#include "lacze_do_gnuplota.hpp"
#include <fstream>
#include <iostream>
#include <iomanip>

/*!
 *  \file rectangle.hpp
 * 
 */

class Rectangle{
    
    Vector2D v[NUMBEROFVERTEX];   // lista wierzcholkow prostokata
    public:
   
   Rectangle();    // Konstruktor klasy

   Rectangle(Vector2D const (&ar)[NUMBEROFVERTEX]);      // Konstruktor klasy

   ~Rectangle();                                        // Destruktor klasy

   Rectangle translation(Vector2D const &t) const;   // metoda translacji prostokata o zadany wektor (z zadanym "na sztywno" wektorem)

   Rectangle rotate(const double &angle) const;     // metoda rotacji prostokata (z zadanym "na sztywno" katem)

   Rectangle translation() const;  // metoda translacji prostokata (wektor podaje uzytkownik)

   Rectangle rotate() const;   // metoda rotacji prostokata (kat podaje uzytkownik)

   void new_rectangle( Vector2D ((&ar)[NUMBEROFVERTEX])) const;  // metoda zwracajaca wierzcholki prostokata

   bool check_length(Vector2D const (&vx)[NUMBEROFVERTEX]) const; // metoda sprawdzania dlugosci przeciwleglych bokow prostokata

   Rectangle numberofrotation();  // metoda obracajaca prostokat n razy   

   bool Writetofile(std:: string filename); // metoda zapisu danych do pliku
   
   bool operator == (const Rectangle &Rec) const;   // przeciazenie operatora == 

   void RectangleToStdout(std::ostream &StrmWy);  //zapisuje wierzcholki do wyjscia
   
   void PrintRectangle();   // Metoda wyswietlajaca prostokat w Gnuplocie   
    
};
std::ostream &operator << (std::ostream &out, Rectangle const &Rec);  // Przeciazenie operatora wpisywania 

 std::ofstream &operator << (std::ofstream &fout, Rectangle const &Rec); // Przeciazenie operatora wpisywania dla pliku
