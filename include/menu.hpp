#include <iostream>
#include <stdlib.h>
#include <fstream>
#include "cuboid.hpp"
#include "lacze_do_gnuplota.hpp"

/*!
 * \file  menu.hpp
 *  
 *  \brief Plik zawiera definicje klasy reprezentujacej menu do obslugi
 *         obrotow 3D
 */

/*!
 *  \class Menu
 *  \brief Opisuje menu dla obrotow 3D
 */
class Menu
{
private:
    /*!
 * \brief Zmienna okreslajaca czy menu jest aktywne
 */
    bool open;

    /*!
 * \brief Macierz obrotu, ma sluzyc do zapisu i uzycia.
 *        Macierz pozostanie w pamieci, dopoki uzytkownik
 *        nie zacznie definiowac nowej (nie zacznie wpisywac
 *        osi i katow.
 */
    Matrix3D mat_rot;

public:
/*!
 * \brief Konstruktor bezparametryczny menu
 */
    Menu();
/*!
 *  \brief Inicjuje menu
 *  Argumenty:
 *      tablica Vector3D 2x4
 */
    void init_menu(Vector3D (&tab)[2][4]);

/*!
 *  \brief Sprawdza i wyswietla wszelkie asercje odnosnie prostopadloscianu
 *  Argumenty:
 *      cube - sprawdzany prostopadloscian
 */
    bool assert(Cuboid const &cube);

/*!
 * \brief Obsluguje wybor menu
 *  Argumenty:
 *      op - operator switch'a
 *      cube - wyswietlany prostopadloscian
 */
    void switch_menu(const char &op, Cuboid &cube);
/*!
 * \brief Obsluguje skladanie rotacji obrotu
 */
    void switch_rotation();

/*!
 * \brief Wyswietla informacje o bokach figury na standardowym wyjsciu
 *  Argumenty:
 *      cube - wyswietlany prostopadloscian
 */
    void print_side_length(Cuboid const &cube) const;

/*!
 * \brief Wyswietla menu
 */
void show();

/*!
 * Przyklad zapisu wspolrzednych zbioru punktow do pliku, z ktorego
 * dane odczyta program gnuplot i narysuje je w swoim oknie graficznym.
 * \param[in] filename - nazwa pliku, do którego zostana zapisane
 *                          wspolrzędne punktów.
 * \param[in] cube - wyswietlany prostopadloscian
 * \retval true - gdy operacja zapisu powiodła się,
 * \retval false - w przypadku przeciwnym.
 */
    bool Write_cub_to_file(const char *filename, Cuboid const &cube);

/*!
 * \brief Wyswietla prostopadloscian w GNUplocie
 *  Argumenty:
 *      cube - wyswietlany prostopadloscian
 */
    void Print_to_gnuplot(Cuboid const &cube);
};