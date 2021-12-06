class Cliente: public Usuario {
  private:
    string num_compras;
  public:
    Cliente();
    Cliente (std::string _usuario, std::string _contraseña, std::string edad, std::string _region, string _num_compras);
    void ver_perfil();
    string get_num_compras();
    void set_num_compras(string _num_compras);
    void ver_catalogo();
    void comprar(int num_clientes,Cliente *Lista_clientes, int nume_productos, Producto* Lista_Productos,int i);
    void quejas_reclamos();
    void ayuda_cliente();
    void iniciar_sesion(std::string _usuario, std:: string _password,int nume_clientes, Cliente* listaC,Empleado* ListaEm);
    void actualizar(int num_clientes,Cliente* Lista_clientes);
};
