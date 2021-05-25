#include "../include/menu.hpp"

Menu::Menu()
{
    open = 1;
}

void Menu::init_menu(Vector3D (&tab)[2][4])
{
    Cuboid cube(tab);
    assert(cube);
    char n;
    show();
    while (open)
    {
        std::cout << "Twoj wybor? (m - menu) > ";
        std::cin >> n;
        std::cout << "\n";
        switch_menu(n, cube);
    }
}

bool Menu::assert(Cuboid const &cube)
{
    print_side_length(cube);

    if (cube.check_v())
        std::cout << "Przecwilegle boki sa rownolegle\n\n";
    if (cube.check_vec_eq())
    {
        std::cout << "Boki wychodzace z dwoch przeciwleglych wierzcholkow,\n";
        std::cout << "sa wzgledem siebie prostopadle\n\n";
    }
    if (!cube.check_cube())
    {
        std::cerr << "Blednie zainicjowany prostokat\n";
        open = 0;
        return 0;
    }
    return 1;
}

void Menu::print_side_length(Cuboid const &cube) const
{
    double l[3][2];
    cube.write_to_ar(l);

    if (abs(l[0][0] == l[0][1]) <=0.00000000001)
        std::cout << "\nDluzsze przeciwlegle boki sa sobie rowne\n";
    else
        std::cout << "\n !!! Dluzsze przeciwlegle boki nie sa sobie rowne\n";

    std::cout << "Dlugosc pierwszego boku: " << l[0][0] << "\n";

    std::cout << "Dlugosc trzeciego boku: " << l[0][1] << "\n";

    if (abs(l[1][0] - l[1][1])<=0.00000000001)
        std::cout << "\nKrotsze przeciwlegle boki sa sobie rowne\n";
    else
        std::cout << "\n !!! Krotsze przeciwlegle boki nie sa sobie rowne\n";

    std::cout << "Dlugosc pierwszego boku: " << l[1][0] << "\n";

    std::cout << "Dlugosc trzeciego boku: " << l[1][1] << "\n";
    if (abs(l[2][0] - l[2][1]) <=0.00000000001)
        std::cout << "\nPoprzeczne przeciwlegle boki sa sobie rowne\n";
    else
        std::cout << "\n !!! Poprzeczne przeciwlegle boki nie sa sobie rowne\n";
    std::cout << "Dlugosc pierwszego boku: " << l[2][0] << "\n";
    std::cout << "Dlugosc trzeciego boku: " << l[2][1] << "\n\n";
}

void Menu::switch_menu(const char &op, Cuboid &cube)
{
    int times, iter;
    switch (op)
    {
    case 'o':
    {
        std::cout << "   Podaj sekwencje oznaczen oraz katy obrotu w stopniach. Wejscie typu 'axis angle'\n";
        std::cout << "   !!! Aby zakonczyc wczytywanie wpisz: '. k' !!!\n";
        switch_rotation();
        std::cout << "Ile razy powtorzyc operacjie? > ";
        std::cin >> times;
        for (iter = 0; iter < times; ++iter)
        {
            cube = cube.rotation(mat_rot);
        }
        Print_to_gnuplot(cube);
        assert(cube);
        break;
    }

    case 't':
    {
        cube = cube.rotation(mat_rot);
        Print_to_gnuplot(cube);
        break;
    }

    case 'r':
    {
        std::cout << mat_rot << "\n";
        break;
    }

    case 'p':
    {
        Vector3D t;
        std::cout << "Wprowadz wektor o jaki chcesz przesunac prostokat. Wejscie typu: 'x y z' > ";
        std::cin >> t;
        cube = cube.translation(t);
        Print_to_gnuplot(cube);
        break;
    }

    case 'w':
    {
        std::cout << cube;
        break;
    }

    case 's':
    {
        print_side_length(cube);
        break;
    }

    case 'm':
    {
        show();
        break;
    }

    case 'k':
    {
        std::cout << "Koniec dzialania programu\n";
        open = 0;
        break;
    }
    default:
    {
        std::cout << "Bledna opcja\n"
                  << std::endl;
        break;
    }

    }
}

void Menu::switch_rotation()
{
    mat_rot = Matrix3D();
    Matrix3D tmp;
    double angle;
    char axis;
    std::cin.ignore(1000000, '\n');
    std::cin >> axis >> angle;
    while (axis != '.')
    {
        switch (axis)
        {
        case 'x':
        {
            mat_rot = tmp.MatrixRotate(angle, 'x') * mat_rot;
            break;
        }
        case 'y':
        {
            mat_rot = tmp.MatrixRotate(angle, 'y') * mat_rot;
            break;
        }
        case 'z':
        {
            mat_rot = tmp.MatrixRotate(angle, 'z') * mat_rot;
            break;
        }
        default:
        {
            std::cerr << "Bledne oznaczenie osi. Dopuszczalne znaki to: x y z\n Sprobuj jeszcze raz\n";
        }
        }
        std::cin.ignore(1000000, '\n');
        std::cin >> axis >> angle;
    }
}

void Menu::show()
{
    std::cout << "  o - obrot bryly o zadana sekwencje katow\n";
    std::cout << "  t - powtorzenie poprzedniego obrotu\n";
    std::cout << "  r - wyswietlenie macierzy rotacji\n";
    std::cout << "  p - przesuniecie prostokata o zadany wektor\n";
    std::cout << "  w - wyswietlenie wspolrzednych wierzcholkow\n";
    std::cout << "  s - sprawdzenie dlugosci przeciwleglych bokow\n";
    std::cout << "  m - wyswietl menu\n";
    std::cout << "  k - koniec dzialania programu\n\n";
}

bool Menu::Write_cub_to_file(const char *filename, Cuboid const &cube)
{
    std::ofstream filestrm;

    filestrm.open(filename);
    if (!filestrm.is_open())
    {
        std::cerr << ":(  Operacja otwarcia do zapisu \"" << filename << "\"" << std::endl
                  << ":(  nie powiodla sie." << std::endl;
        return false;
    }
    std::ostringstream out;
    cube.print_cuboid2(filestrm);

    filestrm.close();
    return !filestrm.fail();
}

void Menu::Print_to_gnuplot(Cuboid const &cube)
{
    PzG::LaczeDoGNUPlota Lacze; // Ta zmienna jest potrzebna do wizualizacji

    Lacze.DodajNazwePliku("../datasets/cuboid.dat", PzG::RR_Ciagly, 2);

    Lacze.DodajNazwePliku("../datasets/cuboid.dat", PzG::RR_Punktowy, 2);

    Lacze.ZmienTrybRys(PzG::TR_3D);
    cube.print_cuboid2(std::cout);
    if (!this->Write_cub_to_file("../datasets/cuboid.dat", cube))
        std::cerr << "ERROR" << std::endl;
    Lacze.Rysuj(); // <- Tutaj gnuplot rysuje, to co zapisaliśmy do pliku
    std::cout << "Naciśnij ENTER, aby kontynuowac" << std::endl;
    std::cin.ignore(100000, '\n');
}