#ifndef LANDSCAPE_HH
#define LANDSCAPE_HH
#include "Dr3D_gnuplot_api.hh"
#include "Drone.hh"

class LandscapeInterface
{
public:
    /**
     * @brief check if drone is above figure  
     * 
     * @param drone 
     * @return true if is above 
     * @return false if isn't 
     */
    virtual bool is_higher(std::shared_ptr<Drone> drone)=0;

    virtual bool is_above(std::shared_ptr<Drone> drone)=0;
    
    virtual bool to_land(std::shared_ptr<Drone> drone)=0;

    /**
     * @brief Get the id
     * 
     * @return id
     */
    virtual uint get_id()=0;

    /**
     * @brief Get the height
     * 
     * @return height
     */
    virtual double get_height()=0;

    /**
     * @brief prints info about figure
     * 
     */
    virtual void print_info()=0;

    /**
     * @brief removes figure
     * 
     */
    virtual void remove()=0;
};

#endif