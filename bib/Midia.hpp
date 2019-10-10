#ifndef _MIDIA_HPP_
#define _MIDIA_HPP_

// FINALIZADA!

#include <iostream>

class Produtor;

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
    float duracao;
    int anoLancamento;
    char tipo;

    const Midia::Genero* genero;

public:
    int qtdMidias;

    Midia();
    Midia(std::string nome, int codigo, float duracao, int anoLancamento, char tipo, const Midia::Genero* genero);
    ~Midia();

    std::string getNome();
    void setNome(std::string nome);
    int getCodigo();
    void setCodigo(int codigo);
    float getDuracao();
    void setDuracao(float duracao);
    int getAnoLancamento();
    void setAnoLancamento(int anoLancamento);
    std::string getTipo();

    const Midia::Genero* getGenero();

    void imprimeQtdMidias();

    virtual void imprimeInfoMidia() = 0;
    virtual void imprimeNoArquivo(std::ofstream& file) = 0;
};

#endif