#include "Interfaz.h"
#include <iostream>
#include <fstream>

ofstream Guardar("Datos_Usuarios.txt", ios::app);
ifstream Lec_interfaz;


void menu_cliente ()
{
  Cliente clientePrueba ("Carlos","contraseñasecreta","21", "Tacna");
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
  Empleado empleadoPrueba ("empleado1","contraempleado", "20", "Arequipa",007);
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
  Administrador adminPrueba ("gerente123","2021", "30", "Moquegua",0001);
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
      run = false;
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

      int num_clientes = num_registros_iniciales();

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


  int menu_iniciar_sesion(){
  int opcion;
  std::cout << "1. Iniciar como Cliente" << std::endl;
  std::cout << "2. Iniciar como Empleado" << std::endl;
  std::cout << "3. Iniciar como Administrador" << std::endl;
  std::cout << "0. Cancelar " << std::endl;
  std::cout << "Ingrese opción: ";
  std::cin >> opcion;

  switch (opcion){
    case 1:{
      std::cout<<"Se esta logueando como Cliente"<<std::endl;
      break;
    }
    case 2:{
      std::cout<<"Se esta logueando como Empleado"<<std::endl;
      break;
    }
    case 3:{
      std::cout<<"Se esta logueando como Administrador"<<std::endl;
      break;
    }
    default: {
      std::cout<<"Opcion Cancelado"<<std::endl;
    }
  }
  return opcion;
}

void iniciar_sesion(Usuario *ptr_usuario){
  std::string str_usuario;
  std::string password;

  std::cout<<"Ingrese su usuario: ";
  std::cin>>str_usuario;
  std::cout<<"Ingrese su contraseña: ";
  std::cin>>password;
  ptr_usuario->iniciar_sesion(str_usuario,password);

}

int num_registros_iniciales() {
    Lec_interfaz.open("Datos_Usuarios.txt", ios::in);
    if (!Lec_interfaz.is_open()) { //verificas que el archivo haya podido abrirse
        cout << "El archivo no ha podido abrirse" << endl;
    }

    string primera_linea;   // La primera línea solo es el número de registros actuales

    getline(Lec_interfaz, primera_linea);

    Lec_interfaz.close();
    int num_clientes = stoi(primera_linea);
    return num_clientes;
}

Cliente* array_registros_iniciales(){
    
  int num_clientes = num_registros_iniciales();
  string linea1, usuario, contraseña, edad, region;
  Lec_interfaz.open("Datos_Usuarios.txt", ios::in);
  
  Cliente* Lista_Registros = new Cliente[num_clientes];
  
  Lec_interfaz >> linea1;
  for (int i = 0;i<num_clientes; ++i){
      Lec_interfaz >> usuario;
      //usuario.pop_back();
      Lec_interfaz >> contraseña;
      //contraseña.pop_back();
      Lec_interfaz >> edad;
      //edad.pop_back();
      Lec_interfaz >> region;
      region.pop_back();
      Cliente clienteNuevo(usuario, contraseña, edad, region);
      Lista_Registros[i] = clienteNuevo;
  }
  Lec_interfaz.close();
  
  //delete[] Lista_Registros;
  return Lista_Registros;
}

void registrar_cliente() {

    int num_clientes = num_registros_iniciales();
    string usuario, contraseña, region; int opcion, edad;

    cout << "Ingrese nombre de usuario: "; cin >> usuario;
    std::cout << "Ingrese la contraseña: "; cin >> contraseña;
    cout << "Ingrese su edad: "; cin >> edad;
    cout << "Ingresa tu región: "; cin >> region;

    Guardar << usuario << " " << contraseña << " " << edad << " " << region << std::endl;

    cout << "\n\n ¡Cuenta creada con éxito!" << endl;
}

int num_productos_totales() {
    Lec_interfaz.open("inventario.txt", ios::in);
    if (!Lec_interfaz.is_open()) { //verificas que el archivo haya podido abrirse
        cout << "El archivo no ha podido abrirse" << endl;
    }

    string primera_linea_tienda;   // La primera línea solo es el número de registros actuales

    getline(Lec_interfaz, primera_linea_tienda);

    Lec_interfaz.close();
    int num_Productos = stoi(primera_linea_tienda);
    return num_Productos;
}

Producto* array_productos_totales(){
    
  int num_Productos = num_productos_totales();
  string linea1_productos, nombre, tipo, codigo, cantidad,precio;
  Lec_interfaz.open("inventario.txt", ios::in);
  
  Producto* Lista_Productos = new Producto[num_Productos];
  
  Lec_interfaz >> linea1_productos;
  for (int i = 0;i<num_Productos; ++i){
      Lec_interfaz >>nombre ;
      //usuario.pop_back();
      Lec_interfaz >> tipo;
      //contraseña.pop_back();
      Lec_interfaz >> codigo;
      //edad.pop_back();
      Lec_interfaz >>cantidad ;
     // region.pop_back();
      Lec_interfaz >> precio;
      precio.pop_back();
      Producto ProductoNuevo(nombre, tipo, codigo, cantidad,precio);
      Lista_Productos[i] = ProductoNuevo;
  }
  Lec_interfaz.close();
  
  //delete[] Lista_Registros;
  return Lista_Productos;
}
