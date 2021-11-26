#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include "Usuarios.h"
#include "cliente.h"
#include "empleado.h"
#include "admin.h"
#include "Interfaz.h"


using namespace std;


int main(){ 
 
 
  bool run = true;  
  while (run){
    menu_principal(run);
  }
  
  
  /*Cliente* lista_existente = new Cliente[num_registros_iniciales()];
  for (int i = 0; i < num_registros_iniciales(); ++i){
    lista_existente[i] = *array_registros_iniciales();
  }


  for (int i = 0; i < num_registros_iniciales(); ++i){
    cout << lista_existente[i].get_usuario() << endl;
  }
  */
  /*
  Cliente* lista[num_registros_iniciales()];
  */
  /*
  array_registros_iniciales();

  cout << lista_existente[1].get_usuario() << endl;
  
  for (int i = 0; i<8; ++i){
    cout << i << ". " << (*lista[i]).get_usuario() << endl;
  }
  */
  return 0;
}
