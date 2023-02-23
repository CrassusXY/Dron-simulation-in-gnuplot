#ifndef COORDINATESYSTEM_HH
#define COORDINATESYSTEM_HH

#include "Matrix.hh"

class CoordinateSystem
{
protected:
    Vector<3> center;
    RotMatrix<3> orient;
    CoordinateSystem* parent;
public:
    /**
     * @brief Construct a new Coordinate System
     * 
     */
    CoordinateSystem();
    
    /**
     * @brief Construct a new Coordinate System
     * 
     * @param _center Vector containing center  
     * @param _orient RotMatrix containing orientation of the coordinate system
     * @param _parent pointer to parent
     */
    CoordinateSystem(Vector<3> _center, RotMatrix<3> _orient, CoordinateSystem *_parent = nullptr) : center(_center), orient(_orient), parent(_parent) {};

    /**
     * @brief 
     * 
     * @param Vector<3> translation vector 
     */
    void translation(Vector<3> Vect) {center = center + Vect;}

    /**
     * @brief 
     * 
     * @param RotMatrix rotation matrix 
     */
    void rotation(RotMatrix<3> RMat) {orient = orient * RMat;}

    /**
     * @brief 
     * 
     * @param CoordinateSystem
     * @return Recalculated CoordinateSystem 
     */
    CoordinateSystem recalculate(const CoordinateSystem & CS){return CoordinateSystem(CS.center + (CS.orient * center), CS.orient * orient, CS.parent);}
    
    /**
     * @brief recalculate to base coordinate system
     * 
     */
    void to_any(){while(parent != nullptr) to_previous();}

    /**
     * @brief recalculate to base coordinate system
     * 
     */
    void to_previous(){if(parent != nullptr){(*this)=recalculate(*parent);}}

    /**
     * @brief 
     * 
     * @param Vector<3>
     * @return point in parent coordinate system
     */
    Vector<3> point_in_parent(const Vector<3> & WW){return center + orient*WW;}
};

#endif