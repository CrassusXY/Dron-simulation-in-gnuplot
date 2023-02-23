#ifndef HILL_HH
#define HILL_HH

#include "CoordinateSystem.hh"
#include "DrawingInterface.hh"
#include "LandscapeInterface.hh"
class Hill : public CoordinateSystem, public DrawingInterface, public LandscapeInterface
{
protected:
    double height;
    double radius;
public:
    /**
     * @brief Construct a new Hill
     * 
     * @param center of hill
     * @param orient of hill
     * @param _height of hill peak
     * @param _radius of hill base 
     * @param _api pointer to api
     */
    Hill(Vector<3> center, RotMatrix<3> orient, double _height, double _radius, drawNS::Draw3DAPI * _api): 
        CoordinateSystem(center, orient, nullptr), 
        DrawingInterface(_api),
        height(_height),
        radius(_radius) {}
    
    /**
     * @brief 
     * 
     * @param drone 
     * @return true if drone is higher than hill
     * @return false if drone isn't higher than hill
     */
    bool is_higher(std::shared_ptr<Drone> drone) override;

    bool is_above(std::shared_ptr<Drone> drone) override;

    bool to_land(std::shared_ptr<Drone> drone) override;

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
    uint get_id()override {return id;};

    /**
     * @brief Get the height
     * 
     * @return height 
     */
    double get_height()override {return height;};

    /**
     * @brief Draws hill
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