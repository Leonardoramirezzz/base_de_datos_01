#include <fstream>
#include <iostream>
#include "empleado.h"

ifstream Lec_empleado;

Empleado::Empleado(){
}

Empleado::Empleado (string _usuario, string _contraseña, string _edad, string _region, int _id) : Usuario(_usuario, _contraseña, _edad, _region) {
  id = _id;
}


void Empleado::ver_almacen(string region){
  cout << "------------  GAMESPOT  ------------" << endl;
  string texto;
  string nombre_almacen = "Inventario_" + get_region() + ".txt";
  Lec_empleado.open(nombre_almacen.c_str(), ios::in);
  if(Lec_empleado.fail()) cout << "Error al abrir el archivo" << endl;
  while (!Lec_empleado.eof()){   // Mientras no se el final del archivo
    getline(Lec_empleado,texto);
    cout << texto << endl;
  }
  Lec_empleado.close(); 
}

void Empleado::ver_quejas(){
 string texto;
  Lec_empleado.open("Quejas_Cliente.txt", ios::in);
  if(Lec_empleado.fail()) cout << "Error al abrir el archivo" << endl;
  while (!Lec_empleado.eof()){   // Mientras no se el final del archivo
    getline(Lec_empleado,texto);
    cout << texto << endl;
  }
  Lec_empleado.close(); }
