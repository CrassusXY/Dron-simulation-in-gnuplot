#ifndef ROTMATRIX_HH
#define ROTMATRIX_HH

#include "Vector.hh"
#include <cmath>

template <int SIZE>
class RotMatrix
{
private:
    std::vector<Vector<SIZE>> rows;
public:
    /**
     * @brief Construct a new Rot Matrix
     * 
     */
    RotMatrix();
    /**
     * @brief Construct a new Rot Matrix
     * 
     * @param angle 
     * @param axis 
     */
    RotMatrix(double angle, char axis = 'Z');
    
    /**
     * @brief subtraction two rotation matrix
     * 
     * @param arg2 second rotation matrix
     * @return difference of two RotMatrix 
     */
    RotMatrix<SIZE> operator-(const RotMatrix<SIZE> & arg2) const;

    /**
     * @brief multiplication of two rotation matrix
     * 
     * @param arg2 second matrix object
     * @return RotMatrix<SIZE> 
     */
    RotMatrix<SIZE> operator* (const RotMatrix & arg2) const;

    /**
     * @brief multiplication rotation matrix by double 
     * 
     * @param vector 
     * @return result of rotation matrix by number multiplication
     */
    Vector<SIZE> operator* (const Vector<SIZE> & vector) const;

    /**
     * @brief getter
     * 
     * @param ind 
     * @return const Vector<SIZE>& 
     */
    const Vector<SIZE> & operator[] (int ind) const;

    /**
     * @brief setter
     * 
     * @param ind 
     * @return Vector<SIZE>& 
     */
    Vector<SIZE> & operator[] (int ind);

    /**
     * @brief 
     * 
     * @return determinant of rotation matrix
     */
    double determinant() const;
};

template <int SIZE>
std::ostream & operator << (std::ostream & strm, const RotMatrix<SIZE> & matrix);

#endif