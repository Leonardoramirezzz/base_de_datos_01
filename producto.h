#pragma once
#include <iostream>

using namespace std;

class Producto {
  private:
    string nombre, tipo, codigo, cantidad, precio;
  public:
    Producto ();
    Producto (string _nombre, string _tipo, string _codigo, string _cantidad, string _precio);
    void set_nombre(string _nombre);
    string get_nombre();

    void set_tipo(string _tipo);
    string get_tipo();

    void set_codigo(string _codigo);
    string get_codigo();

    void set_cantidad(string _cantidad);
    string get_cantidad();

    void set_precio(string _precio);
    string get_precio();

    void ver_producto();
};
