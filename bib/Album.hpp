#ifndef _ALBUM_HPP_
#define _ALBUM_HPP_

#include <iostream>
#include <list>
#include "Musica.hpp"

class Artista;

class Album
{
private:
    std::string nome;
    int duracao;
    int anoLancamento;
    int qtdMusicas;

    std::list<Musica*>* musicas;
    Artista *artista;

public:
    Album();
    Album(std::string nome, int duracao, int anoLancamento);
    ~Album();

    std::string getNome();
    void setNome(std::string nome);
    int getDuracao();
    void setDuracao(int duracao);
    int getAnoLancamento();
    void setAnoLancamento(int anoLancamento);

    std::list<Musica*>* getMusicas();
    void setMusicas(std::list<Musica*>* musicas);
    void addMusica(Musica* musica);
    Artista* getArtista();
    void setArtista(Artista* artista);
};

#endif