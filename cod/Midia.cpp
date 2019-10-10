#include "../bib/Midia.hpp"

Midia::Genero::Genero() {}

Midia::Genero::Genero(std::string nome, std::string sigla)
{
    this->nome = nome;
    this->sigla = sigla;
}

Midia::Genero::~Genero() {}

std::string Midia::Genero::getNome()
{
    return this->nome;
}

std::string Midia::Genero::getSigla()
{
    return this->sigla;
}

int qtdMidias = 0;

Midia::Midia()
{
    this->qtdMidias ++;
}

Midia::Midia(std::string nome, int codigo, float duracao, int anoLancamento, char tipo, const Midia::Genero* genero)
{
    this->nome = nome;
    this->codigo = codigo;
    this->duracao = duracao;
    this->anoLancamento = anoLancamento;
    this->tipo = tipo;

    this->genero = genero;

    this->qtdMidias ++;
}

Midia::~Midia()
{
    this->qtdMidias --;
}

std::string Midia::getNome()
{
    return this->nome;
}

void Midia::setNome(std::string nome)
{
    this->nome = nome;
}

int Midia::getCodigo()
{
    return this->codigo;
}

void Midia::setCodigo(int codigo)
{
    this->codigo = codigo;
}

float Midia::getDuracao()
{
    return this->duracao;
}

void Midia::setDuracao(float duracao)
{
    this->duracao = duracao;
}

int Midia::getAnoLancamento()
{
    return this->anoLancamento;
}

void Midia::setAnoLancamento(int anoLancamento)
{
    this->anoLancamento = anoLancamento;
}

std::string Midia::getTipo()
{
    if(this->tipo == 'M')
    {
        return "Musica";
    }
    else if(this->tipo == 'P')
    {
        return "Podcast";
    }
    return "Indefinido";
}

const Midia::Genero* Midia::getGenero()
{
    return this->genero;
}

void Midia::imprimeQtdMidias()
{
    std::cout << std::endl << "################################" << std::endl << std::endl;
    std::cout << "Quantidade de produtos de " << this->getNome() << ":" << std::endl;
    std::cout << this->qtdMidias << std::endl;
    std::cout << std::endl << "################################" << std::endl << std::endl;
}