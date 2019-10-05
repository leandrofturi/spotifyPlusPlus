#ifndef _USUARIO_HPP_
#define _USUARIO_HPP_

#include <iostream>
#include <fstream>

class Usuario
{
protected:
    std::string nome;
    int codigo;

public:
    Usuario();
    Usuario(std::string nome, int codigo);
    ~Usuario();

    std::string getNome();
    void setNome(std::string nome);
    int getCodigo();
	void setCodigo(int codigo);

    void imprimeNoArquivo(std::ofstream& file);
};

#endif