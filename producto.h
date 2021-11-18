#include <iostream>

using namespace std;

class Producto {
  private:
    string nombre, tipo, codigo; 
    int cantidad; 
    double precio;
  public:
    Producto ();
    Producto (string _nombre, string _tipo, string _codigo, int _cantidad, double _precio);
    void set_nombre(string _nombre);
    string get_nombre();

    void set_tipo(string _tipo);
    string get_tipo();

    void set_codigo(string _codigo);
    string get_codigo();

    void set_cantidad(int _cantidad);
    int get_cantidad();

    void set_precio(double _precio);
    double get_precio();

    void ver_producto();
};