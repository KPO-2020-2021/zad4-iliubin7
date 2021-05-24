#include "../tests/doctest/doctest.h"
#include "../include/cuboid.hpp"

TEST_CASE("test konstruktor bezparametryczny prostopadloscianu i przeciazenie operatora << 1")
{
    Cuboid a;
    std::ostringstream out;
    out << a; //
    std::ostringstream out2;
    out2 << "Wierzcholek A: \n"
         << "[ 0.0000000000 ]\n[ 0.0000000000 ]\n[ 0.0000000000 ]\n\n";
    out2 << "Wierzcholek B: \n"
         << "[ 1.0000000000 ]\n[ 0.0000000000 ]\n[ 0.0000000000 ]\n\n";
    out2 << "Wierzcholek C: \n"
         << "[ 1.0000000000 ]\n[ 1.0000000000 ]\n[ 0.0000000000 ]\n\n";
    out2 << "Wierzcholek D: \n"
         << "[ 0.0000000000 ]\n[ 1.0000000000 ]\n[ 0.0000000000 ]\n\n";
    out2 << "Wierzcholek E: \n"
         << "[ 0.0000000000 ]\n[ 0.0000000000 ]\n[ 1.0000000000 ]\n\n";
    out2 << "Wierzcholek F: \n"
         << "[ 1.0000000000 ]\n[ 0.0000000000 ]\n[ 1.0000000000 ]\n\n";
    out2 << "Wierzcholek G: \n"
         << "[ 1.0000000000 ]\n[ 1.0000000000 ]\n[ 1.0000000000 ]\n\n";
    out2 << "Wierzcholek H: \n"
         << "[ 0.0000000000 ]\n[ 1.0000000000 ]\n[ 1.0000000000 ]\n\n";
    CHECK(out.str() == out2.str());
}

TEST_CASE("test konstruktor parametryczny prostopadloscianu (przeciazenie z double) i przeciazenie operatora << 2")
{
    double tab[2][4][3];
    for (int i = 0; i < 2; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            for (int k = 0; k < 3; ++k)
            {
                tab[i][j][k] = 1.0;
            }
        }
    }
    Cuboid a(tab);
    std::ostringstream out;
    out << a; 
    std::ostringstream out2;
    out2 << "Wierzcholek A: \n"
         << "[ 1.0000000000 ]\n[ 1.0000000000 ]\n[ 1.0000000000 ]\n\n";
    out2 << "Wierzcholek B: \n"
         << "[ 1.0000000000 ]\n[ 1.0000000000 ]\n[ 1.0000000000 ]\n\n";
    out2 << "Wierzcholek C: \n"
         << "[ 1.0000000000 ]\n[ 1.0000000000 ]\n[ 1.0000000000 ]\n\n";
    out2 << "Wierzcholek D: \n"
         << "[ 1.0000000000 ]\n[ 1.0000000000 ]\n[ 1.0000000000 ]\n\n";
    out2 << "Wierzcholek E: \n"
         << "[ 1.0000000000 ]\n[ 1.0000000000 ]\n[ 1.0000000000 ]\n\n";
    out2 << "Wierzcholek F: \n"
         << "[ 1.0000000000 ]\n[ 1.0000000000 ]\n[ 1.0000000000 ]\n\n";
    out2 << "Wierzcholek G: \n"
         << "[ 1.0000000000 ]\n[ 1.0000000000 ]\n[ 1.0000000000 ]\n\n";
    out2 << "Wierzcholek H: \n"
         << "[ 1.0000000000 ]\n[ 1.0000000000 ]\n[ 1.0000000000 ]\n\n";
    CHECK(out.str() == out2.str());
}

TEST_CASE("test konstruktor parametryczny prostopadloscianu (przeciazenie z Vector3D) i przeciazenie operatora << 3")
{
    double tab_vec[3] = {1, 2, 3};
    Vector3D tab[2][4];
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            tab[i][j] = Vector3D(tab_vec);
        }
    }
    Cuboid a(tab);
    std::ostringstream out;
    out << a; 
    std::ostringstream out2;
    out2 << "Wierzcholek A: \n"
         << "[ 1.0000000000 ]\n[ 2.0000000000 ]\n[ 3.0000000000 ]\n\n";
    out2 << "Wierzcholek B: \n"
         << "[ 1.0000000000 ]\n[ 2.0000000000 ]\n[ 3.0000000000 ]\n\n";
    out2 << "Wierzcholek C: \n"
         << "[ 1.0000000000 ]\n[ 2.0000000000 ]\n[ 3.0000000000 ]\n\n";
    out2 << "Wierzcholek D: \n"
         << "[ 1.0000000000 ]\n[ 2.0000000000 ]\n[ 3.0000000000 ]\n\n";
    out2 << "Wierzcholek E: \n"
         << "[ 1.0000000000 ]\n[ 2.0000000000 ]\n[ 3.0000000000 ]\n\n";
    out2 << "Wierzcholek F: \n"
         << "[ 1.0000000000 ]\n[ 2.0000000000 ]\n[ 3.0000000000 ]\n\n";
    out2 << "Wierzcholek G: \n"
         << "[ 1.0000000000 ]\n[ 2.0000000000 ]\n[ 3.0000000000 ]\n\n";
    out2 << "Wierzcholek H: \n"
         << "[ 1.0000000000 ]\n[ 2.0000000000 ]\n[ 3.0000000000 ]\n\n";
    CHECK(out.str() == out2.str());
}

TEST_CASE("test konstruktor parametryczny prostopadloscianu (przeciazenie z Vector3D) i przeciazenie operatora << 4")
{
    double tab_vec[3] = {0.0000000001, 0.0000000002, 0.0000000003};
    Vector3D tab[2][4];
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            tab[i][j] = Vector3D(tab_vec);
        }
    }
    Cuboid a(tab);
    std::ostringstream out;
    out << a; 
    std::ostringstream out2;
    out2 << "Wierzcholek A: \n"
         << "[ 0.0000000001 ]\n[ 0.0000000002 ]\n[ 0.0000000003 ]\n\n";
    out2 << "Wierzcholek B: \n"
         << "[ 0.0000000001 ]\n[ 0.0000000002 ]\n[ 0.0000000003 ]\n\n";
    out2 << "Wierzcholek C: \n"
         << "[ 0.0000000001 ]\n[ 0.0000000002 ]\n[ 0.0000000003 ]\n\n";
    out2 << "Wierzcholek D: \n"
         << "[ 0.0000000001 ]\n[ 0.0000000002 ]\n[ 0.0000000003 ]\n\n";
    out2 << "Wierzcholek E: \n"
         << "[ 0.0000000001 ]\n[ 0.0000000002 ]\n[ 0.0000000003 ]\n\n";
    out2 << "Wierzcholek F: \n"
         << "[ 0.0000000001 ]\n[ 0.0000000002 ]\n[ 0.0000000003 ]\n\n";
    out2 << "Wierzcholek G: \n"
         << "[ 0.0000000001 ]\n[ 0.0000000002 ]\n[ 0.0000000003 ]\n\n";
    out2 << "Wierzcholek H: \n"
         << "[ 0.0000000001 ]\n[ 0.0000000002 ]\n[ 0.0000000003 ]\n\n";

    CHECK(out.str() == out2.str());
}

TEST_CASE("test konstruktor parametryczny prostopadloscianu (przeciazenie z double) i przeciazenie operatora << 5")
{
    double tab[2][4][3];
    for (int i = 0; i < 2; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            for (int k = 0; k < 3; ++k)
            {
                tab[i][j][k] = -1.0;
            }
        }
    }
    Cuboid a(tab);
    std::ostringstream out;
    out << a; 
    std::ostringstream out2;
    out2 << "Wierzcholek A: \n"
         << "[ -1.0000000000 ]\n[ -1.0000000000 ]\n[ -1.0000000000 ]\n\n";
    out2 << "Wierzcholek B: \n"
         << "[ -1.0000000000 ]\n[ -1.0000000000 ]\n[ -1.0000000000 ]\n\n";
    out2 << "Wierzcholek C: \n"
         << "[ -1.0000000000 ]\n[ -1.0000000000 ]\n[ -1.0000000000 ]\n\n";
    out2 << "Wierzcholek D: \n"
         << "[ -1.0000000000 ]\n[ -1.0000000000 ]\n[ -1.0000000000 ]\n\n";
    out2 << "Wierzcholek E: \n"
         << "[ -1.0000000000 ]\n[ -1.0000000000 ]\n[ -1.0000000000 ]\n\n";
    out2 << "Wierzcholek F: \n"
         << "[ -1.0000000000 ]\n[ -1.0000000000 ]\n[ -1.0000000000 ]\n\n";
    out2 << "Wierzcholek G: \n"
         << "[ -1.0000000000 ]\n[ -1.0000000000 ]\n[ -1.0000000000 ]\n\n";
    out2 << "Wierzcholek H: \n"
         << "[ -1.0000000000 ]\n[ -1.0000000000 ]\n[ -1.0000000000 ]\n\n";
    CHECK(out.str() == out2.str());
}

TEST_CASE("test operator == dla klasy Cuboid")
{
    Cuboid a, b;

    CHECK(a == b);
}

TEST_CASE("test operator == dla klasy Cuboid false")
{
    Cuboid a;
    double tab_vec[3] = {1, 2, 3};
    Vector3D tab[2][4];
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            tab[i][j] = Vector3D(tab_vec);
        }
    }
    Cuboid b(tab);
    CHECK(!(a == b));
}

TEST_CASE("test Cuboid: ret_cube1() 1")
{
    double tab_vec[3] = {1, 2, 3};
    Vector3D tab[2][4];
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            tab[i][j] = Vector3D(tab_vec);
        }
    }
    Cuboid a(tab);
    Vector3D tab2[2][4];
    a.ret_cube1(tab2);
    for (int i = 0; i < 2; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            CHECK(tab[i][j] == tab2[i][j]);
        }
    }
}

TEST_CASE("test Cuboid: ret_cube() 2")
{
    double tab_vec[3] = {-1, -2, -3};
    Vector3D tab[2][4];
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            tab[i][j] = Vector3D(tab_vec);
        }
    }
    Cuboid a(tab);
    Vector3D tab2[2][4];
    a.ret_cube1(tab2);
    for (int i = 0; i < 2; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            CHECK(tab[i][j] == tab2[i][j]);
        }
    }
}

TEST_CASE("test Cuboid: ret_cube() 3")
{
    double tab_vec[3] = {0.0000000001, 0.0000000002, 0.0000000003};
    Vector3D tab[2][4];
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            tab[i][j] = Vector3D(tab_vec);
        }
    }
    Cuboid a(tab);
    Vector3D tab2[2][4];
    a.ret_cube1(tab2);
    for (int i = 0; i < 2; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            CHECK(tab[i][j] == tab2[i][j]);
        }
    }
}

TEST_CASE("test Cuboid: translacja(Vector3D) 1")
{
    Cuboid a;
    double tab[3] = {1, 2, 3};
    Vector3D tran(tab);
    Cuboid c = a.translation(tran);
    double tab2[2][4][3] = {{{1, 2, 3}, {2, 2, 3}, {2, 3, 3}, {1, 3, 3}}, {{1, 2, 4}, {2, 2, 4}, {2, 3, 4}, {1, 3, 4}}};
    Cuboid b(tab2);
    CHECK(c == b);
}

TEST_CASE("test Cuboid: translatcja(Vector3D) 2")
{
    Cuboid a;
    double tab[3] = {-1, -2, -3};
    Vector3D tran(tab);
    Cuboid c = a.translation(tran);
    double tab2[2][4][3] = {{{-1, -2, -3}, {0, -2, -3}, {0, -1, -3}, {-1, -1, -3}}, {{-1, -2, -2}, {0, -2, -2}, {0, -1, -2}, {-1, -1, -2}}};
    Cuboid b(tab2);
    CHECK(c == b);
}

TEST_CASE("test Cuboid: rotacja(Matrix3D)")
{
    Cuboid a;
    double tab[3] = {-1, -2, -3};
    Vector3D tran(tab);
    Cuboid c = a.translation(tran);
    double tab2[2][4][3] = {{{-1, -2, -3}, {0, -2, -3}, {0, -1, -3}, {-1, -1, -3}}, {{-1, -2, -2}, {0, -2, -2}, {0, -1, -2}, {-1, -1, -2}}};
    Cuboid b(tab2);
    CHECK(c == b);
}  

TEST_CASE("test Cuboid: new_vect i check_length_of_v 3")
{
    Vector3D tops[2][4];
    double iter[4][3] = {{-2, -2, 0}, {0, -2, 0}, {0, 0, 0}, {-2, 0, 0}};
    for (int i = 0; i < 4; ++i)
    {
        tops[0][i] = Vector3D(iter[i]);
        iter[i][2] = 2;
        tops[1][i] = Vector3D(iter[i]);
    }
    Cuboid a(tops);
    Vector3D opp[3][2];
    a.new_vect(opp);
    double tab[3][3] = {{2, 0, 0}, {0, 0, 2}, {0, 2, 0}};
    Vector3D vec[3];
    for (int i = 0; i < 3; ++i)
    {
        vec[i] = Vector3D(tab[i]);
    }
    for (int i = 0; i < 3; ++i)
    {
        CHECK(opp[i][0] == opp[i][1]);
        CHECK(opp[i][1] == vec[i]);
    }
    CHECK(a.check_v());
    CHECK(a.check_cube());
}


TEST_CASE("test Cuboid: check_cube 1"){
    Cuboid a;
    CHECK(a.check_cube());
}

TEST_CASE("test Cuboid: check_cube 2"){
    Vector3D tops[2][4];
    double iter[4][3] = {{-2, -2, 0}, {0, -2, 0}, {0, 0, 0}, {-2, 0, 0}};
    for (int i = 0; i < 4; ++i)
    {
        tops[0][i] = Vector3D(iter[i]);
        iter[i][2] = 2;
        tops[1][i] = Vector3D(iter[i]);
    }
    Cuboid a(tops);
    CHECK(a.check_cube());
}

TEST_CASE("test Cuboid: check_cube "){
    Vector3D tops[2][4];
    double iter[4][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
    for (int i = 0; i < 4; ++i)
    {
        tops[0][i] = Vector3D(iter[i]);
        iter[i][2] = 2;
        tops[1][i] = Vector3D(iter[i]);
    }
    Cuboid a(tops);
    CHECK(!a.check_cube());
}

TEST_CASE("test Cuboid: check_cub "){
    Vector3D tops[2][4];
    double iter[4][3] = {{0, 0, 0}, {2, 0, 0}, {2, 2, 0}, {0, 2, 0}};
    for (int i = 0; i < 4; ++i)
    {
        tops[0][i] = Vector3D(iter[i]);
        iter[i][2] = 2;
        tops[1][i] = Vector3D(iter[i]);
    }
    Cuboid a(tops);
    CHECK(a.check_cube());
}

TEST_CASE("test Cuboid: check_cube "){
    Vector3D tops[2][4];
    double iter[4][3] = {{214, 3234, 4140}, {4234, 0, 0}, {114, 41243, 0}, {0,0, 0}};
    for (int i = 0; i < 4; ++i)
    {
        tops[0][i] = Vector3D(iter[i]);
        iter[i][2] = 2;
        tops[1][i] = Vector3D(iter[i]);
    }
    Cuboid a(tops);
    CHECK(!a.check_cube());
}

TEST_CASE("test Cuboid: check_cube 6 small"){
    Vector3D tops[2][4];
    double iter[4][3] = {{0, 0, 0}, {0.0000000002, 0, 0}, {0.0000000002, 0.0000000002, 0}, {0, 0.0000000002, 0}};
    for (int i = 0; i < 4; ++i)
    {
        tops[0][i] = Vector3D(iter[i]);
        iter[i][2] = 2;
        tops[1][i] = Vector3D(iter[i]);
    }
    Cuboid a(tops);
    CHECK(a.check_cube());
}

TEST_CASE("test Cuboid: check_cube 7 small neg"){
    Vector3D tops[2][4];
    double iter[4][3] = {{0, 0, 0}, {-0.0000000002, 0, 0}, {-0.0000000002, -0.0000000002, 0}, {0, -0.0000000002, 0}};
    for (int i = 0; i < 4; ++i)
    {
        tops[0][i] = Vector3D(iter[i]);
        iter[i][2] = 2;
        tops[1][i] = Vector3D(iter[i]);
    }
    Cuboid a(tops);
    CHECK(a.check_cube());
}

TEST_CASE("test Cuboid: print_cube 2 "){
    Vector3D tops[2][4];
    double iter[4][3] = {{0, 0, 0}, {2, 0, 0}, {2, 2, 0}, {0, 2, 0}};
    for (int i = 0; i < 4; ++i)
    {
        tops[0][i] = Vector3D(iter[i]);
        iter[i][2] = 2;
        tops[1][i] = Vector3D(iter[i]);
    }
    Cuboid a(tops);
  std::ostringstream out;
  std::ostringstream out2;
  a.print_cuboid1(out);
out2<<"0.0000000000 0.0000000000 0.0000000000 \n";
out2<<"2.0000000000 0.0000000000 0.0000000000 \n\n";

out2<<"2.0000000000 2.0000000000 0.0000000000 \n";
out2<<"0.0000000000 2.0000000000 0.0000000000 \n\n";

out2<<"0.0000000000 0.0000000000 2.0000000000 \n";
out2<<"2.0000000000 0.0000000000 2.0000000000 \n\n";

out2<<"2.0000000000 2.0000000000 2.0000000000 \n";
out2<<"0.0000000000 2.0000000000 2.0000000000 \n\n";

out2<<"0.0000000000 0.0000000000 0.0000000000 \n";
out2<<"2.0000000000 0.0000000000 0.0000000000 \n";

  CHECK (out.str() == out2.str());
}