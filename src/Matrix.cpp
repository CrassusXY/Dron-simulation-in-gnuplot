#include "Matrix.hh"

template <int SIZE>
RotMatrix<SIZE>::RotMatrix(double angle, char axis)
{
    double radian = (angle * M_PI / 180);
    
    switch (axis)
    {
    case 'X':
        rows.push_back(Vector<SIZE>{1.0, 0.0, 0.0});
        rows.push_back(Vector<SIZE>{0.0, cos(radian), -sin(radian)});
        rows.push_back(Vector<SIZE>{0.0, sin(radian), cos(radian)});
        break;
    case 'Y':
        rows.push_back(Vector<SIZE>{cos(radian), 0.0, sin(radian)});
        rows.push_back(Vector<SIZE>{0.0, 1.0, 0.0});
        rows.push_back(Vector<SIZE>{-sin(radian), 0.0, cos(radian)});
        break;
    case 'Z':
        if(SIZE == 3){
            rows.push_back(Vector<SIZE>{cos(radian), -sin(radian), 0.0});
            rows.push_back(Vector<SIZE>{sin(radian), cos(radian), 0.0});
            rows.push_back(Vector<SIZE>{0.0, 0.0, 1.0});
        }
        if(SIZE == 2){
            rows.push_back(Vector<SIZE>{cos(radian), -sin(radian)});
            rows.push_back(Vector<SIZE>{sin(radian), cos(radian)});
        }
        break;
    default:
        break;
    }
}


template <int SIZE>
RotMatrix<SIZE>::RotMatrix()
{
    if(SIZE == 2){
        rows.push_back(Vector<SIZE>{1.0,0.0}); 
        rows.push_back(Vector<SIZE>{0.0,1.0});
    }
    if(SIZE == 3){
        rows.push_back(Vector<SIZE>{1.0, 0.0, 0.0});
        rows.push_back(Vector<SIZE>{0.0, 1.0, 0.0});
        rows.push_back(Vector<SIZE>{0.0, 0.0, 1.0});
    }
}


template<int SIZE>
double RotMatrix<SIZE>::determinant() const
{
    if(SIZE == 2)
       return(rows[0][0] * rows[1][1] - rows[0][1] * rows[1][0]);
    if(SIZE == 3){
        double sum;
        sum = ((rows[0][0]*rows[1][1]*rows[2][2])+(rows[1][0]*rows[2][1]*rows[0][2])+(rows[2][0]*rows[0][1]*rows[1][2]));
        sum += (-(rows[0][2]*rows[1][1]*rows[2][0])-(rows[2][2]*rows[0][1]*rows[1][0])-(rows[0][0]*rows[1][2]*rows[2][1]));
        return sum;
    }
}


template<int SIZE>
const Vector<SIZE> & RotMatrix<SIZE>::operator[] (int ind) const
{
    if(ind >= 0 && ind < SIZE)
       return(rows[ind]);
    else
        throw std::logic_error("Niepoprawny index matrixa");
}
 
template<int SIZE>
Vector<SIZE> & RotMatrix<SIZE>::operator[] (int ind)
{
    if(ind >= 0 && ind < SIZE)
       return(rows[ind]);
    else
        throw std::logic_error("Niepoprawny index matrixa");
}


template<int SIZE>
RotMatrix<SIZE> RotMatrix<SIZE>::operator-(const RotMatrix<SIZE> & arg2) const
{
    RotMatrix<SIZE> tmp;
    for(int i=0; i<SIZE; i++){
        tmp[i] = (rows[i]-arg2[i]);
    }
    return tmp;
}


template<int SIZE>
RotMatrix<SIZE> RotMatrix<SIZE>::operator* (const RotMatrix<SIZE> & arg2) const
{
    RotMatrix<SIZE> matr;
    Vector<SIZE> tmpvect;
    matr = matr - matr;
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            tmpvect[j] = arg2[j][i];
        }
        for(int k = 0; k < SIZE; k++){
            matr [k][i] =  (rows[k] * tmpvect);
        }   
    }
    return matr;
}

template<int SIZE>
Vector<SIZE> RotMatrix<SIZE>::operator* (const Vector<SIZE> & mvector) const
{
    Vector<SIZE> vect;
    for(int i=0; i<SIZE; i++){
        vect[i]=(rows[i]*mvector);
    }
    return vect;
}


template<int SIZE>
std::ostream & operator << (std::ostream & strm, const RotMatrix<SIZE> & matrix)
{
    int i;
    strm << "[ ";
    for(i = 0; i <SIZE-1; i++)
    {
        strm << matrix[i] << ", ";
    }
    strm << matrix[i];
    strm << " ]";
    return strm;
}

template class RotMatrix<2>;
template class RotMatrix<3>;
template std::ostream& operator<< (std::ostream & strm, const RotMatrix<2> & vector);
template std::ostream& operator<< (std::ostream & strm, const RotMatrix<3> & vector);
