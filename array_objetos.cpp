#include "array_objetos.h"
#include <fstream>
#include <iostream>
#include "cliente.h"
ifstream Lec_arrays;
Array_objetos::Array_objetos(){
  num_clientes_iniciales = 0;
  num_productos_inventarios = 0;
  array_cliente = nullptr;
  array_producto = nullptr;
  array_empleado = nullptr;
}

Array_objetos::~Array_objetos(){
  delete[] array_cliente;
  delete[] array_producto;
  delete[] array_empleado;
}

int Array_objetos::num_registros_iniciales() {
    Lec_arrays.open("Num_Datos_Usuarios.txt", ios::in);
    if (!Lec_arrays.is_open()) { //verificas que el archivo haya podido abrirse
        cout << "El archivo no ha podido abrirse" << endl;
    }

    string primera_linea;   // La primera línea solo es el número de registros actuales

    getline(Lec_arrays, primera_linea);

    Lec_arrays.close();
    num_clientes_iniciales = stoi(primera_linea);
    return num_clientes_iniciales;
}


int Array_objetos::num_productos_iniciales(string region) {
    string nombre_invent = "Inventario_" + region + ".txt";
    Lec_arrays.open(nombre_invent.c_str(), ios::in);
    if (!Lec_arrays.is_open()) { //verificas que el archivo haya podido abrirse
        cout << "El archivo no ha podido abrirse" << endl;
    }

    string primera_linea;   // La primera línea solo es el número de registros actuales

    getline(Lec_arrays, primera_linea);

    Lec_arrays.close();
    num_productos_inventarios = stoi(primera_linea);
    return num_productos_inventarios;
}

void Array_objetos::num_registros_mas_uno(){
  int actualization= num_registros_iniciales()+1;
  remove("Num_Datos_Usuarios.txt");  
  ofstream actualizado("Num_Datos_Usuarios.txt",ios::out);
  actualizado<< actualization;
  actualizado.close();
}

void Array_objetos::actualizar_cantidad_productos(string region, Producto* Lista_productos,int num_productos){
  string nombre_invent = "Inventario_" + region + ".txt";
  remove(nombre_invent.c_str());  
  ofstream actualizado(nombre_invent.c_str(),ios::out);
  actualizado << num_productos << endl;
  for(int i=0;i<num_productos-1;++i){
    actualizado << Lista_productos[i].get_nombre() << " " << Lista_productos[i].get_tipo() << " " << Lista_productos[i].get_codigo() <<" " <<Lista_productos[i].get_cantidad() << " "<<Lista_productos[i].get_precio() << endl; 
  }
  actualizado << Lista_productos[num_productos-1].get_nombre() << " " << Lista_productos[num_productos-1].get_tipo() << " " << Lista_productos[num_productos-1].get_codigo() <<" " <<Lista_productos[num_productos-1].get_cantidad() << " "<<Lista_productos[num_productos-1].get_precio();
}


Cliente* Array_objetos::array_registros_iniciales(){
    
  int num_clientes = num_registros_iniciales();
  string usuario, contraseña, edad, region,num_compras;
  Lec_arrays.open("Datos_Usuarios.txt", ios::in);
  
  array_cliente = new Cliente[num_clientes];
  
  for (int i = 0;i<num_clientes; ++i){
      Lec_arrays >> usuario;
      Lec_arrays >> contraseña;
      Lec_arrays >> edad;
      Lec_arrays >> region;
      Lec_arrays >> num_compras;
      Cliente clienteNuevo(usuario, contraseña, edad, region, num_compras);
      array_cliente[i] = clienteNuevo;
  }
  Lec_arrays.close();
  return array_cliente;
}


Producto* Array_objetos::array_productos_totales(string region){
  int num_Productos = num_productos_iniciales(region);
  string linea1_productos, nombre, tipo, codigo, cantidad,precio;
  if(region == "Norte"){Lec_arrays.open("Inventario_Norte.txt", ios::in);}
  else if(region == "Sur"){Lec_arrays.open("Inventario_Sur.txt", ios::in);}
  else if(region == "Centro"){Lec_arrays.open("Inventario_Centro.txt", ios::in);}
  else if(region == "Selva"){Lec_arrays.open("Inventario_Selva.txt", ios::in);}
  else if(region == "Lima"){Lec_arrays.open("Inventario_Lima.txt", ios::in);}
  
  array_producto = new Producto[num_Productos];
  
  Lec_arrays >> linea1_productos;
  for (int i = 0;i<num_Productos; i++){
      Lec_arrays >>nombre;
      Lec_arrays >> tipo;
      Lec_arrays >> codigo;
      Lec_arrays >> cantidad;
      Lec_arrays >> precio;
      Producto ProductoNuevo(nombre, tipo, codigo, cantidad,precio);
      array_producto[i] = ProductoNuevo;
  }
  Lec_arrays.close();
  return array_producto;
}

Empleado* Array_objetos::crear_array_empleado(){
  Empleado empC("BestEmployee1","contrasena","20","Centro",015);
  Empleado empL("BestEmployee2","nolodigas","30","Lima",010);
  Empleado empN("BestEmployee3","secreto","19","Norte",020);
  Empleado empSel("BestEmployee4","incognito","32","Selva",023);
  Empleado empSur("BestEmployee5","nadielosabe","26","Sur",016);

  array_empleado = new Empleado[5];
  array_empleado[0]=empC;
  array_empleado[1]=empL;
  array_empleado[2]=empN;
  array_empleado[3]=empSel;
  array_empleado[4]=empSur;
  return array_empleado;
}
