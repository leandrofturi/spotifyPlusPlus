#ifndef _PLATAFORMADIGITAL_HPP_
#define _PLATAFORMADIGITAL_HPP_

#include <iostream>
#include <fstream>
#include <limits>
#include <algorithm>
#include <list>
#include <vector>
#include "Produtor.hpp"
#include "Podcaster.hpp"
#include "Artista.hpp"
#include "Midia.hpp"
#include "Assinante.hpp"
#include "../cpp-utils/util/StringUtils.h"
#include "../cpp-utils/util/Tokenizer.h"

class PlataformaDigital
{
private:
    std::string nome;

    std::list<Assinante*>* assinantes;
    std::list<Produtor*>* produtores;
    std::list<Midia*>* midias;
    std::list<Midia::Genero*>* generos;

public:
    PlataformaDigital();
    PlataformaDigital(std::string nome);
    ~PlataformaDigital();

    std::string getNome();
    void setNome(std::string nome);

    void imprimeMidiasPorGenero(Midia::Genero* genero);
    std::list<Assinante*>* getAssinantes();
    void setAssinantes(std::list<Assinante*>* assinantes);
    void addAssinante(Assinante* assinante);
    void rmAssinante(Assinante* assinante);
    void imprimeAssinantes();
    std::list<Produtor*>* getProdutores();
    void setProdutores(std::list<Produtor*>* produtores);
    void addProdutor(Produtor* produtor);
    void rmProdutor(Produtor* produtor);
    std::list<Midia*>* getMidias();
    void setMidias(std::list<Midia*>* midias);
    void addMidia(Midia* midia);
    void rmMidia(Midia* midia);
    void addMidia(Midia* midia, std::list<Produtor*>* produtores);
    std::list<Midia::Genero*>* getGeneros();
    void setGeneros(std::list<Midia::Genero*>* generos);
    void addGenero(Midia::Genero* genero);
    void rmGenero(Midia::Genero* genero);

    void carregaArquivoUsuarios(std::ifstream& file);
    void carregaArquivoGeneros(std::ifstream& file);
    void carregaArquivoMidias(std::ifstream& file);
    void carregaArquivoFavoritos(std::ifstream& file);
};

#endif