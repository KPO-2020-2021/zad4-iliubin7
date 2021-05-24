#include"../tests/doctest/doctest.h"

#include"vector3D.hpp"

TEST_CASE("test Vector3D konstruktor bezparametryczny oraz przeciazenie strumienia wyjsciowego<<"){
Vector3D a;

    std::ostringstream out;
    out << a; 

    CHECK("[ 0.0000000000 ]\n[ 0.0000000000 ]\n[ 0.0000000000 ]\n" == out.str());
}


TEST_CASE("test Vector3D konstruktor parametryczny oraz przeciazenie strumienia #include <cmath>wyjsciowego << i wejsciowego >>"){
    Vector3D a;
    std::istringstream in("1.0 5.0 6.0");
    in >> a;
    std::ostringstream out;
    out << a; 

    CHECK("[ 1.0000000000 ]\n[ 5.0000000000 ]\n[ 6.0000000000 ]\n" == out.str());
}

TEST_CASE("test Vector3D konstruktor parametryczny dla malych wartosci oraz przeciazenie strumienia wyjsciowego << i wejsciowego >>"){
    Vector3D a;
    std::istringstream in("0.0000000001 0.0000000005 0.0000000005");
    in >> a;
    std::ostringstream out;
    out << a; 

    CHECK("[ 0.0000000001 ]\n[ 0.0000000005 ]\n[ 0.0000000005 ]\n" == out.str());
}

TEST_CASE("test Vector3D konstruktor parametryczny dla duzych wartosci oraz przeciazenie strumienia wyjsciowego << i wejsciowego >>"){
    Vector3D a;
    std::istringstream in("12345678 12345678 12345678");
    in >> a;
    std::ostringstream out;
    out << a; 

    CHECK("[ 12345678.0000000000 ]\n[ 12345678.0000000000 ]\n[ 12345678.0000000000 ]\n" == out.str());
}

TEST_CASE("test Vector3D dodawanie wektorow"){
    double tab[3][3] = {{4,2,1},{2,7,1}, {6,9,2}};
    Vector3D a(tab[0]);
    Vector3D b(tab[1]);
    Vector3D res(tab[2]);

    Vector3D sum = a+b;
    CHECK(res == sum);
}

TEST_CASE("test Vector3D dodawanie wektorow dla malych wartosci 1"){
    double tab[3][3] = {{0.0000000004,0.0000000002,1},{0.0000000002,0.0000000007,1}, {0.0000000006,0.0000000009,2}};
    Vector3D a(tab[0]);
    Vector3D b(tab[1]);
    Vector3D res(tab[2]);

    Vector3D sum = a+b;
    CHECK(res == sum);
}

TEST_CASE("test Vector3D dodawanie wektorow dla malych wartosci 2"){
    double tab[3][3] = {{0.00000000004,0.00000000002,1},{0.00000000002,0.00000000007,1}, {0.00000000006,0.00000000009,2}};
    Vector3D a(tab[0]);
    Vector3D b(tab[1]);
    Vector3D res(tab[2]);

    Vector3D sum = a+b;
    CHECK(res == sum);
}

TEST_CASE("test Vector3D dodawanie wektorow dla duzych wartosci, granicze wartosci"){
    double tab[3][3] = {{99999,99999,1},{1,1,1},{100000,100000,2}};
    Vector3D a(tab[0]);
    Vector3D b(tab[1]);
    Vector3D res(tab[2]);

    Vector3D sum = a+b;
    CHECK(res == sum);
}

TEST_CASE("test Vector3D odejmowanie wektorow"){
    double tab[3][3] = {{4,2,1},{2,7,0}, {2,-5,1}};
    Vector3D a(tab[0]);
    Vector3D b(tab[1]);
    Vector3D res(tab[2]);

    Vector3D sum = a-b;
    CHECK(res == sum);
}

TEST_CASE("test Vector3D odejmowanie wektorow dla malych wartosci 1"){
    double tab[3][3] = {{0.0000000004,0.0000000002,1},{0.0000000002,0.0000000007,0}, {0.0000000002,-0.0000000005,1}};
    Vector3D a(tab[0]);
    Vector3D b(tab[1]);
    Vector3D res(tab[2]);

    Vector3D sum = a-b;
    CHECK(res == sum);
}

TEST_CASE("test Vector3D odejmowanie wektorow dla malych wartosci 2"){
    double tab[3][3] = {{0.00000000004,0.00000000002,1},{0.00000000002,0.00000000007,0}, {0.00000000004,-0.00000000005,1}};
    Vector3D a(tab[0]);
    Vector3D b(tab[1]);
    Vector3D res(tab[2]);

    Vector3D sum = a+b;
    CHECK(res == sum);
}

TEST_CASE("test Vector3D odejmowanie wektorow dla duzych wartosci, granicze wartosci"){
    double tab[3][3] = {{99999,99999,1},{1,1,0},{100000,100000,1}};
    Vector3D a(tab[2]);
    Vector3D b(tab[0]);
    Vector3D res(tab[1]);

    Vector3D sum = a-b;
    CHECK(res == sum);
}

TEST_CASE("test Vector3D mnozenie wektorow przez skalar 1"){
    double tab[2][3] = {{4,2,1},{136,68,34}};
    double tmp;
    Vector3D a(tab[0]);
    tmp =34;
    Vector3D b = a*tmp;
    Vector3D res(tab[1]);

    
    CHECK(res == b);
}

TEST_CASE("test Vector3D mnozenie wektorow przez skalar 2"){
    double tab[2][3] = {{4,2,1},{0.000000004,0.0000000002,0.0000000001}};
    double tmp;
    Vector3D a(tab[0]);
    tmp =0.000000001;
    Vector3D b = a*tmp;
    Vector3D res(tab[1]);

    
    CHECK(res == b);
}

TEST_CASE("test Vector3D mnozenie wektorow przez 0"){
    double tab[2][3] = {{4,2,1},{0,0,0}};
    double tmp;
    Vector3D a(tab[0]);
    tmp =0;
    Vector3D b = a*tmp;
    Vector3D res(tab[1]);

    
    CHECK(res == b);
}

TEST_CASE("test Vector3D mnozenie wektora zerowego przez skalar"){
    double tab[2][3] = {{0,0,0},{0,0,0}};
    double tmp;
    Vector3D a(tab[0]);
    tmp =1231234;
    Vector3D b = a*tmp;
    Vector3D res(tab[1]);

    
    CHECK(res == b);
}

TEST_CASE("test Vector3D dzielenie wektorow przez skalar"){
    double tab[2][3] = {{4,2,2},{2,1,1}};
    double tmp;
    Vector3D a(tab[0]);
    tmp =2;
    Vector3D b = a/tmp;
    Vector3D res(tab[1]);

    
    CHECK(res == b);
}

TEST_CASE("test Vector3D dzielenie wektorow przez maly skalar"){
    double tab[2][3] = {{4,2,1},{40000000000,20000000000,10000000000}};
    double tmp;
    Vector3D a(tab[0]);
    tmp =0.000000001;
    Vector3D b = a/tmp;
    Vector3D res(tab[1]);

        CHECK(!(a == b));

}

TEST_CASE("test Vector3D dzielenie wektora zerowego przez skalar"){
    double tab[2][3] = {{0,0,0},{0,0,0}};
    double tmp;
    Vector3D a(tab[0]);
    tmp =1231234;
    Vector3D b = a*tmp;
    Vector3D res(tab[1]);

    
    CHECK(res == b);
}

TEST_CASE("test Vector3D: modul2 1"){
    double tab[2][3] = {{3,4,1}};
    double res;
    Vector3D a(tab[0]);
    res = 26;
    
        CHECK((res == a.modul2()));
}

TEST_CASE("test Vector3D::modul2 2"){
    double tab[2][3] = {{0.003,0.004,1}};
    double res;
    Vector3D a(tab[0]);
    res = 1.000025;

        CHECK((abs(res - a.modul2())<=0.0001));
}

TEST_CASE("test Vector3D: modul2 3"){
    double tab[2][3] = {{0,0,0}};
    double res;
    Vector3D a(tab[0]);
    res = 0;
    
        CHECK((res == a.modul2()));
}

TEST_CASE("test Vector3D::modul2 4"){
    double tab[2][3] = {{-3,-4,1}};
    double res;
    Vector3D a(tab[0]);
    res = 26;
    
        CHECK((res == a.modul2()));
}

TEST_CASE("test Vector3D::get_length 1"){
    double tab[2][3] = {{1,2,2}};
    double res;
    Vector3D a(tab[0]);
    res = 3;
    
        CHECK((res == a.get_length()));
}

TEST_CASE("test Vector3D::get_length 2"){
    double tab[2][3] = {{0.001,0.002,0.002}};
    double res;
    Vector3D a(tab[0]);
    res = 0.003;
        CHECK((abs(res - a.get_length())) <= 0.00001);
}

TEST_CASE("test Vector3D: get_length 3"){
    double tab[2][3] = {{0,0,0}};
    double res;
    Vector3D a(tab[0]);
    res = 0;
    
        CHECK((res == a.get_length()));
}

TEST_CASE("test Vector3D:get_lenth 4"){
    double tab[2][3] = {{-5,-12,0}};
    double res;
    Vector3D a(tab[0]);
    res = 13;
    
        CHECK((res == a.get_length()));
}
TEST_CASE("test operator [] 1"){
    double tab[2][3] = {{3,1,0}};
    double res;
    Vector3D a(tab[0]);
    res = 3;

    CHECK (abs(res - a[0])<= 0.000001);
}

TEST_CASE("test operator [] 2"){
    double tab[2][3] = {{3,1,0}};
    double res;
    Vector3D a(tab[0]);
    res = 1;

    CHECK (abs(res - a[1])<= 0.000001);
}

TEST_CASE("test operator [] 3"){
    double tab[2][3] = {{3,1,0}};
    double res;
    Vector3D a(tab[0]);
    res = 0;

    CHECK (abs(res - a[2])<= 0.000001);
}

TEST_CASE("test operator const [] 4"){
    double tab[2][2] = {{3,1}};
    double res;
    Vector3D a(tab[0]);
    res = 1;

    double b = a[1];
    CHECK (abs(res - b)<= 0.000001);
}

TEST_CASE("test iloczyn skalarny 1"){
    double tab[3] = {3,1,7};
    double tab2[3] = {3,1,2};
    double res;
    Vector3D a(tab);
    Vector3D b(tab2);
    res = 24;

    CHECK (abs(res - a.v_scalar(b))<= 0.000001);
}

TEST_CASE("test iloczyn scalarny 2"){
    double tab[3] = {3,1,7};
    double tab2[3] = {3,1,2};
    double res;
    Vector3D a(tab);
    Vector3D b(tab2);
    res = 24;

    CHECK (abs(res - a.v_scalar(b))<= 0.000001);
}

TEST_CASE("test iloczyn scalarny 3"){
    double tab[3] = {3,1,-7};
    double tab2[3] = {3,1,2};
    double res;
    Vector3D a(tab);
    Vector3D b(tab2);
    res = -4;

    CHECK (abs(res - a.v_scalar(b))<= 0.000001);
}

TEST_CASE("test iloczyn skalarny 4"){
    double tab[3] = {0,0,0};
    double tab2[3] = {0,0,0};
    double res;
    Vector3D a(tab);
    Vector3D b(tab2);
    res = 0;

    CHECK (abs(res - a.v_scalar(b))<= 0.000001);
}

TEST_CASE("test iloczyn scalarny 5"){
    double tab[3] = {-3,1,-7};
    double tab2[3] = {3,1,2};
    double res;
    Vector3D a(tab);
    Vector3D b(tab2);
    res = -22;

    CHECK (abs(res - a.v_scalar(b))<= 0.000001);
}

TEST_CASE("test iloczyn skalarny 6"){
    double tab[3] = {-3,-1,-7};
    double tab2[3] = {-3,-1,-2};
    double res;
    Vector3D a(tab);
    Vector3D b(tab2);
    res = 24;

    CHECK (abs(res - a.v_scalar(b))<= 0.000001);
}

TEST_CASE("test vector_zmien 1"){
    double tab[3] = {-3,1,-7};
    Vector3D a(tab);
    double tab2[3];
    a.vector_zmien(tab2);
    for (int i=0;i<3;++i){
    CHECK (tab[i] == tab2[i]);
    }
}

TEST_CASE("test vector_zmien 2"){
    double tab[3] = {-1231,3214,415413};
    Vector3D a(tab);
    double tab2[3];
    a.vector_zmien(tab2);
    int i;
    for (i=0;i<3;++i){
    CHECK (tab[i] == tab2[i]);
    }
}

TEST_CASE("test vector_zmien 3"){
    double tab[3] = {-0.00000003,2142141,-0.0092419847};
    Vector3D a(tab);
    double tab2[3];
    a.vector_zmien(tab2);
    int i;
    for (i=0;i<3;++i){
    CHECK (tab[i] == tab2[i]);
    }
}

TEST_CASE("test vector_zmien 4"){
    double tab[3] = {1244,423525,0.000003};
    Vector3D a(tab);
    double tab2[3];
    a.vector_zmien(tab2);
    int i;
    for (i=0;i<3;++i){
    CHECK (tab[i] == tab2[i]);
    }
}

TEST_CASE("test vector_zmien 5"){
    double tab[3] = {0,0,0};
    Vector3D a(tab);
    double tab2[3];
    a.vector_zmien(tab2);
    int i;
    for (i=0;i<3;++i){
    CHECK (tab[i] == tab2[i]);
    }
}