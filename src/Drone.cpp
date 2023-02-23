#include "Drone.hh"

using std::vector;
using drawNS::Point3D;
using drawNS::APIGnuPlot3D;

void Drone::zakrec_smiglem()
{
    propellers[0].rotation(RotMatrix<3>(10));
    propellers[1].rotation(RotMatrix<3>(-10));
    propellers[2].rotation(RotMatrix<3>(10));
    propellers[3].rotation(RotMatrix<3>(-10));

}

void Drone::fly_vertically(const double & height)
{
    translation(Vector<3>{0, 0, height});
}

void Drone::animate_fly_vertically(const double & height)
{
  double frames=abs(height/velocity*10);
  for(double i=0.0; i<frames; i++){
    fly_vertically(height/frames);
    zakrec_smiglem();
    draw();
    api->redraw();
    std::this_thread::sleep_for(std::chrono::microseconds(10000));
  }
}


void Drone::fly_horizontally(const double & distance)
{
    translation(orient * Vector<3>{distance, 0 ,0});
}

void Drone::animate_fly_horizontally(const double & distance)
{
  double frames=abs(distance/velocity*10);
  animate_rotate(20, 'Y');
  for(double i=0; i<frames; i++){
    rotation(RotMatrix<3>(-20, 'Y'));
    fly_horizontally((distance/frames));
    zakrec_smiglem();
    rotation(RotMatrix<3>(20, 'Y'));
    draw();
    api->redraw();
    std::this_thread::sleep_for(std::chrono::microseconds(10000));
  }
  animate_rotate(-30, 'Y');
  animate_rotate(10, 'Y');
}

void Drone::animate_rotate(const double & angle, char axis)
{
  double frames=abs(angle/velocity);
  for(double i=0; i<frames; i++){
    rotation(RotMatrix<3>(angle/frames, axis));
    zakrec_smiglem();
    draw();
    api->redraw();
    std::this_thread::sleep_for(std::chrono::microseconds(10000));
  }
}

Vector<3> Drone::get_pos()
{
  return Vector<3>{center[0], center[1], center[2]-body.get_height()};
}

void Drone::draw ()
{   
    for(unsigned int j=0; j < drawing_ids.size(); j++){
        api->erase_shape(drawing_ids[j]);
    }
    Cuboid tmp_body=body;
    std::array<HexaPrism, 4> tmp_propellers=propellers;
    //std::cout<<"Cemter brona"<<center<<std::endl;
    //std::cout<<"Orient brona"<<orient<<std::endl;
    for(int i=0; i<4; i++){
        tmp_propellers[i].draw();
        drawing_ids.push_back(tmp_propellers[i].get_id());
    }
    tmp_body.draw();
    drawing_ids.push_back(tmp_body.get_id());
}