#pragma once
#include "Usuarios.h"
#include "producto.h"
#include "empleado.h"
using namespace std;

class Cliente: public Usuario {
  public:
    Cliente();
    Cliente (std::string _usuario, std::string _contraseña, std::string edad, std::string _region);
    void ver_perfil();
    void ver_catalogo();
    void comprar(int nume_productos, Producto* Lista_Productos);
    void quejas_reclamos();
    void ayuda_cliente();
    void iniciar_sesion(std::string _usuario, std:: string _password,int nume_clientes, Cliente* listaC,Empleado* ListaEm);
};
