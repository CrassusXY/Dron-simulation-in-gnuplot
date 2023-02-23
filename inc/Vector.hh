#ifndef VECTOR_HH
#define VECTOR_HH
#define EPS_DBL 0.000001

#include <vector>
#include <iostream>
#include "Dr3D_gnuplot_api.hh"

template <int SIZE>
class Vector
{
private:
    std::vector<double> xy;
    inline static uint currently=0;
    inline static uint overall=0;
public:
    /**
     * @brief Destroy the Vector object
     * 
     */
    ~Vector() {currently--;}

    /**
     * @brief Construct a new Vector object initialized with 0
     * 
     */
    Vector(){
        for (int i = 0; i < SIZE; i++){
            xy.push_back(0.0);
        }
        currently++;
        overall++;
    };

    /**
     * @brief Construct a new Vector object
     * 
     * @param initializer_list with numbers to initialize vector 
     */
    Vector(std::initializer_list<double> il): xy(il) {currently++; overall++;};

    /**
     * @brief Copying constructor a new Vector object
     * 
     * @param _new 
     */
    Vector(const Vector & _new): xy(_new.xy){currently++; overall++;}


    /**
     * @brief Get number of all vectors used in program 
     * 
     * @return number of all vectors
     */
    static uint get_overall() {return overall;};

    /**
     * @brief Get the currently used vector objects
     * 
     * @return currently used vector objects
     */
    static uint get_currently() {return currently;};


    /**
     * @brief adding two vectors 
     * 
     * @param arg2 second vector object
     * @return sum of two Vectors
     */
    Vector operator+ (const Vector<SIZE> & arg2) const;

    /**
     * @brief subtraction two vectors
     * 
     * @param arg2 second vector object
     * @return difference of two Vectors
     */
    Vector operator- (const Vector<SIZE> & arg2) const;

    /**
     * @brief multiplication of two vectors
     * 
     * @param arg2 second vector object
     * @return result of two vectors multiplication
     */
    double operator* (const Vector<SIZE> & arg2) const;

    /**
     * @brief multiplication vector by double 
     * 
     * @param arg  
     * @return result of vector by number multiplication
     */
    double operator* (const double & arg) const;

    /**
     * @brief getter
     * 
     * @param ind 
     * @return const double& 
     */
    const double & operator [] (int ind) const;

    /**
     * @brief setter
     * 
     * @param ind 
     * @return double& 
     */
    double & operator[] (int ind);

    /**
     * @brief returns vector length
     * 
     * @return double 
     */
    double length() const;
};


template <int SIZE>
std::ostream & operator << (std::ostream & strm, const Vector<SIZE> & vector);

//converts Vector3D into Point3D
drawNS::Point3D convert (Vector<3> arg);


#endif