#include"../tests/doctest/doctest.h"
#include"matrix3D.hpp"
#include"vector3D.hpp"

TEST_CASE("test konstruktor bezparametryczny i przeciazenie operatorow << >> 1"){
    //double tab[3][3] = {{3,1}};
    Matrix3D a;
    std::ostringstream out;
    out << a; // 
    CHECK (out.str() == "| 1.0000000000 * | 0.0000000000 * | 0.0000000000 * | 0.0000000000 * | 1.0000000000 * | 0.0000000000 * | 0.0000000000 * | 0.0000000000 * | 1.0000000000 * ");
}

TEST_CASE("test  konstruktor parametryczny i przeciazenie operatorow << >> 2"){
    double tab[3][3] = {{3,1,0},{3,1,0},{3,1,0}};
    Matrix3D a(tab);
    std::ostringstream out;
    out << a; // 
    CHECK (out.str() == "| 3.0000000000 * | 1.0000000000 * | 0.0000000000 * | 3.0000000000 * | 1.0000000000 * | 0.0000000000 * | 3.0000000000 * | 1.0000000000 * | 0.0000000000 * ");
}

TEST_CASE("test  konstruktor parametryczny i przeciazenie operatorow << >> 3"){
    double tab[3][3] = {{0.0003,0.0001,0},{0.0003,0.0001,0},{0.0003,0.0001,0}};
    Matrix3D a(tab);
    std::ostringstream out;
    out << a; // 
    CHECK (out.str() == "| 0.0003000000 * | 0.0001000000 * | 0.0000000000 * | 0.0003000000 * | 0.0001000000 * | 0.0000000000 * | 0.0003000000 * | 0.0001000000 * | 0.0000000000 * ");
}

TEST_CASE("test  konstruktor parametryczny i przeciazenie operatorow << >> 4"){
    double tab[3][3] = {{-0.0003,0.0001,0},{0.0003,-0.0001,0},{0,0,0}};
    Matrix3D a(tab);
    std::ostringstream out;
    out << a; // 
    CHECK (out.str() == "| -0.0003000000 * | 0.0001000000 * | 0.0000000000 * | 0.0003000000 * | -0.0001000000 * | 0.0000000000 * | 0.0000000000 * | 0.0000000000 * | 0.0000000000 * ");
}

TEST_CASE("test  konstruktor parametryczny i przeciazenie operatorow << >> 5"){
    double tab[3][3] = {{0,0,0},{0,0,0},{0,0,0}};
    Matrix3D a(tab);
    std::ostringstream out;
    out << a; // 
    CHECK (out.str() == "| 0.0000000000 * | 0.0000000000 * | 0.0000000000 * | 0.0000000000 * | 0.0000000000 * | 0.0000000000 * | 0.0000000000 * | 0.0000000000 * | 0.0000000000 * ");
}

TEST_CASE("test   przeciazenie operatorow << >> 6"){
    double tab[3][3] = {{0,0,0},{0,0,0},{0,0,0}};
    Matrix3D a(tab);
    std::istringstream in("1 2 3 4 5 6 7 8 9");
    in >> a;
    std::ostringstream out;
    out << a; // 
    CHECK (out.str() == "| 1.0000000000 * | 2.0000000000 * | 3.0000000000 * | 4.0000000000 * | 5.0000000000 * | 6.0000000000 * | 7.0000000000 * | 8.0000000000 * | 9.0000000000 * ");
}

TEST_CASE("test Matrix operator * (vector) 1"){
    double tab[3][3] = {{1,0,0},{0,1,0},{0,0,1}};
    double vec[3] = {1,2,3};
    Matrix3D a(tab);
    Vector3D b(vec);

    Vector3D c(vec);

    CHECK (c==(a*b));
}

TEST_CASE("test Matrix operator * (vector) zero 2"){
    double tab[3][3] = {{0,0,0},{0,0,0},{0,0,0}};
    double vec[3] = {0,0,0};
    Matrix3D a(tab);
    Vector3D b(vec);

    Vector3D c(vec);

    CHECK (c==(a*b));
}

TEST_CASE("test Matrix operator * (vector) 3"){
    double tab[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
    double vec[3] = {1,-1,1};
    double res[3] = {2,5,8};
    Matrix3D a(tab);
    Vector3D b(vec);

    Vector3D c(res);

    CHECK (c==(a*b));
}

TEST_CASE("test Matrix operator +   N1"){
    double tab[3][3] = {{1,2,0},{3,4,0},{0,0,0}};
    double tab2[3][3] = {{4,3,0},{2,1,0},{0,0,0}};
    double res[3][3] = {{5,5,0},{5,5,0},{0,0,0}};

    Matrix3D a(tab);
    Matrix3D b(tab2);

    Matrix3D c(res);

    CHECK (c==(a+b));
}

TEST_CASE("test Matrix operator + 0   N2"){
    double tab[3][3] = {{1,2,0},{3,4,0},{0,0,0}};
    double tab2[3][3] = {{0,0,0},{0,0,0},{0,0,0}};
    double res[3][3] = {{1,2,0},{3,4,0},{0,0,0}};

    Matrix3D a(tab);
    Matrix3D b(tab2);

    Matrix3D c(res);

    CHECK (c==(a+b));
}

TEST_CASE("test Matrix operator +     N3"){
    double tab[3][3] = {{1,2,0},{3,4,0},{0,0,0}};
    double tab2[3][3] = {{0.0000000001,0.0000000001,0},{0.0000000001,0.0000000001,0},{0,0,0}};
    double res[3][3] = {{1.0000000001,2.0000000001,0},{3.0000000001,4.0000000001,0},{0,0,0}};

    Matrix3D a(tab);
    Matrix3D b(tab2);

    Matrix3D c(res);

    CHECK (c==(a+b));
}

TEST_CASE("test Matrix operator () 1"){
    double tab[3][3] = {{1,2,0},{3,4,0},{0,0,0}};
    double res = 1;

    Matrix3D a(tab);

    CHECK (res == a(0,0));
}

TEST_CASE("test Matrix operator () 2"){
    double tab[3][3] = {{1,0.00002,0},{3,4,0},{0,0,0}};
    double res = 0.00002;

    Matrix3D a(tab);

    CHECK (res == a(0,1));
}

TEST_CASE("test Matrix operator () 3"){
    double tab[3][3] = {{1,2,0},{-3,4,0},{0,0,0}};
    double res = -3;

    Matrix3D a(tab);

    CHECK (res == a(1,0));
}

TEST_CASE("test Matrix operator () 4"){
    double tab[3][3] = {{1,2,0},{-3,0,0},{0,0,0}};
    double res = 0;

    Matrix3D a(tab);

    CHECK (res == a(1,1));
}

TEST_CASE("test Matrix Matrix3D: gauss() 1"){
    double tab[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
    double tab2[3][3] = {{1,2,3},{0,-3,-6},{0.6,0,-0.6}};
    Matrix3D a(tab);
    Matrix3D b(tab2);

    CHECK ((a.gauss()) == b);
}

TEST_CASE("test Matrix Matrix3D: gauss() 2"){
    double tab[3][3] = {{3,2},{3,4}};
    double tab2[3][3] = {{3,2},{0,2}};
    Matrix3D a(tab);
    Matrix3D b(tab2);

    CHECK ((a.gauss()) == b);
}

TEST_CASE("test Matrix Matrix3D: determinant() 1"){
    double tab[3][3] = {{1,2},{3,4}};
    Matrix3D a(tab);
    double det; 
    det = 0;
    CHECK ((a.determinant()) == det);
}

TEST_CASE("test Matrix Matrix3D: determinant() 2"){
    double tab[3][3] = {{3,2},{3,4}};
    Matrix3D a(tab);
    double det; 
    det = 0;
    CHECK ((a.determinant()) == det);
}

TEST_CASE("test Matrix Matrix3D: multiply() 1"){
    double tab[3][3] = {{3,2,1},{3,4,1},{1,1,1}};
    Matrix3D a(tab);  //macierz jednostkowa
    Matrix3D b;
    double tab_res[3][3] = {{3,2,1},{3,4,1},{1,1,1}};
    Matrix3D res(tab_res);
    CHECK (a*b == res);
}

TEST_CASE("test Matrix Matrix3D: multiply() 2"){
    double tab[3][3] = {{1,2},{3,4}};
    Matrix3D a(tab);  //macierz jednostkowa
    Matrix3D b(tab);
    double tab_res[3][3] = {{7,10},{15,22}};
    Matrix3D res(tab_res);
    CHECK (a*b == res);
}

TEST_CASE("test Matrix Matrix3D: multiply() 3"){
    double tab[3][3] = {{4,2,4},{4,21,4},{6,9,8}};
    double tab2[3][3] = {{1,3,2},{4,2,1},{4,3,2}};
    Matrix3D a(tab);  //macierz jednostkowa
    Matrix3D b(tab2);
    double tab_res[3][3] = {{28,28,18},{104,66,37},{74,60,37}};
    Matrix3D res(tab_res);
    CHECK (a*b == res);
}

TEST_CASE("test Matrix 3D rotation x"){
    Matrix3D a;
    a = a.MatrixRotate(90,'x');
    double tab[3][3] = {{1,0,0},{0,0,-1},{0,1,0}};
    Matrix3D b(tab);    
    CHECK (a == b);
}

TEST_CASE("test Matrix 3D rotation x 2"){
    Matrix3D a;
    a = a.MatrixRotate(180,'x');
    double tab[3][3] = {{1,0,0},{0,-1,0},{0,0,-1}};
    Matrix3D b(tab);    
    CHECK (a == b);
}

TEST_CASE("test Matrix 3D rotation x 3"){
    Matrix3D a;
    a = a.MatrixRotate(450,'x');
    double tab[3][3] = {{1,0,0},{0,0,-1},{0,1,0}};
    Matrix3D b(tab);    
    CHECK (a == b);
}

TEST_CASE("test Matrix 3D rotation y"){
    Matrix3D a;
    a = a.MatrixRotate(0,'y');
    double tab[3][3] = {{1,0,0},{0,1,0},{0,0,1}};
    Matrix3D b(tab);    
    CHECK (a == b);
}

TEST_CASE("test Matrix 3D rotation y 2"){
    Matrix3D a;
    a = a.MatrixRotate(135,'y');
    double tab[3][3] = {{-sqrt(2)/2,0,sqrt(2)/2},{0,1,0},{-sqrt(2)/2,0,-sqrt(2)/2}};
    Matrix3D b(tab);    
    CHECK (a == b);
}

TEST_CASE("test Matrix 3D rotation y 3"){
    Matrix3D a;
    a = a.MatrixRotate(60,'y');
    double tab[3][3] = {{1/2,0,sqrt(3)/2},{0,1,0},{-sqrt(3)/2,0,1/2}};
    Matrix3D b(tab);    
    CHECK (a == b);
}

TEST_CASE("test Matrix 3D rotation z"){
    Matrix3D a;
    a = a.MatrixRotate(360,'z');
    double tab[3][3] = {{1,0,0},{0,1,0},{0,0,1}};
    Matrix3D b(tab);    
    CHECK (a == b);
}

TEST_CASE("test Matrix 3D rotation z 2"){
    Matrix3D a;
    a = a.MatrixRotate(360000000,'z');
    double tab[3][3] = {{1,0,0},{0,1,0},{0,0,1}};
    Matrix3D b(tab);    
    CHECK (a == b);
}

TEST_CASE("test Matrix 3D rotation z 3"){
    Matrix3D a;
    a = a.MatrixRotate(-360000000,'z');
    double tab[3][3] = {{1,0,0},{0,1,0},{0,0,1}};
    Matrix3D b(tab);    
    CHECK (a == b);
}

TEST_CASE("test Matrix 3D rotation multiple axis"){
    Matrix3D a;
    a = a.MatrixRotate(90,'z');
    a = a * a.MatrixRotate(90,'y');
    a = a * a.MatrixRotate(90,'x');
    double tab[3][3] = {{0,0,1},{0,1,0},{-1,0,0}};
    Matrix3D b(tab);    
    CHECK (a == b);
}

TEST_CASE("test Matrix 3D rotation multiple axis"){
    Matrix3D a;
    a = a.MatrixRotate(0,'z');
    a = a * a.MatrixRotate(0,'y');
    a = a * a.MatrixRotate(0,'x');
    double tab[3][3] = {{1,0,0},{0,1,0},{0,0,1}};
    Matrix3D b(tab);    
    CHECK (a == b);
}

TEST_CASE("test Matrix Matrix3D: rotation_of_three() 1"){
    Matrix3D a;
    a = a.MatrixRotate(90,'z');
    double tab[3] = {1,1,1};
    Vector3D v(tab);
    v = a.rotation_of_three(v);
    double tab_res[3] = {-1,1,1}; 
    Vector3D res(tab_res);
    CHECK (v == res);
}

TEST_CASE("test Matrix3D: rotation_of_three() 2"){
    Matrix3D a;
    a = a.MatrixRotate(30,'y');
    double tab[3] = {1,1,1};
    Vector3D vec(tab);
    vec = a.rotation_of_three(vec);
    double tab_res[3] = {1.366025404,1,0.366025404}; 
    Vector3D res(tab_res);
    CHECK (vec == res);
}

TEST_CASE("test Matrix3D: rotation_of_three() 3"){
    Matrix3D a;
    a = a.MatrixRotate(135,'x');
    double tab[3] = {1,1,1};
    Vector3D v(tab);
    v = a.rotation_of_three(v);
    double tab_res[3] = {1,-1.414213562,0}; 
    Vector3D res(tab_res);
    CHECK (v == res);
}

TEST_CASE("test Matrix3D: rotation_of_three() multiple 1"){
    Matrix3D a;
    a = a.MatrixRotate(90,'x');
    a = a * a.MatrixRotate(90,'y');
    a = a * a.MatrixRotate(90,'z');
    double tab[3] = {1,1,1};
    Vector3D v(tab);
    v = a.rotation_of_three(v);
    double tab_res[3] = {1,-1,1}; 
    Vector3D res(tab_res);
    CHECK (v == res);
}

TEST_CASE("test Matrix3D: rotation_of_three() multiple 2"){
    Matrix3D a;
    a = a.MatrixRotate(135,'z');
    a = a * a.MatrixRotate(135,'y');
    a = a * a.MatrixRotate(135,'x');
    double tab[3] = {1,1,1};
    Vector3D v(tab);
    v = a.rotation_of_three(v);
    double tab_res[3] = {1.5,-0.5,-0.7071067812}; 
    Vector3D res(tab_res);
    CHECK (v == res);
}

TEST_CASE("test Matrix3D: rotation_of_three() multiple 3"){
    Matrix3D a;
    a = a.MatrixRotate(270,'z');
    a = a * a.MatrixRotate(180,'y');
    a = a * a.MatrixRotate(135,'x');
    double tab[3] = {1,1,1};
    Vector3D v(tab);
    v = a.rotation_of_three(v);
    double tab_res[3] = {-1.414213562,1,0}; 
    Vector3D res(tab_res);
    CHECK (v == res);
}

TEST_CASE("test Matrix3D: rotation_of_three() multiple 4"){
    Matrix3D a;
    a = a.MatrixRotate(270,'x');
    a = a * a.MatrixRotate(180,'x');
    a = a * a.MatrixRotate(135,'x');
    double tab[3] = {2,1,3};
    Vector3D v(tab);
    v = a.rotation_of_three(v);
    double tab_res[3] = {2,1.414213562,-2.828427125}; 
    Vector3D res(tab_res);
    CHECK (v == res);
}

TEST_CASE("test Matrix3D: rotation_of_three() multiple 5"){
    Matrix3D a;
    a = a.MatrixRotate(270,'y');
    a = a * a.MatrixRotate(180,'y');
    a = a * a.MatrixRotate(135,'y');
    double tab[3] = {6,1,13};
    Vector3D v(tab);
    v = a.rotation_of_three(v);
    double tab_res[3] = {-13.43502884,1,-4.949747468}; 
    Vector3D res(tab_res);
    CHECK (v == res);
}

TEST_CASE("test Matrix3D: rotation_of_three() multiple 6"){
    Matrix3D a;
    a = a.MatrixRotate(270,'x');
    a = a * a.MatrixRotate(180,'y');
    a = a * a.MatrixRotate(135,'z');
    double tab[3] = {2,1,3};
    Vector3D v(tab);
    v = a.rotation_of_three(v);
    double tab_res[3] = {2.121320344,-3,-0.707106781}; 
    Vector3D res(tab_res);
    CHECK (v == res);
}

TEST_CASE("test Matrix3D: rotation_of_three() multiple 7"){
    Matrix3D a;
    a = a.MatrixRotate(270,'z');
    a = a * a.MatrixRotate(180,'y');
    a = a * a.MatrixRotate(135,'x');
    double tab[3] = {2,1,3};
    Vector3D v(tab);
    v = a.rotation_of_three(v);
    double tab_res[3] = {-2.828427125,2,1.414213562}; 
    Vector3D res(tab_res);
    CHECK (v == res);
}



