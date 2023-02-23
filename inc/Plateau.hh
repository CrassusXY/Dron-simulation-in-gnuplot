#ifndef PLATEAU_HH
#define PLATEAU_HH

#include "Matrix.hh"
#include "CoordinateSystem.hh"
#include "DrawingInterface.hh"
#include "LandscapeInterface.hh"

class Plateau : public CoordinateSystem, public DrawingInterface, public LandscapeInterface
{
protected:
    double radius;
    double height;
public:
    /**
     * @brief Construct a new Plateau
     * 
     * @param center pos of plateau center
     * @param orient of plateau
     * @param _radius of plateau base
     * @param _height of plateau
     * @param _api pointer to api
     */
    Plateau(Vector<3> center, RotMatrix<3> orient, double _radius, double _height, drawNS::Draw3DAPI * _api): 
        CoordinateSystem(center, orient, nullptr), 
        DrawingInterface (_api),
        radius(_radius),
        height(_height)
        {if(_radius<0||_height<0)
            throw std::logic_error("Height or radius is lower than 0");
        }


    /**
     * @brief Get the points
     * 
     * @return std::vector<Vector<3>> 
     */
    std::vector<Vector<3>> get_points() const;
    
    /**
     * @brief 
     * 
     * @param drone 
     * @return true if drone is higher than plateau
     * @return false if drone isn't higher than plateau
     */
    bool is_higher(std::shared_ptr<Drone> drone) override;

    bool is_above(std::shared_ptr<Drone> drone) override;

    bool to_land(std::shared_ptr<Drone> drone) override;

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
    double get_height()override {return height;};

    /**
     * @brief Draws plateau
     * 
     */
    void draw() override;

    /**
     * @brief prints info about hill
     * 
     */
    void print_info() override;

    /**
     * @brief removes hill 
     * 
     */
    void remove() override;
};

#endif