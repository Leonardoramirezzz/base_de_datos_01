#pragma once
#include <string>
#include <string.h>

using namespace std;

class Usuario {
  private:
    std::string usuario, password, region, edad;
    //int edad;
  public:
    bool sesion_iniciada;
  public:
    Usuario();
    Usuario (std::string _usuario, std::string _password, string _edad, std::string _region);
    void iniciar_sesion(std::string _usuario,std::string _password);
    void cerrar_sesion();
    void set_usuario(std::string _usuario);
    void set_password(std::string _password);
    void set_region (std::string _region);
    void set_edad (string _edad);
    string get_edad();
    string get_region();
    string get_usuario();
    string get_contraseña();
    
};
