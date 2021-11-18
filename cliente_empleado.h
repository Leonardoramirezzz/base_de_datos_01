#include "usuario.h"

using namespace std;

class Cliente: public Usuario {
  public:
    Cliente();
    Cliente (std::string _usuario, std::string _contraseña, int edad, std::string _region);
    void ver_perfil();
    void ver_catalogo();
    void comprar();
    void quejas_reclamos();
    void ayuda_cliente();
};

class Empleado: public Usuario {
  public:  
    int id;
    Empleado (std::string _usuario, std::string _contraseña, int _edad, std::string _region, int _id);
    void ver_almacen();
    void ver_quejas();
};