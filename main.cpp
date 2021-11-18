#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include "usuario_general.h"

using namespace std;

ofstream Guardar("Datos_Usuarios.txt", ios::app);
ifstream Lec2;

string lee(ifstream &a){    //01
  string s, contenido;
  while(getline(a,s)){
    contenido += s + "\n";
  }
  return contenido;
}

int cuenta(const string &contenido, char c){    //02
  int count = 0;
  string::const_iterator i;
  for (i = contenido.begin(); i != contenido.end(); ++i){
    if (*i == c){
      ++count;
    }
  }
  return count;
}

int num_usuarios(){   //03, Num de usuarios actuales
  int cantidad; string contenido;
  Lec2.open("Datos_Usuarios.txt");
  contenido = lee(Lec2);
  cantidad = cuenta(contenido, ':');
  return cantidad;
}



/*void iniciar_sesion(std::ifstream &Lec_2){
  
  Lec_2.open("Datos_Usuario.txt",std::ios::in);
  std::string usuario,contraseña,edad,region,usuarioAux,contraAux;
  bool encontrado= false;
  std::cout<<"Digite el usuario: ";
  std::cin>>usuarioAux;
  std::cout<<"Digite la contraseña: ";
  std::cin>>contraAux;
  Lec_2>>usuario;
  while(!Lec_2.eof() && encontrado==false){
    
    Lec_2>>usuario;
    if (usuario==usuarioAux){
      std::cout<<"Sesion iniciada con exito";
      encontrado=true;

    }
    Lec_2>>contraseña;
    if (contraseña==contraAux){
      std::cout<<"Sesion iniciada con exito";
      encontrado=true;
    }
    Lec_2>>edad;
    Lec_2>>region;
  }
  Lec_2.close();
  if (encontrado==false){
    std::cout<< "Usuario no encontrado" << std :: endl;
  }
}
*/
void menu_cliente ()
{
  Cliente clientePrueba ("Carlos","contraseñasecreta",21, "Tacna");
  int opcion_1;
  cout << "\n\n---------------------  GAMESPOT  ---------------------" << endl;
  std::cout << "1. Ver catalogo" << std::endl;
  std::cout << "2. Comprar " << std::endl;
  std::cout << "3. Quejas y reclamos" << std::endl;
  std::cout << "4. Ayuda al cliente"<< std::endl;
  std::cout << "0. Salir de la pantalla" << std::endl;
  std::cout << "Ingrese opción: ";

  cin >> opcion_1;
  switch (opcion_1){
    case 0:{
      break;
    }
    case 1:{  
      clientePrueba.ver_catalogo(); 
      break;
    }
    case 2:{  // Comprar
      clientePrueba.comprar();  
      break;
    }
    case 3:{
      clientePrueba.quejas_reclamos();
      break;
    }
    case 4:{ 
      clientePrueba.ayuda_cliente();    
      break;
    }
  }
  cout <<endl;
}

void menu_empleado(){
  int opcion_empleado;
  Empleado empleadoPrueba ("empleado1","contraempleado", 20, "Arequipa",007);
  cout << "\n\n---------------------  GAMESPOT  ---------------------" << endl;
  cout << "1. Ver almacén" << endl;
  cout << "2. Ver quejas" << endl;
  cout << "0. Salir de la Sesión" << endl;
  cout << "Ingrese su opción: ";
  cin >> opcion_empleado;

  switch (opcion_empleado){
    case 1:{
      empleadoPrueba.ver_almacen(); 
      break;
    }
    case 2:{
      empleadoPrueba.ver_quejas();
      break;
    }
    case 0:{    // menu principal
      break;    
    }
  }
  cout << endl;
}

void menu_admin(){
  Administrador adminPrueba ("gerente123","2021", 30, "Moquegua",0001);
  int opcion_admin;
  cout << "\n\n---------------------  GAMESPOT  ---------------------" << endl;
  cout << "1. Ver compras" << endl;
  cout << "2. Ver datos de los usuarios" << endl;
  cout << "3. Ver estadísticas de las tiendas" << endl;
  cout << "0. Salir de la Sesión" << endl;
  cout << "Ingrese su opción: ";
  cin >> opcion_admin;

  switch (opcion_admin){
    case 1:{
      adminPrueba.ver_compras(); // Falta implementar
      break;
    }
    case 2:{
      adminPrueba.ver_datos();
      break;
    }
    case 3:{
      adminPrueba.ver_estadisticas(); // Falta implementar
      break;
    }
    case 0:{
      break;
    }
  }
  cout << endl;
}



void menu_principal (bool &run) {
  string usuario, contraseña, region; int opcion,edad;

  cout << "---------------------  GAMESPOT  ---------------------" << endl;
  cout << "1. Iniciar sesión" << endl;
  cout << "2. Registrarse como cliente" << std::endl;
  cout << "3. (Probar) Menú cliente" << std::endl;
  cout << "4. (Probar) Menú empleado" << std::endl;
  cout << "5. (Probar) Menú administrador" << std::endl;
  cout << "0. Salir del programa" << endl;
  cout << "Ingrese opción: ";

  cin >> opcion;

  switch (opcion){
    case 0:{
      //run = false;
      break;
     }
    case 1:
    {
      cout << "Ingrese nombre de usuario: "; cin >> usuario;
      cout << "Ingrese la contraseña: "; cin >> contraseña;
      //verificar(usuario,contraseña,run);
      break;

    }
    case 2:{

      int num_clientes = num_usuarios();

      cout << "Ingrese nombre de usuario: "; cin >> usuario;
      std::cout << "Ingrese la contraseña: "; cin >> contraseña;
      cout << "Ingrese su edad: "; cin >> edad;
      cout << "Ingresa tu región: "; cin >> region;

      Guardar << "Usuario: " << usuario << " - " << contraseña <<  " - " << edad << " - " << region << std::endl;
      
      cout << "\n\n ¡Cuenta creada con éxito!" << endl;
      //Cliente clienteN (usuario,contraseña, edad, region);
      
      // ARRAY DE OBJETOS CLASE CLIENTE
      /*
      Cliente *arr = new Cliente[num_clientes+1];
      for (int i = num_clientes; i < num_clientes+1; ++i){
        Cliente clienteN (usuario, contraseña, edad, region);
      }
      */
      break;
      }
    case 3:{
      menu_cliente();
      break;
    }
    case 4:{
      menu_empleado();
      break;
    }
    case 5:{
      menu_admin();
    }
    }
  }



int main(){ 
  
  bool run = true;  
  while (run){
    menu_principal(run);
  }
  
  return 0;
}
