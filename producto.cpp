#include "producto.h"

Producto::Producto(){}

Producto::Producto (string _nombre, string _tipo, string _codigo, string _cantidad, string _precio){
  nombre = _nombre;
  tipo = _tipo;
  codigo = _codigo;
  cantidad = _cantidad;
  precio = _precio;
}


void Producto::set_nombre(string _nombre){
  nombre = _nombre;
}

string Producto::get_nombre(){
  return nombre;
}

void Producto::set_tipo(string _tipo){
  tipo = _tipo;
}
string Producto::get_tipo(){
  return tipo;
}

void Producto::set_codigo(string _codigo){
  codigo = _codigo;
}
string Producto::get_codigo(){
  return codigo;
}

void Producto::set_cantidad(string _cantidad){
  cantidad = _cantidad;
}
string Producto::get_cantidad(){
  return cantidad;
}

void Producto::set_precio(string _precio){
  precio = _precio;
}
string Producto::get_precio(){
  return precio;
}


void Producto::ver_producto(){
  
  cout << "Nombre: " << nombre << endl;
  cout << "tipo: " << tipo << endl;
  cout << "código: " << codigo << endl;
  cout << "cantidad: " << cantidad << endl;
  cout << "precio: " << precio << endl;
}
