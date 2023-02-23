#include"Scene.hh"
#include <thread>
#include <chrono>

using std::vector;
using drawNS::Point3D;
using drawNS::APIGnuPlot3D;
using std::cout;
using std::cin;
using std::endl;


void wait4key() {
  do {
    std::cout << "\n Press a key to continue..." << std::endl;
  } while(std::cin.get() != '\n');
}

void menu() {
  cout<<endl<<"Menu:"<<endl;
  cout<<"Lot drona -> f"<<endl;
  cout<<"Dodaj element powierzchni -> d"<<endl;
  cout<<"Usun element powierzchni -> u"<<endl;
  cout<<"Wyswietl elementy powierzchni -> p"<<endl;
  cout<<"Wyswietl ilosc wektorow -> w"<<endl;
  cout<<"Zakrec smiglem -> s"<<endl;
  cout<<"Koniec pracy programu -> q"<<endl;
}


int main(){
  char choice;
  uint del;
  double h, d, a, v;
  Scene scene;

  scene.api->redraw();


  menu();
  while(choice != 'q')
  {
    cout << "Podaj swoj wybor wybor (menu -> m): ";
    cin >> choice;

    switch (choice)
    {
    case 'm':
      menu();
      break;
    case 'f':
      cout<<"Podaj wysokosc lotu: ";
      cin>>h;
      cout<<endl<<"Podaj kat: ";
      cin>>a;
      cout<<endl<<"Podaj odleglosc lotu: ";
      cin>>d;
      cout<<endl<<"Podaj predkosc: ";
      cin>>v;
      scene.dragonfly->change_velocity(v);
      scene.fly(a, h, d);
      break;
    case 'd':
      scene.add_landscape_element();
      break;
    case 'u':
      scene.show_landscape_elements();
      cout << "Podaj id elementu, ktory chcesz usunac: ";
      cin >> del;
      scene.delete_landscape_element(del);
      break;
    case 'p':
      scene.show_landscape_elements();
      break;
    case 'w':
      std::cout<<"Aktualnie w pamieci: "<< Vector<3>().get_currently() << std::endl;
      std::cout<<"Ogolnie: "<< Vector<3>().get_overall() << std::endl;
      break;
    case 's':
      scene.dragonfly->zakrec_smiglem();
      break;
    case 'q':
      cout << "Koniec pracy programu!" << endl;
      delete scene.api;
      break;
    default:
      cout<<"Brak takiej opcji w menu!";
      break;
    }

  }
}
