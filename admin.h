#pragma once
#include "empleado.h"

using namespace std;

class Administrador: public Empleado {
  private:
    int num_empleados;
  public:
    Administrador (std::string _usuario, std::string _contraseña, string _edad, std::string _region, int _id,int num_empleados);
    void Ver_cantidad_de_empleados();
    void ver_datos();
    int get_num_empleados();
};
