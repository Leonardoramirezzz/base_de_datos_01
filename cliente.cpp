#include "cliente.h"
#include <fstream>
#include <iostream>

ofstream Guardar_2("Quejas_Cliente.txt", ios::app);

ifstream Lec_cliente;


Cliente::Cliente(){}

Cliente::Cliente (string _usuario, string _contraseña, string _edad, string _region) : Usuario(_usuario, _contraseña, _edad, _region){}

void Cliente::ver_perfil(){
  cout << "\n--------- GameSpot ---------" << endl;
  cout << "Cuenta de cliente: " << endl;
  cout << "Usuario: " << get_usuario() << endl;
  cout << "Contraseña: " << get_contraseña() << endl;
  cout << "Edad: " << get_edad() << endl;
  cout << "Región: " << get_region() << endl;
}

void Cliente::ver_catalogo(){
  string texto;
  Lec_cliente.open("inventario.txt", ios::in);
  if(Lec_cliente.fail()) cout << "Error al abrir el archivo" << endl;
  while (!Lec_cliente.eof()){   // Mientras no se el final del archivo
    getline(Lec_cliente,texto);
    cout << texto << endl;
  }
  Lec_cliente.close(); 
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
  Lec_cliente.open("Preguntas_frecuentes.txt", ios::in);
  if(Lec_cliente.fail()) cout << "Error al abrir el archivo" << endl;

  while (!Lec_cliente.eof()){   // Mientras no se el final del archivo
    getline(Lec_cliente,texto);
    cout << texto << endl;
  }
  Lec_cliente.close(); 
}

