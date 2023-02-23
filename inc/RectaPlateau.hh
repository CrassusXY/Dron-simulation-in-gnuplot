#ifndef RECTAPLATEAU_HH
#define RECTAPLATEAU_HH

#include "Cuboid.hh"
#include "LandscapeInterface.hh"

class RectaPlateau: public CoordinateSystem, public DrawingInterface, public LandscapeInterface
{   
protected:
    Cuboid cubo;
    double radius;
public:
    /**
     * @brief Construct a new RectaPlateau
     * 
     * @param center pos of plateau rectacenter
     * @param orient of rectaplateau
     * @param _length 
     * @param _width 
     * @param _height 
     * @param _api pointer to api
     */
    RectaPlateau(Vector<3> center, RotMatrix<3> orient, double _length, double _width, double _height, drawNS::Draw3DAPI * _api): 
        CoordinateSystem(center, orient, nullptr),
        DrawingInterface(_api),
        cubo(center, orient, nullptr, _length, _width, _height, _api),
        radius(sqrt(_width*_width+_length*_length))
        {}


    /**
     * @brief Get the id 
     * 
     * @return id 
     */
    uint get_id()override {return id;};
    
    /**
     * @brief Get the height
     * 
     * @return height 
     */
    double get_height()override {return cubo.get_height();};

    /**
     * @brief 
     * 
     * @param drone 
     * @return true if drone is higher than reactaplateau
     * @return false if drone isn't higher than reactaplateau
     */
    bool is_higher(std::shared_ptr<Drone> drone) override;

    bool is_above(std::shared_ptr<Drone> drone) override;

    bool to_land(std::shared_ptr<Drone> drone) override;

    /**
     * @brief Draws rectaplateau
     * 
     */
    void draw()override;

    /**
     * @brief prints info about rectaplateau
     * 
     */
    void print_info() override;

    /**
     * @brief removes rectaplateau
     * 
     */
    void remove() override;
};

#endif