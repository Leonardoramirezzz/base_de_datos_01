#include "admin.h"
#include <iostream>
#include <fstream>


ifstream Lec3;

Administrador::Administrador (string _usuario, string _contraseña, string _edad, string _region, int _id) : Empleado(_usuario, _contraseña, _edad, _region, _id) {}

void Administrador::ver_compras(){

}

void Administrador::ver_datos(){
  string texto;
  Lec3.open("Datos_Usuarios.txt", ios::in);
  if(Lec3.fail()) cout << "Error al abrir el archivo" << endl;

  while (!Lec3.eof()){   // Mientras no se el final del archivo
    getline(Lec3,texto);
    cout << texto << endl;
  }
  Lec3.close(); 
}

void Administrador::ver_estadisticas(){
  
}
