#include <cstring>
#include <fstream>
#include <iostream>
#include "Tienda.h"
#include "Usuarios.h"

Usuario::Usuario(){
}

Usuario::Usuario (string _usuario, string _password, string _edad, string _region){
  usuario = _usuario;
  password = _password;
  edad = _edad;
  region = _region;
  sesion_iniciada = false;
}

void Usuario::set_usuario(string _usuario){
  usuario = _usuario;
}
void Usuario::set_password(string _password){
  password = _password;
}
void Usuario::set_region (string _region){
  region = _region;
}
void Usuario::set_edad(string _edad){
  edad = _edad;
}
string Usuario::get_region(){
  return region;
}
string Usuario::get_edad(){
  return edad;
}
string Usuario::get_usuario(){
  return usuario;
}
string Usuario::get_contraseña(){
  return password;
}
