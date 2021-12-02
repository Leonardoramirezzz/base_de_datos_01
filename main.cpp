#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include "producto.h"
#include "Tienda.h"
#include "Usuarios.h"
#include "cliente.h"
#include "empleado.h"
#include "admin.h"
#include "Interfaz.h"
#include "array_objetos.h"

using namespace std;

int main(){ 
  bool run = true;  
  while (run){
    menu_principal(run);
  }
  return 0;
}

