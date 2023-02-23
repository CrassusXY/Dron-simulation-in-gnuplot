#include "Surface.hh"

using drawNS::Point3D;
using drawNS::APIGnuPlot3D;


void Surface::draw()
{
    std::vector<std::vector<Point3D>> _surface;
    api->erase_shape(id);
    for(double i=-15.0; i<=15.0; i++){
        _surface.push_back(std::vector<Point3D>{Point3D{i,15,height}, Point3D{i,-15,height}});
    }
    for(double j=-15.0; j<=15.0; j++){
        _surface.push_back(std::vector<Point3D>{Point3D{15,j,height}, Point3D{-15, j,height}});
    }

    id=api->draw_surface(_surface, "green");
}