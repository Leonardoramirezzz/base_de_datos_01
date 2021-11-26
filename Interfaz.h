#pragma once
#include <fstream>
#include <vector>
#include "Usuarios.h"
#include "cliente.h"
#include "empleado.h"
#include "admin.h"
#include "Tienda.h"


using namespace std;

void menu_cliente();
void menu_empleado();
void menu_admin();

void menu_principal (bool &run);
int menu_iniciar_sesion();
void iniciar_sesion();
int num_registros_iniciales();
Cliente* array_registros_iniciales();
Producto* array_productos_totales();
void registrar_cliente();
