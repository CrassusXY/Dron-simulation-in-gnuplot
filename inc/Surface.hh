#ifndef SURF_HH
#define SURF_HH
#include "CoordinateSystem.hh"
#include "Dr3D_gnuplot_api.hh"
#include "DrawingInterface.hh"


class Surface: public DrawingInterface
{
protected:
    double height;
public:
    /**
     * @brief Construct a new Surface
     * 
     * @param _api 
     */
    Surface(drawNS::Draw3DAPI * _api): DrawingInterface(_api), height(0.0) {}

    /**
     * @brief draws surface
     * 
     */
    void draw() override;
};

#endif