#pragma once
#include "Usuarios.h"

using namespace std;

class Empleado: public Usuario {
  public:  
    int id;
    Empleado (std::string _usuario, std::string _contraseña, string _edad, std::string _region, int _id);
    void ver_almacen();
    void ver_quejas();
};
