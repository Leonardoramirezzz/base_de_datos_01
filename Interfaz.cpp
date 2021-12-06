#include "Interfaz.h"
#include <iostream>
#include <string>
#include <string.h>
#include <fstream>

ofstream Guardar("Datos_Usuarios.txt", ios::app);
ifstream Lec_interfaz;

void menu_cliente (Cliente persona, int i)
{
  
  Array_objetos lista_compra;
  Producto* lista = lista_compra.array_productos_totales(persona.get_region());
  Cliente* listaC = lista_compra.array_registros_iniciales();
  int opcion_1;
  cout << "\n\n---------------------  GAMESPOT  ---------------------" << endl;
  cout << "¡Bienvienido a la tienda de la región: " << persona.get_region() << "!"<< endl;
  cout << "1. Ver catalogo" << endl;
  cout << "2. Comprar " << endl;
  cout << "3. Quejas y reclamos" << endl;
  cout << "4. Ayuda al cliente"<< endl;
  cout << "5. Ver Perfil"<< endl;
  cout << "0. Cerrar sesión" << endl;
  cout << "Ingrese opción: ";

  cin >> opcion_1;
  switch (opcion_1){
    case 0:{
      break;
    }
    case 1:{  
      persona.ver_catalogo(); 
      menu_cliente(persona,i);
      break;
    }
    case 2:{  // Comprar
      
      int compras;
      persona.ver_catalogo();
      cout << "\nSeleccione el producto que desea comprar: " << endl;
      cin >> compras;
      persona.comprar(lista_compra.num_registros_iniciales(), listaC, compras, lista,i);
      lista_compra.actualizar_cantidad_productos(persona.get_region(),lista,lista_compra.num_productos_iniciales(persona.get_region()));
      
      

      menu_cliente(persona,i);
      break;
    }
    case 3:{
      persona.quejas_reclamos();
      menu_cliente(persona,i);
      break;
    }
    case 4:{ 
      persona.ayuda_cliente();  
      menu_cliente(persona,i);
      break;
    }
    case 5:{
      persona.ver_perfil();
      menu_cliente(persona,i);
    }
  }
  cout <<endl;
}

void menu_empleado(Empleado semiadmin){
  int opcion_empleado;
  cout << "\n\n---------------------  GAMESPOT  ---------------------" << endl;
  cout << "1. Ver almacén" << endl;
  cout << "2. Ver quejas" << endl;
  cout << "0. Salir de la Sesión" << endl;
  cout << "Ingrese su opción: ";
  cin >> opcion_empleado;

  switch (opcion_empleado){
    case 1:{
      semiadmin.ver_almacen(semiadmin.get_region()); 
      menu_empleado(semiadmin);
      break;
    }
    case 2:{
      semiadmin.ver_quejas();
      menu_empleado(semiadmin);
      break;
    }
    case 0:{ 
      break;    
    }
  }
  cout << endl;
}

void menu_admin(){
  Administrador admin("Gamespot2021","powertotheplayers","70","Lima",007,5); 
  int opcion_admin;
  cout << "\n\n---------------------  GAMESPOT  ---------------------" << endl;
  cout << "1. Ver número de empleados" << endl;
  cout << "2. Ver datos de los usuarios" << endl;
  cout << "0. Salir de la Sesión" << endl;
  cout << "Ingrese su opción: ";
  cin >> opcion_admin;

  switch (opcion_admin){
    case 1:{
      admin.Ver_cantidad_de_empleados(); 
      menu_admin();
      break;
    }
    case 2:{
      admin.ver_datos();
      menu_admin();
      break;
    }
    case 0:{
      break;
    }
  }
  cout << endl;
}

void menu_principal (bool &run) {
  
  string usuario, contraseña,edad, region; int opcion;

  cout << "---------------------  GAMESPOT  ---------------------" << endl;
  cout << "1. Iniciar sesión" << endl;
  cout << "2. Registrarse como cliente" << endl;
  cout << "0. Salir del programa" << endl;
  cout << "Ingrese opción: ";

  cin >> opcion;

  switch (opcion){
    case 0:{
      run = false;
      break;
     }
    case 1:
    {
      Cliente login("0","0","0","0","0");
      cout << "Ingrese nombre de usuario: "; cin >> usuario;
      cout << "Ingrese la contraseña: "; cin >> contraseña;
      Array_objetos lista_login;
      int num_regis_ini = lista_login.num_registros_iniciales();
      Cliente* lista = lista_login.array_registros_iniciales();
      Empleado* lista_emp = lista_login.crear_array_empleado();
      login.iniciar_sesion(usuario,contraseña,num_regis_ini,lista,lista_emp);
      break;

    }
    case 2:{

      cout << "Ingrese nombre de usuario: "; cin >> usuario;
      cout << "Ingrese la contraseña: "; cin >> contraseña;
      cout << "Ingrese su edad: "; cin >> edad;
      region = ingresar_region();

      
      Guardar << usuario << " " << contraseña << " " << edad << " " << region <<       " 0"<< endl;

      Array_objetos numero_actualizado;
      numero_actualizado.num_registros_mas_uno();

      cout << "\n\n ¡Cuenta creada con éxito!" << endl;

      
      break;
    }
      
  }
}


string ingresar_region(){
  int respuesta; string region;
  cout << "Ingrese a qué region pertenece: " << endl;
  cout << "1. Norte (Áncash - La Libertad - Piura - Cajamarca - Lambayeque - Tumbes" << endl;
  cout << "2. Sur (Arequipa - Apurímac - Cusco - Moquegua - Puno - Tacna)" << endl;
  cout << "3. Centro (Ica - Junín - Ayacucho - Paso - Huancavelica - Huánuco) " << endl;
  cout << "4. Selva (Made de Dios - Loreto - San Martín - Amazonas - Ucayali)" << endl;
  cout << "5. Lima y Callao (Lima - Lima metropolitana - Lima región - Callao)" << endl;
  cin >> respuesta;
  switch (respuesta){
    case 1:{
      region = "Norte";
      break;
    }
    case 2:{
      region = "Sur";
      break;
    }
    case 3:{
      region = "Centro";
      break;
    }
    case 4:{
      region = "Selva";
      break;
    }
    case 5:{
      region = "Lima";
      break;
    }
  }
  return region;
}

