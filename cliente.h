#pragma once
#include "Usuarios.h"

using namespace std;

class Cliente: public Usuario {
  public:
    Cliente();
    Cliente (std::string _usuario, std::string _contraseña, std::string edad, std::string _region);
    void ver_perfil();
    void ver_catalogo();
    void comprar();
    void quejas_reclamos();
    void ayuda_cliente();
};

