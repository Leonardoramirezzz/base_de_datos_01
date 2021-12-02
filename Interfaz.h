#pragma once
#include <string>
#include <string.h>
#include <fstream>
#include "Usuarios.h"
#include "cliente.h"
#include "empleado.h"
#include "admin.h"
#include "producto.h"
#include "Tienda.h"
#include "array_objetos.h"
using namespace std;

void menu_cliente(Cliente persona);
void menu_empleado(Empleado semiadmin);
void menu_admin();

void menu_principal (bool &run);
string ingresar_region();
