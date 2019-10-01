#ifndef _MUSICA_HPP_
#define _MUSICA_HPP_

#include <iostream>
#include "Midia.hpp"

class Musica : public Midia
{
private:
    int duracao;
    int anoLancamento;

public:
    Musica();
    Musica(std::string nome, bool explicito, Genero* genero, int duracao, int anoLancamento);
    ~Musica();

    int getDuracao();
	void setDuracao(int duracao);
	int getAnoLancamento();
	void setAnoLancamento(int anoLancamento);
};

#endif