#include "../include/vector.hpp"

template <typename type, unsigned int SIZE>
Vector<type,SIZE>::Vector()
{
    for( unsigned int i = 0; i < SIZE; ++i)
    {
        size[i] = 0.0;
    }
}
template <typename type, unsigned int SIZE>
Vector<type,SIZE>::Vector(type tmp[SIZE])
{
    for(unsigned int i = 0; i < SIZE; ++i)
    {
        size[i] = tmp[i];
    }
}
template <typename type, unsigned int SIZE>
 Vector<type, SIZE>::~Vector(){}

template <typename type, unsigned int SIZE>
Vector<type, SIZE> Vector<type, SIZE>::operator+(const Vector<type, SIZE> &v) const
{
    Vector result;
    for (unsigned int i = 0; i < SIZE; ++i) {
        result[i] = size[i] + v[i];
    }
    return result;
}

template <typename type, unsigned int SIZE>
Vector<type, SIZE> Vector<type, SIZE>::operator-(const Vector<type, SIZE> &v) const
{
    Vector result;
    for (unsigned int i = 0; i < SIZE; ++i)
    {
        result[i] = size[i] - v[i];
    }
    return result;
}

template <typename type, unsigned int SIZE>
Vector<type, SIZE> Vector<type, SIZE>::operator*(const type &tmp) const
{
    Vector result;
    for (unsigned int i = 0; i < SIZE; ++i) {
        result[i] = size[i] * tmp;
    }
    return result;
}

template <typename type, unsigned int SIZE>
Vector<type, SIZE> Vector<type, SIZE>::operator/(const type &tmp) const
{
    Vector result;
    if( tmp == 0)
    {
        std::cerr << "ERROR: Nie mozna dzielic przez 0 !" << std::endl;
        return *this;
    }
    for(unsigned i = 0; i < SIZE; ++i)
    {
        result[i] = size[i] / tmp;
    }
    return result;
}
template <typename type, unsigned int SIZE>
type Vector<type, SIZE>::modul2() const
{
    type result = 0;
    for(unsigned i=0; i < SIZE; i++)
    {
        result += pow(size[i], 2);
    }
    return result;
}
template <typename type, unsigned int SIZE>
type Vector<type, SIZE> ::get_length() const
{
    double len, mod2;
    Vector tmp;
    tmp = *this;
    mod2 = tmp.modul2();
    len = pow(mod2, 1.0 / SIZE);

    return len;
}

template <typename type, unsigned int SIZE>
void Vector<type, SIZE>::vector_zmien(type (&tab)[SIZE]) const
{
    for(unsigned int i=0; i<SIZE; ++i)
    {
        tab[i] = size[i];
    }
}

template <typename type, unsigned int SIZE>
bool Vector<type, SIZE>::operator==(const Vector &v) const
{
    for (unsigned int i=0;i<SIZE;i++){
        if ((abs(size[i] - v.size[i]) <= MIN_DIFF))
            return true;
    }
    return false;
}
template <typename type, unsigned int SIZE> 
type Vector<type,SIZE>::v_scalar(Vector<type,SIZE> const & vec) const{
    type result;
    result = 0;
    for (unsigned int i=0;i<SIZE;++i){
        result+= size[i]*vec.size[i];
    }
    return result;
}

template <typename type, unsigned int SIZE>
const type &Vector<type, SIZE>::operator [] (unsigned int index) const
{
    if (index < 0 || index >= SIZE) {
        std::cerr << "Error: Wektor jest poza zasiegiem!" << std::endl;
    }
    return size[index];
}

template <typename type, unsigned int SIZE>
type &Vector<type, SIZE>::operator [] (unsigned int index)
{
    return const_cast<double &>(const_cast<const Vector *>(this)->operator[](index));
}

template <typename type, unsigned int SIZE>
std::ostream &operator << (std::ostream &out, Vector<type,SIZE> const &tmp)
{
    for (unsigned int i = 0; i < SIZE; ++i) {
        out << "[ " << tmp[i] << " ]\n";
    }
    return out;
}

template <typename type, unsigned int SIZE>
std::istream &operator >> (std::istream &in, Vector<type,SIZE> &tmp)
{
    for (unsigned int i = 0; i < SIZE; ++i) {
        in >> tmp[i];
    }
    std::cout << std::endl;
    return in;
}

