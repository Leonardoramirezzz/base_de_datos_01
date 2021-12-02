#pragma once
#include <iostream>
#include <string>
#include <string.h>
#include <fstream>
#include "Usuarios.h"
#include "cliente.h"
#include "empleado.h"
#include "producto.h"
#include "Tienda.h"

using namespace std;

class Array_objetos{
  private:
    Cliente* array_cliente;
    Producto* array_producto;
    Empleado* array_empleado;
    int num_clientes_iniciales;
    int num_productos_inventarios;
  public:
    Array_objetos();
    ~Array_objetos();
    int num_registros_iniciales();
    int num_productos_iniciales(string region);
    void num_registros_mas_uno();
    void actualizar_cantidad_productos(string region, Producto* Lista_productos,int num_productos);
    Cliente* array_registros_iniciales();
    Producto* array_productos_totales(string region); 
    void actualizar_cantidad_productos(string region, int num_productos);
    Empleado* crear_array_empleado();
};

