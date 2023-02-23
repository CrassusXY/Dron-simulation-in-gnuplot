#include "RectaPlateau.hh"

using std::vector;
using drawNS::Point3D;
using drawNS::APIGnuPlot3D;

bool RectaPlateau::is_higher(std::shared_ptr<Drone> drone)
{
    Vector<3> dronpos = drone->get_pos();

    if(dronpos[2]>cubo.get_height()){
        return true;
    }
    else
        return false;
}

bool RectaPlateau::is_above(std::shared_ptr<Drone> drone)
{
    Vector<3> drone_center = drone->get_pos();
    drone_center[2] = 0;

    Vector<3> tmp = drone_center-center;
    if( ((radius+drone->get_radius()) > tmp.length()))
        return true;
    else
        return false;
}

bool RectaPlateau::to_land(std::shared_ptr<Drone> drone)
{
    Vector<3> drone_center = drone->get_pos();
    drone_center[2] = 0;

    Vector<3> tmp = drone_center-center;

    if(is_above(drone)==true){
        if(radius > tmp.length())
            return true;
        else
            return false;
    }
    else
        return true;
}


void RectaPlateau::draw ()
{
    vector<Vector<3>> points=cubo.get_points();
    vector<Point3D> lower, upper;
    vector<vector<Point3D> > tmp;

    api->erase_shape(id);

    for(int i=0; i<4; i++){
        lower.push_back(convert(point_in_parent(points[i])));
        upper.push_back(convert(point_in_parent(points[i+4])));
    }

    tmp.push_back(lower);
    tmp.push_back(upper);

    id=api->draw_polyhedron(tmp, "yellow");
}

void RectaPlateau::print_info()
{
    std::cout<< "Plaskowyz prostopadloscienny znajdujacy sie w punkcie: " << center << " o id: " << id;
}

void RectaPlateau::remove()
{
    api->erase_shape(id);
}
