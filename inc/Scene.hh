#ifndef SCENE_HH
#define SCENE_HH

#include "Drone.hh"
#include "Surface.hh"
#include "Hill.hh"
#include "RectaPlateau.hh"
#include "Plateau.hh"

class Scene
{
protected:
    std::vector<std::shared_ptr<DrawingInterface>> drawable_elements;
    std::vector<std::shared_ptr<LandscapeInterface>> landscape_elements;
public:
    std::shared_ptr<Drone> dragonfly;
    drawNS::Draw3DAPI * api;

    Scene();
    
    /**
     * @brief prints info about all landscape elements
     * 
     */
    void show_landscape_elements() const;

    /**
     * @brief adds new landscape element
     * 
     */
    void add_landscape_element();

    /**
     * @brief 
     * 
     * @param id of element to delete
     */
    void delete_landscape_element(uint del);

    /**
     * @brief check if drone is higher than all elements
     * 
     * @return true 
     * @return false 
     */
    bool is_higher_than_all();

    bool to_land();

    double landing_height();

    void fly(const double & angle, const double & height, const double & distance);

    void draw_all(){
        for(std::shared_ptr<DrawingInterface> x : drawable_elements){
            x->draw();
        }
    }
};



#endif