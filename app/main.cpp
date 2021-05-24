// Executables must have the following defined if the library contains
// doctest definitions. For builds with this disabled, e.g. code shipped to
// users, this can be left out.
#ifdef ENABLE_DOCTEST_IN_LIBRARY
#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"
#endif

#include <iostream>
#include <stdlib.h>
#include "size.hpp"
#include  "vector3D.hpp"
#include "exampleConfig.h"
#include "../include/menu.hpp"

/*
 * Simple main program that demontrates how access
 * CMake definitions (here the version number) from source code.
 */
int main() {
  std::cout << "C++ Boiler Plate v"
            << PROJECT_VERSION_MAJOR
            << "."
            << PROJECT_VERSION_MINOR
            << "."
            << PROJECT_VERSION_PATCH
            << "."
            << PROJECT_VERSION_TWEAK
            << std::endl;
  std::system("cat ../LICENSE");

  // Bring in the dummy class from the example source,
  // just to show that it is accessible from main.cpp.
  Menu m;

  double i1[NUMBEROFVERTEX][SIZE] = {{0, 0, 0}, {50, 0, 0}, {50, 50, 0} , {0, 50, 0}};
  double i2[NUMBEROFVERTEX][SIZE] = {{0, 0, 100}, {50, 0, 100}, {50, 50, 100} , {0, 50, 100}};

  Vector3D vc[SIZE2D][NUMBEROFVERTEX];
  for (int i = 0; i < NUMBEROFVERTEX; ++i)
  {
    vc[0][i] = Vector3D(i1[i]);
    vc[1][i] = Vector3D(i2[i]);
  }
    Cuboid cub(vc);
  m.init_menu(vc);
}
