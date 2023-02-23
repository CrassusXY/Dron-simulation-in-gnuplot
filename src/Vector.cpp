#include "Vector.hh"
#include <cmath>

template<int SIZE>
const double & Vector<SIZE>::operator [] (int ind) const
{
    if(ind < 0 || ind > SIZE){
       throw std::logic_error("Niepoprawny index wektora");
    }
    else{
        return xy[ind];
    }
}

template<int SIZE>
double & Vector<SIZE>::operator [] (int ind)
{
    if(ind < 0 || ind > SIZE){
       throw std::logic_error("Niepoprawny index wektora");
    }
    else{
        return xy[ind];
    }
}

template<int SIZE>
Vector<SIZE> Vector<SIZE>::operator+ (const Vector<SIZE> & arg2) const
{
    Vector<SIZE> tmp;
    for(int i = 0; i <SIZE; i++){
        tmp[i]=(xy[i]+arg2[i]);
    }
    return tmp;
}

template<int SIZE>
Vector<SIZE> Vector<SIZE>::operator- (const Vector<SIZE> & arg2) const
{
    Vector<SIZE> tmp;
    for(int i = 0; i <SIZE; i++){
        tmp[i]=(xy[i]-arg2[i]);
    }
    return tmp;
}

template<int SIZE>
double Vector<SIZE>::operator* (const Vector<SIZE> & arg2) const
{
    double sum;
    for(int i = 0; i <SIZE; i++){
        sum += (xy[i]*arg2[i]);
    }
    return sum;
}

template<int SIZE>
double Vector<SIZE>::operator* (const double & arg) const
{
    double sum;
    for(int i = 0; i <SIZE; i++){
        sum += (xy[i]*arg);
    }
    return sum;
}

template<int SIZE>
double Vector<SIZE>::length() const
{
    double sum;
    for(int i = 0; i <SIZE; i++){
        sum += (xy[i]*xy[i]);
    }
    return(sqrt(sum));
}


template<int SIZE>
std::ostream & operator << (std::ostream & strm, const Vector<SIZE> & vector)
{
    int i;
    strm << "[";
    for(i = 0; i <(SIZE-1); i++)
    {
        strm << vector[i] << ", ";
    }
    strm << vector[i] << "]";
    return strm;
}

drawNS::Point3D convert (Vector<3> arg)
{
    return drawNS::Point3D(arg[0], arg[1], arg[2]);
}


template class Vector <2>;
template class Vector <3>;
template class Vector <6>;

template std::ostream& operator<< (std::ostream & strm, const Vector<2> & vector);
template std::ostream& operator<< (std::ostream & strm, const Vector<3> & vector);
template std::ostream& operator<< (std::ostream & strm, const Vector<6> & vector);