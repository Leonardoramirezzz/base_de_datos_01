#include <string>
#include <string.h>

using namespace std;

class Usuario {
  public:
    std::string usuario, contraseña, region; int edad;
    Usuario();
    Usuario (std::string _usuario, std::string _contraseña, int _edad, std::string _region);
    void iniciar_sesion();
    void cerrar_sesion();
};