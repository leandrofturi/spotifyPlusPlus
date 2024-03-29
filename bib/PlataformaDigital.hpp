#ifndef _PLATAFORMADIGITAL_HPP_
#define _PLATAFORMADIGITAL_HPP_

#define MAX(x, y) (x > y) ? x : y

#include <iostream>
#include <fstream>
#include <cmath>
#include <list>
#include <vector>
#include <tuple>
#include <unistd.h>
#include "Produtor.hpp"
#include "Podcaster.hpp"
#include "Artista.hpp"
#include "Midia.hpp"
#include "Assinante.hpp"
#include "Album.hpp"
#include "../cpp-utils/util/StringUtils.h"
#include "../cpp-utils/util/DateUtils.h"
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

    //ACESSO DAS LISTAS DE MIDIAS DIRETAMENTE
    friend std::list<Midia*>* getFavoritas(Assinante* assinante);
    friend std::list<Midia*>* getMidias(Produtor* produtor);

    //OBJETIVOS ESPECIFICOS PARA GERACAO DE RELATORIOS
    std::list<std::tuple<Midia*, int> > top10Midias();
    //<MIDIA, QTD DE VEZES QUE FOI FAVORITADA>
    std::list<std::tuple<Produtor*, int> > top10Produtores();
    //<PRODUTOR, QTD DE MIDIAS FAVORITADAS>

public:
    PlataformaDigital();
    PlataformaDigital(std::string nome);
    ~PlataformaDigital();

    std::string getNome();
    void setNome(std::string nome);

    void addAssinante(Assinante* assinante);
    void rmAssinante(Assinante* assinante);
    Assinante* buscaAssinante(int codigo);
    void imprimeAssinantes();
    
    void addProdutor(Produtor* produtor);
    void rmProdutor(Produtor* produtor);
    Produtor* buscaProdutor(int codigo);
    void imprimeProdutores();
    double minutosOuvidosPorProdutor(Produtor* produtor);
    int qtdMusicasFavoritadasPorProdutor(Produtor* produtor);

    void addMidia(Midia* midia, std::list<Produtor*>* produtores);
    void rmMidia(Midia* midia);
    Midia* buscaMidia(int codigo);
    void imprimeMidias();
    double minutosOuvidosPorMidia(Midia* midia);
    int qtdVezesFavoritada(Midia* midia);

    void addGenero(Midia::Genero* genero);
    void rmGenero(Midia::Genero* genero);
    Midia::Genero* buscaGenero(std::string sigla);
    void imprimeMidiasPorGenero(Midia::Genero* genero);
    Midia::Genero* generoMaisOuvido();
    double minutosOuvidosPorGenero(Midia::Genero* genero);
    int qtdMusicasFavoritadasPorGenero(Midia::Genero* genero);

    void addAlbum(Album* album);
    void rmAlbum(Album* album);
    Album* buscaAlbum(int codigo);

    void carregaArquivoUsuarios(std::ifstream& file);
    void carregaArquivoGeneros(std::ifstream& file);
    void carregaArquivoMidias(std::ifstream& file);
    void carregaArquivoFavoritos(std::ifstream& file);

    void escreveEstatisticas();
    void escreveMidiasPorProdutores();
    void escreveFavoritas();
    void escreveBackup();
};

//METODOS DE ORDENACAO
template <typename T>
bool ordenaCrescPorCodigo(T *obj1, T *obj2);

template <typename T>
bool ordenaCrescPorNome(T *obj1, T *obj2);

template <typename T>
bool ordenaDecPor2Elemento(std::tuple<T*, int> obj1, std::tuple<T*, int> obj);

//INICIALIZACAO DA PLATAFORMA
PlataformaDigital* inicializaSpotifyPlusPlus(std::string fileUsuarios, std::string fileGeneros, std::string fileMidias, std::string fileFavoritas);

#endif