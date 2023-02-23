#include "Hill.hh"

using std::vector;
using drawNS::Point3D;
using drawNS::APIGnuPlot3D;


bool Hill::is_higher(std::shared_ptr<Drone> drone)
{
    Vector<3> dronpos = drone->get_pos();

    if(dronpos[2]>height){
        return true;
    }
    else
        return false;
}

bool Hill::is_above(std::shared_ptr<Drone> drone)
{
    Vector<3> drone_center = drone->get_pos();
    drone_center[2] = 0;

    Vector<3> tmp = drone_center-center;
    if( ((radius+drone->get_radius()) > tmp.length()))
        return true;
    else
        return false;
}

bool Hill::to_land(std::shared_ptr<Drone> drone)
{
    if(is_above(drone)==true)
        return false;
    else
        return true;
}

vector<Vector<3>> Hill::get_points() const
{
    vector<Vector<3>> points;

    points.push_back(Vector<3>{radius, 0, 0});
    points.push_back(Vector<3>{radius/2, radius/2*sqrt(3), 0});
    points.push_back(Vector<3>{-radius/2, radius/2*sqrt(3), 0});
    points.push_back(Vector<3>{-radius, 0, 0});
    points.push_back(Vector<3>{-radius/2, -radius/2*sqrt(3), 0});
    points.push_back(Vector<3>{radius/2, -radius/2*sqrt(3), 0});
    points.push_back(Vector<3>{radius, 0, 0});

    return points;
}


void Hill::draw ()
{
    vector<Vector<3>> points=get_points();
    vector<Point3D> all;
    vector<vector<Point3D> > tmp;

    api->erase_shape(id);
    
    for(int i=0; i<6; i++){
        all.push_back(convert(point_in_parent(Vector<3>{0,0,height})));
        all.push_back(convert(point_in_parent(points[i])));
        all.push_back(convert(point_in_parent(points[i+1])));
    }

    tmp.push_back(all);

    id=api->draw_polyhedron(tmp, "yellow");
}

void Hill::print_info()
{
    std::cout<< "Wzgorze znajdujace sie w punkcie: " << center << " o id: " << id;
}

void Hill::remove()
{
    api->erase_shape(id);
}
