#ifndef HEXAPRISM_HH
#define HEXAPRISM_HH

#include "CoordinateSystem.hh"
#include "DrawingInterface.hh"

class HexaPrism : public CoordinateSystem, public DrawingInterface
{
protected:
    double radius;
    double height;
public:
    /**
     * @brief Construct a new Hexa Prism
     * 
     * @param center of HexaPrism
     * @param orient of HexaPrism
     * @param parent pointer to parent coordinate system 
     * @param _radius base radius
     * @param _height height of Hexaprism
     * @param _api pointer to api
     */
    HexaPrism(Vector<3> center, RotMatrix<3> orient, CoordinateSystem *parent, double _radius, double _height, drawNS::Draw3DAPI * _api): 
        CoordinateSystem(center, orient, parent), 
        DrawingInterface(_api),
        radius(_radius), 
        height(_height) 
        {if(_radius<0||_height<0)
            {throw std::logic_error("Height or radius is lower than 0");}}

    /**
     * @brief Get the points
     * 
     * @return std::vector<Vector<3>> 
     */
    std::vector<Vector<3>> get_points() const;
    
    /**
     * @brief Get the id
     * 
     * @return id
     */
    int get_id(){return id;};

    /**
     * @brief Draws HexaPrism
     * 
     */
    void draw() override;
};

#endif