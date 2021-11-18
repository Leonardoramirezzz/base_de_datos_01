#include "cliente_empleado.h"
#include <fstream>
#include <iostream>

ofstream Guardar_2("Quejas_Cliente.txt", ios::app);
ifstream Lec;

Cliente::Cliente(){}

Cliente::Cliente (string _usuario, string _contraseña, int _edad, string _region) : Usuario(_usuario, _contraseña, _edad, _region){}

void Cliente::ver_perfil(){
  cout << "\n--------- GameSpot ---------" << endl;
  cout << "Cuenta de cliente: " << endl;
  cout << "Usuario: " << usuario << endl;
  cout << "Contraseña: " << contraseña << endl;
  cout << "Edad: " << edad << endl;
  cout << "Región: " << region << endl;
}

void Cliente::ver_catalogo(){
  string texto;
  Lec.open("inventario.txt", ios::in);
  if(Lec.fail()) cout << "Error al abrir el archivo" << endl;
  while (!Lec.eof()){   // Mientras no se el final del archivo
    getline(Lec,texto);
    cout << texto << endl;
  }
  Lec.close(); 
}

void Cliente::comprar(){
  // Falta
}

void Cliente::quejas_reclamos(){
  string reclamo;
  cout << "Escriba su reclamo: " << endl;
  getline(cin,reclamo);
  Guardar_2 << "Nuevo reclamo: " << reclamo << endl;
}

void Cliente::ayuda_cliente(){
  string texto;
  Lec.open("Preguntas_frecuentes.txt", ios::in);
  if(Lec.fail()) cout << "Error al abrir el archivo" << endl;

  while (!Lec.eof()){   // Mientras no se el final del archivo
    getline(Lec,texto);
    cout << texto << endl;
  }
  Lec.close(); 
}


//--------------------------------------------

Empleado::Empleado (string _usuario, string _contraseña, int _edad, string _region, int _id) : Usuario(_usuario, _contraseña, _edad, _region) {
  id = _id;
}

void Empleado::ver_almacen(){
  string texto;
  Lec.open("inventario.txt", ios::in);
  if(Lec.fail()) cout << "Error al abrir el archivo" << endl;
  while (!Lec.eof()){   // Mientras no se el final del archivo
    getline(Lec,texto);
    cout << texto << endl;
  }
  Lec.close(); 
}

void Empleado::ver_quejas(){
 string texto;
  Lec.open("Quejas_Cliente.txt", ios::in);
  if(Lec.fail()) cout << "Error al abrir el archivo" << endl;
  while (!Lec.eof()){   // Mientras no se el final del archivo
    getline(Lec,texto);
    cout << texto << endl;
  }
  Lec.close(); }
