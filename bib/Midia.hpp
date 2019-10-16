#ifndef _MIDIA_HPP_
#define _MIDIA_HPP_

// ATRIBUTOS OK!

#include <iostream>
#include <ctime>

class Midia
{
public:
    class Genero
    {
    private:
        std::string nome;
        std::string sigla;

    public:
        Genero();
        Genero(std::string nome, std::string sigla);
        ~Genero();

        std::string getNome();
        std::string getSigla();
    };

protected:
    std::string nome;
    int codigo;
    double duracao;
    int anoLancamento;
    std::string tipo;

    Midia::Genero* genero;

public:
    int qtdMidias;

    Midia();
    Midia(std::string nome, int codigo, double duracao, int anoLancamento, Midia::Genero* genero);
    ~Midia();

    std::string getNome();
    void setNome(std::string nome);
    int getCodigo();
    double getDuracao();
    void setDuracao(double duracao);
    std::string formataDuracao();
    int getAnoLancamento();
    void setAnoLancamento(int anoLancamento);
    std::string getTipo();

    Midia::Genero* getGenero();

    void imprimeQtdMidias();
    virtual void imprimeInfoMidia() = 0;
    virtual void imprimeNoArquivo(std::ofstream& file) = 0;
};

#endif