#ifndef RECTANGLE_HH
#define RECTANGLE_HH

#include "Matrix.hh"
#include "CoordinateSystem.hh"
#include "DrawingInterface.hh"

class Cuboid : public CoordinateSystem, public DrawingInterface
{
protected:
    double length;
    double width;
    double height;
public:
    /**
     * @brief Construct a new Cuboid
     * 
     * @param center of cuboid
     * @param orient orientation of cuboid 
     * @param parent pointer to parent coordinate system 
     * @param _length of cuboid
     * @param _width of cuboid
     * @param _height of cuboid
     * @param _api pointer to api
     */
    Cuboid(Vector<3> center, RotMatrix<3> orient, CoordinateSystem *parent, double _length, double _width, double _height, drawNS::Draw3DAPI * _api): 
        CoordinateSystem(center, orient, parent), 
        DrawingInterface (_api),
        length(_length), width(_width), 
        height(_height)
        {if(_width<0||_height<0||_length<0)
            throw std::logic_error("Height or width or length is lower than 0");
        }

    /**
     * @brief Get the points of cuboid 
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
     * @brief Get the height cuboid
     * 
     * @return double 
     */
    double get_height(){return height;}

    /**
     * @brief Draws cuboid
     * 
     */
    void draw()override;
};

#endif