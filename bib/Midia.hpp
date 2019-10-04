#ifndef _MIDIA_HPP_
#define _MIDIA_HPP_

#include <iostream>
#include <list>

class Produtor;

class Midia
{
public:
    class Genero
    {
    private:
        std::string nome;
        std::string sigla; // que e isso?

        std::list<Midia*>* midias;

    public:
        Genero();
        Genero(std::string nome, std::string sigla);
        ~Genero();

        std::string getNome();
        void setNome(std::string nome);
        std::string getSigla();
        void setSigla(std::string sigla);

        std::list<Midia*>* getMidias();
        void setMidias(std::list<Midia*>* midias);
        void addMidia(Midia* midia);
        void rmMidia(Midia* midia);
    };

protected:
    std::string nome;
    int codigo;
    int duracao;
    int anoLancamento;
    char tipo;

    Midia::Genero* genero;
    std::list<Produtor*>* produtores;

public:
    int qtdMidias;

    Midia();
    Midia(std::string nome, int codigo, int duracao, int anoLancamento, char tipo, Midia::Genero* genero);
    ~Midia();

    std::string getNome();
    void setNome(std::string nome);
    int getCodigo();
    void setCodigo(int codigo);
    int getDuracao();
    void setDuracao(int duracao);
    int getAnoLancamento();
    void setAnoLancamento(int anoLancamento);
    std::string getTipo();

    void imprimeQtdMidias();
    virtual void imprimeInfoMidia() = 0;

    Midia::Genero* getGenero();
    void setGenero(Midia::Genero* genero);
    std::list<Produtor*>* getProdutores();
    void setProdutores(std::list<Produtor*>* produtores);
    void addProdutor(Produtor* produtor);
    void rmProdutor(Produtor* produtor);
};

#endif