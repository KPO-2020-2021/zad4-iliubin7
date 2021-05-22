#include "../include/cuboid.hpp"

Cuboid::Cuboid()
{
    double tab[NUMBEROFVERTEX][SIZE] = {{0, 0, 0}, {1, 0, 0}, {1, 1, 0}, {0, 1, 0}};
    for (int i = 0; i < 4; ++i)
    {
        vc3[0][i] = Vector3D(tab[i]);
        tab[i][2] = 1;
        vc3[1][i] = Vector3D(tab[i]);
    }
}

Cuboid::Cuboid(Vector3D const (&ar)[SIZE2D][NUMBEROFVERTEX])
{
    for (int i = 0; i < 4; ++i)
    {
        vc3[0][i] = ar[0][i];
        vc3[1][i] = ar[1][i];
    }
}

Cuboid::Cuboid(double (&ar3)[SIZE2D][NUMBEROFVERTEX][SIZE])
{
    Vector3D ar[SIZE2D][NUMBEROFVERTEX];
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            ar[0][i] = Vector3D(ar3[0][i]);
            ar[1][i] = Vector3D(ar3[1][i]);
        }
    }
    for (int i = 0; i < 4; ++i)
    {
        ar[0][i] = ar3[0][i];
        ar[1][i] = ar3[1][i];
    }
}

void Cuboid::new_vect(Vector3D (&vx)[SIZE][SIZE2D]) const
{
    vx[0][0] = vc3[0][1] - vc3[0][0];
    vx[0][1] = vc3[1][2] - vc3[1][3];
    vx[1][0] = vc3[1][1] - vc3[0][1];
    vx[1][1] = vc3[1][3] - vc3[0][3];
    vx[2][0] = vc3[0][3] - vc3[0][0];
    vx[2][1] = vc3[1][2] - vc3[1][1];
}

bool Cuboid::check_length_of_v() const
{
    Vector3D opp[3][2];
    this->new_vect(opp);
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 2; ++j)
        {
            if (opp[i][j].get_length() == 0)
                return 0;
        }
    }
    return 1;
}

void Cuboid::write_to_ar(double (&tab)[SIZE][SIZE2D]) const
{
    int i;
    Vector3D opp[3][2];
    this->new_vect(opp);
    for (i = 0; i < 3; ++i)
    {
            tab[i][0] = opp[i][0].get_length();
            tab[i][1] = opp[i][1].get_length();
    }
    if (tab[0]<tab[1]){
        double tmp[2]={tab[0][0],tab[0][1]};
        tab[0][0]=tab[1][0];
        tab[0][1]=tab[1][1];
        tab[1][0]=tmp[1];
        tab[1][1]=tmp[0];
    }

}

bool Cuboid::check_v() const
{
    Vector3D n[3][2];
    this->new_vect(n);
    for (int i = 0; i < 3; ++i)
    {
        if (!(n[i][0] == n[i][1]))
            return 0;
    }
    return 1;
}

void Cuboid::ret_vec(Vector3D (&v)[SIZE2D][SIZE]) const
{
    v[0][0] = vc3[0][2] - vc3[0][1];
    v[0][1] = vc3[1][1] - vc3[0][1];
    v[0][2] = vc3[0][0] - vc3[0][1];

    v[1][0] = vc3[1][0] - vc3[1][3];
    v[1][1] = vc3[0][3] - vc3[1][3];
    v[1][2] = vc3[1][2] - vc3[1][3];
}

bool Cuboid::check_vec_eq() const
{
    Vector3D vecs[SIZE2D][SIZE];
    this->ret_vec(vecs);
    for (int i = 0; i < 2; ++i)
    {
        if (!(vecs[i][0].v_scalar(vecs[i][1]) <= 0.0000000001))
            return 0;
        if (!(vecs[i][0].v_scalar(vecs[i][2]) <= 0.0000000001))
            return 0;
        if (!(vecs[i][1].v_scalar(vecs[i][2]) <= 0.0000000001))
            return 0;
    }
    return 1;
}

bool Cuboid::check_cube() const
{
    if (!(check_v() && check_vec_eq() && check_length_of_v()))
        return 0;
    return 1;
}

bool Cuboid::operator==(const Cuboid &cube) const
{
    for (int i = 0; i < 2; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            if (vc3[i][j] == cube.vc3[i][j])
                return 1;
        }
    }
    return 0;
}

Cuboid Cuboid::translation(Vector3D const &tr) const
{
    Cuboid translated;
    for (int i = 0; i < 2; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            translated.vc3[i][j] = vc3[i][j] + tr;
        }
    }
    return translated;
}

Cuboid Cuboid::rotation(Matrix3D const &mat) const
{
    Cuboid rotated;
    for (int i = 0; i < 2; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            rotated.vc3[i][j] = mat.rotation_of_three(vc3[i][j]);
        }
    }
    return rotated;
}
void Cuboid::ret_cube1(Vector3D (&ar)[SIZE2D][NUMBEROFVERTEX]) const
{
    for (int i = 0; i < 4; ++i)
    {
        ar[0][i] = vc3[0][i];
        ar[1][i] = vc3[1][i];
    }
}

void Cuboid::ret_cube2(double (&ar)[SIZE2D][NUMBEROFVERTEX][SIZE]) const
{
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            ar[0][i][j] = vc3[0][i][j];
            ar[1][i][j] = vc3[1][i][j];
        }
    }
}
void Cuboid::print_cuboid1(std::ostream &out) const
{
    out.precision(10);
    double vecs[SIZE2D][NUMBEROFVERTEX][SIZE];
    this->ret_cube2(vecs);
    for (int i=0;i<2;++i){
        for (int j=0;j<4;++j){
            for (int k=0;k<3; ++k){
                out << std::setw(10) << std::fixed << std::setprecision(10) << vecs[i][j][k] << " ";
            }
            if(j==1 || j==3)
                    out<<std::endl;
            out<<std::endl;
        }
    }
    for (int i=0;i<1;++i){
        for (int j=0;j<2;++j){
            for (int k=0;k<3; ++k){
                out << std::setw(10) << std::fixed << std::setprecision(10) << vecs[i][j][k] << " ";
            }
            out<<std::endl;
        }
    }
}

void Cuboid::print_cuboid2(std::ostream &out) const
{
    Vector3D vec[8];
    double array[SIZE2D][NUMBEROFVERTEX][SIZE];
    vc3[0][0].get_vec(array[0][0]);  //W1
    vc3[0][1].get_vec(array[0][1]);  //W2
    vc3[0][3].get_vec(array[0][2]);  //W3
    vc3[0][2].get_vec(array[0][3]);  //W4
    vc3[1][3].get_vec(array[1][0]);  //W5
    vc3[1][2].get_vec(array[1][1]);  //W6
    vc3[1][0].get_vec(array[1][2]);  //W7
    vc3[1][1].get_vec(array[1][3]);  //W8
    
    out.precision(10);
    for (int i=0;i<2;++i){
        for (int j=0;j<4;++j){
            for (int k=0;k<3; ++k){
                out << std::setw(10) << std::fixed << std::setprecision(10) << array[i][j][k] << " ";
            }
            if(j==1 || j==3)
                    out<<std::endl;
            out<<std::endl;
        }
    }
    for (int i=0;i<1;++i){
        for (int j=0;j<2;++j){
            for (int k=0;k<3; ++k){
                out << std::setw(10) << std::fixed << std::setprecision(10) << array[i][j][k] << " ";
            }
            out<<std::endl;
        }
    }
}

std::ostream &operator<<(std::ostream &Strm, 
                            const Cuboid    &Pr)
{
    Strm.precision(10);
    Vector3D v[SIZE2D][NUMBEROFVERTEX];
    Pr.ret_cube1(v);
    Strm << "Wierzcholek A: " << std::endl
        << v[0][0] << std::endl;
    Strm << "Wierzcholek B: " << std::endl
        << v[0][1] << std::endl;
    Strm << "Wierzcholek C: " << std::endl
        << v[0][2] << std::endl;
    Strm << "Wierzcholek D: " << std::endl
        << v[0][3] << std::endl;
    Strm << "Wierzcholek E: " << std::endl
        << v[1][0] << std::endl;
    Strm << "Wierzcholek F: " << std::endl
        << v[1][1] << std::endl;
    Strm << "Wierzcholek G: " << std::endl
        << v[1][2] << std::endl;
    Strm << "Wierzcholek H: " << std::endl
        << v[1][3] << std::endl;

    return Strm;
}
