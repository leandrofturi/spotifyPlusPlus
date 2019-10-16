#ifndef _PLATAFORMADIGITAL_HPP_
#define _PLATAFORMADIGITAL_HPP_

// ATRIBUTOS OK

#include <iostream>
#include <fstream>
#include <algorithm>
#include <list>
#include <vector>
#include "Produtor.hpp"
#include "Podcaster.hpp"
#include "Artista.hpp"
#include "Midia.hpp"
#include "Assinante.hpp"
#include "Album.hpp"
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
    std::list<Album*>* albuns;

public:
    PlataformaDigital();
    PlataformaDigital(std::string nome);
    ~PlataformaDigital();

    std::string getNome();
    void setNome(std::string nome);

    void addAssinante(Assinante* assinante);
    void rmAssinante(Assinante* assinante);
    Assinante* buscaAssinante(int codigo);
    bool isAssinante(Assinante* assinante);
    void imprimeAssinantes();
    
    void addProdutor(Produtor* produtor);
    void rmProdutor(Produtor* produtor);
    Produtor* buscaProdutor(int codigo);
    bool isProdutor(Produtor* produtor);
    //void imprimeProdutores();

    void addMidia(Midia* midia);
    void rmMidia(Midia* midia);
    bool isMidia(Midia* midia);
    //void imprimeMidias();

    void addGenero(Midia::Genero* genero);
    void rmGenero(Midia::Genero* genero);
    Midia::Genero* buscaGenero(std::string sigla);
    bool isGenero(Midia::Genero* genero);
    void imprimeMidiasPorGenero(Midia::Genero* genero);

    void addAlbum(Album* album);
    void rmAlbum(Album* album);
    Album* buscaAlbum(int codigo);
    bool isAlbum(Album* album);
    void imprimeMidiasPorGenero(Album* album);

    void carregaArquivoUsuarios(std::ifstream& file);
    void carregaArquivoGeneros(std::ifstream& file);
    void carregaArquivoMidias(std::ifstream& file);
    void carregaArquivoFavoritos(std::ifstream& file);
};

#endif