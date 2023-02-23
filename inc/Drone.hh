#ifndef DRONE_HH
#define DRONE_HH

#include "Cuboid.hh"
#include "HexaPrism.hh"


class Drone : public CoordinateSystem, public DrawingInterface
{
    double velocity=1;
    std::vector<int> drawing_ids;
    Cuboid body;
    std::array<HexaPrism, 4> propellers;

public:
    /**
     * @brief Construct a new Drone with center in Vect and orientet by RMat
     * 
     * @param Vect center of a new drone
     * @param RMat orientation of a new drone
     * @param _api api
     */
    Drone(Vector<3> Vect, RotMatrix<3> RMat, drawNS::Draw3DAPI * _api):
    CoordinateSystem(Vect, RMat, nullptr), 
    DrawingInterface(_api), 
    body(Vector<3>{0,0,0}, RotMatrix<3>(), this, 3, 2, 1, _api), 
    propellers{
        HexaPrism(Vector<3>{1.5, 1, 0.65}, RotMatrix<3>(), this, 0.9, 0.3, _api), 
        HexaPrism(Vector<3>{-1.5, 1, 0.65}, RotMatrix<3>(), this, 0.9, 0.3, _api), 
        HexaPrism(Vector<3>{-1.5, -1, 0.65}, RotMatrix<3>(), this, 0.9, 0.3, _api), 
        HexaPrism(Vector<3>{1.5, -1, 0.65}, RotMatrix<3>(), this, 0.9, 0.3, _api)}
    {}

    /**
     * @brief Spins drone propellers
     * 
     */
    void zakrec_smiglem();
    
    /**
     * @brief Moves horizontally the drone by given distance at a given angle
     * 
     * @param distance for drone to fly horizontally
     */
    void fly_horizontally(const double & distance);

    /**
     * @brief Animates drone horizontal movement 
     * 
     * @param distance for drone to fly horizontally
     */
    void animate_fly_horizontally(const double & distance);

    /**
     * @brief Moves vertically the drone by given height
     * 
     * @param height for drone to fly vertically
     */
    void fly_vertically(const double & height);

    /**
     * @brief Animates drone vertical movement 
     * 
     * @param height for drone to fly vertically
     */
    void animate_fly_vertically(const double & height);
    /**
     * @brief Animates drone rotation by given angle with respect to the axis
     * 
     * @param angle for dron to rotate
     * @param axis around which the rotation takes place(X, Y, Z(default))
     */
    void animate_rotate(const double & angle, char axis='Z');

    /**
     * @brief Changes drone velocity
     * 
     * @param _velocity new velocity of the drone
     */
    void change_velocity(const double & _velocity){if(_velocity>0) velocity=_velocity;}
    
    /**
     * @brief Return center of drone base
     * 
     * @return Vector<3> 
     */
    Vector<3> get_pos();

    double get_radius(){
        return(sqrt(13)+0.9);
    }
    
    /**
     * @brief Draws drone
     * 
     */
    void draw() override;
};

#endif