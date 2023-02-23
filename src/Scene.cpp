#include "Scene.hh"
#include <memory>

using std::cout;
using std::cin;
using std::endl;
using std::weak_ptr;
using drawNS::Point3D;
using drawNS::APIGnuPlot3D;

Scene::Scene()
{
    api = new APIGnuPlot3D(-15,15,-15,15,-15,15,-1);
    std::shared_ptr<Surface> surface = std::make_shared<Surface>(api);
    std::shared_ptr<Hill> hill = std::make_shared<Hill>(Vector<3>{5, 7, 0}, RotMatrix<3>(), 3, 4, api);
    std::shared_ptr<RectaPlateau> rectpla = std::make_shared<RectaPlateau>(Vector<3>{-5, 7, 1}, RotMatrix<3>(), 2, 1, 2, api);
    std::shared_ptr<Plateau> plat = std::make_shared<Plateau>(Vector<3>{5, -7, 0}, RotMatrix<3>(), 3, 2, api);
    dragonfly = std::make_shared<Drone>(Vector<3>{0,0,0.5}, RotMatrix<3>(), api);

    landscape_elements.push_back(rectpla);
    landscape_elements.push_back(plat);
    landscape_elements.push_back(hill);

    drawable_elements.push_back(surface);
    drawable_elements.push_back(rectpla);
    drawable_elements.push_back(plat);
    drawable_elements.push_back(hill);
    drawable_elements.push_back(dragonfly);
    
    draw_all();
    draw_all();
}

void Scene::fly(const double & angle, const double & height, const double & distance)
{
    dragonfly->animate_fly_vertically(height);
    if(is_higher_than_all()==true){
        dragonfly->animate_rotate(angle);
        dragonfly->animate_fly_horizontally(distance);
        if(to_land()==true){
            dragonfly->animate_fly_vertically(-(height-landing_height()));
        }
        else{
            dragonfly->animate_rotate(180);
            dragonfly->animate_fly_horizontally(distance);
            dragonfly->animate_rotate(-angle-180);
            dragonfly->animate_fly_vertically(-height);
        }
    }
    else{
        cout<<"Dron leci za nisko!!"<<endl;;
        dragonfly->animate_fly_vertically(-height);
    }
}

void Scene::show_landscape_elements() const
{
    cout << "Elementy krajobrazu znajdujace sie w programie: " << endl;
    for(std::shared_ptr<LandscapeInterface> x : landscape_elements){
        x->print_info();
        cout << endl;
    }
}

bool Scene::is_higher_than_all()
{
    for(std::shared_ptr<LandscapeInterface> x : landscape_elements){
        if(x->is_higher(dragonfly)==false){
            return false;
        }
    }
    return true;
}

bool Scene::to_land()
{
    for(std::shared_ptr<LandscapeInterface> x : landscape_elements){
        if(x->to_land(dragonfly)==false){
            return false;
        }
    }
    return true;
}

double Scene::landing_height()
{
    for(std::shared_ptr<LandscapeInterface> x : landscape_elements){
        if(x->to_land(dragonfly) && x->is_above(dragonfly)){
            return x->get_height();
        }
    }
    return 0;
}

void Scene::delete_landscape_element(uint del)
{
    int i=0, j=0, k=-1;

    for(std::shared_ptr<LandscapeInterface> x : landscape_elements){
        i++;
        if(del == x->get_id()){

            cout << "Usuwam z Landscape_elements -> ";
            x->print_info();
            cout << endl;
            k=1;
            break;
        }
    }
    for(std::shared_ptr<DrawingInterface> y : drawable_elements){
        j++;
        if(del == y->id){
            cout<<"Usuwam z Drawable_elements -> "<< y->id << endl;
            api->erase_shape(y->id);
            break;
        }
    }
    if(k==1){
        cout<<"i = " << i << " j = " << j << endl;
        drawable_elements.erase(drawable_elements.begin()+(j-1));
        landscape_elements.erase(landscape_elements.begin()+(i-1));
        api->redraw();
    }
    if(k==-1)
        cout<<"Bledne id!"<<endl;
}

void Scene::add_landscape_element()
{
    std::shared_ptr<RectaPlateau> tmprect;
    std::shared_ptr<Plateau> tmppla;
    std::shared_ptr<Hill> tmphill;
    int fig;
    double x, y, r, a, b, c;
    cout << "Figury mozliwe do dodania: " << endl << "1 - Wzgorze" << endl << "2 - Plaskowyz" << endl << "3 - Plaskowyz prostopadloscienny" << endl;
    cout << "Jaka figura wariacie: ";
    cin >> fig;
 

    switch (fig)
    {
    case 1:
        cout << "Podaj promien podstawy: ";
        cin >> a;
        cout << "Podaj wysokosc: ";
        cin >> b;
        cout << "Podaj wspl X srodka figury: ";
        cin >> x;
        cout << "Podaj wspl Y srodka figury: ";
        cin >> y;
        tmphill = std::shared_ptr<Hill>(new Hill(Vector<3>{x,y,0}, RotMatrix<3>(), b, a, api));
        landscape_elements.push_back(tmphill);
        drawable_elements.push_back(tmphill);
        break;
    case 2:
        cout << "Podaj promien: ";
        cin >> a;
        cout << "Podaj wysokosc: ";
        cin >> b;
        cout << "Podaj wspl X srodka figury: ";
        cin >> x;
        cout << "Podaj wspl Y srodka figury: ";
        cin >> y;
        cout << "Podaj kat obrotu figury: ";
        cin >> r;
        tmppla = std::shared_ptr<Plateau>(new Plateau(Vector<3>{x,y,0}, RotMatrix<3>(r), b, a, api));
        landscape_elements.push_back(tmppla);
        drawable_elements.push_back(tmppla);
        break;
    case 3:
        cout << "Podaj dlugosc: ";
        cin >> a;
        cout << "Podaj szerokosc: ";
        cin >> b;
        cout << "Podaj wysokosc: ";
        cin >> c;
        cout << "Podaj wspl X srodka figury: ";
        cin >> x;
        cout << "Podaj wspl Y srodka figury: ";
        cin >> y;
        cout << "Podaj kat obrotu figury: ";
        cin >> r;
        tmprect = std::shared_ptr<RectaPlateau>(new RectaPlateau(Vector<3>{x, y, c/2}, RotMatrix<3>(r), a, b, c, api));
        landscape_elements.push_back(tmprect);
        drawable_elements.push_back(tmprect);
        break;
    default:
        cout << "Brak takiej figury";
        break;
    }
    draw_all();
    api->redraw();
}