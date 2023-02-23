#include "Cuboid.hh"

using std::vector;
using drawNS::Point3D;
using drawNS::APIGnuPlot3D;

vector<Vector<3>> Cuboid::get_points() const
{
    vector<Vector<3>> points;

    points.push_back(Vector<3>{-length/2, -width/2, -height/2});
    points.push_back(Vector<3>{length/2, -width/2, -height/2});
    points.push_back(Vector<3>{length/2, width/2, -height/2});
    points.push_back(Vector<3>{-length/2, width/2, -height/2});
    points.push_back(Vector<3>{-length/2, -width/2, height/2});
    points.push_back(Vector<3>{length/2, -width/2, height/2});
    points.push_back(Vector<3>{length/2, width/2, height/2});
    points.push_back(Vector<3>{-length/2, width/2, height/2});
    return points;
}

void Cuboid::draw ()
{
    vector<Vector<3>> points=this->get_points();
    vector<Point3D> lower, upper;
    vector<vector<Point3D> > tmp;
    //std::cout<<"Cemter Cuboimda"<<center<<std::endl;
    //std::cout<<"Orient Cuboimda"<<orient<<std::endl;
    //std::cout<<"Parent: "<<parent<<std::endl;

    to_previous();
    //std::cout<<"Cemter Cuboimda2"<<center<<std::endl;
    //std::cout<<"Parent2: "<<parent<<std::endl;
    for(int i=0; i<4; i++){
        lower.push_back(convert(point_in_parent(points[i])));
        upper.push_back(convert(point_in_parent(points[i+4])));
    }

    tmp.push_back(lower);
    tmp.push_back(upper);

    id = api->draw_polyhedron(tmp, "red");
}
