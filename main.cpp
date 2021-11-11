#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
using namespace std;

//ifstream Lec("Datos_Usuarios.txt", ios::out|ios::app);
ofstream Guardar("Datos_Usuarios.txt", ios::app);
//ofstream Guardar_2("Quejas_Cliente.txt", ios::app);


class Usuario {
  public:
    string usuario, contraseña, edad, region;

    Usuario (string, string, int, string);
    void iniciar_sesion(){}
    void cerrar_sesion(){}
};

Usuario::Usuario(string _usuario, string _contraseña, int _edad, string _region){
  usuario = _usuario; contraseña = _contraseña;
}

class Cliente: public Usuario{
  public:
    Cliente(string, string, int, string);
    void ver_perfil(){
      cout << "Usuario: " << usuario << endl << "Contraseña: " << contraseña << endl << "Edad: " << edad << endl << "Región: " << region; 
    }
    void ver_catalogo(){};
    //en proceso necesita Almacen
    void comprar(){};
    //en proceso necesita clase tienda 
    void quejas_reclamos(){
      string reclamo;
      cout << "Escriba su reclamo: " << endl;
      getline(cin,reclamo);
      //Guardar_2 << reclamo << endl;
    }
    void ayuda_cliente()
    {
      cout<<"Servicio de soporte al cliente de Gamestop cual es el problema que tiene: "<<endl<<"1.No aparece disponible el producto que deseo. "<< endl<<"2. Status de mis productos si en medio de la fecha de envio ocurre un accidente zombie a escala global"<<endl<< "3.Comportamiento hostil por parte de los trabajadores"<<endl;
      int eleccion_ayuda;
      cin>> eleccion_ayuda;
      switch(eleccion_ayuda)
      {
        case 1: cout<<"El producto puede que se encuentre agotado, se pondra en la lista de pedidos para tenerlo lo mas pronto posible."<<endl;
        break;
        case 2: cout<<"Lo siento pero la empresa no se hace cargo segun sus politicas, pero a cambio obtendra un cupon de 30% de descuento en su proxima compra"<<endl;
        break;
        case 3: cout<<"Enviaremos un mensaje a los encargados"<<endl;
        break;
      }
    }
    void calificar(){};
};

Cliente::Cliente(string _usuario, string _contraseña, int _edad, string _region) : Usuario(_usuario, _contraseña, _edad, _region){}

class Empleado: public Usuario{
  public:
    int id;
    Empleado (string, string, int, string, int);
    void ver_almacen(){};
    void ver_quejas(){};
};

Empleado::Empleado(string _usuario, string _contraseña, int _edad, string _region, int _id) : Usuario(_usuario, _contraseña, _edad, _region){
  id = _id;
}

class Administrador: public Empleado{
  public:
    Administrador(string, string, int, string, int);
    void ver_compras(){};
    void ver_datos(){};
    void estadisticas(){};
};

Administrador::Administrador(string _usuario, string _contraseña, int _edad, string _region, int _id) : Empleado(_usuario, _contraseña, _edad, _region, _id){}


/*bool verificar(ifstream &Lec){
  
  Lec.open("Datos_Usuario.txt",ios::in);
  string _usuario,_contraseña,usuarioAux,contraAux;
  bool encontrado= false;
  cout<<"Digite el usuario: ";
  cin>>usuarioAux;
  cout<<"Digite la contraseña: ";
  cin>>contraAux;

  while(!Lec.eof() && encontrado==false){
    Lec>>_contraseña;
    Lec>>_usuario;
    if (_usuario==usuarioAux && _contraseña==contraAux){
      cout<<"Sesion iniciada con exito";
      encontrado=true;      
    }
  }
  Lec.close();
  if (encontrado==false){
    cout<< "Usuario no encontrado";
  }
}
*/

void menu_cliente (bool &run_2)
{
  int opcion_1;
  cout << "---------------------  GAMESPOT  ---------------------" << endl;
  cout << "1. Ver catalogo" << endl;
  cout << "2. Carritos de compras " << endl;
  cout << "3. Calificación" << endl;
  cout << "4. Quejas y reclamos" << endl;
  cout << "5. Ayuda al cliente"<<endl;
  cout << "0. Salir de la pantalla" << endl;
  cout << "Ingrese opción: ";

  cin >> opcion_1;
  switch (opcion_1){
    case 0:{
      run_2=false;
      break;
    }
  }
}

/*bool verificar(string _usuario,string _contraseña,bool &run){
  ifstream leer("Datos_Usuarios.txt",ios::in);
  string Usuario,Contraseña;

  leer>>Usuario;
  while(!leer.eof()){
    leer>>Contraseña;
    if(Usuario ==_usuario && Contraseña == _contraseña){
      leer.close();
      cout<<"Encontrado";
      run=false;
      return false;
    }
    leer>>Usuario;
    
  }
  leer.close();
  return true;

}*/

void menu_principal (bool &run) {
  string usuario, contraseña, region; int opcion,edad;

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
      cout << "Ingrese nombre de usuario: "; cin >> usuario;
      cout << "Ingrese la contraseña: "; cin >> contraseña;
      //verificar(usuario,contraseña,run);
      break;

    }
    case 2:{
      cout << "Ingrese nombre de usuario: "; cin >> usuario;
      cout << "Ingrese la contraseña: "; cin >> contraseña;
      cout << "Ingrese su edad: "; cin >> edad;
      cout << "Ingresa tu región: "; cin >> region;

      Guardar << "Usuario: " << usuario << " - Contraseña: " << contraseña <<  " - Edad: " << edad << " - Región: " << region << endl;
      
      cout << "\n\n ¡Cuenta creada con éxito!" << endl;
      Cliente clienteN (usuario,contraseña, edad, region);
      

      break;
      }
    
    }
    
  }






int main(){ 
  
  bool run = true;
  bool run_2 =true;
  while (run){
    menu_principal(run);
  }
  /*
  while(run_2){
    menu_cliente(run_2);
  }
  */
  //Cliente clienteN("Leonardo","1234", 18, "Moquegua");
  //clienteN.ver_perfil();
  return 0;
}

// guardar "numero"  guardar usuario guarda contraseña
