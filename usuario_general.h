#include "cliente_empleado.h"

//using namespace std;

class Administrador: public Empleado {
  public:
    Administrador (std::string _usuario, std::string _contraseña, int _edad, std::string _region, int _id);
    void ver_compras();
    void ver_datos();
    void ver_estadisticas();
};