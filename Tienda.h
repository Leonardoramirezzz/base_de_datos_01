#pragma once
#include <fstream>
#include "producto.h"
#include "array_objetos.h"

using namespace std;

class Tienda {
  private:
    int id;
    string direccion;
    string nombre_catalogo;
    string region;
    Producto* inventario;
  public:
    Tienda();
    Tienda(int _id, string _direccion, string _nombre_catalogo);
    ~Tienda();
    void set_id(int _id);
    int get_id();
    void set_direccion(string _direccion);
    string get_direccion();
    void set_nombre_catalogo(string _nombre_catalogo);
    string get_nombre_catalogo();
    void imprimirTienda();
    bool recibir_queja(std::string _queja);
    void ver_quejas();
    void mostrar_catalogo(int numero_productos);
    Producto* get_inventario();
};
