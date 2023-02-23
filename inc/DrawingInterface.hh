#ifndef DRAWING_HH
#define DRAWING_HH
#include "Dr3D_gnuplot_api.hh"

class DrawingInterface
{
protected:
    drawNS::Draw3DAPI * api;
public:
    uint id;
    /**
     * @brief Construct a new Drawing Interface
     * 
     * @param _api 
     */
    DrawingInterface (drawNS::Draw3DAPI * _api): api(_api) {}
    
    virtual void draw() = 0; 
};

#endif