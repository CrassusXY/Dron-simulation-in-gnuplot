#include "Plateau.hh"

using std::vector;
using drawNS::Point3D;
using drawNS::APIGnuPlot3D;


bool Plateau::is_higher(std::shared_ptr<Drone> drone)
{
    Vector<3> dronpos = drone->get_pos();

    if(dronpos[2]>height){
        return true;
    }
    else
        return false;
}

bool Plateau::is_above(std::shared_ptr<Drone> drone)
{
    Vector<3> drone_center = drone->get_pos();
    drone_center[2] = 0;

    Vector<3> tmp = drone_center-center;
    if( ((radius+drone->get_radius()) > tmp.length()))
        return true;
    else
        return false;
}

bool Plateau::to_land(std::shared_ptr<Drone> drone)
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
    else{
        return true;
    }
        
}

vector<Vector<3>> Plateau::get_points() const
{
    vector<Vector<3>> points;

    points.push_back(Vector<3>{radius, 0, 0});
    points.push_back(Vector<3>{radius/2, radius*2, 0});
    points.push_back(Vector<3>{-radius/2, radius, 0});
    points.push_back(Vector<3>{-radius*1.5, -radius/4, 0});
    points.push_back(Vector<3>{0, -radius*sqrt(3), 0});
    points.push_back(Vector<3>{radius/2, -radius/2*sqrt(3), 0});
    points.push_back(Vector<3>{radius, 0, 0});

    points.push_back(Vector<3>{radius, 0, height});
    points.push_back(Vector<3>{radius/2, radius*2, height});
    points.push_back(Vector<3>{-radius/2, radius, height});
    points.push_back(Vector<3>{-radius*1.5, -radius/4, height});
    points.push_back(Vector<3>{0, -radius*sqrt(3), height});
    points.push_back(Vector<3>{radius/2, -radius/2*sqrt(3), height});
    points.push_back(Vector<3>{radius, 0, height});

    return points;
}


void Plateau::draw ()
{
    vector<Vector<3>> points=get_points();
    vector<Point3D> lower, upper;
    vector<vector<Point3D> > tmp;

    api->erase_shape(id);

    for(int i=0; i<7; i++){
        lower.push_back(convert(point_in_parent(points[i])));
        upper.push_back(convert(point_in_parent(points[i+7])));
    }

    tmp.push_back(lower);
    tmp.push_back(upper);

    id=api->draw_polyhedron(tmp, "yellow");
}

void Plateau::print_info()
{
    std::cout<< "Plaskowyz znajdujacy sie w punkcie: " << center << " o id: " << id;
}

void Plateau::remove()
{
    api->erase_shape(id);
}
