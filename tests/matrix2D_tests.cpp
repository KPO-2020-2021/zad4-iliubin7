#include"../tests/doctest/doctest.h"
#include"matrix2D.hpp"
#include"vector2D.hpp"

TEST_CASE("test Matrix  konstruktor bezparametryczny i przeciazenie operatorow << >>"){
    //double tab[2][2] = {{3,1}};
    Matrix2D a;
    std::ostringstream out;
    out << a; // 
    CHECK (out.str() == "| 1.0000000000 * | 0.0000000000 * | 0.0000000000 * | 1.0000000000 * ");
}

TEST_CASE("test Matrix konstruktor parametryczny i przeciazenie operatorow << >>"){
    double tab[2][2] = {{3,1},{3,1}};
    Matrix2D a(tab);
    std::ostringstream out;
    out << a; // 
    CHECK (out.str() == "| 3.0000000000 * | 1.0000000000 * | 3.0000000000 * | 1.0000000000 * ");
}

TEST_CASE("test Matrix  konstruktor parametryczny i przeciazenie operatorow << >>"){
    double tab[2][2] = {{0.0003,0.0001},{0.0003,0.0001}};
    Matrix2D a(tab);
    std::ostringstream out;
    out << a; // 
    CHECK (out.str() == "| 0.0003000000 * | 0.0001000000 * | 0.0003000000 * | 0.0001000000 * ");
}

TEST_CASE("test Matrix  konstruktor parametryczny i przeciazenie operatorow << >>"){
    double tab[2][2] = {{-0.0003,0.0001},{0.0003,-0.0001}};
    Matrix2D a(tab);
    std::ostringstream out;
    out << a; // 
    CHECK (out.str() == "| -0.0003000000 * | 0.0001000000 * | 0.0003000000 * | -0.0001000000 * ");
}

TEST_CASE("test Matrix  konstruktor parametryczny i przeciazenie operatorow << >>"){
    double tab[2][2] = {{0,0},{0,0}};
    Matrix2D a(tab);
    std::ostringstream out;
    out << a; // 
    CHECK (out.str() == "| 0.0000000000 * | 0.0000000000 * | 0.0000000000 * | 0.0000000000 * ");
}

TEST_CASE("test Matrix   przeciazenie operatorow << >>"){
    double tab[2][2] = {{0,0},{0,0}};
    Matrix2D a(tab);
    std::istringstream in("1 2 3 4");
    in >> a;
    std::ostringstream out;
    out << a; // 
    CHECK (out.str() == "| 1.0000000000 * | 2.0000000000 * | 3.0000000000 * | 4.0000000000 * ");
}

TEST_CASE("test Matrix operator * (vector)"){
    double tab[2][2] = {{1,0},{0,1}};
    double vec[2] = {1,2};
    Matrix2D a(tab);
    Vector2D b(vec);

    Vector2D c(vec);

    CHECK (c==(a*b));
}

TEST_CASE("test Matrix operator * (vector) zero"){
    double tab[2][2] = {{0,0},{0,0}};
    double vec[2] = {0,0};
    Matrix2D a(tab);
    Vector2D b(vec);

    Vector2D c(vec);

    CHECK (c==(a*b));
}

TEST_CASE("test Matrix  operator * (vector) neg"){
    double tab[2][2] = {{1,2},{3,4}};
    double vec[2] = {1,-1};
    double res[2] = {-1,-1};
    Matrix2D a(tab);
    Vector2D b(vec);

    Vector2D c(res);

    CHECK (c==(a*b));
}

TEST_CASE("test Matrix  operator +"){
    double tab[2][2] = {{1,2},{3,4}};
    double tab2[2][2] = {{4,3},{2,1}};
    double res[2][2] = {{5,5},{5,5}};

    Matrix2D a(tab);
    Matrix2D b(tab2);

    Matrix2D c(res);

    CHECK (c==(a+b));
}

TEST_CASE("test Matrix  operator + 0"){
    double tab[2][2] = {{1,2},{3,4}};
    double tab2[2][2] = {{0,0},{0,0}};
    double res[2][2] = {{1,2},{3,4}};

    Matrix2D a(tab);
    Matrix2D b(tab2);

    Matrix2D c(res);

    CHECK (c==(a+b));
}

TEST_CASE("test Matrix  operator + small"){
    double tab[2][2] = {{1,2},{3,4}};
    double tab2[2][2] = {{0.0000000001,0.0000000001},{0.0000000001,0.0000000001}};
    double res[2][2] = {{1.0000000001,2.0000000001},{3.0000000001,4.0000000001}};

    Matrix2D a(tab);
    Matrix2D b(tab2);

    Matrix2D c(res);

    CHECK (c==(a+b));
}

TEST_CASE("test Matrix  operator ()"){
    double tab[2][2] = {{1,2},{3,4}};
    double res = 1;

    Matrix2D a(tab);

    CHECK (res == a(0,0));
}

TEST_CASE("test Matrix  operator ()"){
    double tab[2][2] = {{1,0.00002},{3,4}};
    double res = 0.00002;

    Matrix2D a(tab);

    CHECK (res == a(0,1));
}

TEST_CASE("test Matrix  operator ()"){
    double tab[2][2] = {{1,2},{-3,4}};
    double res = -3;

    Matrix2D a(tab);

    CHECK (res == a(1,0));
}

TEST_CASE("test Matrix  operator ()"){
    double tab[2][2] = {{1,2},{-3,0}};
    double res = 0;

    Matrix2D a(tab);

    CHECK (res == a(1,1));
}

TEST_CASE("test Matrix  Matrix2D: gauss()"){
    double tab[2][2] = {{1,2},{3,4}};
    double tab2[2][2] = {{1,2},{0,-2}};
    Matrix2D a(tab);
    Matrix2D b(tab2);

    CHECK ((a.gauss()) == b);
}

TEST_CASE("test Matrix  Matrix2D: gauss() 2"){
    double tab[2][2] = {{3,2},{3,4}};
    double tab2[2][2] = {{3,2},{0,2}};
    Matrix2D a(tab);
    Matrix2D b(tab2);

    CHECK ((a.gauss()) == b);
}

TEST_CASE("test Matrix Matrix2D: determinant() 1"){
    double tab[2][2] = {{1,2},{3,4}};
    Matrix2D a(tab);
    double det; 
    det = -2;
    CHECK ((a.determinant()) == det);
}

TEST_CASE("test Matrix  Matrix2D: determinant() 2"){
    double tab[2][2] = {{3,2},{3,4}};
    Matrix2D a(tab);
    double det; 
    det = 6;
    CHECK ((a.determinant()) == det);
}

TEST_CASE("test Matrix  Matrix2D: multiply() 1"){
    double tab[2][2] = {{3,2},{3,4}};
    Matrix2D a(tab);  
    Matrix2D b;
    double tab_res[2][2] = {{3,2},{3,4}};
    Matrix2D res(tab_res);
    CHECK (a*b == res);
}

TEST_CASE("test Matrix  Matrix2D: multiply() 2"){
    double tab[2][2] = {{1,2},{3,4}};
    Matrix2D a(tab);  
    Matrix2D b(tab);
    double tab_res[2][2] = {{7,10},{15,22}};
    Matrix2D res(tab_res);
    CHECK (a*b == res);
}

TEST_CASE("test Matrix Matrix2D: multiply() 3"){
    double tab[2][2] = {{-1,0},{12,4}};
    double tab2[2][2] = {{12,7},{1,5}};
    Matrix2D a(tab);  
    Matrix2D b(tab2);
    double tab_res[2][2] = {{-12,-7},{148,104}};
    Matrix2D res(tab_res);
    CHECK (a*b == res);
}