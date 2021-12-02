#include "cliente.h"
#include "Interfaz.h"
#include "empleado.h"
#include <fstream>
#include <iostream>
#include <string>
#include <string.h>

ofstream Guardar_2("Quejas_Cliente.txt", ios::app);

ifstream Lec_cliente;


Cliente::Cliente(){}

Cliente::Cliente (string _usuario, string _contraseña, string _edad, string _region) : Usuario(_usuario, _contraseña, _edad, _region){}

void Cliente::ver_perfil(){
  cout << "\n--------- GameSpot ---------" << endl;
  cout << "Cuenta de cliente: " << endl;
  cout << "Usuario: " << get_usuario() << endl;
  cout << "Contraseña: " << get_contraseña() << endl;
  cout << "Edad: " << get_edad() << endl;
  cout << "Región: " << get_region() << endl;
}

void Cliente::ver_catalogo(){
  string texto;
  string nombre_inventario;
  nombre_inventario = "Inventario_" + get_region() + ".txt";
  int count = 1;
  Lec_cliente.open(nombre_inventario.c_str(), ios::in);
  if(Lec_cliente.fail()) cout << "Error al abrir el archivo" << endl;
  getline(Lec_cliente,texto);
  cout << "\n\n---------------------  GAMESPOT  ---------------------" << endl;
  
  while (!Lec_cliente.eof()){   // Mientras no se el final del archivo 
    getline(Lec_cliente,texto);
    cout << count << ". " << texto << endl;
    count++;
  }
  Lec_cliente.close(); 

}

void Cliente::comprar(int nume_productos, Producto* Lista_Productos){
  int indice = nume_productos-1, nueva_cantidad;
  if (stoi(Lista_Productos[indice].get_cantidad())> 0){
    nueva_cantidad = (stoi(Lista_Productos[indice].get_cantidad()))-1;
    Lista_Productos[indice].set_cantidad(to_string(nueva_cantidad)); 
    
    cout << "Producto escogido: " << Lista_Productos[indice].get_nombre();
    cout << "\n¡La compra fue hecha con éxito!" << endl;
  }
  else cout << "El producto está agotado" << endl;
}


void Cliente::quejas_reclamos(){
  string reclamo;
  cout << "Escriba su reclamo: " << endl;
  cin >> reclamo;
  Guardar_2 << "Nuevo reclamo: " << reclamo << endl;
}

void Cliente::ayuda_cliente(){
  string texto;
  Lec_cliente.open("Preguntas_frecuentes.txt", ios::in);
  if(Lec_cliente.fail()) cout << "Error al abrir el archivo" << endl;

  while (!Lec_cliente.eof()){   // Mientras no se el final del archivo
    getline(Lec_cliente,texto);
    cout << texto << endl;
  }
  Lec_cliente.close(); 
}


void Cliente::iniciar_sesion(std::string _usuario, std:: string _password,int nume_clientes, Cliente* listaC,Empleado* ListaEm){
  if(_usuario== "Gamespot2021" && _password =="powertotheplayers" ) {
    std::cout<<"Bienvenido jefecito"<<std::endl;
    sesion_iniciada = true;
    menu_admin();
    }
  for (int k=0;k<5;k++){
    if (ListaEm[k].get_usuario()== _usuario&& ListaEm[k].get_contraseña()==_password){
    std::cout<<"Sesion iniciada correctamente"<<std::endl<<"Bienvenido de vuelta nuestro valioso y queridisimo empleado  "<<ListaEm[k].get_usuario()<<std::endl;
    sesion_iniciada = true;
    menu_empleado(ListaEm[k]);
    }

  }
  for (int i=0;i<nume_clientes;i++)
  {
    if(listaC[i].get_usuario()==_usuario && listaC[i].get_contraseña()==_password)
    {
      std::cout<<"Sesion iniciada correctamente, disfute su visita a GameSpot "<<listaC[i].get_usuario()<<std::endl;
      sesion_iniciada = true;
      menu_cliente(listaC[i]);
    } 
  }


  if(sesion_iniciada==false){
      std::cout<<"Sesion no encontrada por favor registrese para acceder a la plataforma"<<endl;
  }
  
}
