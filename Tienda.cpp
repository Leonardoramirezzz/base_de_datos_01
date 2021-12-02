#include <iostream>
#include <fstream>
#include "Tienda.h"

ifstream Lec_tienda;

Tienda::Tienda(){
  Array_objetos Inventory;
  inventario = Inventory.array_productos_totales("Centro");
}

Tienda::Tienda(int _id, string _direccion, string _nombre_catalogo){
  Array_objetos Inventory;
  id = _id;
  direccion = _direccion;
  nombre_catalogo = _nombre_catalogo;
  inventario = Inventory.array_productos_totales(_nombre_catalogo);
}

Tienda::~Tienda(){
  delete[] inventario;
}

void Tienda::set_id(int _id){
  id = _id;
}

int Tienda::get_id(){
  return id;
}

void Tienda::set_direccion(string _direccion){
  direccion = _direccion;
}

string Tienda::get_direccion(){
  return direccion;
}

void Tienda::set_nombre_catalogo(string _nombre_catalogo){
  nombre_catalogo = _nombre_catalogo;
}

string Tienda::get_nombre_catalogo(){
  return nombre_catalogo;
}

Producto* Tienda::get_inventario(){
  return inventario;
}


void Tienda::imprimirTienda(){
  cout<<"El id de la tienda es: " << id << endl;
  cout<<"La direccion de la tienda es: " << direccion<<endl;
  cout<<"El catalogo de la tienda es: " << nombre_catalogo<<endl;
}

bool Tienda::recibir_queja(string _queja){
  string nombre_archivo_quejas;
  nombre_archivo_quejas = "archivo_quejas_" + to_string(id) + ".txt";
  ofstream archivo(nombre_archivo_quejas.c_str(), ios::app);
  if (!archivo.is_open()){ //verificas que el archivo haya podido abrirse
    cout<<"El archivo no ha podido abrirse"<<endl;
    return false;
  }
  archivo << _queja << endl << endl;
  archivo.flush();
  archivo.close();
  return true;
}

void Tienda::ver_quejas(){
  string nombre_archivo_quejas;
  nombre_archivo_quejas = "archivo_quejas_" + to_string(id) + ".txt";
  ifstream archivo(nombre_archivo_quejas.c_str(), ios::in);
  if (!archivo.is_open()){ //verificas que el archivo haya podido abrirse
    cout<<"El archivo no ha podido abrirse"<<endl;
    return;
  }
  string linea_archivo;
  cout<<"Quejas de la tienda: " << id << endl;
  /* formato de queja 
      nombre_cliente
      id_cliente 
      queja 
  */
  int cuenta_queja=1;
  while (!archivo.eof()){
    cout<<endl<<"Queja N° "<<cuenta_queja++<<endl;
    for (int i=0;i<2;i++){
      getline(archivo, linea_archivo);
      cout<<linea_archivo<<endl;
    }
    getline(archivo, linea_archivo);
  }
  archivo.close();
}

void Tienda::mostrar_catalogo(int numero_productos){
  cout<<"\t\t\tCatalogo tienda " << id << endl << endl;
  cout<<"Producto\t\t\tPrecio\t\t\tEstado"<<endl;
  cout<<"----------------------------------------------"<<endl;
  for(int i=0; i < numero_productos ; i++){
    cout<<inventario[i].get_nombre()<<"\t\t\t";
    cout<<inventario[i].get_precio()<<"\t\t\t";
    if (stoi(inventario[i].get_cantidad())>0){
      cout << "Disponible";
    }
    else{
      cout << "Agotado";
    } 
    cout<<endl;
  }
}
