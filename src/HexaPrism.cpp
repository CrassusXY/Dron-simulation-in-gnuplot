#include "HexaPrism.hh"

using std::vector;
using drawNS::Point3D;
using drawNS::APIGnuPlot3D;

vector<Vector<3>> HexaPrism::get_points() const
{
    vector<Vector<3>> points;

    points.push_back(Vector<3>{radius, 0, -height/2});
    points.push_back(Vector<3>{radius/2, radius/2*sqrt(3), -height/2});
    points.push_back(Vector<3>{-radius/2, radius/2*sqrt(3), -height/2});
    points.push_back(Vector<3>{-radius, 0, -height/2});
    points.push_back(Vector<3>{-radius/2, -radius/2*sqrt(3), -height/2});
    points.push_back(Vector<3>{radius/2, -radius/2*sqrt(3), -height/2});

    points.push_back(Vector<3>{radius, 0, height/2});
    points.push_back(Vector<3>{radius/2, radius/2*sqrt(3), height/2});
    points.push_back(Vector<3>{-radius/2, radius/2*sqrt(3), height/2});
    points.push_back(Vector<3>{-radius, 0, height/2});
    points.push_back(Vector<3>{-radius/2, -radius/2*sqrt(3), height/2});
    points.push_back(Vector<3>{radius/2, -radius/2*sqrt(3), height/2});
    return points;
}


void HexaPrism::draw ()
{
    vector<Vector<3>> points=get_points();
    vector<Point3D> lower, upper;
    vector<vector<Point3D> > tmp;

    //std::cout<<"Hex.center"<<Hex.center<<std::endl;
    to_previous();
    //std::cout<<"Hex.centerprze"<<Hex.center<<std::endl;
    for(int i=0; i<5; i++){
        lower.push_back(convert(point_in_parent(Vector<3>{0,0,0})));
        lower.push_back(convert(point_in_parent(points[i])));
        lower.push_back(convert(point_in_parent(points[i+1])));

        upper.push_back(convert(point_in_parent(Vector<3>{0,0,0})));
        upper.push_back(convert(point_in_parent(points[i+6])));
        upper.push_back(convert(point_in_parent(points[i+7])));
    }
    lower.push_back(convert(point_in_parent(Vector<3>{0,0,0})));
    lower.push_back(convert(point_in_parent(points[0])));
    lower.push_back(convert(point_in_parent(points[5])));

    upper.push_back(convert(point_in_parent(Vector<3>{0,0,0})));
    upper.push_back(convert(point_in_parent(points[6])));
    upper.push_back(convert(point_in_parent(points[11])));
    tmp.push_back(lower);
    tmp.push_back(upper);

    id=api->draw_polyhedron(tmp, "red");
}